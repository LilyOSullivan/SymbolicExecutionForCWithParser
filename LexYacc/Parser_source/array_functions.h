/*
This header file contains the function required to process arrays
matched in the grammar rules and output them in a format suitable 
for the Prolog predicates in the Prolog terms file.

The functions in this header file are called from
	GRAMMAR.Y
	DECL_FUNCTIONS.H
	and within this Header File itself ARRAY_FUNCTIONS.H
*/

char* process_arrays(char postfix_expression[], char expression[]);
char* create_arrayname(char varname[]);
char* create_dimensions(char varname[], char varlist[]);
char* create_multidims(char dimensions[]);
char* single_array(char* varlist, char* dimensions);
int subtotal_dims(char* dimlist);
int total_dims(char* dimlist);
char* initarray(char* initstr, int rows);
char* multi_array(char varlist[], char dimensions[]);

char* process_arrays(char postfix_expression[], char expression[])
{
	/*
		This function is called from the following grammar rule in GRAMMAR.Y

		postfix_expression
			: primary_expression	
			| postfix_expression '[' expression ']' -- call process_arrays() if '[' in $1
			| postfix_expression '(' ')'	
			| postfix_expression '(' argument_expression_list ')'  
			| postfix_expression '.' IDENTIFIER		
			| postfix_expression PTR_OP IDENTIFIER	
			| postfix_expression INC_OP 
			| postfix_expression DEC_OP	
			;

		This function parsing arrays that are matched by the above grammar rule.
		If there are more than one '[' in the 'postfix_expression' parameter, a
		multi-dimensional array with more than two dimensions is parsed. The array 
		name is copied from 'postfix_expression' upto its first '[' and from the 
		last ']' to the end of the variable and is returned by the function.
		If this is a two dimensional array, the array name and dimensions are
		isolated and added to the final string returned.

		Example:

			C code:					i = b[j][2];
			'postfix_expression'	"b[j]"
			'expression'			"2"	
			Return String:			"b[[j, 2]]"
	*/

	char* arrayname;   // holds the array name
	char* dimension;   // holds the array dimensions
	char* finalstring; // temporary holding string
	char* closebracketstr; // string beginning at last ']'
	char* firstbracketstr; // string beginning at first '['
	char* returnstr;       // return string of the function
	int difference;        // difference in string sizes
	int openbrackets;      // number of opening brackets
	int closebrackets;     // number of closing brackets
	int i;                 // for loop control variable

	closebracketstr = (char*)malloc(strlen(postfix_expression) + 1);
	firstbracketstr = (char*)malloc(strlen(postfix_expression) + 1);
	finalstring = (char*)malloc(strlen(postfix_expression) * 2 + strlen(expression) + 1);

	// MULTI (> 2) DIMENSIONAL ARRAY
	if (strstrcount(postfix_expression, "[") > 1) 
	{	
		// Find the string beginning at the first opening bracket
		strcpy(firstbracketstr, strstr(postfix_expression, "["));
		difference = strlen(postfix_expression) - strlen(firstbracketstr) - 1;
		// Copy from beginning of postfix_expression to this point
		char* substring = copystring(postfix_expression, 0, difference);
		strcat(finalstring, substring);
		free(substring);
		strcat(finalstring, "[");
		// Find the string beginning at the LAST closing bracket	
		strcpy(closebracketstr, last_strstr(firstbracketstr, "]")); 
		difference = strlen(firstbracketstr) - strlen(closebracketstr) - 1;
		// Copy from beginning of firstbracketstr to this point		
		substring = copystring(firstbracketstr, 0, difference);
		strcat(finalstring, substring);
		free(substring);
	}
	else 
	{
		// TWO DIMENSIONAL ARRAY	
		// Isolate the array name	
		char* arrayname = create_arrayname(postfix_expression);
		// Isolate the array dimensions			
		char* dimension = create_dimensions(postfix_expression, "");
		// Build final string		
		strcpy(finalstring, arrayname);
		strcat(finalstring, "[[");
		strcat(finalstring, dimension);
		free(arrayname);
		free(dimension);
	}

	strcat(finalstring, ", ");
	strcat(finalstring, expression);
	openbrackets = strstrcount(finalstring, "[");
	closebrackets = strstrcount(finalstring, "]");
	difference = openbrackets - closebrackets;
	for (i = 0; i < difference; i++)
		strcat(finalstring, "]");

	returnstr = (char*)malloc(strlen(finalstring) + 1);
	strcpy(returnstr, finalstring);	
	free(closebracketstr);
	free(firstbracketstr);
	free(finalstring);
	return returnstr;
}

