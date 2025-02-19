/*
This header file contains the functions used to process the
declarations of variables to their Prolog equivalent for the
Prolog term files. The many different types of declarations,
for integers, floating-point, pointer, enumeration, array and
structure variables and function prototypes and definitions are
handled in this header file. The functions in this header file are
called from the GRAMMAR.Y specification file.
This header file makes extensive use of functions defined in the
following header files:
	STRING_FUNCTIONS.H
	ARRAY_FUNCTIONS.H
	OUTPUT_FUNCTIONS.H
*/

int FirstUseList = NO;

/*
This variable is assigned NO (or zero) to indicate that the linked list ListOfVars
has not been used or is empty. It is set to YES (or 1) when the linked list contains
enteries. This variable is set and reset in the functions:
	void addvariablestolist(char varname[], char vardetails[], char varassign[])
	char * findvariabledetails(char vartype[])
*/


struct ListOfVars
{
	char* variablename;
	char* variabledetails;
	char* assignstring;
	char* varscope;
	int vardeclared;
	struct ListOfVars* varnext;
}varstart, * varnode;

/*
The linked list ListOfVars is used in functions:
	void addvariablestolist(char varname[], char vardetails[], char varassign[])
where details are added to the linked list
and
	char * findvariabledetails(char vartype[])
where details are retrieved from the linked list
*/

void addvariables(char declarator[], int Param);
void addvariablestolist(char varname[], char vardetails[], char varassign[], char varscope[]);
void addvariabledetails(char varname[], char varconstant[]);
char* findvariabledetails(char vartype[]);
char* removestar(char varname[]);
char* change_asterisk(char* str);
char* identifier_function(char identifier[]);
char* process_cast_unary_rule(char unary_op[], char cast_exp[]);
char* process_functions(char S1[], char S2[], char S3[]);
char* process_prototypes(char S1[], char S2[]);
char* process_typedef(char base_type[], char identifier[]);


