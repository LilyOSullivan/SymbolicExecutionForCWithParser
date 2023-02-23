////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- LINKEDLISTS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This header file contains the code for a variety of linked lists.
These linked lists are used to record the line number at which 
certain tokens have been parsed. This information is output to
various Prolog predicates in the Prolog terms file. This information
is used for error reporting and information purposes only.
The tokens that are pushed to the various lists are as follows:
	"case"
	"default"
	"do"
	"for"
	"if"
	"switch"
	"while"
When these tokens are matched in GRAMMAR.L, their appropriate linked
list is checked to see if it already exists. If it does not, it is 
created using the function:
	List CreateList(void);
The line number at which the token is parsed is pushed to the appropriate
linked list using the function:
	void PushList(int X, List L);

When the grammar rule for the appropriate token is matched in GRAMMAR.Y,
the function in charge of processing the rule pops the node from the
appropriate linked list using either of the following functions:
	char * PopList(List L);
	char * BottomList(List L);
If the linked list is emptied fully as a result of this, it is disposed
of using the function:
	void DisposeList(List L);
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** VARIABLES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

// The Linked List structure used for all the Linked Lists declared.
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node
{
	int Element;
	PtrToNode Next;
};

////////////////////////////////////////////////////////////////
// FOR LOOPS
List For;
// Linked List, detailing the line number where the 'for' token is parsed
int ForListUsed = NO;
//  This variable is set to NO (0) indicating that the linked list 'For' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)

////////////////////////////////////////////////////////////////
// DO...WHILE LOOPS
List Do;
// Linked List, detailing the line number where the 'do' token is parsed
int DoListUsed = NO;
//  This variable is set to NO (0) indicating that the linked list 'Do' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)

////////////////////////////////////////////////////////////////
// WHILE LOOPS
List While;
// Linked List, detailing the line number where the 'while' token is parsed
int WhileListUsed = NO;
//  This variable is set to NO (0) indicating that the linked list 'While' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)


////////////////////////////////////////////////////////////////
// IF STATEMENTS
List If;
// Linked List, detailing the line number where the 'if' token is parsed
int IfListUsed = NO;
//  This variable is set to NO (0) indicating that the linked list 'If' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)
int IfEnded = 0;
//  This variable counts the number of if statements parsed

////////////////////////////////////////////////////////////////
// SWITCH STATEMENTS
List Switch;
// Linked List, detailing the line number where the 'switch' token is parsed
int SwitchListUsed = NO;
//  This variable is set to NO (0) indicating that the linked list 'Switch' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)

////////////////////////////////////////////////////////////////
// CASE STATEMENTS
List Case;
// Linked List, detailing the line number where the 'case' token is parsed
int CaseListUsed = NO;
// This variable is set to NO (0) indicating that the linked list 'Case' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)

////////////////////////////////////////////////////////////////
// DEFAULT STATEMENTS
List Default;
// Linked List, detailing the line number where the 'default' token is parsed
int DefaultListUsed = NO;
//  This variable is set to NO (0) indicating that the linked list 'Default' has not previously been
//	used. It is reset to YES (1) whenever the list is created (in grammar.l)

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int IsEmptyList(List L);
List CreateList(void);
void MakeEmpty(List L);
void DisposeList(List L);
void PushList(int X, List L);
char * PopList(List L);
char * BottomList(List L);
int CountList(List L);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
int IsEmptyList(List L)
{
////////////////////////////////////////////////////////////////
/*
This function checks if the list passed as parameter is empty or not.
*/
////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////
	// if the List is empty return NULL 
	return L->Next == NULL;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

List CreateList(void)
{
////////////////////////////////////////////////////////////////
/*
Create the linked list List. This is an EMPTY linked list.
*/
////////////////////////////////////////////////////////////////
	List L;
	L = malloc( sizeof( struct Node ) );
	if(L == NULL)
		printf("ERROR: OUT OF SPACE");
	L->Next = NULL;
	MakeEmpty(L);
	return L;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void MakeEmpty(List L)
{
////////////////////////////////////////////////////////////////
/*
Empty the linked list passed as parameter.
*/
////////////////////////////////////////////////////////////////
	if( L == NULL )
		printf( "ERROR: MUST USE CREATELIST FIRST" );
	else
		while( !IsEmptyList(L) )
			PopList(L);
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void DisposeList(List L)
{
////////////////////////////////////////////////////////////////
/*
Dispose of the Linked list L, free up any allocated memory.
*/
////////////////////////////////////////////////////////////////
	MakeEmpty(L);
	free(L);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void PushList(int X, List L)
{
////////////////////////////////////////////////////////////////
/*
Push the number X onto the linked list L
*/
////////////////////////////////////////////////////////////////

	PtrToNode TmpCell;
	TmpCell = malloc( sizeof(struct Node));
	if( TmpCell == NULL )
		printf("ERROR; OUT OF SPACE");
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = L->Next;
		L->Next = TmpCell;
	}
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * PopList(List L)
{
////////////////////////////////////////////////////////////////
/*
This function finds the element that is at the top of the list passed as parameter
and returns this number as a string. The node is popped from the linked list and
the associated memory is freed.
*/
////////////////////////////////////////////////////////////////
	PtrToNode FirstCell;
	char * elem_str;

	elem_str = (char *) malloc(STRING_LIMIT);

	if( IsEmptyList(L) )
	{
		printf("ERROR: EMPTY STACK - CANNOT POP THE NODE");
		strcpy(elem_str, "");
	}
	else
	{
		FirstCell = L->Next;
		itoa(FirstCell->Element, elem_str, RADIX);
		L->Next = L->Next->Next;
		free( FirstCell );
	}
	return elem_str;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * BottomList(List L)
{
////////////////////////////////////////////////////////////////
/*
This function finds the element that is at the bottom of the list passed as parameter
and returns this number as a string. The node is popped from the linked list and
the associated memory is freed.
*/
////////////////////////////////////////////////////////////////
	PtrToNode LastCell;
	char * elem_str;

	elem_str = (char *) malloc(STRING_LIMIT);

	if( IsEmptyList(L) )
	{
		printf("ERROR: CAN NOT POP NODE FROM EMPTY STACK");
		strcpy(elem_str, "");
	}
	else
	{
		while (L->Next->Next)
		{
			L = L->Next;
		}
		LastCell = L->Next;
		L->Next = NULL;

		itoa(LastCell->Element, elem_str, RADIX);
		free( LastCell );
	}
	return elem_str;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int CountList(List L)
{
////////////////////////////////////////////////////////////////
/*
This function counts the number of nodes in the linked list L
*/
////////////////////////////////////////////////////////////////	
	List Temp;
	int counter = 0;
	Temp = L;

	while (Temp->Next)
	{
		counter++;
		Temp = Temp->Next;
	}
	return counter;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- LINKEDLISTS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