char * create_arrayname(char varname[])
{
	/*
		This function is called from the following functions in DECL_FUNCTIONS.H:
			void addvariables(char declarator[], int Param)
			void addvariabledetails(char varname[], char varconstant[])
		and the following function in this Header File:
			char * process_arrays(char postfix_expression[], char expression[])

		This function will take in a variable of the form "Array[10]" and will return a string
		that contains just the array name "Array"

		E.G. 	input value: 	Array[10]
				return value:	Array
	*/
	
	char* arrayname = (char*)malloc(strlen(varname) + 1);
	unsigned int index = 0, newindex = 0;

	// copy the name of the array as far as the '['
	while (varname[index] != '[')
	{
		arrayname[newindex] = varname[index];
		index++;
		newindex++;
	}
	arrayname[newindex] = '\0';

	return arrayname;
}

char* create_dimensions(char varname[], char varlist[])
{
	/*
		This function is called from the following functions in DECL_FUNCTIONS.H:
			void addvariables(char declarator[])
			void addvariabledetails(char varname[], char varconstant[])
		and the following function in this Header File:
			char * process_arrays(char postfix_expression[], char expression[])

		This function will take in a variable of the form "Array[10]" and will return a string
		that contains just the array dimensions "10"

		e.g. 	input value: 	Array[10]
				return value:	10

		If no dimensions have been declared with the array name
		e.g. Array[];
		the dimensions are found by examining the second parameter to this function
		varlist. 'varlist' is a string of the form [0,0,0].
		Therefore the dimensions are the number of elements found in varlist.
		The number of elements is the number of commas + 1.
		This sum is found, converted to a string and returned by this function.
		This occurs when an array is declared as follows:
			int array[] = {0,0,0,0,0};
	*/

	char dimensions[STRING_LIMIT];	// temporary holding string	
	unsigned int index = 0, newindex = 0;	// while loop control variables	
	int num_elements;						// number elements in varlist	

	// allocate space to the string variables used
	
   	strcpy(dimensions, initialisestring(dimensions, STRING_LIMIT));

	// Go as far as the first '[' and by-pass by one character
	while (varname[index] != '[')
		index++;
	index++;
	
	// Copy from the character past the '[' to the ']'	
	while(varname[index] != ']')
	{
		dimensions[newindex] = varname[index];
		index++;
		newindex++;
	}

	// If the dimensions are not provided as parameter, create the
	// dimensions using the varlist parameter - pad with zeros
	if ( (strcmp(dimensions, "") == 0) && (strcmp(varlist, "") != 0) )
	{	
		num_elements = strstrcount(varlist, ",");
		num_elements++;		
		itoa(num_elements, dimensions, RADIX);	// change to string
	}

	char* returnstr = (char*)malloc(strlen(dimensions) + 1);
	strcpy(returnstr, dimensions);
	return returnstr;		
}

