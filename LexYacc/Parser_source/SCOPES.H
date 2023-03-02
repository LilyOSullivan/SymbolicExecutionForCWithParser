////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- SCOPES.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This header file contains the code which is used to process the 
various scopes seen in the underlying source C code.
This is achieved with the implementation of a Stack linked list.
The Stack contains a field for the line number at which the scope
is parsed and a linked list of the variable seen at this scope.
	
New scopes are added to the Stack when a '{' is matched, using:
	void Push(int lineno);
Variables are added to the Stack using:
	PushVar(char variablename[], int Param);
Scopes are popped from the Stack when '}' is matched, using:
	void Pop(void);
*/
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** VARIABLESS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct VarList				
/*	
The linked list Varlist is nested into the Stack linked list
It contains details of the Variables that have been parsed
for each scope of the program. When a new scope is seen,
variables names are added to this scope and when the scope
ends, they are popped/discarded.
*/
{
	char * VarName;
	int Param;
	struct VarList *Next;
};
////////////////////////////////////////////////////////////////

struct Stack				
/* 	
Stack is a linked list which holds the scopes of the
program under test. As scopes are seen they are pushed
to the top of the stack and when that scope ends it is
popped from the stack.
The stack holds the variable linenumber which is the line
number that that scope began at.
The nested linked list VarList contains the variables that
are declared within the scope.
*/
{
	int linenumber;
	struct VarList *NextVar;
	struct Stack *NextLevel;
};
////////////////////////////////////////////////////////////////

struct Stack Head;			
/* 	
Always points to the head/start of the stack 
*/
////////////////////////////////////////////////////////////////

