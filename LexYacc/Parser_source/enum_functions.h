/*
This header file contains the functions that are required for the
processing of enumeration literals, types and variables to their
equivalent in Prolog terms.
All functions defined here are called from GRAMMAR.Y

As enumerations are declared, they are changed to their Prolog
name, using change_enum() and added to the linked list of Enums
using the function add_enums(). If the enumeration literals have
been initialised to a particular value, this is added to the linked
list of Enums also, otherwise, this is given a default value of (-1).
The traverse_enum() function is called to determine if an IDENTIFIER
is in the linked list of Enums. The reset_enumcounter() function is
used to reset the counter for enumeration literals when the 
enum definition is finished.
*/


int enum_counter = 0;
			// counter for the enumeration literals of an enum type

struct ListOfEnums
{
	char enum_name[STRING_LIMIT];	// name of enumeration literal
	int enum_value;						// initialization value if any
	struct ListOfEnums *enumnext;		// pointer to next Enum node
} 
enumstart, *enumnode;
/*
The linked list ListOfEnums holds a list of all the enumeration literals that
were declared in the source C code program.
It is filled by a calls to function:
	void add_enums(char enumname[]);
and is accessed in function:
	int traverse_enums(char enumname[]);
*/

void add_enums(char enumname[], int value);
int traverse_enums(char enumname[]);
char * change_enum(char * s);
void reset_enumcounter(void);



void add_enums(char enumname[], int value)
{
	/*	
		This function is called from the following place in the grammar file:
		enumerator
			: IDENTIFIER						 -- from here - no initialization
			| IDENTIFIER '=' constant_expression -- from here - explicit initialization
			;
		When an enumerator constant (or 'literal') is declared it is added to the linked
		list ListOfEnums to be used for comparison purposes with variable names later
		in function traverse_enums().

		The second parameter value is the value of the literal being added. If this is
		undefined, the value  (-1) is used, otherwise the value in enum_counter is used.
		If the literal has been explicity defined, change the value in enum_counter
		to value. The enumeration literal after this one will have (value + 1) enum_counter
	*/
	
	// determine the correct value of the enum_counter
	if (value == -1)
		enum_counter = enum_counter;
	else
		enum_counter = value;

	// add the details to the Enum linked list
	enumnode = &enumstart;
	while(enumnode->enumnext)
		enumnode = enumnode->enumnext;
	enumnode->enumnext = (struct ListOfEnums *) malloc (sizeof(struct ListOfEnums));
	enumnode = enumnode->enumnext;

	strcpy(enumnode->enum_name, initialisestring(enumnode->enum_name, STRING_LIMIT));							
	strcpy(enumnode->enum_name, enumname);							
	enumnode->enum_value = enum_counter;
	enumnode->enumnext = NULL;
	// update the enum_counter variable
	enum_counter++;
}


int traverse_enums(char enumname[])
{
	/*	
		This function is called from the following place in the grammar file:
			primary_expression
				: IDENTIFIER			--- from here
				| CONSTANT
				| STRING_LITERAL
				| '(' expression ')'
				;
		When an IDENTIFIER is parsed it is checked to see if it belongs to the enum
		linked list. If it is a result of YES is returned by the function, otherwise
		NO is returned by the function.
	*/

	int result = NO;					// control variable of while loop
	int enum_value = -1;				// return value of the function, default -1

	char* varname = upper(enumname);

	// Traverse the linked list and compare the enums therein with 'varname'.						
	enumnode = enumstart.enumnext;
	while (enumnode && (result == NO))
	{
		char* enumstring = upper(enumnode->enum_name);
		
		// Compare the UPPER CASE equivalent of both strings.
		// If they are the same, result = YES, change 'enum_value'						
		if (strcmp(varname, enumstring) == 0){
						/* if both strings are the same the result is YES or 1	*/
			result = YES;
			enum_value = enumnode->enum_value;
		}
		enumnode = enumnode->enumnext;
		free(enumstring);
	}

	return enum_value;
}

char* change_enum(char * s)
{
	/*
		This function is called from the following places in GRAMMAR.Y:
		enum_specifier
			: ENUM '{' enumerator_list '}'
			| ENUM IDENTIFIER '{' enumerator_list '}' 	-- called here
			| ENUM IDENTIFIER							-- called here
			;

		enumerator
			: IDENTIFIER								-- called here
			| IDENTIFIER '=' constant_expression		-- called here
			;

		It changes the enumerator type name or the enumerator literal to its Prolog
		term. If the enumerator (s) begins with lowercase, "lc_" is added to the 
		beginning of the enumerator, else "uc_" is added to the beginning of the 
		enumerator
	*/

	// variable declaration and allocation of space
	char* returnstr = (char*)malloc(3 + strlen(s) + 1);
	
	// Precede the return string by "lc_" or "uc_"	
	if (islower(s[0]))
		strcpy(returnstr, "lc_");
	else
		strcpy(returnstr, "uc_");
	strcat(returnstr, s);
	
	return returnstr;
}

void reset_enumcounter(void)
{
	/*
		This function re-sets the enum_counter variable back to zero.
		This function is called from the following places in GRAMMAR.Y:
		enum_specifier
			: ENUM '{' enumerator_list '}'				-- called here
			| ENUM IDENTIFIER '{' enumerator_list '}' 	-- called here
			| ENUM IDENTIFIER							
			;
	*/
	enum_counter = 0;
}
