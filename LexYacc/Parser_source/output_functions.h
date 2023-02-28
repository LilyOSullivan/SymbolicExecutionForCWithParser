////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- OUTPUT_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This header file also contains the functions which write the C names
and their equivalent Prolog names to the .NAMES file.
It also contains the function that causes the printing of the
Prolog terms to the .PL file
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * getline(FILE *fp);
void printnames(char prolog_str[], char c_str[]);
char * case_name(char  * varname);
char * scope_details(char * varname, int param);
void printfunction(char inputstring[]);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * getline(FILE *fp)
{
////////////////////////////////////////////////////////////////
/*
This function takes as parameter a pointer to a file that already
exists and is open for reading from.
It will return to a string pointer a single line of that file
i.e. a line that ends at '\n' (or EOF).
This function was written as C defined functions such as fgets/1
return the line of the file to a character array of maximum 255
characters. This was not large enough for the purpose required.

This function is used by printnames() to get each line of the
.NAMES file, one at a time.
*/
////////////////////////////////////////////////////////////////

	char ch;		// taking one character at a time from file
	char c[2];		// character string to assign ch to
	char * line;	// return string of the function

	line = (char *) malloc(STRING_LIMIT);	// make room for line
	strcpy(line, "");					// initialise line
	while ((ch = (char) (getc(fp))) != EOF && ch != '\n')
	{
		c[0] = ch;
		c[1] = '\0';
		strcat(line, c);
	}
	
	////////////////////////////////////////////////////////////////
	// successfully leaving the function with a line of the file
	return line;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void printnames(char prolog_str[], char c_str[])
{
////////////////////////////////////////////////////////////////////
/*
This function is called by a variety of other functions defined in the 
header files of the PARSER. Its purpose is to add the Prolog name and 
the C name, passed as parameters, to the NAMESFile, if they are not already
present in that file.
*/
////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations
	FILE * namefile_ptr;				// pointer to the NAMES file
	char * fileline;					// line from the file
	char * namesline;					// line with Prolog and C name
	char * prolog_name = prolog_str;	// input parameter - Prolog Name
	char * c_name = c_str;				// input parameter - C Name
	int found = 0;						// indicates if namesline is already in NAMES file

	////////////////////////////////////////////////////////////////////
	// Create the prolog and C name string
	namesline = (char *) malloc(STRING_LIMIT);
	strcpy(namesline, "var_names(\'");
	strcat(namesline, prolog_name);
	strcat(namesline, "\', \"");
	strcat(namesline, c_name);
	strcat(namesline, "\").");

	////////////////////////////////////////////////////////////////////
	// Search the file to see if the 'namesline' is already there
	// if it is, set found to true (1)
	namefile_ptr = fopen(NAMESFile, "r");
	while (!feof(namefile_ptr))
	{
		fileline = (char *) malloc(STRING_LIMIT);
		strcpy(fileline, getline(namefile_ptr));
		if (strstr(fileline, namesline) != NULL)
			found = 1;
	}
	fclose(namefile_ptr);

	////////////////////////////////////////////////////////////////////
	// Add the Prolog and C name if it is not already there (found == 0)
	if (found == 0)
	{
		namefile_ptr = fopen(NAMESFile, "a");
		fprintf(namefile_ptr, "var_names(\'%s\', \"%s\").\n", prolog_name, c_name);
		fclose(namefile_ptr);
	}
	////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * case_name(char  * varname)
{
////////////////////////////////////////////////////////////////////
/*
This function is called by a variety of other functions defined in the 
header files of the PARSER. 
Its purpose is to change the 'varname' passed as parameter to its Prolog
equivalent. If the first letter in 'varname' is lower case, the variable 
'name' gets "LC_" and 'varname' copied to it. If the first letter in 'varname' 
is upper case, the variable 'name' gets "UC_" and 'varname' copied to it. 
The variable 'name' is then returned by the function.
*/
////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declaration and space allocation
	char * name;
	name = (char *) malloc(STRING_LIMIT);

	/////////////////////////////////////////////////////////////////
	// Precede the return string 'name' with "LC_" or "UC_"
	if (islower(varname[0]))
		strcpy(name, "LC_");
	else
		strcpy(name, "UC_");
		
	/////////////////////////////////////////////////////////////////
	// Append 'varname' to 'name'	
	strcat(name, varname);
	/////////////////////////////////////////////////////////////////
	// Return the Prolog name 'name'	
	return name;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * scope_details(char * varname, int param)
{
////////////////////////////////////////////////////////////////////
/*
This function is called by a variety of other functions defined in the 
header files of the PARSER. 
Its purpose is to find the scoping details of the variable passed as 
parameter 'varname'. The variable 'param' is either YES or NO. If it 
is YES, then a parameter variable is not being declared, therefore 
scoping information must be addded to 'varname' and returned 
Otherwise, a parameter variable is being declared and NO scoping 
information is added. The variable is returned unchanged.
*/
////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations 
    char * number_str;		// the string equivalent of linenumber
    int linenumber;			// the line number where current scope began
	char * name;			// return string of the function

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables
	name = (char *) malloc(STRING_LIMIT);
	number_str = (char *) malloc(STRING_LIMIT);

	/////////////////////////////////////////////////////////////////
	// get the current scope linenumber
	linenumber = ScopeLineNumber();		// SCOPES.H

	/////////////////////////////////////////////////////////////////
	// Start building the return string 'name'
	strcpy(name, varname);

	/////////////////////////////////////////////////////////////////
	// If 'varname' is NOT parameter variable, append scoping information
	//if (param == NO)
	//{
		strcat(name, "_");
		itoa(linenumber, number_str, 10);
		strcat(name, number_str);
	//}
	////////////////////////////////////////////////////////////////
	// successfully leaving the function	
	return name;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void printfunction(char inputstring[])
{
////////////////////////////////////////////////////////////////
/*
The printfunction() function is called from the following
places in GRAMMAR.Y

external_declaration
	: function_definition	-- call printfunction()
	| declaration			-- call printfunction()	
	;
	
This function is called to print the contents of the pseudo-variable
$$ to the Prolog terms file, denoted by the extern variable PLFile.
The information is appended to the PLFile as it may already contain
predicates.
*/
////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations 
	FILE *file_ptr;				// file pointer	
	char *Prologterms;			// Prolog terms - assigned contents of $$
	
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables	
	Prologterms = (char *) malloc(UNION_SIZE);
	
	/////////////////////////////////////////////////////////////////
	// Initialise Prologterms with contents of $$
	strcpy(Prologterms, inputstring);	

	/////////////////////////////////////////////////////////////////
	// Open file and append to
	file_ptr = fopen(PLFile, "a");
	fprintf(file_ptr, "%s\n", Prologterms);
	
	/////////////////////////////////////////////////////////////////
	// Close file
	fclose(file_ptr);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- OUTPUT_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////