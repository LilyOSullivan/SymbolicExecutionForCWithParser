////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- SWITCH_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/* 
This header file contains the functions that are used in the
processing of switch statements.
This occurs at the following grammar rule in GRAMMAR.Y:
selection_statement
	: IF '(' expression ')' statement							
	| IF '(' expression ')' statement ELSE statement							
	| SWITCH '(' expression ')' statement
							{ strcpy($$, switch_statement($3, $5));	}
	;

The functions in this file, convert the switch statement into the 
format required by the Prolog terms. The result of the processing is
returned to the pseudo-variable $$.

This header file also contains the functions used to process the
case and default statements parsed.
This occurs at the following grammar rule in GRAMMAR.Y:
labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement 
			{ strcpy($$, case_statement($2, $4)); }
	| DEFAULT ':' statement			 
			{ strcpy($$, default_statement($3));  }	 
	;
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// FUNCTIONS FOR PROCESSING SWITCH STATEMENTS
char * switch_statement(char S3[], char S5[]); 
char * unreachablecode(char switchstring[]);	
char * process_default(char switchstmt[]);
char * insertswitch(char switchstmt[], char switchexpression[]); 
// FUNCTIONS FOR PROCESSING CASE STATEMENTS
char * case_statement(char S2[], char S4[]);
char * analyze_case(char casestmt[]);