char * create_multidims(char dimensions[])
{
	/*
		This function is called from the following two functions in DECL_FUNCTIONS.H
			void addvariables(char declarator[], int Param)
			void addvariabledetails(char varname[], char varconstant[])

		This function will take in a variable of the form "Array[5][3]" and will return a
		string that contains the array dimensions as "[5,3]"

		EXAMPLE: 	input value: 	Array[5][3]
					return value:	[5,3]
	*/
	
	char finaldims[STRING_LIMIT];	// temporary holding string	
	char singledim[STRING_LIMIT];	// temporary holding string		
	unsigned int numberdims;			// number iterations of for loop			
	unsigned int openb, closeb;			// position opening & closing brackets in dimensions
	unsigned int i;						// control variable for the for loop 		

	// allocate space to the string variables used

	strcpy(finaldims, initialisestring(finaldims, STRING_LIMIT));

	// Find the number of dimension sets in 'dimensions'.
	// This becomes the number of iteration of the for loop.
	numberdims = strstrcount(dimensions, "[");

	// Start building 'finalstr'
	strcpy(finaldims, "[");					

	// Iterate the for loop numberdims times
	for (i = 1; i <= numberdims; i++)
	{
		// Initialise variables used in each for loop iteration
		// 'singledim' holds a single dimension
		// set the positions of opening & closing brackets to 0 for each loop iteration
		strcpy(singledim, initialisestring(singledim, STRING_LIMIT));	
		openb = 0;	
		closeb = 0;

		// go to the first opening bracket and bypass by one
		while(dimensions[openb] != '[')
			openb++;
		openb++; 	
		// go to the first closing bracket
		while (dimensions[closeb] != ']')
			closeb++;

		// copy into singledim from position of just past the first [ to the first ]
		char* array_indexing_expression = copystring(dimensions, openb, ((closeb - openb) - 1));
		strcpy(singledim, array_indexing_expression);
		free(array_indexing_expression);
		// add the isolated dimension to the finaldims string
		strcat(finaldims, singledim);

		// If this is NOT the final for loop iteration then....
		// re-set the variables involved in the next iteration
		if (i != numberdims)
		{	
			strcat(finaldims, ",");	
			// Create a new dimensions string for the next iteration of the for loop.
			// This new string will be less the first '[dimension]' format in dimension
			strcpy(singledim, initialisestring(singledim, STRING_LIMIT));
			closeb = closeb + 1;
			char* substring = copystring(dimensions, closeb, strlen(dimensions));
			strcpy(singledim, substring);
			free(substring);
			strcpy(dimensions, initialisestring(dimensions, STRING_LIMIT));
			strcpy(dimensions, singledim);
		}
	}

	strcat(finaldims, "]"); 

	char* returnstr = (char*)malloc(strlen(finaldims) + 1);
	strcpy(returnstr, finaldims);		
	return returnstr;		
}

char * single_array(char * varlist, char * dimensions)
{
	/*
		This function is called from:
			void addvariabledetails(char varname[], char varconstant[]) in DECL_FUNCTIONS.H
		when an array of single dimensions has been declared and initialised in the one statement.
		When this occurs the correct initialisation list must be passed back in the
		Prolog Terms file.
		This function builds this initialisation list.

		Taking as parameter a varlist (initialisation list) and the dimensions of the array as a
		string, these dimensions are first changed to their numeric value.
		Next, the number of elements given in varlist are counted.
		If there is no difference between these values, varlist will be returned with no change.
		However, if there is a difference  then that amount of 0's needs to be added to our
		return string.
		This is because if there are fewer initialiszers than members in the array, the
		trailing members are initialized to 0.
		Reference:	"The C Programming Language"
					Brian W. Kernighan, Dennis M. Ritchie
					Prentice Hall Software Series, Second Edition
					ISBN:	0-13-110362-8
					page 219
		Example:
			varlist = "[5,5,5]"		dimensions = "3"
			returnstr = "[5,5,5]"

			varlist = "[5,5,5]"		dimensions = "10"
			returnstr = "[5,5,5,0,0,0,0,0,0,0]"
	*/

	int dim_number;				// numerical equivalent of parameter dimensions
	int num_elems;				// number of elements in parameter varlist
	char* returnstr;			// return string of the function

	returnstr = (char*)malloc(STRING_LIMIT);

	dim_number = atoi(dimensions);		// get numeric equivalent of dimensions
	// find the number of elements in varlist
	num_elems = strstrcount(varlist, ",");

	// if the correct number of dimensions are present, copy varlist & return
	if (num_elems == dim_number)
		strcpy(returnstr, varlist);
	else
	{
		// calculate the difference and pad with 0s
		int diff = dim_number - num_elems;
		int i;
		strcpy(returnstr, "[");
		strcat(returnstr, varlist);
		for(i = 1; i < diff; i++)
			strcat(returnstr, ",0");
		strcat(returnstr, "]");
	}
	return returnstr;
}

