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

char * switch_statement(char S3[], char S5[])
{ 	
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
		----------
		The linenumber at which the 'switch' token has been parsed.
		This parameter is used for error reporting and information purposes
		by the symbolic executor. 

		EXPRESSION(S3)
		--------------
		This is the expression which is tested before the switch statements are
		processed.
	
		SWITCH STATEMENTS (S5)
		----------------------
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

	char* switch_statement_processed = NULL;
	
	int lenstring = strlen(S5) - 1;				// used to determine the length of S5


	// LINE NUMBER -- ERROR REPORTING PURPOSES
	char* popped_value = PopList(Switch); // LINKEDLISTS.H 
	
	if (IsEmptyList(Switch))		// LINKEDLISTS.H 
	{
		DisposeList(Switch);		// LINKEDLISTS.H 
		SwitchListUsed = NO;		// LINKEDLISTS.H 
	}
	
	
	// SWITCH STATEMENTS
		
	if (strlen(S5) != 3)
	{
		//// PROCESS SWITCH STATEMENT ////

		char* unreachable_code = unreachablecode(S5); // remove unreachable code
		char* switch_statement_str = insertswitch(unreachable_code, S3); // insert switch expressions into case statements
		switch_statement_processed = process_default(switch_statement_str);	// add a final default to the switch statement
		
		free(unreachable_code);
		free(switch_statement_str);

		
		if (S5[lenstring] != ']') 
		{	
			// if there is no ']' at end of S5 insert one
			// to ensure else if part is a prolog list		
			strcat(S5, "]");
		}			
	}



	///////////////////////////

	char* SS = switch_statement_processed != NULL ?
		(char*)malloc(9 + strlen(popped_value) + 2 + 11 + strlen(S3) + 3 + 1 + strlen(switch_statement_processed) + 1 + 1)
		: (char*)malloc(9 + strlen(popped_value) + 2 + 11 + strlen(S3) + 3 + 2 + 1 + 1);


	strcpy(SS, "\nswitch(");
	strcat(SS, popped_value);
	strcat(SS, ", ");

	// EXPRESSION
	strcat(SS, "expression(");
	strcat(SS, S3);
	strcat(SS, "), ");

	if (switch_statement_processed != NULL) {

		if (S5[0] != '[')
		{	// if there is no '[' at beginning of S5 insert one
			// to ensure else if part is a prolog list
			strcat(SS, "[");
		}
		strcat(SS, switch_statement_processed);	// append the altered S5 to SS
		free(switch_statement_processed);
	}
	else {
		strcat(SS, "[]");
	}
	strcat(SS, ")"); // finish with a closing bracket


	free(popped_value);

	return SS;
}