// FUNCTIONS FOR PROCESSING DEFAULT STATEMENTS
char * default_statement(char S3[]);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * switch_statement(char S3[], char S5[])
{ 	
////////////////////////////////////////////////////////////////
/*
This function is called at the switch statement on $5 in grammar.y at:
selection_statement
	: IF '(' expression ')' statement 		
	| IF '(' expression ')' statement ELSE statement  
	| SWITCH '(' expression ')' statement			
								-- CALLED HERE
	;
It is called to build the switch statement in the format required
by the Prolog terms.

The switch statement is built in the following format:
	switch(LineNumber, expression(S3), [Switch Statements (S5)])

LineNumber
///////////
The linenumber at which the 'switch' token has been parsed.
This parameter is used for error reporting and information purposes
by the symbolic executor. 

EXPRESSION(S3)
///////////////
This is the expression which is tested before the switch statements are
processed.
	
SWITCH STATEMENTS (S5)
//////////////////////
S5 is processed the most in this function.
Unreachable code, code before the first case or default is completely
removed by a call to this header file function:
		char * unreachablecode(char switchstring[]);	

Next, char * insertswitch(char switchstmt[], char switchexpression[])
is called. This function changes each of the case statements in S5 so 
that they contain the switch expression. For example, if the switch
expression (S3) is 'X' and a case statement in S5 is:
	case(LineNumber, 0, [Case Statements])
this is changed to
	case(LineNumber, X==0, [Case Statements]).
This is done for ALL case statements in S5.

Finally, char * process_default(char switchstmt[]) is called
to add a final default to the switch statements. This is to ensure that]
a default is executed by the switch statement (if present).
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
	// Variable Declarations
	////////////////////////////////////////////////////////////
	char * SS;					// return string of the function	
	int lenstring;				// used to determine the length of S5

	////////////////////////////////////////////////////////////
	// Allocate space to the strings used
	////////////////////////////////////////////////////////////
	SS	= (char *) malloc(STRING_LIMIT);	

	////////////////////////////////////////////////////////////
	// Find the length of S5. less one for the NULL character
	////////////////////////////////////////////////////////////
	lenstring = strlen(S5) - 1;

	////////////////////////////////////////////////////////////
	//  ***						BUILD SS 				 ***  //
	////////////////////////////////////////////////////////////	
		
	////////////////////////////////////////////////////////////
	// NAME OF STATEMENT - SWITCH STATEMENT
	////////////////////////////////////////////////////////////		
	strcpy(SS, "\nswitch(");

	////////////////////////////////////////////////////////////
	// LINE NUMBER -- ERROR REPORTING PURPOSES
	////////////////////////////////////////////////////////////	
	strcat(SS, PopList(Switch));	// LINKEDLISTS.H 
	if (IsEmptyList(Switch))		// LINKEDLISTS.H 
	{
		DisposeList(Switch);		// LINKEDLISTS.H 
		SwitchListUsed = NO;		// LINKEDLISTS.H 
	}
	strcat(SS, ", ");
	
	////////////////////////////////////////////////////////////
	// EXPRESSION
	////////////////////////////////////////////////////////////	
	strcat(SS, "expression(");
	strcat(SS, S3);
	strcat(SS, "), "); 
		
	////////////////////////////////////////////////////////////
	// SWITCH STATEMENTS
	////////////////////////////////////////////////////////////
		
	if (strlen(S5) == 3)
	{
		//// SWITCH STATEMENT EMPTY ////
		strcat(SS, "[]");
	}
	else
	{
		//// PROCESS SWITCH STATEMENT ////
		if (S5[0] != '[') 
		{	// if there is no '[' at beginning of S5 insert one
			// to ensure else if part is a prolog list
			strcat(SS, "[");		
		}		
		strcpy(S5, unreachablecode(S5)); 	// remove unreachable code
		strcpy(S5, insertswitch(S5, S3));	// insert switch expressions into case statements
		strcpy(S5, process_default(S5));	// add a final default to the switch statement
		strcat(SS, S5);						// append the altered S5 to SS
		
		if (S5[lenstring] != ']') 
		{	// if there is no ']' at end of S5 insert one
			// to ensure else if part is a prolog list		
			strcat(S5, "]");
		}			
	}
	strcat(SS, ")");						// finish with a closing bracket

	////////////////////////////////////////////////////////////
	// return the result string of the function
	////////////////////////////////////////////////////////////	
	return SS;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

char * unreachablecode(char switchstring[])
{
////////////////////////////////////////////////////////////////
/*
This function is called from:
	char * switch_statement(char S3[], char S5[])
	;
This function is called to	parse out all the unreachable code that 
is found at the beginning of the switch statement.
This is the code before any case or default in the switch statement.			
If there is no case or default in the code, then the switch is empty or has	
only unreachable code in it and therefore can be considered empty.			
If a case is seen first in the switch we consider from that point on is the	
statements of the switch and ignore the code before it.						
If a default is seen first in the switch we consider from that point on is 	
the statements of the switch and ignore the code before it.		
The input string, less the unreachable code, is returned by the function.
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
	// Variable Declarations
	////////////////////////////////////////////////////////////
	char * returnstring;
	char * defaultptr = NULL;
	char * caseptr = NULL;
	char * tempstring; 
	int defaultref = 0;
	int caseref = 0;

	////////////////////////////////////////////////////////////
	// Allocate space to the strings used
	////////////////////////////////////////////////////////////
	returnstring	= (char *) malloc(STRING_LIMIT);	
	tempstring		= (char *) malloc(STRING_LIMIT);

	////////////////////////////////////////////////////////////	
	// Initialise Strings
	////////////////////////////////////////////////////////////
	strcpy(tempstring, switchstring);
	
	////////////////////////////////////////////////////////////
	// Create the strings and Values:
	//	defaultptr 	-- 	string starting at first default in the 
	//					switch statement, if present.
	// 	defaultref	--	position of default, if present
	//	casetptr 	-- 	string starting at first case in the 
	//					switch statement, if present.
	// 	caseref		--	position of case, if present	
	////////////////////////////////////////////////////////////
	
	if (strstr(tempstring, DEFAULT_STRING) != NULL)
	{
		defaultptr = (char *) malloc(STRING_LIMIT);
		strcpy(defaultptr, strstr(tempstring, DEFAULT_STRING));
		defaultref = strlen(tempstring) - strlen(defaultptr);
	}

	if (strstr(tempstring, CASE_STRING) != NULL)
	{
		caseptr = (char *) malloc(STRING_LIMIT);
		strcpy(caseptr, strstr(tempstring, CASE_STRING));
		caseref = strlen(tempstring) - strlen(caseptr);
		}

	////////////////////////////////////////////////////////////
	// Create the beginning of the string
	////////////////////////////////////////////////////////////
	if (tempstring[0] == '[')	
		strcpy(returnstring, "[");	
	strcat(returnstring, "\n");	

	////////////////////////////////////////////////////////////
	// If both a 'case' and 'default' have been seen then ...
	// Check if the case is seen before the default, if so
	// append the caseptr.
	// If the default has been seen before the case, append
	// the defaultptr.
	// If only a case has been seen, append the caseptr.
	// If only a default has been seen, append the defaultptr.
	// Else just append ']' to the return string.
	////////////////////////////////////////////////////////////

	if (caseptr != NULL && defaultptr != NULL)
	{
		if (caseref < defaultref)
			//// CASE FIRST ////
			strcat(returnstring, caseptr);
		else
			//// DEFAULT FIRST ////
			strcat(returnstring, defaultptr);	
	}
	else
	{
		if (caseptr != NULL)
			//// CASE ONLY ////
			strcat(returnstring, caseptr);
		else if (defaultptr != NULL)
			//// DEFAULT ONLY ////
			strcat(returnstring, defaultptr);
		else
			//// NO CASES OR DEFAULTS ////
			strcat(returnstring, "]"); 
	}
	
	////////////////////////////////////////////////////////////
	// return the result string of the function
	////////////////////////////////////////////////////////////
	return returnstring;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

char * process_default(char switchstmt[])
{
////////////////////////////////////////////////////////////////
/*
This function is called from:
	char * switch_statement(char S3[], char S5[])
	;
This function is called upon in the switch statement, which it takes as 
parameter I want to make the default statement the last labelled statement 
in the switchstmt. This "finaldefault" will only be executed if and only 
if none of the cases in the	switchstmt have been matched (and if no break 
has been executed).			
If the default lies in the middle of the case statements of will remain there	
This is because a case before this could have been matched, but the follwing 
statements did not contain a break, therefore the statements of the default 
could be executed as execution would fall to the statements following.					
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
	// Variable Declarations
	////////////////////////////////////////////////////////////
	char * returnstring;		// return string of the function
	char * holdstring;			// work string of the function
	char * tempstring;			// temporary holding string of the function
	int defaultcount = 0;		// number of defaults in the switchstmt
	char * defaultptr = NULL;	// holds string starting with DEFAULT_STRING
	

	////////////////////////////////////////////////////////////
	// Allocate space to the strings used
	////////////////////////////////////////////////////////////
	returnstring	= (char *) malloc(STRING_LIMIT);
	holdstring		= (char *) malloc(STRING_LIMIT);
	
	////////////////////////////////////////////////////////////	
	// Initialise Strings
	////////////////////////////////////////////////////////////	
	strcpy(holdstring, switchstmt);

	////////////////////////////////////////////////////////////	
	// Initialise Integer variables
	////////////////////////////////////////////////////////////	
	defaultcount = strstrcount(holdstring, DEFAULT_STRING);
	/* find the number of defaults in the switchstmt		*/

	if(defaultcount > 0)
	////////////////////////////////////////////////////////////
	// if there are more than 0 (should only be 0 or 1) defaults in	
	// switch statement the proceed by:				
	// -- find string beginning default (defaultptr).			
	// -- Put entire holdstring into tempstring, less 2 for closing ] and NULL.	
	// -- Concatenate the comma, "final" and then defaultptr.		
	// -- copy tempstring back into holdstring
	////////////////////////////////////////////////////////////
	{
		defaultptr = (char *) malloc(STRING_LIMIT);
		strcpy(defaultptr, strstr(holdstring, DEFAULT_STRING));
		tempstring		= (char *) malloc(STRING_LIMIT);
		strcpy(tempstring, copystring(holdstring, 0, (strlen(holdstring) - 2)));
		strcat(tempstring, ", \n");
		strcat(tempstring, "final");
		strcat(tempstring, defaultptr);
		strcpy(holdstring, "");
		strcpy(holdstring, tempstring);
	}
	////////////////////////////////////////////////////////////
	// return the result string of the function
	////////////////////////////////////////////////////////////	
	strcpy(returnstring, holdstring);
	return returnstring;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

char * insertswitch(char switchstmt[], char switchexpression[])
{
////////////////////////////////////////////////////////////////
/*
This function is called from:
	char * switch_statement(char S3[], char S5[])
	;
This function takes in switchstmt (S5) and the switch expression.
It builds a new string, where the expression of the case statements
in switchstmt are joined with the switch expression. This new string is
returned by the function.
For example, if the 
switchexpression is "X" 
switchstmt is 
"[case(12, 0, [assignment(Y, 0]), case(12, 1, [assignment(Y, 1])...]"
where case/3 is of the format:
	case(LineNumber, Case Expression, [Case Statements])
The return string is
"[case(12, X==0, [assignment(Y, 0]), case(12, X==1, [assignment(Y, 1])...]"
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////
	// Variable Declarations
	////////////////////////////////////////////////////////////
	char * returnstring;		// return string of the function
	char * expression;			// holds the second parameter - expression of the switch stmt
	char * holdstring;			// holding string of the function
	char * workstring;			// work string of the function
	int count;					// number of instances of CASE_STRING in holdstring
	int loopcounter;			// control variable of the FOR loop
	char * caseptr = NULL;		// holds string starting with CASE_STRING	
	char * commaptr = NULL;		// holds string starting with COMMA_STRING
	char * second_caseptr = NULL;// position of next case statement
	
	////////////////////////////////////////////////////////////
	// Allocate space to the strings used
	////////////////////////////////////////////////////////////
	returnstring	= (char *) malloc(STRING_LIMIT);
	expression  	= (char *) malloc(STRING_LIMIT);	
	workstring 		= (char *) malloc(STRING_LIMIT);	
	holdstring		= (char *) malloc(STRING_LIMIT);
	
	////////////////////////////////////////////////////////////	
	// Initialise Strings
	////////////////////////////////////////////////////////////
	strcpy(expression, switchexpression);
	strcpy(holdstring, switchstmt);
	
	////////////////////////////////////////////////////////////	
	// Number of case statements in the input string.
	////////////////////////////////////////////////////////////
	count = strstrcount(holdstring, CASE_STRING);

	if (count > 0)
	{	////////////////////////////////////////////////////////////
		// Case statements found - process the case statements
		caseptr = (char *) malloc(STRING_LIMIT);
		strcpy(caseptr, strstr(holdstring, CASE_STRING));		
		strcpy(workstring, copystring(holdstring, 0, (strlen(holdstring) - strlen(caseptr) - 1)));
	
		for (loopcounter = 1; loopcounter < count; loopcounter++)
		{
			
			caseptr = (char *) malloc(STRING_LIMIT);
			strcpy(caseptr, strstr(holdstring, CASE_STRING));				
			commaptr =  (char *) malloc(STRING_LIMIT);
			strcpy(commaptr, strstr(caseptr, COMMA_STRING));
			strcat(workstring, copystring(caseptr, 0, (strlen(caseptr) - strlen(commaptr))));
			strcat(workstring, expression);
			strcat(workstring, "==");

			if(strstr(commaptr, CASE_STRING) != NULL)
			{
				second_caseptr = (char *) malloc(STRING_LIMIT);
				strcpy(second_caseptr, strstr(commaptr, CASE_STRING));
				strcat(workstring, copystring(commaptr, 1, (strlen(commaptr) - strlen(second_caseptr) - 2)));
				strcpy(holdstring, "");
				strcpy(holdstring, second_caseptr);
			}
			
		}	
		////////////////////////////////////////////////////////////
		// Process that last case statement
		if (loopcounter == count)
		{
			caseptr = (char *) malloc(STRING_LIMIT);
			strcpy(caseptr, strstr(holdstring, CASE_STRING));				
			commaptr =  (char *) malloc(STRING_LIMIT);
			strcpy(commaptr, strstr(caseptr, COMMA_STRING));
			strcat(workstring, copystring(caseptr, 0, (strlen(caseptr) - strlen(commaptr))));
			strcat(workstring, expression);
			strcat(workstring, "==");
			strcat(workstring, copystring(commaptr, 1, strlen(commaptr)));		
		}

		strcpy(returnstring, workstring);
	}
	else
	{	////////////////////////////////////////////////////////////
		// no cases found - return the statement as it was
		strcpy(returnstring, switchstmt);
	}	
	
	////////////////////////////////////////////////////////////
	// return the result string of the function
	////////////////////////////////////////////////////////////
	return returnstring;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
char * case_statement(char S2[], char S4[])
{
/////////////////////////////////////////////////////////////////////
/*
This function parses Case statements to their equivalent in Prolog 
terms, which has the following format:
	case(LineNumber, CaseExpr, CaseStmts)

LineNumber
///////////
The linenumber at which the 'case' token has been parsed.
This parameter is used for error reporting and information purposes
by the symbolic executor. 

CaseExpr
////////
The expression to be tested in the case statement

CaseStmts
/////////
The statements to be executed if CaseExpr is evaluated to true. They must
be enclosed in Prolog List. Therefore, if they are not already wrapped in
a '[' and ']', this must be done in the functions defined in this header file.
If there are any further case statements, nested within the current case
statement, they must be removed and processed separately.
*/
/////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;				// return string of the function
	int lenstring = strlen(S4) - 1;	// length of S4 (case statements) less 1 for NULL char

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	returnstr 	 = (char *) malloc(STRING_LIMIT);	

	/////////////////////////////////////////////////////////////////
	// START PREDICATE
	strcpy(returnstr, "case(");

	/////////////////////////////////////////////////////////////////
	// LINENUMBER	
	strcat(returnstr, PopList(Case));	// LINKEDLISTS.H
	if (IsEmptyList(Case))				// LINKEDLISTS.H
	{
		DisposeList(Case);				// LINKEDLISTS.H
		CaseListUsed = NO;				// LINKEDLISTS.H
	}
	strcat(returnstr, ", ");
	
	/////////////////////////////////////////////////////////////////
	// CASE EXPRESSION	
	strcat(returnstr,  S2);
	strcat(returnstr, ", ");
	
	/////////////////////////////////////////////////////////////////
	// CASE STATEMENTS	

	if (strstr(S4, "case(") != NULL)
	{
		/////////////////////////////////////////////////////////////////
		// NESTED CASE - DO NOT CARRY FORWARD, APPEND NESTED CASE
		strcat(returnstr, "[]), "); strcat(returnstr, S4);
	}
	else
	{
		/////////////////////////////////////////////////////////////////
		// NO NESTED CASE - PROCESS AS PROLOG LIST
		if (S4[0] != '[')			
			strcat(returnstr, "[");	
		strcat(returnstr, S4);
		if (S4[lenstring] != ']')
			strcat(returnstr, "]");	
		strcat(returnstr, ")");	
	}

	////////////////////////////////////////////////////////////////
	// successfully leaving the case_statement() function	
	return returnstr;		
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

char * default_statement(char S3[])
{
/////////////////////////////////////////////////////////////////////
/*
This function parses Default statements to their equivalent in Prolog 
terms, which has the following format:
	default(LineNumber, DefaultStmts)

LineNumber
///////////
The linenumber at which the 'default' token has been parsed.
This parameter is used for error reporting and information purposes
by the symbolic executor. 

DefaultStmts
////////////
The statements to be executed if the default branch is taken. They must
be enclosed in Prolog List. Therefore, if they are not already wrapped in
a '[' and ']', this must be done in the functions defined in this header file.
*/
/////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;				// return string of the function
	int lenstring = strlen(S3) - 1;	// length of S3 (default statements) less 1 for NULL char

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	returnstr 	 = (char *) malloc(STRING_LIMIT);	
	
	strcpy(returnstr, "\ndefault(");

	/////////////////////////////////////////////////////////////////
	// LINENUMBER	
	strcat(returnstr, PopList(Default));	// LINKEDLISTS.H
	if (IsEmptyList(Default))				// LINKEDLISTS.H
	{
		DisposeList(Default);				// LINKEDLISTS.H
		DefaultListUsed = NO;				// LINKEDLISTS.H
	}
	strcat(returnstr, ", ");
	
	/////////////////////////////////////////////////////////////////
	// DEFAULT STATEMENTS			
	if (S3[0] != '[')			
		strcat(returnstr, "[");	
	strcat(returnstr, S3);
	if (S3[lenstring] != ']')
		strcat(returnstr, "]");	
	strcat(returnstr, ")");		

	////////////////////////////////////////////////////////////////
	// successfully leaving the case_statement() function	
	return returnstr;	
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- SWITCH_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////