int subtotal_dims(char * dimlist)
{
	/*
		This function is called from:
			char * multi_array(char varlist[], char dimensions[])
		when an array of multi dimensions has been declared and initialised in the one statement.
		When this occurs the correct initialisation list must be passed back in
		the Prolog Terms file.

		This function is called with parameter dimensionlist which is a string of the dimensions of
		an array that has multiple dimensions.
		For Example: 	"[4,2,3]" is the dimensionlist for an array declared as A[4][2][3]
		The function will return the product of all these dimensions bar the first one!!!
		For Example: 2*3 = 6 in this example
	*/

 	int total = 1;			// total of dimensions
	char * dimstr;			// modified dimlist string (less [ and ], and comma added)
	char * singledim;		// a single dimension from dimstr
	int index = 0;			// control variable of while loop
	int prev;				// holds beginning of dimension
	int numdim;				// number equivalent of singledim

	// allocate space to the variables used
	dimstr = (char*)malloc(STRING_LIMIT);
	singledim = (char*)malloc(STRING_LIMIT);

	// remove the opening and closing [ and ] and append a comma
	char* substring = copystring(dimlist, 1, (strlen(dimlist) - 3));
	strcpy(dimstr, substring);
	strcat(dimstr, ",");
	free(substring);

	while (dimstr[index] != ',')
		// pass the first comma without any processing
		index++;
   	// pass the comma itself
    index++;
	
	// find each individual dimension into singledim
	// change to its numeric equivalent
	// multiply with current value of total
	while (dimstr[index] != '\0')
	{
		prev = index;
		while (dimstr[index] != ',')
			index++;
		if (dimstr[index] == ',')
		{
			char* substring = copystring(dimstr, prev, index);
			strcpy(singledim, substring);
			free(substring);
			numdim = atoi(singledim);
			total = total * numdim;
		}
		index++;
	}
	free(dimstr);
	free(singledim);
	return total;	// return total of the dimensions
}

int total_dims(char * dimlist)
{
	/*
	This function is called from:
		char * multi_array(char varlist[], char dimensions[]) in this Header File
	when an array of multi dimensions has been declared and initialised in the one statement.
	When this occurs the correct initialisation list must be passed back in the
	Prolog Terms file.

	This function is called with parameter dimlist which is a string of the dimensions of
	an array that has multiple dimensions.
	For Example: 	"[4,2,3]" is the dimlist for an array declared as A[4][2][3]
	The function will return the product of these dimensions
	For Example: 4*2*3 = 24 in this example
	*/

 	int total = 1;			// total of dimensions
	char * dimstr;			// modified dimlist string (less [ and ], and comma added)
	char * singledim;		// a single dimension from dimstr
	int index = 0;			// control variable of while loop
	int prev;				// holds beginning of dimension
	int numdim;				// number equivalent of singledim

	// allocate space to the variables used
	dimstr = (char*)malloc(STRING_LIMIT);
	singledim = (char*)malloc(STRING_LIMIT);

	// remove the opening and closing [ and ] and append a comma
	strcpy(dimstr, copystring(dimlist, 1, (strlen(dimlist) - 3)));
	strcat(dimstr, ",");

	// while loop
	// find each individual dimension into singledim
	// change to its numeric equivalent
	// multiply with current value of total
	while (dimstr[index] != '\0')
	{
		prev = index;
		while (dimstr[index] != ',')
			index++;
		if (dimstr[index] == ',')
		{
			char* substring = copystring(dimstr, prev, index);
			strcpy(singledim, substring);
			free(substring);
			numdim = atoi(singledim);
			total = total * numdim;
		}
		index++;
	}
	free(dimstr);
	free(singledim);
	return total;	// return total of the dimensions
}

