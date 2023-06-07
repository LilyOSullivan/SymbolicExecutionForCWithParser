/*
This header file also contains the functions which write the C names
and their equivalent Prolog names to the .NAMES file.
It also contains the function that causes the printing of the
Prolog terms to the .PL file
*/

#include <stdarg.h>

char* case_name(char* varname);
char* scope_details(char* varname, int param);
void printfunction(char inputstring[]);

char* case_name(char* varname)
{
	/*
	This function is called by a variety of other functions defined in the
	header files of the PARSER.
	Its purpose is to change the 'varname' passed as parameter to its Prolog
	equivalent. If the first letter in 'varname' is lower case, the variable
	'name' gets "LC_" and 'varname' copied to it. If the first letter in 'varname'
	is upper case, the variable 'name' gets "UC_" and 'varname' copied to it.
	The variable 'name' is then returned by the function.
	*/

	char* name = (char*)malloc(3 + strlen(varname) + 1);

	// Precede the return string 'name' with "LC_" or "UC_"
	if (islower(varname[0]))
		strcpy(name, "LC_");
	else
		strcpy(name, "UC_");

	// Append 'varname' to 'name'
	strcat(name, varname);
	return name;
}

char* scope_details(char* varname, int param)
{
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
	
	int linenumber = ScopeLineNumber();	// get the current scope linenumber	- SCOPES.H
	int number_str_size = snprintf(NULL, 0, "%d", linenumber); // Calculate size needed for number_str
	char* number_str = (char*)malloc(number_str_size + 1 + 1);
	snprintf(number_str, number_str_size + 1, "%d", linenumber); // Write linenumber to number_str

	char* name = (char*)malloc(strlen(varname) + 1 + strlen(number_str) + 1);

	strcpy(name, varname);
	strcat(name, "_");
	strcat(name, number_str);

	free(number_str);

	return name;
}

void printfunction(char inputstring[])
{
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

	FILE* file_ptr;				// file pointer
	char* Prologterms = (char*)malloc(strlen(inputstring) + 1);
	strcpy(Prologterms, inputstring);

	// Open file and append to
	file_ptr = fopen(PLFile, "a");
	fprintf(file_ptr, "%s\n", Prologterms);
	free(Prologterms);
	fclose(file_ptr);
}
