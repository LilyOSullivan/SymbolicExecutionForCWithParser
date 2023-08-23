#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <omp.h>

#define TIMEOUT 30 * 1000 // 30 seconds in milliseconds

// Return a count of the number of files in a directory. 
// This modifies the second parameter to point to an array of characters (Filenames)
// Eg: count = 2, filenames[0] = "hello.cpp", filenames[1] = "world.pdf"
int get_c_files(char* directory_path, char** filenames)
{
    WIN32_FIND_DATAW file_data;
    HANDLE file_handle;
    WCHAR full_path[MAX_PATH];
    int count = 0;

    MultiByteToWideChar(CP_UTF8, 0, directory_path, -1, full_path, MAX_PATH);

    wcscat_s(full_path, MAX_PATH, L"\\*");

    file_handle = FindFirstFileW(full_path, &file_data);
    if (file_handle == INVALID_HANDLE_VALUE) {
        printf("Path '%s' not found\n", directory_path);
        return 0;
    }

    do {
        if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            char filename[MAX_PATH];

            // Convert the filename from wide character to multi-byte (UTF-8)
            WideCharToMultiByte(CP_UTF8, 0, file_data.cFileName, -1, filename, MAX_PATH, NULL, NULL);

            int length = strlen(filename);

            // Check if file has ".c" extension
            if (length > 2 && strcmp(filename + length - 2, ".c") == 0) {
                filename[length - 2] = '\0';  // Remove ".c" extension

                // Store filename in the filenames array
                filenames[count] = _strdup(filename);
                count++;
            }
        }
    } while (FindNextFileW(file_handle, &file_data) != 0);

    FindClose(file_handle);
    return count;
}

// Return a foldername which begins with the second parameter (Prefix)
char* find_folder_by_prefix(char* path, char* prefix) {
    HANDLE hFind;
    WIN32_FIND_DATAW FindData;
    wchar_t search_path[MAX_PATH];
    wchar_t prefix_w[MAX_PATH];
    char* folder_name = NULL;

    // Convert the path and prefix to wide character strings
    MultiByteToWideChar(CP_UTF8, 0, path, -1, search_path, MAX_PATH);
    MultiByteToWideChar(CP_UTF8, 0, prefix, -1, prefix_w, MAX_PATH);

    // Construct the search path by appending the prefix and wildcard to the path
    wcscat_s(search_path, MAX_PATH, prefix_w);
    wcscat_s(search_path, MAX_PATH, L"*");

    // Find the first matching folder in the search path
    hFind = FindFirstFileW(search_path, &FindData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
                wcscmp(FindData.cFileName, L".") != 0 &&
                wcscmp(FindData.cFileName, L"..") != 0) {

                // Found a matching folder
                int folder_name_len = WideCharToMultiByte(CP_UTF8, 0, FindData.cFileName, -1, NULL, 0, NULL, NULL);
                folder_name = (char*)malloc(folder_name_len);
                WideCharToMultiByte(CP_UTF8, 0, FindData.cFileName, -1, folder_name, folder_name_len, NULL, NULL);
                break;
            }
        } while (FindNextFileW(hFind, &FindData) != 0);

        FindClose(hFind);
    }

    return folder_name;
}

void GetCurrentDirectoryPath(char* path) {
    wchar_t pathW[MAX_PATH];
    if (GetCurrentDirectoryW(MAX_PATH, pathW) != NULL) {
        char temp[MAX_PATH];
        WideCharToMultiByte(CP_UTF8, 0, pathW, -1, temp, MAX_PATH, NULL, NULL);
        sprintf_s(path, MAX_PATH, "%s\\%s", temp, "regression_tests\\");
    }
    else {
        fprintf(stderr, "Error getting the current directory");
        exit(1);
    }
}

BOOL run_executable(char* run_command, char* filename) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    WCHAR run_test_command_converted[MAX_PATH * 2];
    int count = 0;

    MultiByteToWideChar(CP_UTF8, 0, run_command, -1, run_test_command_converted, MAX_PATH * 2);

    if (!CreateProcess(NULL, run_test_command_converted, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("\tCreateProcess failed with error %d\n", GetLastError());
        return FALSE;
    }
    DWORD waitResult = WaitForSingleObject(pi.hProcess, TIMEOUT);
    TerminateProcess(pi.hProcess, 1);
    if (waitResult == WAIT_TIMEOUT) {
        // The wait time elapsed and the process did not end.
        fprintf(stderr, "\tThe generated executable timed out\n\n");
        return FALSE;
    }
    else if (waitResult == WAIT_OBJECT_0) {
        // The process ended before the timeout.
        return TRUE;
    }
    else {
        printf("\tThe executable for \'%s\' had an error occur!!\n\n", filename);
        return FALSE;
    }
}