char * initarray(char * initstr, int rows)
{
	/*
	This function is called from:
		char * multi_array(char varlist[], char dimensions[]) in this Header file
	when an array of multi dimensions has been declared and initialised in the one statement.
	When this occurs the correct initialisation list must be passed back in
	the Prolog Terms file.
	This function helps build this initialisation list as explained in following example:
	Example:
	C Code:
		char myarr[2][3][2] = {{3,4,{66}},5,{6}} ;
	Initialisation of myarr should be:
		a[0][0][0] 3			a[1][0][0] 5
		a[0][0][1] 4			a[1][0][1] 6
		a[0][1][0] 66			a[1][1][0] 0
		a[0][1][1] 0			a[1][1][1] 0
		a[0][2][0] 0			a[1][2][0] 0
		a[0][2][1] 0			a[1][2][1] 0

	Prolog List Required:
		[ [3,4,[66]],0,0,0,[5,[6]],0,0,0,0 ] (flattened later in Prolog Code)

	initarray() takes as parameter:
		initstr -- "[[3,4,[66]],5,[6]]
		rows	--  6	-- 	this is the dimensions of array (not 1st one)
							multiplied together.

	elemstr becomes: "[3,4,[66]],5,[6],"

	Outer While  - 1st iteration
		rowstr 	= "[3,4,[66]],"
		reststr = "5,[6],"

		numelems = 3
		rowstr is padded with 0s to become: "[3,4,[66]],0,0,0,"
		returnstr = "[3,4,[66]],0,0,0,"

		setup for next iteration
		reststr is not "", it does not begin with "["
		therefore elemstr becomes: "[5,[6]],"

	Outer While  - 2nd iteration
		rowstr 	= "[5,[6]],"
		reststr = ""

		numelems = 2
		rowstr is padded with 0s to become: "[5,[6]],0,0,0,0,"
		returnstr = "[3,4,[66]],0,0,0," + "[5,[6]],0,0,0,0,"

		setup for next iteration
		reststr is not "", therefore elemstr becomes: ""

	Exit Outer While
	returnstr is "  [3,4,[66]],0,0,0,[5,[6]],0,0,0,0,"
	*/

	char * returnstr;	// return string of the function initarray()
	char * elemstr;	 	// this is initstr less opening [ and closing ]
						// and with a final ',' added

	// allocate space to the string(s) used
	returnstr = (char*)malloc(STRING_LIMIT);
	elemstr = (char*)malloc(STRING_LIMIT);

   	// remove the leading [ and finishing ] from initstr and store result into elemstr
   	// 3 is taken from the length of initstr as we avoid the null character at the end and
   	// one character each for the [ and ] we want removed
	char* substring = copystring(initstr, 1, strlen(initstr) - 3);
	strcpy(elemstr, substring);
	free(substring);
	// append a comma
	strcat(elemstr, ",");

	// begin processing
	// start the build for returnstr
	strcpy(returnstr, " ");

	// outer while -- still have a string to process
	while( (strcmp(elemstr, "")) !=  0)
	{
		int index = 1;			// control for inner while started at 1
								// as index = 0 is always '['
		int openbracket = 1;	// number '[' is started at 1 (first '[' is index = 0)
		int closebracket = 0;	// no ']' seen yet
		char * rowstr;			// current row to be processed
		char * reststr;			// rest of the row(s) to be processed
		int numelems = 0;		// number of elements in current row

		rowstr = (char*)malloc(STRING_LIMIT);
		reststr = (char*)malloc(STRING_LIMIT);

		// inner while
		// find the place corresonding ']' of the first '['
		// (at index = 0) is (result is value in index)
		while(openbracket != closebracket)
		{
			if (elemstr[index] == '[')	openbracket++;
			if (elemstr[index] == ']')	closebracket++;
			index++;
		}

		// rowstr -- isolate from first '[' to its corresponding closing ']'
		char* first_dimension_expression = copystring(elemstr, 0, index);
		strcpy(rowstr, first_dimension_expression);
		free(first_dimension_expression);
		// reststr -- rest of string from index + 1 to end
		char* rest = copystring(elemstr, index + 1, strlen(elemstr));
		strcpy(reststr, rest);
		free(rest);

		// find the number of elements in rowstr,
		// pad if necessary
		// append result to returnstr
		numelems = mystrstrcount(rowstr, ',');
		if( numelems != rows)
		{
			int i;
			int diff = rows - numelems;
			for (i = 1; i <= diff; i++)
				strcat(rowstr, "0,");
		}
		strcat(returnstr, rowstr);

		// begin set up the variables for next iteration of outer while
		// if reststr is empty, make elemstr empty
		// if reststr NOT empty & has '[' in it, copy to elemstr
		// if reststr NOT empty & does NOT have '[' in it,
		// add '[' to beginning, copy reststr, end with '],'
		if( (strcmp(reststr, "")) == 0)
			strcpy(elemstr, "");
		else
		{
			if(reststr[0] == '[')
				strcpy(elemstr, reststr);
			else
			{
				strcpy(elemstr, "[");
				reststr[(strlen(reststr) - 1)] = ']';
				strcat(elemstr, reststr);
				strcat(elemstr, ",");
			}
		}
		// end set up variables for next iteration of outer while

		free(rowstr);
		free(reststr);
	}
	// end outer while - string is empty

	free(elemstr);

	return returnstr;
}


