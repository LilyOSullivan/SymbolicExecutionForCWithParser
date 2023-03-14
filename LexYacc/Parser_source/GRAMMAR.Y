%{
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** GRAMMAR.Y SPECIFICATION FILE
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This is the grammar specification file for the ANSI C programming
language. The original file has been sourced at the following
reference:
	J. Lee. ANSI C Lex and YACC Grammar Files, April 1985.
	FTP: ftp.uu.net, FILE: usenet/net.sources/ansi.c.grammar.Z.

This file is used as the input grammar file of the parser generator 
used in the WCET Analysis Tool.
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** GRAMMAR FILE DEFINITONS SECTION
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
extern int yylex();
extern void yyerror(const char*);
extern int yychar;
////////////////////////////////////////////////////////////////
// *** INCLUDE USER-DEFINED HEADER FILES
////////////////////////////////////////////////////////////////
#include "definitions.h"
#include "string_functions.h"
#include "linkedlists.h"
#include "parameters.h"
#include "scopes.h"
#include "ascii_functions.h"
#include "switch_functions.h"
#include "typedef_functions.h"
#include "enum_functions.h"
#include "output_functions.h"
#include "array_functions.h"
#include "decl_functions.h"	
#include "if_functions.h"
#include "iteration_functions.h"  	
#include "structures.h"
#include "conversion_functions.h"

%}