BOOL DeleteDirectory(const WCHAR* directory) {
    BOOL bSuccess = FALSE;
    WIN32_FIND_DATAW findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    WCHAR DirPath[MAX_PATH];
    WCHAR FileName[MAX_PATH];

    swprintf_s(DirPath, MAX_PATH, L"%s\\*", directory);
    hFind = FindFirstFileW(DirPath, &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            const WCHAR* fileOrDirName = findFileData.cFileName;
            if (wcscmp(fileOrDirName, L".") != 0 && wcscmp(fileOrDirName, L"..") != 0) {
                swprintf_s(FileName, MAX_PATH, L"%s\\%s", directory, fileOrDirName);
                if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    // Recursively delete sub-directory
                    bSuccess = DeleteDirectory(FileName);
                }
                else {
                        bSuccess = DeleteFileW(FileName);
                }
            }
        } while (FindNextFileW(hFind, &findFileData) != 0);

        FindClose(hFind);
        bSuccess = RemoveDirectoryW(directory);
    }

    return bSuccess;
}

void RunTestsOnFiles(char* path, char* main_pl_path) {
    char* filenames[200];
    int count = get_c_files(path, filenames);
    printf("Found %d tests\n\n", count);
    #pragma omp parallel for
    for (int i = 0; i < count; i++) {
        // Run parser
        char run_parser[MAX_PATH * 3];
        sprintf_s(run_parser, sizeof(run_parser), ".\\Parser.exe -p\"regression_tests\" %s > nul", filenames[i]);
        int return_code = system(run_parser);
        if (return_code != 0) {
            fprintf(stderr, "\tParser returned status code %d for \'%s\'\n", return_code, filenames[i]);
            free(filenames[i]);  // Free memory allocated for each filename
            continue;
        }

        // Run ECLiPSe Prolog
        char run_eclipse[MAX_PATH * 3];
        sprintf_s(run_eclipse, sizeof(run_eclipse), "cd \"%s\" && eclipse -f \"%s\" -e \"regression_main('%s').\" > nul", path, main_pl_path, filenames[i]);
        return_code = system(run_eclipse);
        if (return_code != 0) {
            fprintf(stderr, "\tECLiPSe returned status code %d for \'%s\'\n", return_code, filenames[i]);
            free(filenames[i]);  // Free memory allocated for each filename
            continue;
        }

        // Find ECLiPSe generated directory
        char* test_folder_name = find_folder_by_prefix(path, filenames[i]);
        if (test_folder_name == NULL) {
            fprintf(stderr, "\tFolder-prefix search unable to find folder for %s\n", filenames[i]);
            free(filenames[i]);  // Free memory allocated for each filename
            continue;
        }

        // Compile the generated test-cases
        char test_folder_path[MAX_PATH];
        sprintf_s(test_folder_path, sizeof(test_folder_path), "%s%s\\", path, test_folder_name);
        char compile_test_case[MAX_PATH * 2];
        sprintf_s(compile_test_case, sizeof(compile_test_case), "cd \"C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/Build\" && vcvarsall.bat amd64 > nul && cd \"%s\" && cl /nologo %s_tests_main.c /Fe:a.exe > nul", test_folder_path, filenames[i]);
        return_code = system(compile_test_case);
        if (return_code != 0) {
            fprintf(stderr, "\tCompilation of C-files returned %d for compilation of %s\n", return_code, filenames[i]);
            free(test_folder_name);
            free(filenames[i]);
            continue;
        }

        // Run compiled test case executable
        char run_test_case[MAX_PATH];
        sprintf_s(run_test_case, sizeof(run_test_case), "%s\\a.exe", test_folder_path);
        if (run_executable(run_test_case, filenames[i]) == FALSE) {
            free(filenames[i]);
            continue;
        }

        // Remove the generated tests
        // Deletion may fail as the .exe test-case process is terminating
        WCHAR test_folder_path_converted[MAX_PATH];
        MultiByteToWideChar(CP_UTF8, 0, test_folder_path, -1, test_folder_path_converted, MAX_PATH);
        BOOL is_deleted = FALSE;
        for (int attempt = 0; attempt < 24; attempt++) {
            is_deleted = DeleteDirectory(test_folder_path_converted);
            if (is_deleted) {
                break; // Folder deleted successfully
            }
            Sleep(500); // 500 milliseconds
        }
        if (!is_deleted) {
            DWORD error = GetLastError();
            LPVOID errorMsg;
            FormatMessageA(   // Use ANSI version
                FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                NULL,
                error,
                0,
                (LPSTR)&errorMsg,
                0,
                NULL
            );
            printf("\t\tFailed to remove directory '%s': %s\n", test_folder_name, (char*)errorMsg);
            LocalFree(errorMsg);
        }

        free(test_folder_name);
        free(filenames[i]);
    }
}

int main(int argc, char* argv[]) {
    
    char main_pl_path[MAX_PATH];
    // Convert a relative to absolute path
    _fullpath(main_pl_path, "../Prolog/main.pl", MAX_PATH);

    char path[MAX_PATH];
    GetCurrentDirectoryPath(path);

    RunTestsOnFiles(path, main_pl_path);

    return 0;
}