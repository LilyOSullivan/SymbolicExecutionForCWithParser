////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** PARSER HEADER FILE -- PARSER_FUNCTIONS.H
// This header file is included in the PARSER.C file.
// It contains the functions and definitions that are required
// to cause the parsing of the preprocessed version (.I file) of 
// the C program under analysis.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Functionality
// **************
// Parse the file (.i file as preprocessed) passed as one of the
// parameters to produce Prolog Terms File ( .PL) and the names
// (.NAMES) files.
//
// Input
// *****
// 4 parameters -- 	name of parser,
//				--  path of C file -- this is where .PL and .NAMES files
//					are output to
//				--	the name of file to be parsed (less extension)
//				--  the path to the .i file - relative path
// Notes
// *****
// The .i file is deleted after parsing is complete.
// The .PL and .NAMES files are output to the path of the C program.
//
////////////////////////////////////////////////////////////////
// *** LIBRARIES USED
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

////////////////////////////////////////////////////////////////
// *** USER-DEFINED FILES USED
////////////////////////////////////////////////////////////////
#include "grammar.tab.c"	
				// The parser file generated using AYACC.
				// This file also contains the lexical analyser 
				// generated using ALex.
////////////////////////////////////////////////////////////////
// *** DEFINITIONS USED
////////////////////////////////////////////////////////////////

#define PARSER_PARAMS 4
// number of input parameters to the parser.c file
// the first is the name of the parser itself -- parser
// the second is the path of the original file -- where .pl and .names file
// will be output
// the third is the name of the file to be parsed -- less its extension
// the fourth is the relative path -- from where parser is called. This
// path is where the .i file from preprocessing is.

#define STRINGLIMIT 1000
// limit of the size of the filenames input to function

#define ERROR1 	"PARSER -- NUMBER OF INPUT ARGUMENTS IS NOT CORRECT"
#define ERROR2 	"PARSER -- CANNOT CREATE FILE"
#define ERROR3 	"PARSER -- CANNOT OPEN FILE FOR READING FROM"
#define ERROR4 	"PARSER -- CANNOT OPEN FILE TO APPEND TO"
#define ERROR5	"PARSER -- CHECK FOR COMPLILATION ERRORS IN THE CODE UNDER ANALYSIS"
// error codes for the various errors that are caught by the parser.
// execution is aborted if any of these errors are encountered.

////////////////////////////////////////////////////////////////
// *** VARIABLES
////////////////////////////////////////////////////////////////
char* C_Filename;
char * PLFile;		// name of the file to which prolog terms are written
					// named in main parser function
					// created in print_dicontiguous/1  (in this header file)
					// appended to in grammar.y
					// appended to in print_dummy_dec/1 (in this header file)

////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
//void lilyparser_get_function_name(char* line);
//void lilyparser_add_function_name(char* name);
int yyparse(void);								// extern function yyparse() to parse the file
int parser_error(char errorcode[]);				// prints errors to screen & causes parsing to abort
int print_discontiguous(char * infile);			// prints the discontigous/1 terms to PL file
int parse_file(char *infile);					// parses the .I file (Preprocessed .C file)
void yyerror (const char *s);					// in built error reporting for yyparse()
int print_dummy_dec(char * infile);				// prints the dummy declarations to PL file
int print_start_of_parsed_predicate(char* infile); // prints "parsed([
int print_end_of_parsed_predicate(char* infile); // prints "])."

////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int print_start_of_parsed_predicate(char* infile) {
	FILE* fp;
	if ((fp = fopen(infile, "w")) == NULL)
		return parser_error(ERROR2);

	fputs("parsed([\n", fp);
	fclose(fp);
	return 0;
}