char * unreachablecode(char switchstring[])
{
	/*
		This function is called from:
			char * switch_statement(char S3[], char S5[])
			;
		This function is called to parse out all the unreachable code that 
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

	char* returnstring;
	char* defaultptr = NULL;
	char* caseptr = NULL;
	char* tempstring = (char*)malloc(strlen(switchstring) + 1);
	int defaultref = 0;
	int caseref = 0;

	strcpy(tempstring, switchstring);
	
	// Create the strings and Values:
	//	defaultptr 	-- 	string starting at first default in the 
	//					switch statement, if present.
	// 	defaultref	--	position of default, if present
	//	casetptr 	-- 	string starting at first case in the 
	//					switch statement, if present.
	// 	caseref		--	position of case, if present	
	
	if (strstr(tempstring, DEFAULT_STRING) != NULL)
	{
		defaultptr = strstr(tempstring, DEFAULT_STRING);
		defaultref = strlen(tempstring) - strlen(defaultptr);
	}

	if (strstr(tempstring, CASE_STRING) != NULL)
	{
		caseptr = strstr(tempstring, CASE_STRING);
		caseref = strlen(tempstring) - strlen(caseptr);
	}

	// If both a 'case' and 'default' have been seen then ...
	// Check if the case is seen before the default, if so
	// append the caseptr.
	// If the default has been seen before the case, append
	// the defaultptr.
	// If only a case has been seen, append the caseptr.
	// If only a default has been seen, append the defaultptr.
	// Else just append ']' to the return string.

	char* selected_ptr = NULL;


	if (caseptr != NULL && defaultptr != NULL)
	{
		selected_ptr = (caseref < defaultref) ? caseptr : defaultptr;
	}
	else if (caseptr != NULL) {
		selected_ptr = caseptr;
	}
	 else if (defaultptr != NULL) {
		selected_ptr = defaultptr;
	}


	if (selected_ptr != NULL) {
		returnstring = (char*)malloc(3 + strlen(selected_ptr) + 1);
		if (tempstring[0] == '[')
			strcpy(returnstring, "[");
		strcat(returnstring, "\n");

		strcat(returnstring, selected_ptr);
	}
	else {
		// No cases or defaults
		returnstring = (char*)malloc(3 + 1 + 1);
		if (tempstring[0] == '[')
			strcpy(returnstring, "[");
		strcat(returnstring, "\n");

		strcat(returnstring, "]");
	}

	free(tempstring);

	return returnstring;
}

char * process_default(char switchstmt[])
{
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

	char* holdstring;
	
	/* find the number of defaults in the switchstmt */

	if(strstrcount(switchstmt, DEFAULT_STRING) > 0)
	{	
		// if there are more than 0 (should only be 0 or 1) defaults in	
		// switch statement the proceed by:				
		// -- find string beginning default (defaultptr).			
		// -- Put entire holdstring into tempstring, less 2 for closing ] and NULL.	
		// -- Concatenate the comma, "final" and then defaultptr.		
		// -- copy tempstring back into holdstring
		char* defaultptr = strstr(switchstmt, DEFAULT_STRING);
		char* hold_string_shortened = copystring(switchstmt, 0, (strlen(switchstmt) - 2));
		holdstring = (char*)malloc(strlen(hold_string_shortened) + 4 + 5 + strlen(defaultptr) + 1);
		strcpy(holdstring, hold_string_shortened);
		strcat(holdstring, ", \n");
		strcat(holdstring, "final");
		strcat(holdstring, defaultptr);

		free(hold_string_shortened);
	}
	else {
		holdstring = (char*)malloc(strlen(switchstmt) + 1);
		strcpy(holdstring, switchstmt);
	}

	char* returnstring = (char*)malloc(strlen(holdstring) + 1);
	strcpy(returnstring, holdstring);
	free(holdstring);
	return returnstring;
}

char * insertswitch(char switchstmt[], char switchexpression[])
{
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

	char * returnstring;		// return string of the function
	char * expression;			// holds the second parameter - expression of the switch stmt
	char * holdstring;			// holding string of the function

	int count;					// number of instances of CASE_STRING in holdstring
	int loopcounter;			// control variable of the FOR loop
	char * second_caseptr = NULL;// position of next case statement
	
	
	// Allocate space to the strings used
	expression	= (char *) malloc(strlen(switchexpression) + 1);
	holdstring = (char*)malloc(strlen(switchstmt) + 1);
	
	// Initialise Strings
	strcpy(expression, switchexpression);
	strcpy(holdstring, switchstmt);
	
	// Number of case statements in the input string.
	count = strstrcount(holdstring, CASE_STRING);

	if (count > 0)
	{	

		char* temp;
		char* copy;
		char* workstring = copystring(holdstring, 0, (strlen(holdstring) - strlen(strstr(holdstring, CASE_STRING)) - 1));
		// Case statements found - process the case statements
	
		for (loopcounter = 1; loopcounter < count; loopcounter++)
		{
			char* caseptr = strstr(holdstring, CASE_STRING);
			char* commaptr = strstr(caseptr, COMMA_STRING);
			char* case_statement_substring = copystring(caseptr, 0, (strlen(caseptr) - strlen(commaptr)));

			if(strstr(commaptr, CASE_STRING) != NULL)
			{
				second_caseptr = strstr(commaptr, CASE_STRING);
				temp = copystring(commaptr, 1, (strlen(commaptr) - strlen(second_caseptr) - 2));
				strcpy(holdstring, second_caseptr);
			}
			else {
				temp = (char*)malloc(1 + 1);
				strcpy(temp, "");
			}
			copy = workstring;
			workstring = (char*)malloc(strlen(copy) + strlen(case_statement_substring) + strlen(expression) + 2 + strlen(temp) + 1);
			strcpy(workstring, copy);
			strcat(workstring, case_statement_substring);
			strcat(workstring, expression);
			strcat(workstring, "==");
			strcat(workstring, temp);

			free(case_statement_substring);

			free(temp);
			free(copy);
			
		}	
		// Process that last case statement
		if (loopcounter == count)
		{
			char* caseptr = strstr(holdstring, CASE_STRING);
			char* commaptr = strstr(caseptr, COMMA_STRING);
			char* case_statement_substring = copystring(caseptr, 0, (strlen(caseptr) - strlen(commaptr)));
			temp = copystring(commaptr, 1, strlen(commaptr));
			copy = workstring;
			workstring = (char*)malloc(strlen(copy) + strlen(case_statement_substring) + strlen(expression) + 2 + strlen(temp) + 1);

			strcpy(workstring, copy);
			strcat(workstring, case_statement_substring);
			strcat(workstring, expression);
			strcat(workstring, "==");
			strcat(workstring, temp);

			free(case_statement_substring);
			free(temp);
		}
		returnstring = (char*)malloc(strlen(workstring) + 1);
		strcpy(returnstring, workstring);
		free(workstring);
	}
	else
	{	
		// no cases found - return the statement as it was
		returnstring = (char*)malloc(strlen(switchstmt) + 1);
		strcpy(returnstring, switchstmt);
	}	
	
	free(expression);
	
	free(holdstring);

	return returnstring;
}