////////////////////////////////////////////////////////////////
// *** GRAMMAR DEFINITIONS
////////////////////////////////////////////////////////////////
%union
{
	char id[UNION_SIZE];
}
%token <id> IDENTIFIER CONSTANT STRING_LITERAL 
%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN 
%token <id> TYPE_NAME
%token TYPEDEF EXTERN STATIC REGISTER
%token AUTO
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS 
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%type <id> primary_expression
%type <id> expression
%type <id> assignment_operator
%type <id> assignment_expression
%type <id> conditional_expression
%type <id> unary_expression
%type <id> argument_expression_list
%type <id> unary_operator postfix_expression
%type <id> cast_expression
%type <id> multiplicative_expression
%type <id> additive_expression
%type <id> shift_expression
%type <id> relational_expression
%type <id> equality_expression
%type <id> and_expression
%type <id> exclusive_or_expression
%type <id> inclusive_or_expression
%type <id> logical_and_expression
%type <id> logical_or_expression
%type <id> type_name
%type <id> abstract_declarator
%type <id> direct_abstract_declarator
%type <id> constant_expression
%type <id> parameter_type_list
%type <id> parameter_list
%type <id> parameter_declaration
%type <id> declaration_specifiers
%type <id> storage_class_specifier
%type <id> type_specifier
%type <id> struct_or_union_specifier
%type <id> struct_or_union
%type <id> struct_declaration
%type <id> specifier_qualifier_list
%type <id> type_qualifier
%type <id> declarator
%type <id> direct_declarator
%type <id> pointer
%type <id> type_qualifier_list
%type <id> identifier_list
%type <id> declaration
%type <id> init_declarator_list
%type <id> init_declarator
%type <id> initializer
%type <id> initializer_list
%type <id> struct_declaration_list
%type <id> enum_specifier
%type <id> enumerator_list
%type <id> enumerator
%type <id> struct_declarator_list
%type <id> struct_declarator
%type <id> declaration_list
%type <id> expression_statement
%type <id> statement
%type <id> labeled_statement
%type <id> compound_statement
%type <id> statement_list
%type <id> selection_statement
%type <id> iteration_statement
%type <id> jump_statement
%type <id> function_definition
%type <id> external_declaration
%type <id> translation_unit
%start translation_unit
%%
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** GRAMMAR FILE RULES SECTION
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
primary_expression	
	: IDENTIFIER		
	{ 
		strcpy($$, identifier_function($1));	// DECL_FUNCTIONS.H
	}		
	| CONSTANT		
	{ 	
		strcpy($$, ascii_function($1)); 	// ASCII_FUNCTIONS.H
		strcpy($$, check_number($1)); 		// CONVERSION_FUNCTIONS.H
	}
	| STRING_LITERAL	
	{ 
		strcpy($$, $1);
	}
	| '(' expression ')'	
	{ 
		strcpy($$, "("); strcat($$, $2); strcat($$, ")"); 
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
postfix_expression
	: primary_expression	
	{ 
		strcpy($$, $1); 
	}
	| postfix_expression '[' expression ']' 
	{ 
		if (strstr($1, "[") != NULL) 
		{
			strcpy($$, process_arrays($1, $3)); // ARRAY_FUNCTIONS.H
		}
		else 
		{
			strcpy($$, $1); strcat($$, "["); strcat($$, $3); strcat($$, "]"); 
		}
	
	}
	| postfix_expression '(' ')'	
	{ 
		////////////////////////////////////////////////////////////////
		// Process function calls (without arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		////////////////////////////////////////////////////////////////
		char *func_name;
		func_name = (char *) malloc(STRING_LIMIT);
		strcpy(func_name, copystring($1, 3, strlen($1)));
		strcpy($$, "\nfunction_call("); 


		if (isupper(func_name[0]))
			strcat($$, "UC_");
		else
			strcat($$, "LC_");

		strcat($$, func_name);
		

		strcat($$, ", [");  strcat($$, "]"); strcat($$, ")");
	}
	| postfix_expression '(' argument_expression_list ')'  
	{ 
		////////////////////////////////////////////////////////////////
		// Process function calls (with arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		////////////////////////////////////////////////////////////////	
		char *func_name;
		func_name = (char *) malloc(STRING_LIMIT);
		strcpy(func_name, copystring($1, 3, strlen($1)-3));
		strcpy($$, "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat($$, "UC_");
		else
			strcat($$, "LC_");

		strcat($$, func_name);
		strcat($$, ", ["); strcat($$, $3); strcat($$, "]"); strcat($$, ")");	
	}
	| postfix_expression '.' IDENTIFIER		
	{	
		////////////////////////////////////////////////////////////////
		// Process records/structures
		////////////////////////////////////////////////////////////////		
		strcpy($$, process_records($1, $3));	// STRUCTURES.H
	}
	| postfix_expression PTR_OP IDENTIFIER	
	{ 		
		////////////////////////////////////////////////////////////////
		// Process linked list statements
		////////////////////////////////////////////////////////////////
		$3[0] = convert_tolower($3[0]); strcpy($$, "linkedlist("); 
		strcat($$, $1); strcat($$, ", "); strcat($$, $3); strcat($$, ")");
	}		
	| postfix_expression INC_OP 
	{
		////////////////////////////////////////////////////////////////
		// Process statements such as i++;
		////////////////////////////////////////////////////////////////		
		strcpy($$, "\npost_increment("); 
		if ( (strstr($1, "dereference") != NULL) && ($1[0] != '(') )
		{
			strcat($$, "("); strcat($$, $1); strcat($$, " , ");
			strcat($$, "(");  strcat($$, $1); strcat($$, "+1)");
		}
		else
		{
			strcat($$, $1); strcat($$, " , "); strcat($$, $1); strcat($$, "+1)");
		}
	}
	| postfix_expression DEC_OP	
	{	
		////////////////////////////////////////////////////////////////
		// Process statements such as i--;
		////////////////////////////////////////////////////////////////
		strcpy($$, "\npost_decrement("); strcat($$, $1); 
		strcat($$, " , "); strcat($$, $1); strcat($$, "-1)");
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

argument_expression_list
	: assignment_expression			
	{strcpy($$, $1); }
	| argument_expression_list ',' assignment_expression	
	{strcpy($$, $1); strcat($$, ","); strcat($$, $3);  }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

unary_expression
	: postfix_expression		
	{	strcpy($$, $1);  }	
	| INC_OP unary_expression	
	{	
		////////////////////////////////////////////////////////////////
		// Process statements such as ++i;
		////////////////////////////////////////////////////////////////
		strcpy($$, "\npre_increment("); strcat($$, $2);  strcat($$, " , ");
		strcat($$, $2); strcat($$, "+1)");
	}
	| DEC_OP unary_expression	
	{	
		////////////////////////////////////////////////////////////////
		// Process statements such as --i;
		////////////////////////////////////////////////////////////////
		strcpy($$, "\npre_decrement("); strcat($$, $2); strcat($$, " , ");
		strcat($$, $2);	strcat($$, "-1)");
	}
	| unary_operator cast_expression
	{
		////////////////////////////////////////////////////////////////
		// Process casting expressions
		////////////////////////////////////////////////////////////////
		strcpy($$, process_cast_unary_rule($1, $2));	// DECL_FUNCTIONS.H
	}
	| SIZEOF unary_expression	
	{
		////////////////////////////////////////////////////////////////
		// Process sizeof statements
		////////////////////////////////////////////////////////////////	
		strcpy($$, "sizeof"); 
		if ($2[0] != '(') 
		{
			strcat($$, "("); strcat($$, $2); strcat($$, ")");
		}
		else
		{
			strcat($$, $2);
		}
	}
	| SIZEOF '(' type_name ')'	
	{	
		////////////////////////////////////////////////////////////////
		// Process sizeof(type) statements
		////////////////////////////////////////////////////////////////	
		strcpy($$, "sizeof"); strcat($$, "("); 
		strcat($$, change_asterisk($3)); 	// DECL_FUNCTIONS.H
		strcat($$, ")");
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

unary_operator
	: '&'	{ strcpy($$, "address_of"); 	}
	| '*'	{ strcpy($$, "dereference"); 	}
	| '+'	{ strcpy($$, "+"); 		}		
	| '-'	{ strcpy($$, "-"); 		}
	| '~'	{ strcpy($$, "~"); 	   	}
	| '!'	{ strcpy($$, "exclamation");	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

cast_expression
	: unary_expression	
	{
		////////////////////////////////////////////////////////////////
		// Surround negative numbers with ( and )
		////////////////////////////////////////////////////////////////	
		if ($1[0] == '-')
		{
			strcpy($$, "("); strcat($$, $1); strcat($$, ")");
		}
		else
		{
			strcpy($$, $1); 
		}
	}	
	| '(' type_name ')' cast_expression	
	{	
		////////////////////////////////////////////////////////////////
		// Process cast expressions
		////////////////////////////////////////////////////////////////	
		strcpy($$, "cast(("); strcat($$, change_asterisk($2)); // DECL_FUNCTIONS.H
		strcat($$, "), "); strcat($$, $4); strcat($$, ")"); 
	}		
	;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

multiplicative_expression
	: cast_expression	
	{strcpy($$, $1); }	
	| multiplicative_expression '*' cast_expression	
	{
		////////////////////////////////////////////////////////////////
		// Process * - change '*' to multiply to avoid confusion with 
		// the pointer dereference '*'		
		////////////////////////////////////////////////////////////////	
		strcpy($$, "multiply("); strcat($$, $1); strcat($$, ", "); 
		strcat($$, $3); strcat($$, ")");				
	}	
	| multiplicative_expression '/' cast_expression	
	{
		strcpy($$, $1); strcat($$, "/"); strcat($$, $3); 
	}
	| multiplicative_expression '%' cast_expression	
	{	
		////////////////////////////////////////////////////////////////
		// Process % - change '%' to modulo to avoid confusion with 
		// the Prolog comments operator '%'		
		////////////////////////////////////////////////////////////////	
		strcpy($$, "mod("); strcat($$, $1); strcat($$, " , "); 
		strcat($$, $3); strcat($$, ")");
	}	
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

additive_expression
	: multiplicative_expression	{strcpy($$, $1); }
	| additive_expression '+' multiplicative_expression	
	{ strcpy($$, $1); strcat($$, "+"); strcat($$, $3);   }	
	| additive_expression '-' multiplicative_expression	
	{ strcpy($$, $1); strcat($$, "-");  strcat($$, $3);   }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

shift_expression
	: additive_expression	{strcpy($$, $1); }
	| shift_expression LEFT_OP additive_expression	{strcpy($$, $1); strcat($$, "<<"); strcat($$, $3); }
	| shift_expression RIGHT_OP additive_expression	{strcpy($$, $1); strcat($$, ">>"); strcat($$, $3); }	
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

relational_expression
	: shift_expression	{strcpy($$, $1); }
	| relational_expression '<' shift_expression	
		{strcpy($$, $1); strcat($$, "<");  strcat($$, $3); }	
	| relational_expression '>' shift_expression	
		{strcpy($$, $1); strcat($$, ">");  strcat($$, $3); }
	| relational_expression LE_OP shift_expression	
		{strcpy($$, $1); strcat($$, "<="); strcat($$, $3); }	
	| relational_expression GE_OP shift_expression  
		{strcpy($$, $1); strcat($$, ">="); strcat($$, $3); }	
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

equality_expression
	: relational_expression		{strcpy($$, $1); }
	| equality_expression EQ_OP relational_expression	
		{strcpy($$, $1); strcat($$, "=="); strcat($$, $3); }	
	| equality_expression NE_OP relational_expression	
		{strcpy($$, $1); strcat($$, "<>"); strcat($$, $3); }	
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

and_expression
	: equality_expression	
	{	strcpy($$, $1); }
	| and_expression '&' equality_expression 	// bitwise AND
	{	strcpy($$, $1); strcat($$, "&"); strcat($$, $3); }	
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

exclusive_or_expression
	: and_expression	{strcpy($$, $1); }
	| exclusive_or_expression '^' and_expression 	// bitwise XOR
	{strcpy($$, $1); strcat($$, "^"); strcat($$, $3); }	
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

inclusive_or_expression
	: exclusive_or_expression	{strcpy($$, $1); }
	| inclusive_or_expression '|' exclusive_or_expression 	// bitwise OR
	{ strcpy($$, $1); strcat($$, "|"); strcat($$, $3);}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

logical_and_expression
	: inclusive_or_expression	{strcpy($$, $1); }
	| logical_and_expression AND_OP inclusive_or_expression	
	{	strcpy($$, "andop(");	strcat($$, $1); 
		strcat($$, " , "); strcat($$, $3); strcat($$, ")");
	}
	;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

logical_or_expression
	: logical_and_expression	{strcpy($$, $1); }
	| logical_or_expression OR_OP logical_and_expression	
	{	strcpy($$, "orop("); strcat($$, $1); 
		strcat($$, " , "); strcat($$, $3); strcat($$, ")"); 
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

conditional_expression
	: logical_or_expression		{ strcpy($$, $1); }
	| logical_or_expression '?' expression ':' conditional_expression
	{ 
		////////////////////////////////////////////////////////////////
		// Process ternary expressions from C to Prolog 		
		////////////////////////////////////////////////////////////////	
		strcpy($$, "ternary("); 
		strcat($$, "expression("); strcat($$, $1); strcat($$, "),");
		strcat($$, "["); strcat($$, $3); strcat($$, "]");
		strcat($$, ", "); strcat($$, "["); strcat($$, $5);
		strcat($$, "]"); strcat($$, ")");
	}
	;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

assignment_expression
	: conditional_expression	{ strcpy($$, $1); }
	| unary_expression assignment_operator assignment_expression 
	{ 		
		strcpy($$, $2); strcat($$, $1); 
		strcat($$, " , "); strcat($$, $3); strcat($$, ")"); 
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

assignment_operator
	: '='		{ strcpy($$, "\nassignment(");      }
	| MUL_ASSIGN	{ strcpy($$, "\nmul_assignment(");  }
	| DIV_ASSIGN	{ strcpy($$, "\ndiv_assignment(");  }
	| MOD_ASSIGN	{ strcpy($$, "\nmod_assignment(");  }
	| ADD_ASSIGN	{ strcpy($$, "\nadd_assignment(");  }
	| SUB_ASSIGN	{ strcpy($$, "\nsub_assignment(");  }
	| LEFT_ASSIGN	{ strcpy($$, "\nleft_assignment("); }
	| RIGHT_ASSIGN	{ strcpy($$, "\nright_assignment(");}
	| AND_ASSIGN	{ strcpy($$, "\nand_assignment(");  }
	| XOR_ASSIGN	{ strcpy($$, "\nxor_assignment(");  }
	| OR_ASSIGN	{ strcpy($$, "\nor_assignment(");   }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

expression
	: assignment_expression		{ strcpy($$, $1); }
	| expression ',' assignment_expression		
	{ 	strcpy($$, "comma("); strcat($$, $1);
		strcat($$, " , "); strcat($$, $3); strcat($$, ")"); 
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

constant_expression
	: conditional_expression	{ strcpy($$, $1); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

declaration
	: declaration_specifiers ';'	
	{ 
		strcpy($$, struct_declaration($1));	// STRUCTURES.H
	}
	| declaration_specifiers init_declarator_list ';' 
	{ 		
		////////////////////////////////////////////////////////////////
		// Process declarations		
		////////////////////////////////////////////////////////////////
		int lenSS;
		strcpy($$, findvariabledetails($1));	// DECL_FUNCTIONS.H
		lenSS = strlen($$) - 1;
		
		if ($$[lenSS] != ',')
			strcat($$, ",");
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

declaration_specifiers
	: storage_class_specifier		
	{ strcpy($$, $1);  }
	| storage_class_specifier declaration_specifiers	
	{ strcpy($$, $1);  strcat($$, $2);}
	| type_specifier	
	{ strcpy($$, $1); }
	| type_specifier declaration_specifiers	  
	{	
		////////////////////////////////////////////////////////////////
		// Only append comma if not a type such as "unsigned int"
		////////////////////////////////////////////////////////////////		
		strcpy($$, $1); 
		if ( (strcmp($1, "signed") == 0) || (strcmp($1, "unsigned") == 0) )
		{
		}
		else if ((strcmp($1, "short") == 0) && (strcmp($2, "int") == 0))
		{			
		}
		else
		{
			strcat($$, ", ");
		}
		strcat($$, $2); 
	} 
	| type_qualifier		
	{strcpy($$, $1); }
	| type_qualifier declaration_specifiers	
	{strcpy($$, $1); strcat($$, $2); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

init_declarator_list
	: init_declarator		
	{ strcpy($$, $1);   }
	| init_declarator_list ',' init_declarator	
	{ strcpy($$, $1); strcat($$, ", "); strcat($$, $3); }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

init_declarator
	: declarator					
	{ 		
		strcpy($$, $1); addvariables($1, NO);	// DECL_FUNCTIONS.H
	}	
	| declarator '=' initializer	
	{ 					
		strcpy($$, $1); addvariabledetails($1, $3);// DECL_FUNCTIONS.H
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

storage_class_specifier
	: TYPEDEF	
	{ 
		strcpy($$, "typedef"); 
		set_typedef_flag();	// TYPEDEF_FUNCTIONS.H
	}
	| EXTERN	{ strcpy($$, ""); }
	| STATIC	{ strcpy($$, ""); }
	| AUTO		{ strcpy($$, ""); }
	| REGISTER	{ strcpy($$, ""); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

type_specifier
	: VOID				{ strcpy($$, "void"); 		}
	| CHAR				{ strcpy($$, "char"); 		}	
	| SHORT				{ strcpy($$, "short"); 		}			
	| INT				{ strcpy($$, "int");  		}	
	| LONG				{ strcpy($$, "long");  	}
	| FLOAT				{ strcpy($$, "floats"); 	}
	| DOUBLE			{ strcpy($$, "double");  	}		
	| SIGNED			{ strcpy($$, "signed"); 	}
	| UNSIGNED			{ strcpy($$, "unsigned"); 	}
	| struct_or_union_specifier 	{ strcpy($$, $1);		}
	| enum_specifier		{ strcpy($$, $1); 		}
	| TYPE_NAME			
	{ 					  
		add_typedefs(change_typedef($1));// TYPEDEF_FUNCTIONS.H					
		strcpy($$, change_typedef($1));	 // TYPEDEF_FUNCTIONS.H
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'	
	{ 	
		////////////////////////////////////////////////////
		// change the structure name.
		char * struct_name;
		struct_name = (char *) malloc(STRING_LIMIT);
		if (islower($2[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");	
		strcat(struct_name, $2);
		
		////////////////////////////////////////////////////
		strcpy($$, $1); strcat($$, ", "); 
		strcat($$, struct_name); strcat($$, ", ");  strcat($$, "["); 
		strcat($$, $4); 
		Pop(); 	// SCOPES.H
		strcat($$, "]");
	}
	| struct_or_union '{' struct_declaration_list '}'  
	{ 
		strcpy($$, $1); strcat($$, ", ["); strcat($$, $3); 
		Pop(); 	// SCOPES.H
		strcat($$, "]");		
	}
	| struct_or_union IDENTIFIER		
	{ 
		////////////////////////////////////////////////////
		// change the structure name.
		char * struct_name;
		struct_name = (char *) malloc(STRING_LIMIT);
		if (islower($2[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");	
		strcat(struct_name, $2);
		
		////////////////////////////////////////////////////		
		strcpy($$, $1); strcat($$, ", "); 
		strcat($$, struct_name); 	
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct_or_union
	: STRUCT	{ strcpy($$, "struct "); }
	| UNION		{ strcpy($$, "union ");  }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct_declaration_list
	: struct_declaration		
	{ strcpy($$, $1); }
	| struct_declaration_list struct_declaration	
	{ strcpy($$, $1); strcat($$, ", "); strcat($$, $2); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'	
	{ 
		/////////////////////////////////////////////////////////////////
		// Many variables declared in $2, they must be separated.		
		if (strstr($2, ",") != NULL) 
		{
			strcpy($$, seperate_fields($1, $2)); // STRUCTURES.H
		}
		else 
		/////////////////////////////////////////////////////////////////
		// Build the structure list, removing the 'struct' keyword if present		
		{	
			strcpy($$, "([");   strcat($$, $2); 
			strcat($$, "], ");  strcpy($1, strip_struct($1));// STRUCTURES.H			
			strcat($$, $1);     strcat($$, ")");
		}
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

specifier_qualifier_list
	: type_specifier specifier_qualifier_list	{ strcpy($$, $1); strcat($$, $2); }	
	| type_specifier	{ strcpy($$, $1);  }			
	| type_qualifier specifier_qualifier_list	{ strcpy($$, $1); strcat($$, $2); }
	| type_qualifier	{ strcpy($$, $1);  }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct_declarator_list
	: struct_declarator	 
	{ 
		$1[0] = convert_tolower($1[0]);  strcpy($$, $1);
	}
	| struct_declarator_list ',' struct_declarator	
	{ 	strcpy($$, $1); strcat($$, ","); 
		$3[0] = convert_tolower($3[0]); strcat($$, $3);
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

struct_declarator
	: declarator	{  strcpy($$, $1); }
	| ':' constant_expression	{ strcpy($$, ":"); strcat($$, $2);}
	| declarator ':' constant_expression   {  strcpy($$, $1); strcat($$, ":"); strcat($$, $3);}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
enum_specifier	
	: ENUM '{' enumerator_list '}'	
	{ 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		
		strcpy($$, "enum , "); strcat($$, "["); strcat($$, $3); 
		Pop(); 			// SCOPES.H
		strcat($$, "]"); 
		reset_enumcounter(); 	// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
	| ENUM IDENTIFIER '{' enumerator_list '}' 
	{ 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Change their name to Prolog equivalent using change_enum()
		// Add the name to NAMES file using printnames()
		// Add the literal to Enum linked list using add_enums()
		// Pop Scope when '}' is parsed and reset enumerations counter
		
		char *enum_name;
		enum_name = (char *) malloc(STRING_LIMIT);
		
		strcpy(enum_name, change_enum($2));	// ENUM_FUNCTIONS.H
		
		strcpy($$, "enum , "); strcat($$, "["); strcat($$, enum_name);		
		strcat($$, "]");       strcat($$, ", ");strcat($$, "["); 
		strcat($$, $4); 
		Pop(); 					// SCOPES.H
		strcat($$, "]"); 
		reset_enumcounter(); 			// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
	| ENUM IDENTIFIER		
	{ 	////////////////////////////////////////////////////////////////
		// Change enum name to Prolog equivalent using change_enum()
		strcpy($$, "enum , "); 		
		strcat($$, change_enum($2));	// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

enumerator_list
	: enumerator				
	{
			strcpy($$, $1); 
	}
	| enumerator_list ',' enumerator	
	{	
		strcpy($$, $1); strcat($$, ", "); strcat($$, $3); 
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

enumerator	
	: IDENTIFIER	
	{ 	////////////////////////////////////////////////////////////////
		/* 	
		Process enumeration literals.
		Change their name to Prolog equivalent using change_enum()
		Add the name to NAMES file using printnames()
		Add the literal to Enum linked list using add_enums()
		*/
		////////////////////////////////////////////////////////////////
		char *enum_name;
		enum_name = (char *) malloc(STRING_LIMIT);		
		strcpy(enum_name, change_enum($1));	// ENUM_FUNCTIONS.H
		strcpy($$, enum_name);
		add_enums($1, -1);			// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	} 
	| IDENTIFIER '=' constant_expression	
	{ 
		////////////////////////////////////////////////////////////////
		/* 
	 	Process enumeration literals with initializations:
		e.g. enum daYs {mon, tues, wed = 20, thurs, fri = 7};
		Change the enum name to Prolog equivalent using change_enum()
		Add the name to NAMES file using printnames()
		Add the literal to Enum linked list using add_enums(), with its enum value.		
		*/
		////////////////////////////////////////////////////////////////		
		char *enum_name;
		int i;
		enum_name = (char *) malloc(STRING_LIMIT);		
		strcpy(enum_name, change_enum($1));	// ENUM_FUNCTIONS.H
		strcpy($$, enum_name);				
		i = atoi($3);				// change string to integer
		add_enums($1, i); 			// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

type_qualifier
	: CONST		{ strcpy($$, "const"); }
	| VOLATILE	{ strcpy($$, "volatile"); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

declarator
	: pointer direct_declarator	
	{ 
		strcpy($$, $1); strcat($$, $2); 
	}
	| direct_declarator		
	{  
		strcpy($$, $1);
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

direct_declarator
	: IDENTIFIER			
	{  strcpy($$, $1); }
	| '(' declarator ')'		
	{ 	
		strcpy($$, "("); strcat($$, $2); strcat($$, ")");
	}
	| direct_declarator '[' constant_expression ']'  
	{ 	
		strcpy($$, $1); strcat($$, "["); strcat($$, $3); strcat($$, "]"); 
	}
	| direct_declarator '[' ']'	
	{ strcpy($$, $1); strcat($$, "["); strcat($$, "]"); }
	| direct_declarator '(' parameter_type_list ')'	
	{ 
		////////////////////////////////////////////////////////////////		
		/* 	function prototypes and definitions come through this rule.
			in order to distinguish them later on from variables we 
			add the string "function_prototype" to $$
			if this is the function defintion this will have to be stripped later.
			if it is the function prototype it is left as it is.
		*/
		////////////////////////////////////////////////////////////////		
		$1[0] = convert_tolower($1[0]);		
		strcpy($$, "function_prototype(");
		strcat($$, $1);	strcat($$, ", "); strcat($$, "[");		
		strcat($$, $3); strcat($$, "]"); strcat($$, ", "); strcat($$, ").");		
	}
	| direct_declarator '(' identifier_list ')'	
	{ 
		strcpy($$, $1); strcat($$, "("); strcat($$, $3); strcat($$, ")"); 
	}
	| direct_declarator '(' ')'		
	{ 
		strcpy($$, $1); strcat($$, "("); strcat($$, ")"); 
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

pointer
	: '*'	
	{ strcpy($$, "*"); 	}
	| '*' type_qualifier_list		
	{ strcpy($$, "*"); strcat($$, $2);  }
	| '*' pointer				
	{ strcpy($$, "*"); strcat($$, $2); }
	| '*' type_qualifier_list pointer	
	{ strcpy($$, "*"); strcat($$, $2); strcat($$, $3);   }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

type_qualifier_list
	: type_qualifier	{ strcpy($$, $1);  }
	| type_qualifier_list type_qualifier	{ strcpy($$, $1); strcat($$, $2);  }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

parameter_type_list
	: parameter_list		
	{ 
		int lenSS = strlen($1) - 1;
		if ($1[lenSS] == ',')	
			$1[lenSS] = ' ';
		strcpy($$, $1); 
	}
	| parameter_list ',' ELLIPSIS	{ strcpy($$, $1); strcat($$, ","); strcat($$, "..."); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

parameter_list
	: parameter_declaration		
	{ 
		strcpy($$, $1);  
	}
	| parameter_list ',' parameter_declaration		
	{ 
		strcpy($$, $1); 
		strcat($$, $3);  
	}	
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

parameter_declaration
	: declaration_specifiers declarator	
	{ 			
		if (PListFirstUse == NO)	// PARAMETERS.H
		{
			PListFirstUse = YES;	// PARAMETERS.H
			P = CreatePList();	// PARAMETERS.H
		}	
		PushPList($2, P);		// PARAMETERS.H
		Push(yylineno);	// SCOPES.H
		addvariables($2, YES);			// DECL_FUNCTIONS.H
		strcpy($$, findvariabledetails($1));	// DECL_FUNCTIONS.H	
	}
	| declaration_specifiers abstract_declarator	
	{ 
		strcpy($$, $1); strcat($$, $2); 
	}
	| declaration_specifiers		
	{ 
		strcpy($$, $1);  
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

identifier_list
	: IDENTIFIER		{ strcpy($$, $1); }
	| identifier_list ',' IDENTIFIER 	{ strcpy($$, $1); strcat($$, ","); strcat($$, $3); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

type_name
	: specifier_qualifier_list		{ strcpy($$, $1);  }
	| specifier_qualifier_list abstract_declarator  { strcpy($$, $1); strcat($$, $2); }
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

abstract_declarator
	: pointer		{ strcpy($$, $1); }	
	| direct_abstract_declarator	{ strcpy($$, $1);  }
	| pointer direct_abstract_declarator	{ strcpy($$, $1); strcat($$, $2); }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

direct_abstract_declarator
	: '(' abstract_declarator ')'	{ strcpy($$, "("); strcat($$, $2); strcat($$, "("); }
	| '[' ']'			{ strcpy($$, "["); strcat($$, "]"); }
	| '[' constant_expression ']'	{ strcpy($$, "["); strcat($$, $2); strcat($$, "]"); }
	| direct_abstract_declarator '[' ']'	{ strcpy($$, $1); strcat($$, "["); strcat($$, "]"); }
	| direct_abstract_declarator '[' constant_expression ']'	{ strcpy($$, $1); strcat($$, "["); strcat($$, $3); strcat($$, "]"); }
	| '(' ')'		{ strcpy($$, "("); strcat($$, ")"); }
	| '(' parameter_type_list ')'	
	{ strcpy($$, "("); strcat($$, $2); strcat($$, ")"); 
	}
	| direct_abstract_declarator '(' ')'	
	{ strcpy($$, $1); strcat($$, "("); strcat($$, ")"); 
	}
	| direct_abstract_declarator '(' parameter_type_list ')'	
	{ strcpy($$, $1); strcat($$, "("); strcat($$, $3); strcat($$, ")"); 	
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

initializer
	: assignment_expression		
	{ 
		strcpy($$, $1); 
	}
	| '{' initializer_list '}'	
	{ 
		strcpy($$, "["); strcat($$, $2); 
		Pop(); 	// SCOPES.H
		strcat($$, "]"); 
	}
	| '{' initializer_list ',' '}'	
	{
		strcpy($$, "{"); strcat($$, $2); strcat($$, ","); 
		Pop(); 	// SCOPES.H
		strcat($$, "}"); 
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

initializer_list
	: initializer	{ strcpy($$, $1); } 
	| initializer_list ',' initializer	
	{ strcpy($$, $1); strcat($$, ","); strcat($$, $3); 	}	
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

statement	
	: labeled_statement	{ strcpy($$, $1); }	
	| compound_statement	{ strcpy($$, $1); }
	| expression_statement	{ strcpy($$, $1); }
	| selection_statement  	{ strcpy($$, $1); }
	| iteration_statement	{ strcpy($$, $1); }
	| jump_statement	{ strcpy($$, $1); }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

labeled_statement
	: IDENTIFIER ':' statement	
	{  
		strcpy($$, $1); strcat($$, ":"); strcat($$, $3);  
	}
	| CASE constant_expression ':' statement 
	{
		strcpy($$, case_statement($2, $4));	// SWITCH_FUNCTIONS.H
	}	
	| DEFAULT ':' statement	
	{ 
		strcpy($$, default_statement($3));  	// SWITCH_FUNCTIONS.H
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

compound_statement
	: '{' '}'					
	{	strcpy($$, "["); 
		Pop(); 	// SCOPES.H
		strcat($$, "]");
	}		
	| '{' statement_list '}'			
	{	
		strcpy($$, "["); strcat($$, $2); 		
		Pop();  	// SCOPES.H
		strcat($$, "]"); 
	}
	| '{' declaration_list '}'			
	{
		int lenS2 = strlen($2) - 1;
		if ($2[lenS2] == ',')
			$2[lenS2] = ' ';		
		strcpy($$, "["); strcat($$, $2); 		
		Pop(); 	 // SCOPES.H
		strcat($$, "\n]"); 
	}
	| '{' declaration_list statement_list '}'	
	{
		strcpy($$, "["); strcat($$, $2); strcat($$, $3); 
		Pop(); 	 // SCOPES.H
		strcat($$, "\n]");  
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

declaration_list
	: declaration			{ strcpy($$, $1); 		  }
	| declaration_list declaration	{ strcpy($$, $1); strcat($$, $2); }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

statement_list
	: statement			{ strcpy($$, $1); }	
	| statement_list statement	{ strcpy($$, $1); strcat($$, ", "); strcat($$, $2);  }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

expression_statement
	: ';'				{ strcpy($$, "null");   }	
	| expression ';'	{ strcpy($$, "expression_statement("); strcat($$, $1); strcat($$, ")");  }
	;					
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

selection_statement
	: IF '(' expression ')' statement 	
	{	
		strcpy($$, if_statement($3, $5)); 	  // IF_FUNCTIONS.H
	}  		
	| IF '(' expression ')' statement ELSE statement  
	{ 	strcpy($$, ifelse_statement($3, $5, $7)); // IF_FUNCTIONS.H
	}
	| SWITCH '(' expression ')' statement	
	{
		strcpy($$, switch_statement($3, $5));	  // SWITCH_FUNCTIONS.H 
	}
	; 
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

iteration_statement	
	: WHILE '(' expression ')' statement	
	{ 	strcpy($$, while_statement($3, $5));	 // ITERATION_FUNCTIONS.H 
	}
	| DO statement WHILE '(' expression ')' ';'	
	{ 	strcpy($$, do_statement($2, $5));	 // ITERATION_FUNCTIONS.H 
	}
	| FOR '(' expression_statement expression_statement ')' statement 
	{	strcpy($$, for2_statement($3, $4, $6));	 // ITERATION_FUNCTIONS.H  
	}
	| FOR '(' expression_statement expression_statement expression ')' statement 
	{	strcpy($$, for_statement($3, $4, $5, $7));// ITERATION_FUNCTIONS.H 
	}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

jump_statement
	: GOTO IDENTIFIER ';'	{strcpy($$, "goto"); strcat($$, $2); strcat($$, ";"); }
	| CONTINUE ';'		{strcpy($$, "continue");  }
	| BREAK ';'		{strcpy($$, "break");    }
	| RETURN ';'		{strcpy($$, "return");  }
	| RETURN expression ';'	{strcpy($$, "return("); strcat($$, $2); strcat($$, ")");}
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

translation_unit
	: external_declaration	{strcpy($$, $1);  }
	| translation_unit external_declaration	 
	{strcpy($$, $1); strcat($$, $2);  }
	;
	
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

external_declaration
	: function_definition	
	{	
		strcpy($$, $1); 
		printfunction($$); 	// OUTPUT_FUNCTIONS.H
	}
	| declaration			
	{	////////////////////////////////////////////////////////////////
		// Global Variable declarations
		////////////////////////////////////////////////////////////////
		int lenS1 = strlen($1) - 1;
		strcpy($$, "\nglobal_variables([");
		if($1[lenS1] == ',')
			$1[lenS1] = ' ';	   
		strcat($$, $1);
		strcat($$, "], void),\n");	   
		printfunction($$);	// OUTPUT_FUNCTIONS.H
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement	 
	{	
		strcpy($$, $1); strcat($$, $2); strcat($$, $3); strcat($$, $4); 
	}
	| declaration_specifiers declarator compound_statement			
	{	
		////////////////////////////////////////////////////////////////
		// Function Defintions
		////////////////////////////////////////////////////////////////
		strcpy($$, process_functions($1, $2, $3));	// DECL_FUNCTIONS.H
	}	
	| declarator declaration_list compound_statement			
	{
		strcpy($$, $1); strcat($$, $2); strcat($$, $3); 
	}
	| declarator compound_statement		
	{  			
		////////////////////////////////////////////////////////////////
		// Function Prototypes
		////////////////////////////////////////////////////////////////		
		strcpy($$, process_prototypes($1, $2));	// DECL_FUNCTIONS.H
	}			
	;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** GRAMMAR FILE ADDITIONAL USER CODE SECTION
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
%%
#include "lex.yy.c"		// include the lexical analyser file

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END GRAMMAR.Y SPECIFICATION FILE
////////////////////////////////////////////////////////////////