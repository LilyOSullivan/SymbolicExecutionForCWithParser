/*
This header file contains the functions which process the iteration
statements in the grammar.y file. These are called from the following
grammar rule in grammar.y:
iteration_statement	
	: WHILE '(' expression ')' statement	
	{ 	strcpy($$, while_statement($3, $5));	 
	}
	| DO statement WHILE '(' expression ')' ';'	
	{ 	strcpy($$, do_statement($2, $5));	  
	}
	| FOR '(' expression_statement expression_statement ')' statement 
	{	strcpy($$, for2_statement($3, $4, $6));	 
	}
	| FOR '(' expression_statement expression_statement expression ')' statement 
	{	strcpy($$, for_statement($3, $4, $5, $7));
	}
	;
*/

char* while_statement(char expression[], char statement[]);
char* do_statement(char statement[], char expression[]);
char* for2_statement(char exprstmt1[], char exprstmt2[], char statement[]);
char* for_statement(char expr1[], char expr2[], char expr3[], char statement[]);

char* while_statement(char expression[], char statement[])
{
	/*
		While loops are parsed to their equivalent in Prolog terms in the
		following format:
			while(LineNumber, expression(Condition), While Statements)
		LineNumber
		***********
		The linenumber at which the 'while' token has been parsed.
		This parameter is used for error reporting and information purposes
		by the symbolic executor. 

		expression(Condition)
		*********************
		The condition tested by the while statement. No processing is necessary
		to the Condition part, other than wrapping it in the expression() string.

		While Statements
		*****************
		These are the statements that must be executed if the Condition is true.
		They must be enclosed in Prolog List. Therefore, if they are not already wrapped in
		a '[' and ']', this must be done in this function.
	*/

	int lenstring;				// used to determine the length of statement
	char * returnstr;			// return string of the function	

	returnstr = (char *) malloc(STRING_LIMIT);

	// PREDICATE
	strcpy(returnstr, "\nwhile(");

	// LINENUMBER -- functions in LINKEDLISTS.H
	strcat(returnstr, PopList(While));
	if (IsEmptyList(While))			
	{
		DisposeList(While);			
		WhileListUsed = NO;			
	}
	strcat(returnstr, ", ");

	// EXPRESSION(CONDITION)
	strcat(returnstr, "expression(");
	strcat(returnstr, expression);
	strcat(returnstr, "), ");
	
	// WHILE STATEMENTS	
	lenstring = strlen(statement) - 1; 
	if (statement[0] != '[')		
		strcat(returnstr, "[");		
	strcat(returnstr, statement);
	if (statement[lenstring] != ']')
		strcat(returnstr, "]");		
	strcat(returnstr, ")");

	return returnstr;				
}

char * do_statement(char statement[], char expression[])
{
	/*
		DO..While loops are parsed to their equivalent in Prolog terms in the
		following format:
			do(LineNumber, While Statements, expression(Condition))
		LineNumber
		***********
		The linenumber at which the 'do' token has been parsed.
		This parameter is used for error reporting and information purposes
		by the symbolic executor. 

		Do..While Statements
		*****************
		These are the statements that must be executed once and then if the Condition is true.
		They must be enclosed in Prolog List. Therefore, if they are not already wrapped in
		a '[' and ']', this must be done in this function.

		expression(Condition)
		*********************
		The condition tested by the do..while statement. No processing is necessary
		to the Condition part, other than wrapping it in the expression() string.
	*/
	int lenstring;				// used to determine the length of statement
	char * returnstr;			// return string of the function	

	returnstr = (char *) malloc(STRING_LIMIT);

	// PREDICATE
	strcpy(returnstr, "\ndo(");

	// LINENUMBER	-- functions in LINKEDLISTS.H
	strcat(returnstr, PopList(Do));	
	if (IsEmptyList(Do))			
	{
		DisposeList(Do);			
		DoListUsed = NO;			
	}
	strcat(returnstr, ", ");
	printf("%s", PopList(While));	
	if (IsEmptyList(While))			
	{
		DisposeList(While);			
		WhileListUsed = NO;			
	}

	// DO..WHILE STATEMENTS	
	lenstring = strlen(statement) - 1;
	if (statement[0] != '[')
		strcat(returnstr, "[");	
	strcat(returnstr, statement);
	if (statement[lenstring] != ']')
		strcat(returnstr, "]");		 
	strcat(returnstr, ", ");

	// EXPRESSION(CONDITION)	
	strcat(returnstr, "expression(");
	strcat(returnstr, expression);
	strcat(returnstr, "))");
	
	return returnstr;				
}

