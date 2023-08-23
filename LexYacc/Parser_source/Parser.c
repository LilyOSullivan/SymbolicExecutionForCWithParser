// Functionality
// **************
// Parse the .c file passed as one of the
// parameters to produce Prolog Terms File ( .PL)
//
// Notes
// *****
// The .PL files are output to the path of the C program.

#include <io.h>


#include "Parser_Functions.h"
// User defined header file containing all the functions used
// in the parser

int main (int argc, char * argv[]) {
	char* arguments[2]; // [file_path, filename]

	process_argument_flags(argc, argv, arguments);
	
	char C_path[_MAX_PATH];
	sprintf(C_path, "%s\\\\%s.c", arguments[0], arguments[1]);
	if (_access(C_path, 0) != 0) {
		printf("'%s.c' does not exist at path: %s\n", arguments[1], arguments[0]);
		exit(1);
	}

	// Set filepath to the .PL file (PLFile - global)
	PLFile = (char*)malloc(STRINGLIMIT);
	sprintf(PLFile, "%s\\\\%s.pl", arguments[0], arguments[1]);

	FILE* iFile = preprocess_c_file_at_path(C_path);

	// prints "parsed(["
	print_start_of_parsed_predicate(PLFile);

	// PARSE the preprocessed .c file
	parse_file(iFile);

	print_end_of_parsed_content(PLFile);

	return 0;
}