char * multi_array(char varlist[], char dimensions[])
{
	/*
	This function is called from:
		void addvariabledetails(char varname[], char varconstant[]) in DECL_FUNCTIONS.H
	when an array of multi dimensions has been declared and initialised in the one statement.
	When this occurs the correct initialisation list must be passed back in
	our Prolog Terms file.
	This function builds this initialisation list.

	Taking as parameter a varlist (initialisation list) and the dimensions of the array as a
	string, the product of the dimensions are found to establish how many initialisers there
	should be. The amount of initialisers there should be in each row of the initialiser list
	is established by getting the product of all but the first dimension in dimensions.

	Next, the number of elements given in varlist are counted.
	If there is no difference between these values, varlist will be returned with no change.
	However, if there is a difference  then that amount of 0's needs to be added to our
	return string.

	This is because if there are fewer initialiszers than members in the array, the
	trailing members are initialized to 0.
	Reference:	"The C Programming Language"
				Brian W. Kernighan, Dennis M. Ritchie
				Prentice Hall Software Series, Second Edition
				ISBN:	0-13-110362-8
				page 219/220

	Example:	varlist = "[[4,4],[5,5],[78,90]]"
				dimensions = "4,2,2" (i.e.the array with dimension A[_][2][2])
				returnstr = "[4,4],0,0,[5,5],0,0,[78,90],0,0,0,0,0,0"
	*/

	// variables
	char * returnstr;		// return string of the function
	int noelements = 0;		// number elements in varlist (if any)
   	int numdimension;		// product of dimensions of array - as a number
	int difference;			// difference in dimensions given & number elements
	int i;					// control variable for the for loop
	int subdimension;		// product of all but first dimensions of array

	// allocate space for string used
	returnstr = (char*)malloc(STRING_LIMIT);
	// get the product of the dimensions by calling total_dims() in ARRAY_FUNCTIONS.H
	numdimension = total_dims(dimensions);
	// get the product of (all but the first) dimensions by calling subtotal_dims() in ARRAY_FUNCTIONS.H
	subdimension = subtotal_dims(dimensions);

	// call initarray() (ARRAY_FUNCTIONS.H) to get the initializer list for the rows defined
	strcpy(returnstr, initarray(varlist, subdimension));
	strcat(returnstr, "\0");

	// find the number of elements in the string. If less than numdimension
	// pad the resulting strings with 0s.
	noelements = mystrstrcount(returnstr, ',');
	difference = numdimension - noelements;

	for (i=1; i <= difference; i++)
		strcat(returnstr, "0,");
	if (returnstr[strlen(returnstr)-1] == ',')
		returnstr[strlen(returnstr)-1] = ' ';

	// return the string built with initializer list
	return returnstr;
}