void addvariables(char* declarator, int Param)
{
	/*
		This function is called from :
			init_declarator
				: declarator			--- call addvariables()
				| declarator '=' initializer
				;
		AND
			parameter_declaration
			: declaration_specifiers declarator 	--- call addvariables()
			| declaration_specifiers abstract_declarator
			| declaration_specifiers
			;

		where a variable is declared like follows:
				char ch;
				int x, *y;
				short myarray[100], studentarray[35];
				int arr[3][2];
		It takes as parameter the variable name i.e. declarator & examines it.
		It takes in Param - this is 0 (if not parameter variable), otherwise is 1

		Function Prototype
		*******************
		If declarator is a function prototype, variable details collected are
		released - no action is taken.

		Pointer
		*******
		If the name contains a "*" then a pointer variable is being declared.
		Before any processing, declarator is stored into C_name.

		The "*" is removed from the variable name by calling function:
			char * removestar(char varname[])
		and the name minus this is stored.

		The case of the variable is determined using
			char * case_name(char  * varname);
		and either "LC_" or "UC_" is added to start of declarator.

		The variable and its Param are pushed onto the Stack
			void PushVar(char variablename[], int Param) -- SCOPES.H

		The scope of the variable is determined using:
			char * scope_details(char * varname, int param);
		and the linenumber scope is appended to declarator if necessary.

		Variabledetails is then given the string "pointer"

		The C and Prolog names are stored using:
			void printnames(char prolog_str[], char c_str[])

		E.g. 	declarator= "*Iptr"
				varname = "UC_Iptr_X" -- where X is the linenumber
				Pushed onto Stack = "UC_Iptr"
				vardetails = "pointer"
				C_name = "*Iptr"

		Array - (functions detailed in pointer)
		*****
		If the name contains a "[" then an array variable is being declared.
		Before any processing, declarator is stored into C_name.
		The case of the variable is determined using
			char * case_name(char  * varname);
		and either "LC_" or "UC_" is added to start of declarator.
		The "[" and "]" are removed from the variable name by calling function:
				char * create_arrayname(char varname[])
		and this is pushed onto Stack along with Param.
		The scope of the variable is determined using:
			char * scope_details(char * varname, int param);
		and the linenumber scope is appended to declarator if necessary.
		The C and Prolog names are stored using:
			void printnames(char prolog_str[], char c_str[])
		Single
		******
		If there is only one pair of [ and ] in the name, then a one dimensional
		array is being declared:
		The dimensions for that array are found by calling on:
				char * create_dimensions(char varname[], char varlist[]);
		Variabledetails is then given the string "array"

		E.g. 	declarator = "MyArray[10]"
				varname = "(UC_MyArray_X, 10)"  -- where X is the linenumber
				Pushed onto Stack = "UC_MyArray"
				vardetails = "array"
				C_name = "MyArray[10]"

		Multi
		******
		Else there are more than one pair of [ and ] in the name, then a multi
		dimensional array is being declared.
		The dimensions for the array are found by calling:
				char * create_multidims(char dimensions[])
		Variabledetails is then given the string "multi"

		E.g. 	declarator = "MyArray[10][5]"
				varname = "(UC_MyArray_X, [10, 5])"  -- where X is the linenumber
				Pushed onto Stack = "UC_MyArray"
				vardetails = "multi"
				C_name = "MyArray[10][5]"

		Simple Variables
		*****************
		The case of the variable is determined using
			char * case_name(char  * varname);
		and either "LC_" or "UC_" is added to start of declarator.

		The variable and its Param are pushed onto the Stack
			void PushVar(char variablename[], int Param) -- SCOPES.H

		The scope of the variable is determined using:
			char * scope_details(char * varname, int param);
		and the linenumber scope is appended to declarator if necessary.

		Variabledetails is then given the string "other"

		The C and Prolog names are stored using:
			void printnames(char prolog_str[], char c_str[])

		E.g. 	declarator= "counter"
				varname = "LC_counter_X" -- where X is the linenumber
				Pushed onto Stack = "LC_counter"
				vardetails = "other"
				C_name = "counter"

		Scope
		*****
		Scope is determined by calling function int ScopeLineNumber(void) (SCOPE.H)
		If number returned == GLOBAL_SCOPE_NUMBER, varscope is 'global' else 'local'

		Finally
		*******
		void addvariablestolist(char varname[], char vardetails[], char varassign[])
		is then called to store the name (declarator), vardetails (pointer, other, etc)
		and the assignmentstring (none given in this function) into the linked list ListOfVars
	*/

	char* vardetails = (char*)malloc(18 + 1); // holds variable details e.g.pointer, array..

	char* varscope = (char*)malloc(6 + 1);	// scope of the variable - local or global

	// allocate space to strings and initialise to NULL

	char* declarator_copy = (char*)malloc(STRING_LIMIT + strlen(declarator) + 1);
	strcpy(declarator_copy, declarator);

	if (strstr(declarator_copy, "function_prototype(") != NULL)
	{
		// FUNCTION_PROTOTYPES
		// a function prototype has been declared  - release the Parameter Linked List
		// and reset the parameter list flag
		strcpy(vardetails, "function_prototype");
		DisposePList(P);
		PListFirstUse = NO;
	}
	else if (strstr(declarator_copy, "*") != NULL)
	{
		// POINTER TYPES
		strcpy(vardetails, "pointer");				// store variable details
		char* declarator_without_star = removestar(declarator_copy); // remove the '*' from declarator
		char* declarator_name = case_name(declarator_without_star);
		PushVar(declarator_name, Param);					// push onto stack (scopes.h)
		char* declarator_with_scope_details = scope_details(declarator_name, Param); // OUTPUT_FUNCTIONS.H
		strcpy(declarator_copy, declarator_with_scope_details); // add prolog scope details

		free(declarator_without_star);
		free(declarator_name);
		free(declarator_with_scope_details);
		
	}
	else if (strstr(declarator_copy, "[") != NULL)
	{
		char* varname;
		// ARRAY TYPES
		int num_dims = strstrcount(declarator_copy, "[");

		strcpy(declarator_copy, case_name(declarator_copy)); 		// add prolog terms to declarator - OUTPUT_FUNCTIONS.H
		PushVar(create_arrayname(declarator_copy), Param);	// push array onto Stack (SCOPES.H) and ARRAY_FUNCTIONS.H
		char* array_name = create_arrayname(declarator_copy); // create the name of array	- ARRAY_FUNCTIONS.H
		char* array_p_name = scope_details(array_name, Param); // add prolog scope details-  OUTPUT_FUNCTIONS.H
		free(array_name);

		// SINGLE DIMENSIONAL ARRAY
		if (num_dims == 1)
		{
			char* dimensions;
			if (strcmp(create_dimensions(declarator_copy, ""), "") != 0) // ARRAY_FUNCTIONS.H
			{
				dimensions = create_dimensions(declarator_copy, ""); // ARRAY_FUNCTIONS.H
			}
			else
			{
				dimensions = (char*)malloc(3 + 1);
				// default value for the array
				strcpy(dimensions, "100");
			}
			varname = (char*)malloc(1 + strlen(array_p_name) + 2 + strlen(dimensions) + 1 + 1);
			strcpy(varname, "(");				// start varname
			strcat(varname, array_p_name);		// add array name in prolog
			strcat(varname, ", ");
			strcat(varname, dimensions);
			strcat(varname, ")");
			strcpy(declarator_copy, varname);	// copy the entire details back to declarator
			strcpy(vardetails, "array");	// store vardetails as 'array'

			free(dimensions);

		}
		else
		{
			// MULTI DIMENSIONAL ARRAY
			char* dimensions = create_multidims(declarator);
			varname = (char*)malloc(1 + strlen(array_p_name) + 2 + strlen(dimensions) + 1 + 1);
			strcpy(varname, "(");
			strcat(varname, array_p_name);		// add array name in prolog
			strcat(varname, ", ");
			strcat(varname, dimensions); // ARRAY_FUNCTIONS.H
			strcat(varname, ")");

			strcpy(declarator_copy, varname);
			strcpy(vardetails, "multi");

			free(dimensions);
		}
		free(array_p_name);
		free(varname);
	}
	else
	{
		// 'NORMAL' VARIABLE DECLARATION
		strcpy(vardetails, "other");	// store the variable details
		char* varname_with_Lc_Uc_prefix = case_name(declarator_copy); 	// change to prolog terms - OUTPUT_FUNCTIONS.H
		PushVar(varname_with_Lc_Uc_prefix, YES);	 // push onto Stack (SCOPES.H)
		char* full_variable_name = scope_details(varname_with_Lc_Uc_prefix, YES); // add scope details - OUTPUT_FUNCTIONS.H
		strcpy(declarator_copy, full_variable_name);

		free(full_variable_name);
		free(varname_with_Lc_Uc_prefix);
	}

	// For all variables store the scope details
	if (ScopeLineNumber() == GLOBAL_SCOPE_NUMBER)
		strcpy(varscope, "global");
	else
		strcpy(varscope, "local");


	char varassign[] = "";

	// For all variables - add the variables just declared to the linked list
	addvariablestolist(declarator_copy, vardetails, varassign, varscope);
	free(declarator_copy);
	free(varscope);
	free(vardetails);
}

