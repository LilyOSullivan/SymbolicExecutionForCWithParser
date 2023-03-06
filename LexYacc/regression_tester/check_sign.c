#pragma comment(lib, "Kernel32.lib")

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


int main() {
    char Path_to_i_file[100];
    //sprintf(Path_to_i_file, "%s/%s.i", Path, Filename_without_extension);
    //    system(Path_to_i_file);

    //    char Run_parser_command[100];
    //    sprintf(Run_parser_command, "cd %s && .\\LilyParser.exe .//regression_tests  %s .//regression_tests", Path_to_parser, Filename_without_extension);
    //    system(Run_parser_command);
    //
    //    char Path_to_pl_file[100];
    //    sprintf(Path_to_pl_file, "%s/%s.pl", Path, Filename_without_extension);
    //    // check if file exists
    //    FILE *f = fopen(Path_to_pl_file, "r");
    //    if (f == NULL) {
    //        printf("File %s.pl does not exist. Parser failed to generate .pl file", Filename_without_extension);
    //        return 1;
    //    }
    //    fclose(f);

    char path[] = ".";
    //char path[] = "../LexYacc/regression_tests";
    char path_to_parser[] = "../LexYacc";
    char* filenames[100];  // Assume maximum of 100 files in directory
    char change_to_test_dir[50];

    int count = get_filenames(path, filenames);

    if (count > 0) {
        printf("Files in directory %s:\n", path);
        sprintf(change_to_test_dir, "cd %s", path_to_parser);
        system(change_to_test_dir);
        for (int i = 0; i < count; i++) {
            printf("\t%s\n", filenames[i]);
            char* result;
            if ((result = strstr(filenames[i], ".c")) != NULL && strlen(result) == 2) {
                int length = strlen(filenames[i]);
                if (length >= 2) {
                    filenames[i][length - 2] = '\0';
                }
                strncpy(filenames[i], "", 2);
            }
            else {
                continue; // Ignore non-.c files
            }

            // Preprocess a file, and run the parser
            char Run_parser_command[100];
            sprintf(Run_parser_command, ".\\LilyParser.exe .  %s .", filenames[i]);
            system(Run_parser_command);



            free(filenames[i]);  // Free memory allocated for each filename
        }
    }
    else {
        printf("No files found in directory %s\n", path);
    }

    return 0;


}