char * case_statement(char S2[], char S4[])
{
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

	char* returnstr = (char*)malloc(STRING_LIMIT);	// return string of the function
	int lenstring = strlen(S4) - 1;	// length of S4 (case statements) less 1 for NULL char

	// START PREDICATE
	strcpy(returnstr, "case(");

	// LINENUMBER	
	strcat(returnstr, PopList(Case));	// LINKEDLISTS.H
	if (IsEmptyList(Case))				// LINKEDLISTS.H
	{
		DisposeList(Case);				// LINKEDLISTS.H
		CaseListUsed = NO;				// LINKEDLISTS.H
	}
	strcat(returnstr, ", ");
	
	// CASE EXPRESSION	
	strcat(returnstr,  S2);
	strcat(returnstr, ", ");
	
	// CASE STATEMENTS	

	if (strstr(S4, "case(") != NULL)
	{
		// NESTED CASE - DO NOT CARRY FORWARD, APPEND NESTED CASE
		strcat(returnstr, "[]), "); strcat(returnstr, S4);
	}
	else
	{
		// NO NESTED CASE - PROCESS AS PROLOG LIST
		if (S4[0] != '[')			
			strcat(returnstr, "[");	
		strcat(returnstr, S4);
		if (S4[lenstring] != ']')
			strcat(returnstr, "]");	
		strcat(returnstr, ")");	
	}

	return returnstr;		
}

char* default_statement(char S3[])
{
	/*
		This function parses Default statements to their equivalent in Prolog 
		terms, which has the following format:
			default(LineNumber, DefaultStmts)

		LineNumber
		----------
		The linenumber at which the 'default' token has been parsed.
		This parameter is used for error reporting and information purposes
		by the symbolic executor. 

		DefaultStmts
		------------
		The statements to be executed if the default branch is taken. They must
		be enclosed in Prolog List. Therefore, if they are not already wrapped in
		a '[' and ']', this must be done in the functions defined in this header file.
	*/

	char* returnstr = (char*)malloc(STRING_LIMIT);				// return string of the function
	int lenstring = strlen(S3) - 1;	// length of S3 (default statements) less 1 for NULL char
	
	strcpy(returnstr, "\ndefault(");

	// LINENUMBER	
	char* line_number = PopList(Default); 	// LINKEDLISTS.H
	strcat(returnstr, line_number);
	free(line_number);
	if (IsEmptyList(Default))				// LINKEDLISTS.H
	{
		DisposeList(Default);				// LINKEDLISTS.H
		DefaultListUsed = NO;				// LINKEDLISTS.H
	}
	strcat(returnstr, ", ");
	
	// DEFAULT STATEMENTS			
	if (S3[0] != '[')			
		strcat(returnstr, "[");	
	strcat(returnstr, S3);
	if (S3[lenstring] != ']')
		strcat(returnstr, "]");	
	strcat(returnstr, ")");		

	return returnstr;	
}
