/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// *** MAIN PARSER -- PARSER.C
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
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
//					are  output to
//				--	the name of file to be parsed (less extension)
//				--  the path to the .i file - relative path
// Notes
// *****
// The .i file is deleted after parsing is complete.
// The .PL and .NAMES files are output to the path of the C program.
//
/////////////////////////////////////////////////////////////////
// *** BEGIN MAIN PARSER FUNCTION
/////////////////////////////////////////////////////////////////
#include "Parser_Functions.h"
// User defined header file containing all the functions used
// in the parser

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////

int main (int argc, char * argv[])
{
	/////////////////////////////////////////////////////////////////
	// variable declarations
	char * filepath;	// path of the original C file -- where .pl & .names files will go
	char * filename;	// name of the file to be parsed (less extension)
	char * relativepath;// path from where parser is called -- .i file in this path
	char * ifile;		// path (relativepath) and name of the .i file

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	filepath 	 = (char *) malloc(STRINGLIMIT);
	filename 	 = (char *) malloc(STRINGLIMIT);
	relativepath = (char *) malloc(STRINGLIMIT);
	ifile		 = (char *) malloc(STRINGLIMIT);
	// allocate space to the global variables
	PLFile = (char *) malloc(STRINGLIMIT);

	/////////////////////////////////////////////////////////////////
	// take the parameters passed and store to appropriate strings
	if(argc == PARSER_PARAMS )
	{
		strcpy(filepath, argv[1]);		// path of file
		strcpy(filename, argv[2]);		// name of file
		strcpy(relativepath, argv[3]);	// path from where parser is called
	}
	else
		return parser_error(ERROR1);

	C_Filename = (char*)malloc(STRINGLIMIT);
	strcpy(C_Filename, filename); strcat(C_Filename, ".c");

	/////////////////////////////////////////////////////////////////
	// set up path (filepath) & name of the .PL file (PLFile - global)
	strcpy(PLFile, filepath);		strcat(PLFile, "\\\\");
	strcat(PLFile, filename);		strcat(PLFile, ".pl");

	/////////////////////////////////////////////////////////////////
	// set up path (relativepath) & name of the .i file (ifile)
	strcpy(ifile, relativepath);	strcat(ifile, "\\\\");
	strcat(ifile, filename);		strcat(ifile, ".i");

	/////////////////////////////////////////////////////////////////
	// print the discontiguous statements -- to PLFile
	//print_discontiguous(PLFile);

	print_start_of_parsed_predicate(PLFile);

	/////////////////////////////////////////////////////////////////
	// set up path (filepath) & name of the .NAMES file (NAMESFile - global)

	/////////////////////////////////////////////////////////////////
	// PARSE the input file	-- parse .i file (ifile)
	parse_file(ifile);

	/////////////////////////////////////////////////////////////////
	// print the dummy declarations	 -- to PLFile
	print_dummy_dec(PLFile);

	print_end_of_parsed_predicate(PLFile);
	//print_functionname_database(PLFile);

	/////////////////////////////////////////////////////////////////
	// remove the preprocessed C code (.i file) as it is no longer required
	
	remove(ifile);

	/////////////////////////////////////////////////////////////////
	// successfully leaving the parser
	return 0;
}

////////////////////////////////////////////////////////////////
// *** END MAIN PARSER -- PARSER.C
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////