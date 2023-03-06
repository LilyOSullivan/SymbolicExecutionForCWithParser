#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int get_filenames(char* directory_path, char** filenames)
{
    WIN32_FIND_DATAW file_data;
    HANDLE file_handle;
    WCHAR full_path[MAX_PATH];
    int count = 0;

    MultiByteToWideChar(CP_UTF8, 0, directory_path, -1, full_path, MAX_PATH);

    wcscat_s(full_path, MAX_PATH, L"\\*");

    file_handle = FindFirstFileW(full_path, &file_data);
    if (file_handle == INVALID_HANDLE_VALUE) {
        printf("Error: %s not found\n", directory_path);
        return 0;
    }

    do {
        if (!(file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            char filename[MAX_PATH];
            WideCharToMultiByte(CP_UTF8, 0, file_data.cFileName, -1, filename, MAX_PATH, NULL, NULL);
            filenames[count] = (char*)malloc(strlen(filename) + 1);
            strcpy(filenames[count], filename);
            count++;
        }
    } while (FindNextFileW(file_handle, &file_data) != 0);

    FindClose(file_handle);

    return count;
}

char* find_folder_by_prefix(char* path, char* prefix) {
    HANDLE hFind;
    WIN32_FIND_DATAW FindData;
    wchar_t search_path[MAX_PATH];
    char* folder_name = NULL;
    wchar_t folder_name_w[MAX_PATH];
    int folder_name_len;

    // Convert the path and prefix to wide character strings
    MultiByteToWideChar(CP_UTF8, 0, path, -1, search_path, MAX_PATH);
    MultiByteToWideChar(CP_UTF8, 0, prefix, -1, search_path + wcslen(search_path), MAX_PATH - wcslen(search_path));

    // Construct the search path by appending the prefix to the path
    //wcscat_s(search_path, MAX_PATH, L"\\");
    wcscat_s(search_path, MAX_PATH, L"*");

    // Find the first matching folder in the search path
    hFind = FindFirstFileW(search_path, &FindData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (wcscmp(FindData.cFileName, L".") != 0 && wcscmp(FindData.cFileName, L"..") != 0) {
                    // Found a non-hidden folder
                    wcscpy_s(folder_name_w, MAX_PATH, FindData.cFileName);
                    folder_name_len = WideCharToMultiByte(CP_UTF8, 0, folder_name_w, -1, NULL, 0, NULL, NULL);
                    folder_name = (char*)malloc(folder_name_len);
                    WideCharToMultiByte(CP_UTF8, 0, folder_name_w, -1, folder_name, folder_name_len, NULL, NULL);
                    break;
                }
            }
        } while (FindNextFileW(hFind, &FindData) != 0);

        FindClose(hFind);
    }

    return folder_name;
}

bool delete_directory(char* path) {
    WIN32_FIND_DATAW findData;
    HANDLE findHandle;
    WCHAR filePath[MAX_PATH];
    WCHAR directoryPath[MAX_PATH];

    // convert the path to wide characters
    int wpathLen = MultiByteToWideChar(CP_UTF8, 0, path, -1, NULL, 0);
    if (wpathLen == 0) {
        return false;
    }
    WCHAR* wpath = (WCHAR *)malloc(wpathLen * sizeof(WCHAR));
    if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, wpathLen) == 0) {
        free(wpath);
        return false;
    }

    // create a string with the search path
    swprintf(directoryPath, MAX_PATH, L"%s\\*", wpath);

    // find the first file/directory in the specified directory
    findHandle = FindFirstFileW(directoryPath, &findData);
    if (findHandle == INVALID_HANDLE_VALUE) {
        // failed to find any files/directories in the specified directory
        free(wpath);
        return false;
    }

    // loop through all files/directories in the specified directory
    do {
        // create the full path for the file/directory
        swprintf(filePath, MAX_PATH, L"%s\\%s", wpath, findData.cFileName);

        if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
            // found a directory
            if (wcscmp(findData.cFileName, L".") == 0 || wcscmp(findData.cFileName, L"..") == 0) {
                // ignore the current and parent directories
                continue;
            }

            // recursively delete the directory
            if (!delete_directory((char*)filePath)) {
                // failed to delete the directory
                FindClose(findHandle);
                free(wpath);
                return false;
            }
        }
        else {
            // found a file, delete it
            if (DeleteFileW(filePath) == FALSE) {
                // failed to delete the file
                FindClose(findHandle);
                free(wpath);
                return false;
            }
        }
    } while (FindNextFileW(findHandle, &findData) != 0);

    // close the search handle
    FindClose(findHandle);

    // delete the specified directory
    if (RemoveDirectoryW(wpath) == FALSE) {
        // failed to delete the directory
        free(wpath);
        return false;
    }

    free(wpath);
    return true;
}

