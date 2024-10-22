////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- PARAMETERS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This header file contains the functions which set up the linked
list of parameter variables, when they are parsed.
The functions in this file are called from the following places
in the grammar files:

GRAMMAR.L
/////////
("{"|"<%")		{ AddToScopeList(); }
The AddToScopeList() function uses several of the functions in
this header file. When a '{' is parsed, any parameter variables
that are in the parameters linked list are popped from it one by
one and added to the Scopes linked list, with the appropriate 
scoping details.

GRAMMAR.Y
/////////
parameter_declaration
	: declaration_specifiers declarator	 -- called here
	| declaration_specifiers abstract_declarator	
	| declaration_specifiers		
	;
When parameter variables are declared, they are added to the parameters
linked list, one at a time. If the parameters linked list is empty or
has not been created, it is created in this grammar rule also.
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** VARIABLES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
struct PNode;
typedef struct PNode *PtrToPNode;
typedef PtrToPNode PList;

struct PNode
{
	char * Element;		// Parameter Variable Name
	PtrToPNode PNext;	// Pointer to next node in parameters linked list
};

int PListFirstUse = NO; // Indicates if Parameter Linked List is in Use

PList P; 				// Linked List of Parameter Variable Names

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
extern char * case_name(char  * varname);
	// Extern the function which converts variable names to their Prolog equivalent.
int IsEmptyPList(PList P);
PList CreatePList(void);
void MakeEmptyP(PList P);
void DisposePList(PList P);
void PushPList(char X[], PList P);
char * PopPList(PList P);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int IsEmptyPList(PList P)
{
////////////////////////////////////////////////////////////////
/*
This function is called from the following places:
GRAMMAR.L 
/////////
Called from the function void AddToScopeList(void) which is called
when '{' is parsed. The paramaters linked list is checked to see if it is
empty or not. If it is not empty then the variables that are in the linked
list of parameters are freed and added to the Scopes linked list instead.

PARAMETERS.H
////////////
This function is also called by the following functions in this header file:
	void MakeEmptyP(PList P)
	char * PopPList(PList P)

The function checks if the list passed as parameter, the Parameters linked list,
is empty or not.
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	// if the List is empty return NULL 
	return P->PNext == NULL;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

PList CreatePList(void)
{
////////////////////////////////////////////////////////////////
/*
This function is called from GRAMMAR.Y:
parameter_declaration
	: declaration_specifiers declarator			--- from here
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

It is called to make and return a new empty list of type PList.
It will only be called if the Parameters Linked List has NOT already
been created.
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	// Create Parameters Linked List
	PList P;
	P = malloc( sizeof( struct PNode ) );
	if(P == NULL)
		printf( "ERROR: PARAMETERS LINKED LIST CAN NOT BE CREATED");
	P->PNext = NULL;
	MakeEmptyP(P);
	
	////////////////////////////////////////////////////////////////
	// Return NEW Parameters Linked List
	return P;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void MakeEmptyP(PList P)
{
////////////////////////////////////////////////////////////////
/*
This function is called from:
	void DisposePList(PList P)
	PList CreatePList(void)
It empties the list that is passed as parameter by traversing the list and calling
	char * PopPList(PList P)
to pop each node found.
*/
////////////////////////////////////////////////////////////////
	if( P == NULL )
		printf( "ERROR: MUST USE CREATEPLIST FIRST" );
	else
		while( !IsEmptyPList(P) )
			PopPList(P);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void DisposePList(PList P)
{
////////////////////////////////////////////////////////////////
/*
This function is called from the following places:

GRAMMAR.L
/////////
It is called from the function void AddToScopeList(void) which is called
when '{' is parsed. The parameters linked list is checked to see if it is
empty or not. If it is not empty then the variables that are in the linked
list of parameters are freed and added to the Scopes linked list instead.
This function is then called to dispose of the Parameters linked list.
The Parameters linked list is completely emptied and any memory allocated
to the linked list is freed up.
*/
////////////////////////////////////////////////////////////////
	MakeEmptyP(P);
	free(P);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void PushPList(char X[], PList P)
{
////////////////////////////////////////////////////////////////
/*
This function is called from grammar.y:
parameter_declaration
	: declaration_specifiers declarator			--- from here
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

It is called to push a new node with the information provided by
parameter X onto a Parameter Linked List P.
The List passed as parameter must already exist.
*/
////////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////////
	// Create a new Node and Push onto the Parameters Linked List
	PtrToPNode TmpCell;
	TmpCell = malloc( sizeof(struct PNode));
	if( TmpCell == NULL )
		printf( "ERROR: OUT OF SPACE - MALLOC FAILED" );
	////////////////////////////////////////////////////////////////
	// Add the details of the Parameter Variable to the Parameters Linked List
	// Use the case_name() function to convert X to its Prolog Name equivalent.
	else
	{
		char * Xstr;
		Xstr = (char *) malloc(STRING_LIMIT);
		TmpCell->Element  = (char *) malloc(STRING_LIMIT);
		strcpy(Xstr, X);
		strcpy(Xstr, case_name(Xstr));
		strcpy(TmpCell->Element, Xstr);
		TmpCell->PNext = P->PNext;
		P->PNext = TmpCell;
	}
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * PopPList(PList P)
{
////////////////////////////////////////////////////////////////
/*
This function is called from the following places:

GRAMMAR.L
/////////
This function is called from the function void AddToScopeList(void) which is called
when '{' is parsed. The paramaters linked list is checked to see if it is
empty or not. If it is not empty then the variables that are in the linked
list of parameters are freed and added to the scopes linked list instead.

This function is also called by the following functions in this header file:
	void MakeEmptyP(PList P)

The function finds the element that is at the top of the list passed as parameter
and returns this as a string. The node is popped from the linked list and
the associated memory is freed.

The function:
	int IsEmptyPList(PList L);
is called before the pop operation to make sure the list is not empty. If it is,
the pop operation is not carried out and an error message is issued.
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	// Variable Declarations and Initialisation
	PtrToPNode FirstCell;
	char * elem_str;
	elem_str = (char *) malloc(STRING_LIMIT);

	////////////////////////////////////////////////////////////////
	// If Parameters Linked List is EMPTY, return empty string
	if( IsEmptyPList(P) )
	{
		strcpy(elem_str, "");
	}
	////////////////////////////////////////////////////////////////
	// If Parameters Linked List is NOT l, return the Parameter Variable
	// which is at the top of the Linked List. Discard the top Node.
	else
	{
		FirstCell = P->PNext;
		strcpy(elem_str, FirstCell->Element);
		P->PNext = P->PNext->PNext;
		free( FirstCell );
	}
	////////////////////////////////////////////////////////////////
	//  Return the Parameter Variable at the TOP of the Linked List
	return elem_str;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- PARAMETERS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////