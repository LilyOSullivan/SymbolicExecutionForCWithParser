////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- IF_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/* 
The functions in this header file are called from the following 
places in Grammar.y:

selection_statement
	: IF '(' expression ')' statement
							{ strcpy($$, if_statement($3, $5)); }
	| IF '(' expression ')' statement ELSE statement
							{ strcpy($$, ifelse_statement($3, $5, $7)); }
	| SWITCH '(' expression ')' statement
							{.....}
	;
Their functionality is to change the if statement and if..else statement 
written in C into their equivalent Prolog terms for ouput to the Prolog 
terms file.

The if statement in C is parsed to its equivalent in Prolog 
terms, which has the following format:
if_statement(LineNumber, expression(Condition), If Stmts, Else Stmts)

Predicate
*********
if_statement(....)

LineNumber
***********
The linenumber at which the 'if' token has been parsed.
This parameter is used for error reporting and information purposes
by the symbolic executor. The 'if' token is parsed when the token
code 305 is used.

expression(Condition)
*********************
The condition tested by the if statement. No processing is necessary
to the Condition part, other than wrapping it in the expression() string.

If Stmts
********
These are the statements of the true branch of the if statement. They must
be enclosed in Prolog List. Therefore, if they are not already wrapped in
a '[' and ']', this must be done in the functions defined in this header file.


Else Stmts
**********
These are the statements of the false branch of the if statement. They must
be enclosed in Prolog List. Therefore, if they are not already wrapped in
a '[' and ']', this must be done in the functions defined in this header file.

*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * if_statement(char expression[], char statement[]);
char * ifelse_statement(char expression[], char if_stmt[], char else_stmt[]);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * if_statement(char expression[], char statement[])
////////////////////////////////////////////////////////////////
/* 
The if statement in C is parsed to its equivalent in Prolog 
terms. This function is called when the following grammar rule in
grammar.y is matched.
	IF 	'(' 	expression 	')' 	statement
This is the if function which does NOT have a corresponding else.
Therefore, the Else Stmts of this if statement are written as '[]].
*/
////////////////////////////////////////////////////////////////
{
	/////////////////////////////////////////////////////////////////
	// variable declarations
	unsigned int counter;		// for loop counter
	int blank = 0;				// variable to test if statement is empty
	int lenstring;				// length of statement
	char * returnstr;			// return string of the function
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	returnstr 	 = (char *) malloc(STRING_LIMIT);

	/////////////////////////////////////////////////////////////////
	// PREDICATE
	strcpy(returnstr, "\nif_statement(");

	/////////////////////////////////////////////////////////////////
	// LINENUMBER
	IfEnded--;	
	if ( (CountList(If) > IfEnded) && (yychar == IF_TOKEN) ) 
		strcat(returnstr, BottomList(If));	// LINKEDLISTS.H
	else
		strcat(returnstr, PopList(If));		// LINKEDLISTS.H
	if (IsEmptyList(If))					// LINKEDLISTS.H
	{
		DisposeList(If);					// LINKEDLISTS.H
		IfListUsed = NO;					// LINKEDLISTS.H
	}
	strcat(returnstr, ", ");

	/////////////////////////////////////////////////////////////////
	// EXPRESSION(CONDITION)
	strcat(returnstr, "expression("); 
	strcat(returnstr, expression);
	strcat(returnstr, "), ");

	/////////////////////////////////////////////////////////////////
	// IF STMTS
	lenstring = strlen(statement) - 1; // less one for the NULL character
	for (counter = 0; counter < strlen(statement); counter++)
	{
		if (statement[counter] != '\0')
			blank = 1;
	}
	// Statement parameter is NOT empty
	if (blank == 1)
	{
		if (statement[0] != '[')
			strcat(returnstr, "[");	
		strcat(returnstr, statement);
		if (statement[lenstring] != ']')
			strcat(returnstr, "]");		
	}
	// Statement parameter is empty
	else 
	{
		strcat(returnstr, "[]");
	}
	
	////////////////////////////////////////////////////////////////
	// ELSE STMTS
	strcat(returnstr, ", [])");		
	
	////////////////////////////////////////////////////////////////
	// successfully leaving the if_statement() function
	return returnstr;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * ifelse_statement(char expression[], char if_stmt[], char else_stmt[])
////////////////////////////////////////////////////////////////
/* 
The if statement in C is parsed to its equivalent in Prolog 
terms. This function is called when the following grammar rule in
grammar.y is matched.
	IF '(' expression ')' statement ELSE statement
This is the if function which does have a corresponding else.
*/
////////////////////////////////////////////////////////////////
{
	/////////////////////////////////////////////////////////////////
	// variable declarations
	int lenstringif;			// length of if_stmt
	int lenstringelse;			// length of else_stmt
	char * returnstr;			// return string of the function
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	returnstr 	 = (char *) malloc(STRING_LIMIT);

	/////////////////////////////////////////////////////////////////
	// PREDICATE
	strcpy(returnstr, "\nif_statement(");
	
	/////////////////////////////////////////////////////////////////
	// LINENUMBER
	IfEnded--;	
	if ( (CountList(If) > IfEnded) && (CountList(If) != 2) )
		strcat(returnstr, BottomList(If));	
	else
		strcat(returnstr, PopList(If));
	if (IsEmptyList(If))			
	{
		DisposeList(If);			
		IfListUsed = NO;			
	}
	strcat(returnstr, ", ");

	/////////////////////////////////////////////////////////////////
	// EXPRESSION(CONDITION)
	strcat(returnstr, "expression("); 
	strcat(returnstr, expression);
	strcat(returnstr, "), ");
	
	/////////////////////////////////////////////////////////////////
	// IF STMTS
	lenstringif = strlen(if_stmt) - 1; // less one for the NULL character
	if (if_stmt[0] != '[')
		strcat(returnstr, "[");		
	strcat(returnstr, if_stmt);
	if (if_stmt[lenstringif] != ']')
		strcat(returnstr, "]");		
	strcat(returnstr, ", ");
	/////////////////////////////////////////////////////////////////
	// ELSE STMTS	
	lenstringelse = strlen(else_stmt) - 1; // less one for the NULL character
	if (else_stmt[0] != '[')
		strcat(returnstr, "[");		
	strcat(returnstr, else_stmt);
	if (else_stmt[lenstringelse] != ']')
		strcat(returnstr, "]");		
	strcat(returnstr, ")");
	////////////////////////////////////////////////////////////////
	// successfully leaving the ifelse_statement() function
	return returnstr;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- IF_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////