int main() {
    char path[] = ".\\regression_tests\\";
    char* filenames[200];  

    int count = get_filenames(path, filenames);

   if (count > 0) {
        printf("Files in directory %s:\n", path);
        for (int i = 0; i < count; i++) {
            char* dot_c_substring;
            if ((dot_c_substring = strstr(filenames[i], ".c")) != NULL && strlen(dot_c_substring) == 2) {
                int length = strlen(filenames[i]);
                if (length >= 2) {
                    filenames[i][length - 2] = '\0'; // Remove .c
                }
            }
            else {
                free(filenames[i]);  // Free memory allocated for each filename
                continue; // Ignore non-.c files
            }
            printf("\t%s.c\n", filenames[i]);
            // Preprocess the file, and run the parser
            char run_preprocessor[200];
            sprintf(run_preprocessor, "cd regression_tests && CL /EP /P /nologo %s.c > nul && cd .. && .\\LilyParser.exe regression_tests %s regression_tests > nul", filenames[i], filenames[i]);
            int return_code = system(run_preprocessor);
            if (return_code != 0) {
                fprintf(stderr, "CL/Parser returned status code %d for %s\n", return_code, filenames[i]);
                free(filenames[i]);  // Free memory allocated for each filename
                continue;
            }

            char run_eclipse[MAX_PATH];
            sprintf(run_eclipse, "cd regression_tests && eclipse -f \"Z:/Documents/Github/SymbolicExecutionForCWithParser/Prolog/main.pl\" -e \"regression_main('%s').\" > nul", filenames[i]);
            system(run_eclipse);

            char* test_folder_name = find_folder_by_prefix(path, filenames[i]);
            if (test_folder_name == NULL) {
                fprintf(stderr, "\tCL/Parser returned status code %d for %s\n", return_code, filenames[i]);
                free(filenames[i]);  // Free memory allocated for each filename
                continue;
            }

            char test_folder_path[MAX_PATH];
            sprintf(test_folder_path, "%s%s", path, test_folder_name);

            char compile_cunit[MAX_PATH];
            sprintf(compile_cunit, "cd %s && gcc %s_tests_main.c -lcunit", test_folder_path, filenames[i]);
            int result = system(compile_cunit);
            if (result != 0) {
                fprintf(stderr, "\tGCC returned %d for compilation of %s\n", return_code, filenames[i]);
                free(test_folder_name);
                free(filenames[i]);
                continue;
            }

            char run_cunit[MAX_PATH];
            sprintf(run_cunit, "cd %s && .\\a.exe > nul", test_folder_path);
            result = system(run_cunit);
            if (result < 0) {
                fprintf(stderr, "\tCUnit returned %d failed tests for %s\n", return_code, filenames[i]);
                free(test_folder_name);
                free(filenames[i]);
                continue;
            }
            else {
                printf("\t%s successfully passed\n", filenames[i]);
            }

            char delete_folder[MAX_PATH];
            sprintf(delete_folder, "rmdir /s /q \"%s\"", test_folder_path);
            Sleep(125);
            system(delete_folder);

            free(test_folder_name);
            free(filenames[i]);  // Free memory allocated for each filename
        }
    }
    else {
        printf("No files found in directory %s\n", path);
    }

    return 0;
}