void addvariablestolist(char varname[], char vardetails[], char varassign[], char varscope[])
{
	/*
		This function is called from:
			void addvariables(char declarator[])
		where it is passed values for the varname, vardetails & varassign
		e.g. varname =  I_ptr , vardetails = pointer , varassign = ""

		It is also called from:
			void addvariabledetails(char varname[], char varconstant[])
		where it is passed values for the varname, vardetails & varassign.
		In this case varassign will not be blank but will contain a string
		with details of that variables assignment or initialisation
		e.g. varname = (Array, 5) , vardetails = array
			 varassign = "init_array(Array, [0,0,0,0,0])"

		If this is the first use of the linked list (FirstUseList = NO) then varstart.varnext is
		assigned the value NULL to signify an empty list and FirstUseList is reset.

		The varname, vardetails and varassign are added to the linked list ListOfVars
	*/

	if (FirstUseList == NO)
	{
		varstart.varnext = NULL;
		FirstUseList = YES;
	}
	varnode = &varstart;
	while (varnode->varnext)
	{
		varnode = varnode->varnext;
	}
	varnode->varnext = (struct ListOfVars*)malloc(sizeof(struct ListOfVars));
	varnode = varnode->varnext;

	varnode->variablename = (char*)malloc(strlen(varname) + 1);
	varnode->variabledetails = (char*)malloc(strlen(vardetails) + 1);
	varnode->assignstring = (char*)malloc(strlen(varassign) + 1);
	varnode->varscope = (char*)malloc(strlen(varscope) + 1);
	strcpy(varnode->variablename, varname);
	strcpy(varnode->variabledetails, vardetails);
	strcpy(varnode->assignstring, varassign);
	strcpy(varnode->varscope, varscope);
	varnode->vardeclared = NO;
	varnode->varnext = NULL;
}