int StackUsed = NO;			
/* 
If the stack has not been used before in this program
the StackUsed variable is set to NO (0) which means that
the first line number in the scope will be set to 0 - this
indicates that these are the most global variables in the Stack
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void Push(int lineno);		
int  IsEmpty(void);			
void PushVar(char variablename[], int Param); 
void Pop(void);
int ScopeSearch(char variablename[]);
int ParameterSearch(char variablename[]);
int ScopeLineNumber(void);	

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void Push(int lineno)
{
////////////////////////////////////////////////////////////////
/*
This function is called from the following place in grammar.l
	("{"|"<%") 		
When '{' is parsed a new scope is being declared in C.
A new level is added to the top of the linked list Stack.
The line number that the new scope begins at is added to the linenumber field
of this list.
*/
////////////////////////////////////////////////////////////////

	struct Stack *TmpNode;			
	TmpNode = (struct Stack *) malloc (sizeof(struct Stack));

	if (StackUsed == NO)
	{
		Head.NextLevel = NULL;	
		StackUsed = YES;
	}
	TmpNode->linenumber = lineno;
	TmpNode->NextVar = NULL;
	TmpNode->NextLevel = Head.NextLevel;
	Head.NextLevel = TmpNode;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int IsEmpty(void)
{
////////////////////////////////////////////////////////////////
/*
This function returns 1 if the Stack linked list is empty and 0 otherwise.
This function is called from functions within this header file
*/
////////////////////////////////////////////////////////////////
	if (Head.NextLevel == NULL)
	{

   		return 1;
   	}
   	else
   		return 0;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void PushVar(char variablename[], int Param)
{
////////////////////////////////////////////////////////////////
/*
This function is called from functions in the DECL_FUNCTIONS.H header file,
as variables are being declared. It is also called from GRAMMAR.L when
parameter variables are declared.

This function adds variable names to the nested linked list VarList. Variable names
are added to the end of this list. The level/scope of the Stack that they are added
to is always the current one i.e. the top of the stack.

The second parameter Param indicates if the variable that is being pushed on the stack
is a function parameter (indicated by YES) or a local variable within this function/scope
(indicated by NO).

A check is first made to ensure that we have at least one scope/level on the Stack
before progressing.
If there is no variables stored in this scope/level already then this will be the
first entry. STRING_LIMIT is made for the node using malloc. The variable name is then
stored.
If there are already variables in the nested linked list, we first find the end of
that list and then append the node to that.

If the Stack is empty then a new level is created on the stack by calling Push. 
It is given the line number GLOBAL_SCOPE_NUMBER to indicate that a global variable 
is being declared. Then PushVar() is called recursively to add the variable name
to this level.
*/
////////////////////////////////////////////////////////////////
	Param = NO;
    if (IsEmpty() == 1)
    {	
    	////////////////////////////////////////////////////////////////
    	/* Stack is empty.
    	   This indicates that a global variable is being declared
    	   GLOBAL_SCOPE_NUMBER is pushed onto the Stack as the line number, a new level
    	   is created and PushVar is recursively called to push the
    	   variable onto this new level
    	*/
    	////////////////////////////////////////////////////////////////
    	Push(GLOBAL_SCOPE_NUMBER);
		PushVar(variablename, Param); // NO indicates that this is NOT a parameter variable 
   		return;
    }
    else
    {
		struct Stack *FirstNode;		
		struct VarList *VarNode;		
		FirstNode = Head.NextLevel;

		if (FirstNode->NextVar == NULL)
		{
			////////////////////////////////////////////////////////////////
			// First entry in the nested linked list
			VarNode = (struct VarList *) malloc(sizeof(struct VarList));
			VarNode->VarName  = (char *) malloc(STRING_LIMIT);
			strcpy(VarNode->VarName, variablename);
			VarNode->Param = Param;
			VarNode->Next = NULL;
			FirstNode->NextVar = VarNode;
		}
		else
		{
			////////////////////////////////////////////////////////////////
			// 	Not the first entry in the nested linked list
			//	Need to get to the end and then append node	
		 	VarNode = FirstNode->NextVar;
			while (VarNode->Next)
				VarNode = VarNode->Next;

			VarNode->Next = (struct VarList *) malloc(sizeof(struct VarList));
			VarNode = VarNode->Next;
			VarNode->VarName  = (char *) malloc(STRING_LIMIT);
			strcpy(VarNode->VarName, variablename);
			VarNode->Param = Param;
			VarNode->Next = NULL;
		}
	}
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void Pop(void)
{
////////////////////////////////////////////////////////////////
/*
This function is called when the end of a scope is parsed, i.e. when '}' is parsed.
It is called from the following places in grammar.y

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'	--- from here
	| struct_or_union '{' struct_declaration_list '}'  				--- from here
	| struct_or_union IDENTIFIER
	;
enum_specifier
	: ENUM '{' enumerator_list '}'									--- from here
	| ENUM IDENTIFIER '{' enumerator_list '}' 						--- from here
	| ENUM IDENTIFIER
	;
initializer
	: assignment_expression
	| '{' initializer_list '}'										--- from here
	| '{' initializer_list ',' '}'									--- from here
	;
compound_statement
	: '{' '}'														--- from here
	| '{' statement_list '}'										--- from here
	| '{' declaration_list '}'										--- from here
	| '{' declaration_list statement_list '}'						--- from here
	;

When the end of the scope is reached - before the '}' is actually parsed - the
node at the top of the stack is popped and all memory allocated to such is freed.
*/
////////////////////////////////////////////////////////////////

   	if (IsEmpty() == 1)
   	{	
   		////////////////////////////////////////////////////////////////
   		// Stack is already empty so we cannot perform a Pop operation 
   	}
   	else
   	{
   		////////////////////////////////////////////////////////////////
   		// Stack is NOT empty   	
		struct Stack *FirstNode;			
		FirstNode = Head.NextLevel;			
		if (FirstNode->NextVar == NULL)
		{	
   			////////////////////////////////////////////////////////////////
   			// Empty Stack  			
		}
		else if (FirstNode->linenumber == GLOBAL_SCOPE_NUMBER)
		{	
			////////////////////////////////////////////////////////////////
			// Only scope left on the stack - do not Pop
		}
		else
		{
   			////////////////////////////////////////////////////////////////
   			// Perform Pop operation 	
      		Head.NextLevel = FirstNode->NextLevel;
  			free(FirstNode);

  			if (IsEmpty() == 1)
  			{
  				StackUsed = NO;
  				Head.NextLevel = NULL;
  			}
  		}
	}
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void AmendVar(char * varname, int param)
{
////////////////////////////////////////////////////////////////
/*
This function is called from the function: void AddToScopeList(void) in
GRAMMAR.L. It changes the variable 'varname' with parameter 'param'
if it exists at the line number GLOBAL_SCOPE_NUMBER
*/
////////////////////////////////////////////////////////////////
	struct Stack *StackNode;		// pointer to the stack
	struct VarList *VarNode;		// node of the variables at the current level
	int Amended = 0;				// control variable for VarNode loop - stop when == 1

	StackNode = Head.NextLevel;		// start at the top of the stack

	// find the level where linenumber == GLOBAL_SCOPE_NUMBER
	while(StackNode && StackNode->linenumber != GLOBAL_SCOPE_NUMBER)
		StackNode = StackNode->NextLevel;

	VarNode = StackNode->NextVar;
	while(VarNode && !Amended)
	{
		if ((strcmp(VarNode->VarName, varname) == 0) && (VarNode->Param == param))
		{
			strcat(VarNode->VarName, "_Amended");
			Amended = 1;
		}
		VarNode = VarNode->Next;
	}
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int ScopeSearch(char variablename[])
{
////////////////////////////////////////////////////////////////
/*
This function is called from:

GRAMMAR.Y
/////////
primary_expression
	: IDENTIFIER			--- from here
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;
GRAMMAR.L
/////////	
	void AddToScopeList(void)
	
It takes in a variable name and searches for it in the linked list Stack starting
at the top of the stack and working downwards through it. If the variable is found
the corresponding line number of that scope is returned. The most global scope is GLOBAL_SCOPE_NUMBER
so if this is returned the most global scope has been found.
If the variable is not found (shouldnt happen) then -1 is returned.
*/
////////////////////////////////////////////////////////////////
	struct Stack *StackNode;
	struct VarList *VarNode;

	StackNode = Head.NextLevel;
	
	////////////////////////////////////////////////////////////////
	// Start at the top of the stack and work downwards - exit when correct result found
	while(StackNode)
	{
			VarNode = StackNode->NextVar;
			while(VarNode)
			{
				if (strcmp(VarNode->VarName, variablename) == 0)
					return StackNode->linenumber;
				else
					VarNode = VarNode->Next;
			}
			////////////////////////////////////////////////////////////////
			//try the next level
			StackNode = StackNode->NextLevel;
	}

	////////////////////////////////////////////////////////////////
	// if variable is not, found return -1 
	return -1;

}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int ParameterSearch(char variablename[])
{
////////////////////////////////////////////////////////////////
/*
This function is called from:

GRAMMAR.Y
/////////
primary_expression
	: IDENTIFIER			--- from here
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;
GRAMMAR.L
/////////	
	void AddToScopeList(void)
	
It takes in a variable name and searches for it in the linked list Stack starting
at the top of the stack and working downwards through it. If the variable is found
the corresponding line number of that scope is returned. The most global scope is GLOBAL_SCOPE_NUMBER
so if this is returned the most global scope has been found.
If the variable is not found (shouldnt happen) then -1 is returned.
*/
////////////////////////////////////////////////////////////////
	struct Stack *StackNode;
	struct VarList *VarNode;

	StackNode = Head.NextLevel;
	
	////////////////////////////////////////////////////////////////
	// Start at the top of the stack and work downwards - exit when correct result found
	while(StackNode)
	{
			VarNode = StackNode->NextVar;
			while(VarNode)
			{
				if (strcmp(VarNode->VarName, variablename) == 0)
					return VarNode->Param;
				else
					VarNode = VarNode->Next;
			}

			////////////////////////////////////////////////////////////////
			// try the next level
			StackNode = StackNode->NextLevel;
	}

	////////////////////////////////////////////////////////////////
	// if variable is not, found return -1 
	return -1;

}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int ScopeLineNumber(void)
{
////////////////////////////////////////////////////////////////
/*
This function is called from functions in DECL_FUNCTIONS.H
It returns the linenumber of the current scope as long as the Stack is not empty. 
If it is empty it returns 0.
*/
////////////////////////////////////////////////////////////////
	struct Stack *FirstNode;
	if (IsEmpty() != 1)
	{
		FirstNode = Head.NextLevel;
		return FirstNode->linenumber;
	}
	else
		return 0;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- SCOPES.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