int print_end_of_parsed_predicate(char* infile) {
	FILE* fp;
	if ((fp = fopen(infile, "a")) == NULL)
		return parser_error(ERROR2);
	fputs("\n]).", fp);
	fclose(fp);
	return 0;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int print_discontiguous(char * infile)
{
//////////////////////////////////////////////////////////////////
// prints the discontigous/1 statements to the PL file (infile).
// This allows the various statements in the .PL file
// to be out of sequence and avoids the "procedure clauses are not
// consecutive" error when compiling the PL file in ECLiPSe
//
//////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	FILE * fp;		// file pointer

	////////////////////////////////////////////////////////////////
	// this is the first write to the file so open for writing to
	// this will ensure that the file exists before writing or
	// overwrite it if it is already there.
	if((fp = fopen(infile, "w")) == NULL)
		return parser_error(ERROR2);

	////////////////////////////////////////////////////////////////
	// declare the Prolg predicates that can appear out of sequence,
	// in the Prolog terms file using the 'discontiguous' predicate.
	// This eliminates the "procedure clauses are not consecutive" error,
	// when the Prolog terms file is compiled in ECLiPSe.
	fputs(":- discontiguous(function_definition/4).\n", fp) ;
	fputs(":- discontiguous(global_variables/2).\n", fp);

	////////////////////////////////////////////////////////////////
	// close the file
	fclose(fp);

	////////////////////////////////////////////////////////////////
	// successfully leaving the print_discontiguous function
	return 0;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int parse_file(char * infile)
{
//////////////////////////////////////////////////////////////////
// Calls yyparse to parse the preprocessed .i file.
// yyin is assigned the name of the preprocessed .i file that requires the analysis (infile).
// This is parsed by calling yyparse().
// If there is an error in the parsing, yyerror() will be called automatically
// by yyparse() and parsing will abort.
// If successful, parsing will complete and the infile is closed.
//
//////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	// variable declarations
	FILE *fp;			// pointer to infile (.i file)

	////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////
	// open the infile for reading
	if((fp = fopen(infile,"r")) == NULL)
		return parser_error(ERROR3);

	////////////////////////////////////////////////////////////////
	// parse the infile (i.e. the .i file) assigned to the yyin variable,
	// using the parser function yyparse()
	yyin = fp;
	if((yyparse()))
	{
	   return parser_error(ERROR5);
	}
	////////////////////////////////////////////////////////////////
	// close the file
	fclose(fp);

	////////////////////////////////////////////////////////////////
	// successfully leaving the parse_file function
	return 0;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void yyerror (const char *s)
{
//////////////////////////////////////////////////////////////////
// in built error reporting function for ayacc -- cannot be changed
//////////////////////////////////////////////////////////////////

   fprintf(stderr, "SYNTAX ERROR %s AT LINE NUMBER %d\n", s, yylineno);
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int print_dummy_dec(char *infile)
{
//////////////////////////////////////////////////////////////////
// prints the 'dummy' statements to PL file.
// This allows the various statements in the .PL file
// to be out of sequence and avoids the "procedure clauses are not
// consecutive" error when compiling the PL file in ECLiPSe
//////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	FILE * fp;		// file pointer

	////////////////////////////////////////////////////////////////
	// this is NOT the first write to the file so open for appending
	// to, to ensure that the  existing prolog terms are not overwritten.
	if((fp = fopen(infile, "a")) == NULL)
		return parser_error(ERROR4);

	////////////////////////////////////////////////////////////////
	// print out the dummy declaration for global declarations
	fprintf(fp, "\nglobal_variables(999, 999)\n");
	////////////////////////////////////////////////////////////////
	// close the file
	fclose(fp);

	////////////////////////////////////////////////////////////////
	// successfully leaving the print_dummy_dec function
	return 0;
}
/*
char* function_names[1000];
int function_names_index = 0;



void lilyparser_get_function_name(char* line) {
	char* temp = line;
	int i = 0;

	char holdstr[STRING_LIMIT];
	while (temp[i] != '\0') {
		if (temp[i] != ',') {
			holdstr[i] = temp[i];
		}
		else {
			lilyparser_add_function_name(holdstr);
			break;
		}
		i++;
	}
}

void lilyparser_add_function_name(char* name) {
	function_names[function_names_index] = name;
	function_names_index++;
}

void print_functionname_database(char* infile) {
	FILE* fp;		// file pointer

	if ((fp = fopen(infile, "a")) == NULL)
		return parser_error(ERROR4);

	for (int i = 0; i < function_names_index; i++) {
		char* name = function_names[i];
		fprintf(fp, "\nfunction_name_file_name(%s, %s).\n",name,C_Filename);
	}

	fclose(fp);
}
*/
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END OF PARSER FUNCTIONS -- PARSER_FUNCTIONS.H
////////////////////////////////////////////////////////////////