void addvariabledetails(char varname[], char varconstant[])
{
	/*
		This function is called from :
			init_declarator
				: declarator
				| declarator '=' initializer	--- call  addvariabledetails() here!!!
				;
		where a variable is declared and initialised like follows:
				int x, y = 90;
				short x = 78;, y, z = 45;
				int arry[10];
				struct point maxpoint = {45, 90};

		It takes as parameter the variable name and the value being assigned to it.

		It examines the variable name.

		Pointer
		*******
		If the name contains a "*" then a pointer variable is being declared.

		The "*" is removed from the variable name by calling function:
			char * removestar(char varname[])
		and the name minus this is stored.

		The case of the variable is determined using
			char * case_name(char  * varname);
		and either "LC_" or "UC_" is added to start of varname.

		The variable and its Param (NO) are pushed onto the Stack
			void PushVar(char variablename[], int Param) -- SCOPES.H
		NO - indicates this is not parameter variable.

		The scope of the variable is determined using:
			char * scope_details(char * varname, int param);
		and the linenumber scope is appended to varname if necessary.

		Variabledetails is then given the string "pointer"

		The C and Prolog names are stored using:
			void printnames(char prolog_str[], char c_str[])

		The assignstring is built and stored

		E.g. 	varname = "*Iptr"	varconstant = "34"
				varname = "UC_Iptr_X" -- where X is the linenumber
				Pushed onto Stack = "UC_Iptr"
				vardetails = "pointer"
				assigndetails = "assignment(Iptr, 34).

		Array
		*****
		If the name contains a "[" then an array variable is being declared.
		Arrays can be single dimensional or multi-dimensional.

		The "[" and "]" are removed from the variable name by calling function:
				char * create_arrayname(char varname[])
		and the result is stored in arrayname.

		The case of the variable is determined using
			char * case_name(char  * varname);
		and either "LC_" or "UC_" is added to start of arrayname.

		arrayname is pushed onto Stack along with NO
		- indicates this is not parameter variable.

		The scope of the variable is determined using:
			char * scope_details(char * varname, int param);
		and the linenumber scope is appended to arrayname if necessary.

		The C and Prolog names are stored using:
			void printnames(char prolog_str[], char c_str[])

		Next, start to build finalvarname ...

		Single Dimensions
		*****************
		Arrays can be declared in a number of ways:

			int arry[10];
			int arry[] = {0,0,0,0,0};
			int arry[10] = {3,3,3}; 	//elements [0],[1],[2] set to 3, rest set to 0

		The dimensions for the single dimensional array are found by calling on:
			char * create_dimensions(char varname[], char varlist[]);

		The single_array() function is called which builds the initialisation list for that
		array and returns it so it can be appended to assigndetails

		vardetails is then given the string "array"

		E.G.
			varname = "MyArray[10]"  and varconstant = [3,3,3]
			arrayname = "(UC_MyArray_X, 10)"  -- where X is the linenumber
			Pushed onto Stack = "UC_MyArray"
			vardetails = "array"
			assigndetails = init_array(UC_MyArray_X, [3,3,3,0,0,0,0,0,0,0]),

		Multi Dimensions
		*****************
		Arrays can be declared in a number of ways:

			int arry[4][5];
			int arry[2][4] = {1,2,3,4};	// elements are initialised as follows:
										arry[0][0]=1	arry[0][1]=2	arry[0][2]=3	arry[0][3]=4
										arry[1][0]=0	arry[1][1]=0	arry[1][2]=0	arry[1][3]=0
										i.e. rest in list are initialised to 0

			int arry[4][2][2] = {{2,3},		// elements are initialised as follows:
								{4,5},		arry[0][0][0]=2	arry[0][0][1]=3	arry[0][1][0]=0 arry[0][1][1]=0
								{6,7}};	arry[1][0][0]=4	arry[1][0][1]=5	arry[1][1][0]=0 arry[1][1][1]=0
											arry[2][0][0]=6	arry[2][0][1]=7	arry[2][1][0]=0 arry[2][1][1]=0
											arry[3][0][0]=0	arry[3][0][1]=0	arry[3][1][0]=0 arry[3][1][1]=0
											i.e. rest in list are initialised to 0

		The dimensions for that array are found by calling on:
			char * create_multidims(char varname[]);

		The multi_array() function is called which builds the initialisation list for that
		array and returns it so it can be appended to assigndetails
		e.g.
			int arry[4][2][2] = {{2,3},		// elements are initialised as follows:
								{4,5},		arry[0][0][0]=2	arry[0][0][1]=3	arry[0][1][0]=0 arry[0][1][1]=0
								{6,7}};	arry[1][0][0]=4	arry[1][0][1]=5	arry[1][1][0]=0 arry[1][1][1]=0
											arry[2][0][0]=6	arry[2][0][1]=7	arry[2][1][0]=0 arry[2][1][1]=0
											arry[3][0][0]=0	arry[3][0][1]=0	arry[3][1][0]=0 arry[3][1][1]=0
											i.e. rest in list are initialised to 0
			given as parameter:
				varconstant = "[[2,3],[4,5],[6,7]]"
				dimension = "[4,2,2]"
			it will return the string:
				"2,3,0,0,4,5,0,0,6,7,0,0,0,0,0,0"

		vardetails is then given the string "multi"

		Structure
		*********
		The varconstant is checked to see does it belong to a struct.
		If is does the assignstring is built
		e.g.
			struct point Maxpt = {3,4};
			gives the assignstring
			init_record(Maxpt, [3,4])

		Else
		****
		The variable name does not have to be processed.
		E.g. 	varname = "Counter"	 varconstant = "20"
				var = "Counter" vardetails = "other"
				assigndetails = "assignment(Counter, 20).
		Scope
		*****
		Scope is determined by calling function int ScopeLineNumber(void) (SCOPE.H)
		If number returned == GLOBAL_SCOPE_NUMBER, varscope is 'global' else 'local'

		Finally
		*******
		void addvariablestolist(char varname[], char vardetails[], char varassign[])
		is then called to store the name (declarator), vardetails (pointer, other, etc)
		and the assignmentstring (none given in this function) into the linked list ListOfVars
	*/

	char assigndetails[STRING_LIMIT]; 	// holds assignment string
	char arrayname[STRING_LIMIT];		// holds arrayname if varname is an array
	char finalvarname[STRING_LIMIT];	// holds array details if varname is an array
	char vardetails[STRING_LIMIT];		// holds variable details e.g.pointer, array..
	char dimension[STRING_LIMIT];		// holds dimension if varname is an array
	char varscope[STRING_LIMIT];		// scope that varname belongs to

	char* variable_name = (char*)malloc(STRING_LIMIT);
	strcpy(variable_name, varname);	// Prevents modification to parameter

	strcpy(assigndetails, initialisestring(assigndetails, STRING_LIMIT));
	strcpy(arrayname, initialisestring(arrayname, STRING_LIMIT));
	strcpy(finalvarname, initialisestring(finalvarname, STRING_LIMIT));
	strcpy(vardetails, initialisestring(vardetails, STRING_LIMIT));
	strcpy(dimension, initialisestring(dimension, STRING_LIMIT));

	// POINTER TYPES
	if (strstr(variable_name, "*") != NULL)
	{
		strcpy(variable_name, removestar(variable_name));	// remove the '*' from varname
		strcpy(variable_name, case_name(variable_name));	// add prolog terms "LC_" or "UC_" - OUTPUT_FUNCTIONS.H
		PushVar(variable_name, NO);	// Push onto Stack, not a parameter variable (NO)
		// from SCOPES.H
		strcpy(variable_name, scope_details(variable_name, NO));// append scope number if applicable - OUTPUT_FUNCTIONS.H
		strcpy(vardetails, "pointer");			// store details
		strcpy(assigndetails, "\nassignment(");	// build assignment string
		strcat(assigndetails, variable_name);
		strcat(assigndetails, " , ");
		strcat(assigndetails, varconstant);
		strcat(assigndetails, "),");
	}
	else if (strstr(variable_name, "[") != NULL)
	{
		// ARRAY TYPES
		int numdims; // number of '[' in varname -single Vs multi array

		strcpy(arrayname, create_arrayname(variable_name));// isolate array name from dimensions - ARRAY_FUNCTIONS.H
		// store in arrayname
		strcpy(arrayname, case_name(arrayname));	// find prolog version "LC_" or "UC_" - OUTPUT_FUNCTIONS.H
		PushVar(arrayname, NO);						// Push onto Stack, not a parameter variable (NO)
		// from SCOPES.H
		strcpy(arrayname, scope_details(arrayname, NO)); // append scope if applicable - OUTPUT_FUNCTIONS.H
		strcpy(finalvarname, "(");					// build final array name - "("
		strcat(finalvarname, arrayname);			// array name
		strcat(finalvarname, ", ");					// comma -- dimensions follow

		numdims = strstrcount(variable_name, "[");		// find number of '[' to determine
		// if array is single or multi dimensional

		// SINGLE DIMENSIONAL ARRAY
		if (numdims == 1)
		{
			// find dimensions and finish finalvarname
			char* dimension_string = create_dimensions(variable_name, varconstant);
			strcpy(dimension, dimension_string); // ARRAY_FUNCTIONS.H
			free(dimension_string);

			strcat(finalvarname, dimension);
			strcat(finalvarname, ")");
			strcpy(variable_name, finalvarname);

			// build assigndetails as init_array/2
			strcpy(assigndetails, "\ninit_array(");
			strcat(assigndetails, arrayname);
			strcat(assigndetails, " , ");
			char* single_array_assignment = single_array(varconstant, dimension); // ARRAY_FUNCTIONS.H
			strcat(assigndetails, single_array_assignment); 
			strcat(assigndetails, "),");
			free(single_array_assignment);

			// store vardetails
			strcpy(vardetails, "array");
		}
		else
		{
			// MULTI DIMENSIONAL ARRAY
			// find dimensions and finish finalvarname
			strcpy(dimension, create_multidims(variable_name));	// ARRAY_FUNCTIONS.H
			strcat(finalvarname, dimension);
			strcat(finalvarname, ")");
			// copy back into varname
			strcpy(variable_name, finalvarname);

			// build assigndetails as init_array/2
			strcpy(assigndetails, "\ninit_array(");
			strcat(assigndetails, arrayname);
			strcat(assigndetails, ", [");
			char* multi_dimension_array_assignment = multi_array(varconstant, dimension); // ARRAY_FUNCTIONS.H
			strcat(assigndetails, multi_dimension_array_assignment);
			strcat(assigndetails, "]),");

			free(multi_dimension_array_assignment);

			// store vardetails
			strcpy(vardetails, "multi");
		}
	}
	else
	{
		// OTHER VARIABLE DECLARATIONS


		// STRUCT DECLARATION
		if (strstrcount(varconstant, ",") >= 1)
		{
			strcpy(variable_name, case_name(variable_name));	// apply prolog case rules "LC_" or "UC_" - OUTPUT_FUNCTIONS.H
			PushVar(variable_name, NO);					// Push onto Stack, not a parameter variable (NO)
			// from SCOPES.H
			strcpy(variable_name, scope_details(variable_name, NO));// append scope if applicable - OUTPUT_FUNCTIONS.H
			strcpy(vardetails, "struct");				// store vardetails

			strcpy(assigndetails, "\ninit_record(");	// begin assigndetails init_record/2
			strcat(assigndetails, variable_name);
			strcat(assigndetails, " , ");
			strcat(assigndetails, varconstant);
			strcat(assigndetails, "),");
		}
		else
		{
			// 'NORMAL' VARIABLE DECLARATION
			strcpy(variable_name, case_name(variable_name));// apply prolog case rules "LC_" or "UC_" - OUTPUT_FUNCTIONS.H
			PushVar(variable_name, NO);				// Push onto Stack, not a parameter variable (NO)
			// from SCOPES.H
			strcpy(variable_name, scope_details(variable_name, NO));// append scope if applicable - OUTPUT_FUNCTIONS.H
			strcpy(vardetails, "other");				// store vardetails

			strcpy(assigndetails, "\nassignment(");		// build assigndetails
			strcat(assigndetails, variable_name);
			strcat(assigndetails, " , ");
			strcat(assigndetails, varconstant);
			strcat(assigndetails, "),");
		}
	}

	// For all variables store the scope details
	if (ScopeLineNumber() == GLOBAL_SCOPE_NUMBER)
		strcpy(varscope, "global");
	else
		strcpy(varscope, "local");

	// For all variables - add the variables just declared to the linked list
	addvariablestolist(variable_name, vardetails, assigndetails, varscope);
	free(variable_name);
}


