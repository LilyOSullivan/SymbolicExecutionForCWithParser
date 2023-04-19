/*
This header file contains the functions necessary for changing 
'typedef' definitions to a format appropriate for their equivalent
in Prolog terms.
The functions in this header file are called from the following 
places:

GRAMMAR.L
---------
{L}({L}|{D})*		{ return (check_type(yytext)); }
The check_type() function determines if the token parsed is a
TYPE_NAME token or an IDENTIFIER token. This is determined by 
establishing if the token is already in the Typedef linked list,
using the traverse_types() function defined in this header file.
If the token exists in the linked list, it is returned as a 
TYPE_NAME token. The typedef_flag is NO in this function after
the TYPE_NAME token has been returned.

GRAMMAR.Y
---------
type_specifier
	: VOID		
	| CHAR		
	:
	:
	| TYPE_NAME		-- calls add_typedefs() and change_typedef()
	;
The add_typedefs() function is called to add the TYPE_NAME token 
to the TYPEDEF linked list. The change_typedef() function is called
to change the TYPE_NAME token  to its Prolog equivalent to be added 
the linked list and copied to the pseudo-variable $$.

storage_class_specifier
	: TYPEDEF	-- calls set_typedef_flag()
	| EXTERN	
	| STATIC	
	| AUTO		
	| REGISTER	
	;
The set_typedef_flag() function is called to set the typedef_flag,
indicating that a TYPEDEF declaration is about to be parsed.
This is unset in GRAMMAR.L after the TYPE_NAME has been parsed.
*/

int typedef_flag = NO;
		// This flag, with the NO default value, is SET in the 
		// set_typedef_flag() function each time the "typedef" is parsed.
		// It is NO when its associated TYPE_NAME is parsed in GRAMMAR.L

struct ListOfTypes
{
	char * type_name;
	struct ListOfTypes *typenext;
} typestart, *typenode;
			// The linked list that holds the names of all the typedef 
			// TYPE_NAMES  parsed in the underlying Program under analysis. 
			// TYPE_NAMES are added in GRAMMAR.Y by the function add_typedefs().
			
void add_typedefs(char typedefname[]);
int traverse_types(char typedefname[]);
void set_typedef_flag(void);
char* change_typedef(char* s);

void add_typedefs(char typedefname[])
{
	/*	
		This function adds the parameter 'typedefname' to the linked list
		of TYPEDEFs. The 'typedefname' will only be added to the linked
		list if it does not already exist therein. This is established by
		using the traverse_types() function.
	*/

	// Push the 'typedefname' parameter onto the linked list
	// if it is not already stored there.
	if (traverse_types(typedefname) == NO)
	{	
		// Create a new node and add the 'typedefname' parameter to it
		typenode = &typestart;
		while(typenode->typenext)
			typenode = typenode->typenext;
		typenode->typenext = (struct ListOfTypes *) malloc (sizeof(struct ListOfTypes));
		typenode = typenode->typenext;
		typenode->type_name = (char*)malloc(strlen(typedefname) + 1);
		strcpy(typenode->type_name, typedefname);
		typenode->typenext = NULL;
	}
}


int traverse_types(char typedefname[])
{
	/*	
		This function is called with the parameter 'typedefname'.
		If 'typedefname' exists in the linked list of typedefs, YES (1) is returned;
		else NO (0) is returned.
	*/

	int result = NO;				// return result of the function
									// by default, the result is 0 - NO
	char* param_string;			// assigned the parameter 'typedefname'
	char* linkedlist_string;		// assigned each typedef in linked list
	
	// allocate space to param_string, assign it upper case of 'typedefname'
	char* temp = upper(typedefname);
	param_string = (char*)malloc(strlen(temp) + 1);
	strcpy(param_string, temp);
	
	// Traverse the linked list and compare the typedefs therein with 'typedefname'.
	typenode = typestart.typenext;
	while (typenode && (result == NO))
	{
		// allocate space to linkedlist_string, assign it upper case of current node string
		char* temp = upper(typenode->type_name);
		linkedlist_string = (char*)malloc(strlen(temp) + 1);
		strcpy(linkedlist_string, temp);
		free(temp);
		
		// Compare the UPPER CASE equivalent of both strings.
		// If they are the same, result = EXISTS
		if (strcmp(param_string, linkedlist_string) == 0)						
			result = YES;		
		typenode = typenode->typenext;
	}
	
	return result;		
}


void set_typedef_flag(void)
{
	/*
		This function SETS the typedef_flag if it is NO.
	*/
	if (typedef_flag == NO)
		typedef_flag = YES;
}


char * change_typedef(char * typedefname)
{
	/*
		If the string 's' passed as parameter begins with a lowercase letter, 
		"lc_" is added to the beginning of the string, otherwise "uc_" is added 
		to the beginning of the string. The new string is then returned.

		This is required as typedef defintion names must be distinguishable from
		one another. In C, TYPE_NAMES are case-sensitive. Therefore, the following
		typedef defintions:
			typedef my_new_type;
			typedef My_new_type;
		both refer to different typedef definitions.
	*/
	
	char* returnstr = (char*)malloc(3 + strlen(typedefname) + 1);
	
	// Precede the return string by "lc_" or "uc_"
	if (islower(typedefname[0]))
		strcpy(returnstr, "lc_");
	else
		strcpy(returnstr, "uc_");
	strcat(returnstr, typedefname);
	
	return returnstr;
}