char* for2_statement(char exprstmt1[], char exprstmt2[], char statement[])
{
	/*
		For loops (with two conditions) are parsed to their equivalent in Prolog terms in the
		following format:
			for2(LineNumber, expression(Condition), expression(Condition), For Statements)

		LineNumber
		***********
		The linenumber at which the 'for' token has been parsed.
		This parameter is used for error reporting and information purposes
		by the symbolic executor. 

		expression(Condition) (2)
		*************************
		The condition tested by the for statement. No processing is necessary
		to the Condition part, other than wrapping it in the expression() string.

		For Statements
		***************
		These are the statements that must be executed in the for loop.
		They must be enclosed in Prolog List. Therefore, if they are not already wrapped in
		a '[' and ']', this must be done in this function.
	*/
	// variable declarations
	int lenstring;				// used to determine the length of statement
	char * returnstr;			// return string of the function	

	// allocate space to the string variables used
	returnstr = (char *) malloc(STRING_LIMIT);

	// PREDICATE
	strcpy(returnstr, "\nfor2(");

	// LINENUMBER	-- functions in LINKEDLISTS.H
	strcat(returnstr, PopList(For));	
	if (IsEmptyList(For))			
	{
		DisposeList(For);			
		ForListUsed = NO;			
	}
	strcat(returnstr, ", ");

	// EXPRESSION(CONDITION)	
	strcat(returnstr, "expression(");
	strcat(returnstr, exprstmt1);
	strcat(returnstr, "),");
	strcat(returnstr, "expression(");
	strcat(returnstr, exprstmt2);
	strcat(returnstr, "),");

	// FOR STATEMENTS	
	lenstring = strlen(statement) - 1;
	if (statement[0] != '[')
		strcat(returnstr, "[");	
	strcat(returnstr, statement);
	if (statement[lenstring] != ']')
		strcat(returnstr, "]");	
	strcat(returnstr, ")");

	return returnstr;		
}

char* for_statement(char expr1[], char expr2[], char expr3[], char statement[])
{
	/*
		For loops (with 3 conditions) are parsed to their equivalent in Prolog terms in the
		following format:
		for(LineNumber, expression(Condition), expression(Condition), expression(Condition), For Statements)

		LineNumber
		***********
		The linenumber at which the 'for' token has been parsed.
		This parameter is used for error reporting and information purposes
		by the symbolic executor. 

		expression(Condition) (3)
		*************************
		The condition tested by the for statement. No processing is necessary
		to the Condition part, other than wrapping it in the expression() string.

		For Statements
		***************
		These are the statements that must be executed in the for loop.
		They must be enclosed in Prolog List. Therefore, if they are not already wrapped in
		a '[' and ']', this must be done in this function.
	*/
	int lenstring;				// used to determine the length of statement
	char * returnstr;			// return string of the function	

	// allocate space to the string variables used
	returnstr = (char *) malloc(STRING_LIMIT);

	// PREDICATE
	strcpy(returnstr, "\nfor(");

	// LINENUMBER	-- functions in LINKEDLISTS.H
	strcat(returnstr, PopList(For));	
	if (IsEmptyList(For))			
	{
		DisposeList(For);			
		ForListUsed = NO;			
	}
	strcat(returnstr, ", ");

	// EXPRESSION(CONDITION)	
	strcat(returnstr, "expression("); strcat(returnstr, expr1); strcat(returnstr, "),");
	strcat(returnstr, "expression("); strcat(returnstr, expr2);	strcat(returnstr, "),");
	strcat(returnstr, "expression("); strcat(returnstr, expr3);	strcat(returnstr, "),");

	// FOR STATEMENTS	
	lenstring = strlen(statement) - 1;
	if (statement[0] != '[')
		strcat(returnstr, "[");	
	strcat(returnstr, statement);
	if (statement[lenstring] != ']')
		strcat(returnstr, "]");	
	strcat(returnstr, ")");

	return returnstr;
}