char* findvariabledetails(char vartype[])
{
	/*
	This function is called from:
		declaration
			: declaration_specifiers ';'
			| declaration_specifiers init_declarator_list ';' --- findvariabledetails() called from here!
			;
	"declaration_specifiers init_declarator_list" is where variables are declared like follows:
		int w, x = 89, y = 56, z;
		struct point {
				int x;
				int y;
		}maxpt;
		etc

	When FirstUse == YES this indicates that there are details of variables in the linked list ListOfVars.


	The declaration of the variable is appended to the output string, and following that the assignment
	of that variable to its constant.
	If the variable is a pointer, the string "pointer" is appended to vartype before output.
	If the variable is of type array, the string "array_" is appended to the declaration string
	before output.

	E.g.vartype = "int"
		variablename = "intptr"
		variabledetails = "pointer"
		assignstring = "assignment(intptr, 56)"

		will be returned as:

		declaration(intpointer, intptr),
		assignment(intptr, 56)

	If the variable is of type function_prototype, the return type of the function is appended
	to the function prototype string and returned.
	*/

	char* declstring[STRING_LIMIT];
	int lenstring;
	int lenvarname;
	char tempstring[STRING_LIMIT];
	int i;

	strcpy(declstring, initialisestring(declstring, STRING_LIMIT));
	strcpy(tempstring, initialisestring(tempstring, STRING_LIMIT));
	lenstring = strlen(vartype) - 1;

	// Begin searching the linked list, starting at the beginning.
	varnode = varstart.varnext;
	while (varnode)
	{
		if (varnode->vardeclared == NO)
		{
			// CHECK POINTER TYPES
			if (strstr(varnode->variabledetails, "pointer") != NULL)
			{
				if (strstr(vartype, "struct") != NULL)
				{
					// STRUCTURE DECLARATION
					strcat(declstring, "\ndeclaration(");
					strcat(declstring, "structpointer , [");
					strcat(declstring, varnode->variablename);
					strcat(declstring, "]),");
					strcat(declstring, varnode->assignstring);
				}
				else
				{
					// POINTER DECLARATION
					strcat(declstring, "\ndeclaration(");
					strcat(declstring, vartype);
					if (traverse_types(vartype) == 1)	// TYPEDEF_FUNCTIONS.H
						strcat(declstring, ", pointer , [");
					else
						strcat(declstring, "pointer , [");
					strcat(declstring, varnode->variablename);
					strcat(declstring, "]),");
					strcat(declstring, varnode->assignstring);
				}
			}
			// CHECK ARRAY TYPES
			else if (strstr(varnode->variabledetails, "multi") != NULL)
			{
				// MULTI-DIMENSIONAL ARRAY DECLARATION
				strcat(declstring, "\narray_multideclaration(");
				strcat(declstring, vartype);
				strcat(declstring, " , ");
				strcat(declstring, varnode->variablename);
				strcat(declstring, "),");
				strcat(declstring, varnode->assignstring);
			}
			else if (strstr(varnode->variabledetails, "array") != NULL)
			{
				// SINGLE-DIMENSIONAL ARRAY DECLARATION
				strcat(declstring, "\narray_declaration(");
				strcat(declstring, vartype);
				strcat(declstring, " , ");
				strcat(declstring, varnode->variablename);
				strcat(declstring, "),");
				strcat(declstring, varnode->assignstring);
			}
			else
			{
				// CHECK OTHER TYPES
				if (strcmp(varnode->variabledetails, "function_prototype") == 0)
				{
					// FUNCTION PROTOTYPE DECLARATION
					// Function prototypes are changed from "int f1(int x);" to
					// "function_prototype(f1, [int X], int)"
					i = 0;
					lenvarname = strlen(varnode->variablename) - 4;
					while (i < lenvarname)
					{
						tempstring[i] = varnode->variablename[i];
						i++;
					}
					strcat(declstring, tempstring);
					strcat(declstring, ", ");
					strcat(declstring, vartype);
					strcat(declstring, ").\n");

				}
				else if (strstr(vartype, "struct ") != NULL)
				{
					// STRUCTURE DECLARATION (WITH OR WITHOUT FIELDS)
					if (vartype[lenstring] == ']')
					{
						strcat(declstring, "\nrecord_declaration(");
						strcat(declstring, vartype);
						strcat(declstring, ", [");
						strcat(declstring, varnode->variablename);
					}
					else
					{
						strcat(declstring, "\nrecord_declaration_nofields(");
						strcat(declstring, vartype);
						strcat(declstring, ", [");
						strcat(declstring, varnode->variablename);
					}
					strcat(declstring, "]),");
					strcat(declstring, varnode->assignstring);
				}
				else if (strstr(vartype, "enum ") != NULL)
				{
					// ENUM DECLARATION (WITH OR WITHOUT FIELDS)
					if (vartype[lenstring] == ']')
						strcat(declstring, "\nenum_declaration(");
					else
						strcat(declstring, "\nenum_declaration_nofields(");
					strcat(declstring, vartype);
					strcat(declstring, ", [");
					strcat(declstring, varnode->variablename);
					strcat(declstring, "]),");
					strcat(declstring, varnode->assignstring);
				}
				else
				{
					// NORMAL VARIABLE DECLARATION
					strcat(declstring, "\ndeclaration(");
					strcat(declstring, vartype);
					strcat(declstring, ", [");
					strcat(declstring, varnode->variablename);
					strcat(declstring, "],[");
					strip_last_comma(varnode->assignstring);
					strcat(declstring, varnode->assignstring);
					strcat(declstring, "]),");
				}
			}
		}
		varnode->vardeclared = YES;
		varnode = varnode->varnext;
	}

	char* retstring = (char*)malloc(strlen(declstring) + 1);
	strcpy(retstring, declstring);
	return retstring;
}

