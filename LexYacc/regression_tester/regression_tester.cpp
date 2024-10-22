#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>

// Return a count of the number of files in a directory. 
// This modifies the second parameter to point an array of characters 
// Which each are a filename
// Eg: count = 2, char[0] = "hello.cpp", filenames[1] = "world.pdf"
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

// Return a foldername which begins with the second parameter (Prefix)
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

int main(int argc, char* argv[]) {
   //char main_pl_path[MAX_PATH] = "Z:/Documents/Github/SymbolicExecutionForCWithParser/Prolog/main.pl";
    
    char main_pl_path[MAX_PATH];
    // Convert a relative to absolute path
    _fullpath(main_pl_path, "../Prolog/main.pl", MAX_PATH);

    char path[MAX_PATH];
    wchar_t pathW[MAX_PATH];
    if (GetCurrentDirectoryW(MAX_PATH, pathW) != NULL) {
        char temp[MAX_PATH];
        WideCharToMultiByte(CP_UTF8, 0, pathW, -1, temp, MAX_PATH, NULL, NULL);
        sprintf(path, "%s/%s", temp, "regression_tests/");
    }
    else {
        fprintf(stderr, "Error getting the current directory");
        exit(1);
    }
    char* filenames[200];  

    int count = get_filenames(path, filenames);

   if (count > 0) {
        for (int i = 0; i < count; i++) {
            char* dot_c_substring;
            if ((dot_c_substring = strstr(filenames[i], ".c")) != NULL && strlen(dot_c_substring) == 2) {
                int length = strlen(filenames[i]);
                if (length >= 2) {
                    filenames[i][length - 2] = '\0'; // Remove .c
                }
            }
            else {
                free(filenames[i]);  // Free memory-allocated for each filename
                continue; // Ignore non-.c files
            }
            printf("\t%s.c\n", filenames[i]);
            // Preprocess the file, and run the parser
            char run_preprocessor[MAX_PATH*3];
            sprintf(run_preprocessor, "cd \"%s\" && CL /EP /P /nologo %s.c > nul && cd .. && .\\LilyParser.exe -p\"regression_tests\" %s -d\"regression_tests\" > nul", path, filenames[i], filenames[i]);
            int return_code = system(run_preprocessor);
            if (return_code != 0) {
                fprintf(stderr, "CL/Parser returned status code %d for %s\n", return_code, filenames[i]);
                free(filenames[i]);  // Free memory allocated for each filename
                continue;
            }
            

            // Run ECLiPSe Prolog
            char run_eclipse[MAX_PATH*2];
            sprintf(run_eclipse, "cd \"%s\" && eclipse -f \"%s\" -e \"regression_main('%s').\" > nul", path, main_pl_path, filenames[i]);
            system(run_eclipse);

            char* test_folder_name = find_folder_by_prefix(path, filenames[i]);
            if (test_folder_name == NULL) {
                fprintf(stderr, "\tFolder-prefix search unable to find folder for %s\n", filenames[i]);
                free(filenames[i]);  // Free memory allocated for each filename
                continue;
            }

            char test_folder_path[MAX_PATH*2];
            sprintf(test_folder_path, "%s%s", path, test_folder_name);

            // Compile the generated test-cases
            char compile_test_case[MAX_PATH*2];
            sprintf(compile_test_case, "cd \"C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/Build\" && vcvarsall.bat amd64 > nul && cd \"%s\" && cl /nologo %s_tests_main.c /Fe:a.exe > nul", test_folder_path, filenames[i]);
            return_code = system(compile_test_case);
            if (return_code != 0) {
                fprintf(stderr, "\tCL returned %d for compilation of %s\n", return_code, filenames[i]);
                free(test_folder_name);
                free(filenames[i]);
                continue;
            }

            // Run the generated test-cases
            char run_test_case[MAX_PATH*2];
            sprintf(run_test_case, "cd \"%s\" && a.exe", test_folder_path);
            return_code = system(run_test_case);
            if (return_code != 0) {
                fprintf(stderr, "\Test-cases returned %d failed tests for %s\n", return_code, filenames[i]);
                free(test_folder_name);
                free(filenames[i]);
                continue;
            }
            else {
                printf("\t%s successfully passed\n", filenames[i]);
            }

            // Remove the generated tests and compiled executable
            char delete_folder[MAX_PATH];
            sprintf(delete_folder, "rmdir /s /q \"%s\" > nul", test_folder_path);
            Sleep(75);
            if (system(delete_folder) != 0) {
                Sleep(135);
                system(delete_folder);
            }

            free(test_folder_name);
            free(filenames[i]);  // Free memory-allocated for each filename
        }
    }
    else {
        printf("No files found in directory %s\n", path);
    }

    return 0;
}