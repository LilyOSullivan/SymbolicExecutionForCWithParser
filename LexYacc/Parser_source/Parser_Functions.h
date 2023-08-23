// This header file is included in the PARSER.C file.
// It contains the functions and definitions that are required
// to cause the parsing of the preprocessed version of 
// the C program under analysis.
////////////////////////////////////////////////////////////////
// Functionality
// **************
// Parse the C file passed as one of the
// parameters to produce Prolog Terms File ( .PL)
//
// Input
// *****
//				-- 	name of parser (Implicitely passed)
//				--  (potential flags)
//				--	the name of file to be parsed, less extension
// Notes
// *****
// The .PL file is output to the path of the C program.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <sys/stat.h>


#include "grammar.tab.c"	
				// The parser file generated using AYACC.
				// This file also contains the lexical analyser 
				// generated using ALex.

#define STRINGLIMIT 1000
// limit of the size of the filenames input to function

#define ERROR1 	"PARSER -- NUMBER OF INPUT ARGUMENTS IS NOT CORRECT"
#define ERROR2 	"PARSER -- CANNOT CREATE FILE"
#define ERROR3 	"PARSER -- CANNOT OPEN FILE FOR READING FROM"
#define ERROR4 	"PARSER -- CANNOT OPEN FILE TO APPEND TO"
#define ERROR5	"PARSER -- CHECK FOR COMPLILATION ERRORS IN THE CODE UNDER ANALYSIS"
// error codes for the various errors that are caught by the parser.
// execution is aborted if any of these errors are encountered.

char* C_Filename;
char * PLFile;		// name of the file to which prolog terms are written
					// named in main parser function

int yyparse(void);								// extern function yyparse() to parse the file
int parser_error(char errorcode[]);				// prints errors to screen & causes parsing to abort
int parse_file(FILE* iFile);					// parses the Preprocessed .C file
void yyerror (const char *s);					// in built error reporting for yyparse()
int print_start_of_parsed_predicate(char* infile); // prints "parsed([
int print_end_of_parsed_content(char* infile); // prints dummy global_varaibles && "])."
void process_argument_flags(int argc, char* argv[], char* arguments[]);		// Processes argument flags such as "-h"

void process_argument_flags(int argc, char* argv[],char* arguments[]) 
{
	// Default values if not set by flags
	arguments[0] = "."; // path of the file

	for (int i = 1; i <= argc - 1; i++) {
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				case 'h': // Print help information
					printf("Usage: .\\LilyParser [OPTION]... [FILE]\nParse a C file to Prolog terms.\n\n-h\t Display help information\n-p\t Path to the .c file (DEFAULT: Current Directory ('.'))\n\nExamples:\n\t.\\LilyParser -p\".\" get_sign \n\t.\\LilyParser get_sign \n\t.\\LilyParser -p\"C:/Parser/\" sign \n");
					exit(1);
				case 'p':
					{
						char* path = argv[i];
						path += 2; // Remove -p
						struct stat s;

						// Check the path exists and it is a directory
						if (_stat(path, &s) == -1 || !(s.st_mode & _S_IFDIR)) {
							printf("The path '%s' is not valid\n", path);
							exit(1);
						}
						arguments[0] = path;
						break;
					}
				default:
					printf("Unsupported flag '-%c', ignoring.", argv[i][1]);
			}
		}
		else {
			if (strchr(argv[i], '.') != NULL) {
				printf("Filename '%s' must not have an extension\n", argv[i]);
				exit(1);
			}
			arguments[1] = argv[i]; // No '-' means it is the filename 
		}
	}
}


int parser_error(char errorcode[])
{
	// 	When an error is encountered the errorcode passed as parameter
	// 	to this function is output and execution is aborted by calling
	// 	the exit() function from stdlib.h

	printf("%s\nEXECUTION ABORTED\n", errorcode);
	getch();
	exit(1);	// abort execution
   	return 1;	// denotes erronous termination
}

FILE* preprocess_c_file_at_path(char* C_path) {
	char* pre_process_command = (char*)malloc(STRINGLIMIT);
	sprintf(pre_process_command, "CL /EP /nologo %s", C_path);

	FILE* iFile = _popen(pre_process_command, "r");
	if (iFile == NULL) {
		printf("Failed to CL command: %s\n", pre_process_command);
		exit(1);
	}
	free(pre_process_command);

	// Skip the first line
	// This is the name of the file being processed by CL. 
	char temp[1024];
	fgets(temp, sizeof(temp), iFile);

	return iFile;
}


int print_start_of_parsed_predicate(char* infile) {
	FILE* fp;
	if ((fp = fopen(infile, "w")) == NULL)
		return parser_error(ERROR2);

	fputs("parsed([\n", fp);
	fclose(fp);
	return 0;
}

int print_end_of_parsed_content(char* infile) {

	FILE* fp;
	if ((fp = fopen(infile, "a")) == NULL)
		return parser_error(ERROR2);

	fputs("\nglobal_variables(999, 999)\n\n]).", fp);
	fclose(fp);
	return 0;
}

int parse_file(FILE* iFile)
{
	// Calls yyparse to parse the preprocessed .i file.
	// yyin is assigned the name of the preprocessed .i file that requires the analysis (iFile).
	// This is parsed by calling yyparse().
	// If there is an error in the parsing, yyerror() will be called automatically
	// by yyparse() and parsing will abort.
	// If successful, parsing will complete and the infile is closed.

	yyin = iFile;
	if((yyparse()))
	{
	   return parser_error(ERROR5);
	}

	return 0;
}

void yyerror (const char *s)
{
	// in built error reporting function for ayacc -- cannot be changed
   fprintf(stderr, "SYNTAX ERROR %s AT LINE NUMBER %d\n", s, yylineno);
}