char* removestar(char varname[])
{
	/*
		This function, used in this Header File, will take in a variable
		of the form "*Varname" and will return the Varname minus the *.
		E.G. 	input value: *Iptr
				return value: Iptr

		This function is called from:
			void addvariables(char declarator[])
			void addvariabledetails(char varname[], char varconstant[])
	*/

	char* holdstr = (char*)malloc(strlen(varname) + 1);	// temporary holding string
	unsigned int i = 0, j = 0;			// variables for while loops

	// allocate space to the string variables used
	strcpy(holdstr, initialisestring(holdstr, strlen(varname) + 1));

	// Copy the characters of 'varname' to 'holdstr' provided they
	// are not the character '*'.
	while (i <= strlen(varname))
	{
		if (varname[i] != '*')
		{
			holdstr[j] = varname[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}

	char* returnstr = (char*)malloc(strlen(holdstr) + 1);
	strcpy(returnstr, holdstr);
	free(holdstr);
	return returnstr;
}

char* change_asterisk(char* str)
{
	/*
		This function is called from the following places in GRAMMAR.Y
			unary_expression
				: postfix_expression
				| INC_OP unary_expression
				| DEC_OP unary_expression
				| unary_operator cast_expression
				| SIZEOF unary_expression
				| SIZEOF '(' type_name ')'	-- call change_asterisk($3)
			;
		and
			cast_expression
				: unary_expression
				| '(' type_name ')' cast_expression	-- call change_asterisk($2)
				;
		This function takes in a pointer type and changes it to its Prolog
		equivalent.
		For example:
		if 'str' is "int *", this function will return "intpointer"
	*/

	char* retstr = (char*)malloc(STRING_LIMIT);			// return string of the function
	int asterisk_count = 0;			// number of '*' in 'str'
	unsigned int i = 0;				// while loop control variable

	// Build the return string.
	strcpy(retstr, "");
	while (i < strlen(str))
	{
		if (str[i] != '*')
		{
			char* substring = copystring(str, i, 0);
			strcat(retstr, substring);
			free(substring);
		}
		else
			strcat(retstr, "pointer");
		i++;
	}

	// successfully leaving the function
	return retstr;
}

char* identifier_function(char identifier[])
{
	/*
		This function is called from the following place in GRAMMAR.Y:
		primary_expression
			: IDENTIFIER			-- call identifier_function($1);
			| CONSTANT
			| STRING_LITERAL
			| '(' expression ')'
			;

		It checks the 'identifier' to determine if it an enumeration variable
		or an normal variable and returns the Prolog format to the pseudo-variable
		$$.
	*/

	char* returnstr = (char*)malloc(STRING_LIMIT);	// return string of the function
	char* istr = (char*)malloc(STRING_LIMIT);		// temporary holding string
	int i;					// hold result of enumeration test
	int parameterscope;		// parameter scope of 'identifier'
	int linenumber;			// stack scope of 'identifier'


	// determine if 'identifier' is an enumeration variable.
	// If so, i != -1, return this variable as returns string of function
	i = traverse_enums(identifier);		// ENUM_FUNCTIONS.H
	if (i != -1)
	{
		itoa(i, istr, RADIX);
		strcpy(returnstr, istr);
	}
	// Not an enumeration variable - process as normal variable name
	else
	{
		strcpy(returnstr, case_name(identifier));	// OUTPUT_FUNCTIONS.H
		parameterscope = ParameterSearch(returnstr);// SCOPES.H
		linenumber = ScopeSearch(returnstr);		// SCOPES.H
		if (parameterscope == NO)
		{
			strcat(returnstr, "_");
			itoa(linenumber, istr, RADIX);
			strcat(returnstr, istr);
		}
	}
	free(istr);
	return returnstr;
}

char* process_cast_unary_rule(char unary_op[], char cast_exp[])
{
	/*
	This function is called from the following place in GRAMMAR.Y:
		unary_expression
			: postfix_expression
			| INC_OP unary_expression
			| DEC_OP unary_expression
			| unary_operator cast_expression -- strcpy($$, process_cast_unary_rule($1, $2));
			| SIZEOF unary_expression
			| SIZEOF '(' type_name ')'
		;

	It is called to process a statement such as the following:
		unary_op = "dereference"
		cast_exp = "(Arry + I)"
	If cast_exp is a single variable, this is ok, no processing necessary.
	Otherwise, cast_exp is broken down and the following return string
	is produced:
		dereference(Array + I)
	*/

	unsigned int i = 0;					 // while loop control variable
	unsigned int istr = 0;				 // while loop control variable
	char* returnstr = (char*)malloc(strlen(unary_op) + 1 + strlen(cast_exp) + 1 + 1); // return string of function

	// Begin build return string
	strcpy(returnstr, unary_op);

	//	No brackets around negative numbers
	if (strcmp(unary_op, "-") == 0)
	{
		strcat(returnstr, cast_exp);
	}
	else if (strcmp(unary_op, "dereference") == 0)
	{
			// Surround cast_exp with brackets
			strcat(returnstr, "(");
			strcat(returnstr, cast_exp);
			strcat(returnstr, ")");
	}
	else
	{
		// Surround cast_exp with brackets
		strcat(returnstr, "(");
		strcat(returnstr, cast_exp);
		strcat(returnstr, ")");
	}

	return returnstr;
}
char* process_functions(char S1[], char S2[], char S3[])
{
	/*
	This function is called from the following rule in GRAMMAR.Y:
		function_definition
			: declaration_specifiers declarator declaration_list compound_statement
			| declaration_specifiers declarator compound_statement
						--  call strcpy($$, process_functions($1, $2, $3));
			| declarator declaration_list compound_statement
			| declarator compound_statement
			;

	This rule is parsed when a function is defined i.e. function defintion.
	The different parts are
		$1 = return type of the function
		$2 = name and parameters of the function
			If there are parameters provided this will be parsed as
				function_prototype(function name, [Parameter List],
			If there are not any parameters this will be parsed as
				Functionname()
			These are accounted for in if and else.
		$3 = statements of the function
	$2, the name of the parameters for the function is surrounded by the
	string "function_prototype(" (19 characters) and ends with ")." (2 characters)
	and this will need to be removed.
	*/

	// variable declarations
	const int len_start_prototypestr = 19;	// string "function_prototype(" is 19 chars
	const int len_end_prototypestr = 3;		// string ")." is 2 chars + one for NULL char
	char* S2_substring = NULL;
	
	if (strstr(S2, "*function_prototype(") != NULL)
	{
		// calculating how many characters we need to copy onto $$
		int howmany = (strlen(S2) - len_end_prototypestr) - (len_start_prototypestr + 1);
		S2_substring = copystring(S2, (len_start_prototypestr + 1), howmany);
	}
	else if (strstr(S2, "function_prototype(") != NULL)
	{
		// calculating how many characters we need to copy onto $$
		int howmany = (strlen(S2) - len_end_prototypestr) - len_start_prototypestr;
		S2_substring = copystring(S2, len_start_prototypestr, howmany);	
	}


	char* returnstr;
	if (S2_substring != NULL) {
		returnstr = (char*)malloc(20 + 3 + strlen(S2_substring) + strlen(S3) + 2 + strlen(S1) + 2 + 1);
		strcpy(returnstr, "function_definition(");

		if (isupper(S2_substring[0]))
			strcat(returnstr, "UC_");
		else
			strcat(returnstr, "LC_");
		strcat(returnstr, S2_substring);

		free(S2_substring);
	}
	else {

		int howmany = strlen(S2) - 3;
		// remove the final () and the NULL character
		S2_substring = copystring(S2, 0, howmany);

		returnstr = (char*)malloc(20 + 3 + strlen(S2_substring) + 11 + strlen(S3) + 2 + strlen(S1) + 2 + 1);
		strcpy(returnstr, "function_definition(");
		if (isupper(S2[0]))
			strcat(returnstr, "UC_");
		else
			strcat(returnstr, "LC_");

		S2[0] = convert_tolower(S2[0]);
		// the function name is parsed as upper case so change to lowercase
		strcat(returnstr, S2_substring);
		strcat(returnstr, ", [void], ");
		free(S2_substring);
	}

	
	// append statements of the function
	strcat(returnstr, S3);
	strcat(returnstr, ", ");

	// append return type of the function
	strcat(returnstr, S1);
	strcat(returnstr, "),");

	// successfully leaving the function
	return returnstr;
}

char* process_prototypes(char S1[], char S2[])
{
	/*
	This function is called from the following rule in GRAMMAR.Y:
		function_definition
			: declaration_specifiers declarator declaration_list compound_statement
			| declaration_specifiers declarator compound_statement
			| declarator declaration_list compound_statement
			| declarator compound_statement
									--  call strcpy($$, process_prototypes($1, $2));
			;
	If the function has already been defined with return types, parameters, statements
	i.e. all required features -- then it will not go through this grammar rule
	This function then formats the parameters in a format suitable for function
	definitions and prototypes.
	*/

	char* returnstr = (char*)malloc(STRING_LIMIT);			// return string of the function

	// If S1 contains a 'function_prototype', the function has the
	// return type of void.
	// Change "function_prototype" to "function_definition"
	// Remove the extra ').' at the end of S1
	// Add S2.
	if (strstr(S1, "function_prototype(") != NULL)
	{
		// variable declarations and space allocation
		char* newS1 = (char*)malloc(STRING_LIMIT);
		int lenBracket;

		// Build new return string
		char* bracket_str = strstr(S1, "(");
		lenBracket = strlen(bracket_str) - 3;
		strcpy(newS1, "function_definition");
		strncat(newS1, bracket_str, lenBracket);
		strcat(newS1, "\0");
		strcpy(returnstr, newS1);
		strcpy(returnstr, " ");
		strcpy(returnstr, S2);
		strcat(returnstr, ", ");
		strcat(returnstr, "void).\n");

		free(newS1);
	}
	// Otherwise, S1 is a function name followed by ().
	// Convert the name of the function to lower case.
	// Enclose function statements (S2) in [ and ].
	else
	{
		if (isupper(S1[0]))
			S1[0] = convert_tolower(S1[0]);
		strcpy(returnstr, "function_definition(");

		char* function_name = (char*)malloc(STRING_LIMIT);
		strncat(function_name, S1, strlen(S1) - 2);
		strcat(function_name, "\0");
		if (isupper(function_name[0]))
			strcat(returnstr, "UC_");
		else
			strcat(returnstr, "LC_");

		strcat(returnstr, function_name);
		strcat(returnstr, ", [void], ");
		strcat(returnstr, S2);
		strcat(returnstr, ", void).");

		free(function_name);
	}

	return returnstr;
}

char* process_typedef(char base_type[], char* identifier) {
	char* base_name = (char*)malloc(strlen(base_type) + 7 + 1);
	strcpy(base_name, base_type);
	if (strstr(identifier, "*") != NULL) {
		strcat(base_name, "pointer");
		identifier++;
	}

	char* identifier_processed = change_typedef(identifier);
	char* return_str = (char*)malloc(22 + strlen(base_name) + 2 + strlen(identifier_processed) + 2 + 1);

	strcpy(return_str, "\ntypedef_declaration(");
	strcat(return_str, base_name);
	strcat(return_str, ", ");
	strcat(return_str, identifier_processed);
	strcat(return_str, "),");

	free(identifier_processed);
	free(base_name);

	return return_str;
}