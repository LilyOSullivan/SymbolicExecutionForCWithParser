////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- DEFINITIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This header file contains the libraries and definitions used
throughout the rest of the header files and the grammar files
contained in the PARSER subdirectory of the WCET Analysis Tool.
The header files used are included to the lexical analyser and
parser generator through this file.
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** INCLUDE LIBRARIES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>		
			// use pow function	

#include <string.h>			
			
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// STRING SIZES DEFINITIONS
#define UNION_SIZE 		500	
				// Limit on the number of characters allowed for yylval	
#define STRING_LIMIT 	10000	
				// Limit on the size of the strings used	
	
////////////////////////////////////////////////////////////////
// YES/NO DEFINITIONS
#define YES 	1			//	indicates TRUE, USED or SET			
#define NO 		0			//	indicates FALSE, UNUSED or UNSET	

////////////////////////////////////////////////////////////////
// STRING_FUNCTIONS.H DEFINITIONS
#define UPPER_START 	65		// upper case letters begin at ascii value 65	
#define UPPER_END   	90		// upper case letters end at ascii value 90		
#define LOWER_START 	97		// lower case letters begin at ascii value 97	
#define LOWER_END		122		// lower case letters end at ascii value 122	
#define ASCII_DIFF		32		// there is a difference of 32 between upper and
								// lower case ascii letters e.g. A = 65 a = 97	

////////////////////////////////////////////////////////////////
// ASCII_FUNCTIONS.H DEFINITIONS
#define	SINGLEQUOTE		39	
		// 39 is the ascii value of the ' character
#define CARET			94	
		// 94 is the ascii value of the ^ character	
#define ESCAPE			92	
		// 92 is the ascii value of the \ escape charcater
	
////////////////////////////////////////////////////////////////
// CONVERSION_FUNCTIONS.H DEFINITIONS
#define HEX 	16		
			// hexadecimal numbers have base 16
#define OCTAL 	8		
			// octal numbers have the base 8
#define HEX_LENGTH 2	
			// length of "0x" is 2
#define OCTAL_LENGTH 1	
			// length of "0" is 1

////////////////////////////////////////////////////////////////
// SWITCH_FUNCTIONS.H DEFINITIONS
#define CASE_STRING 	"case("
						// used to find case statements
#define DEFAULT_STRING 	"default("
						// used to find default statements
#define COMMA_STRING	","
						// used to find commas

////////////////////////////////////////////////////////////////
// OTHER DEFINITIONS
#define RADIX 10 
		// used with the itoa and ultoa functions 
		// to indicate a number to base 10 
#define IF_TOKEN 305
		// The token code for the 'if' token, when parsed.
		// This value is available to the yychar variable, which holds
		// the current lookahead token for the parser.
#define GLOBAL_SCOPE_NUMBER 0 
		// level of global variables on the stack 

////////////////////////////////////////////////////////////////
// Extern variables
extern char * NAMESFile;	
				// name of the file that the Prolog & C names are
				// written to in - the .NAMES file
							
extern char * PLFile;
				// name of the file that the Prolog terms are
				// written to - the .PL file					

extern int yylineno;	
				// the number of the line of source code being parsed
				// used for debugging reasons at the moment

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- DEFINITIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////