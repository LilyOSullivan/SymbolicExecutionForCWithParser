%{

// *** GRAMMAR.Y SPECIFICATION FILE

/*
This is the grammar specification file for the ANSI C programming
language. The original file has been sourced at the following
reference:
	J. Lee. ANSI C Lex and YACC Grammar Files, April 1985.
	FTP: ftp.uu.net, FILE: usenet/net.sources/ansi.c.grammar.Z.

This file is used as the input grammar file of the parser generator
used in the WCET Analysis Tool.
*/

extern void yyerror(const char*);
extern int yychar;

#include "string.h"
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

%union
{
	char *id;
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

primary_expression
	: IDENTIFIER
	{
        $$ = (char*) malloc(STRING_LIMIT);
        strcpy($$, identifier_function($1)); // DECL_FUNCTIONS.H
        free($1);
	}
	| CONSTANT
	{
        $$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, ascii_function($1)); // ASCII_FUNCTIONS.H
		strcpy($$, check_number($1));   // CONVERSION_FUNCTIONS.H
        free($1);
	}
	| STRING_LITERAL
	{
        $$ = (char*) malloc(strlen($1));
		strcpy($$, $1);
        free($1);
	}
	| '(' expression ')'
	{
        $$ = (char*) malloc(strlen($2)+2);
		strcpy($$, "(");
        strcat($$, $2);
        strcat($$, ")");
	}
	;

postfix_expression
	: primary_expression
	{
        $$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
        free($1);
	}
	| postfix_expression '[' expression ']'
	{
        $$ = (char*) malloc(STRING_LIMIT);
		if (strstr($1, "[") != NULL)
		{
			strcpy($$, process_arrays($1, $3)); // ARRAY_FUNCTIONS.H
            free($1);
            free($3);
		}
		else
		{
			strcpy($$, $1);
            strcat($$, "[");
            strcat($$, $3);
            strcat($$, "]");
            free($1);
            free($3);
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
        $$ = (char*) malloc(16 + 3 + STRING_LIMIT + 3 + 1 + 1 + 1);
		strcpy($$, "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat($$, "UC_");
		else
			strcat($$, "LC_");

		strcat($$, func_name);
		strcat($$, ", [");
		strcat($$, "]");
		strcat($$, ")");
        free($1);
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
        $$ = (char*) malloc(16+ 3 + STRING_LIMIT + 3 + strlen($3) + 1 + 1 + 1);
		strcpy($$, "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat($$, "UC_");
		else
			strcat($$, "LC_");

		strcat($$, func_name);
		strcat($$, ", [");
        strcat($$, $3);
        strcat($$, "]");
        strcat($$, ")");
        free($1);
        free($3);
	}
	| postfix_expression '.' IDENTIFIER
	{
		////////////////////////////////////////////////////////////////
		// Process records/structures
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, process_records($1, $3));	// STRUCTURES.H
		free($1);
		free($3);
	}
	| postfix_expression PTR_OP IDENTIFIER
	{
		////////////////////////////////////////////////////////////////
		// Process linked list statements
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(11 + strlen($1) + 2 + strlen($3) + 1 + 1);
		$3[0] = convert_tolower($3[0]);
        strcpy($$, "linkedlist(");
		strcat($$, $1);
        strcat($$, ", ");
        strcat($$, $3);
        strcat($$, ")");
        free($1);
        free($3);
	}
	| postfix_expression INC_OP
	{
		////////////////////////////////////////////////////////////////
		// Process statements such as i++;
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(25+(2*strlen($1))+1);
        // 17 + 1 + 3 + 1 + strlen($1)+3 = 25 + strlen($1)
        // 17 + strlen($1) + 3 + strlen($1) + 3 = 23 + 2*strlen($1)

		strcpy($$, "\npost_increment(");
		if ( (strstr($1, "dereference") != NULL) && ($1[0] != '(') )
		{
			strcat($$, "(");
            strcat($$, $1);
            strcat($$, " , ");
			strcat($$, "(");
            strcat($$, $1);
            strcat($$, "+1)");
            free($1);
		}
		else
		{
			strcat($$, $1);
            strcat($$, " , ");
            strcat($$, $1);
            strcat($$, "+1)");
            free($1);
		}
	}
	| postfix_expression DEC_OP
	{
		////////////////////////////////////////////////////////////////
		// Process statements such as i--;
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(17+strlen($1)+3+strlen($1)+3+1);
		strcpy($$, "\npost_decrement(");
        strcat($$, $1);
		strcat($$, " , ");
        strcat($$, $1);
        strcat($$, "-1)");
        free($1);
	}
	;

argument_expression_list
	: assignment_expression
	{
        $$ = (char*) malloc(strlen($1));
        strcpy($$, $1);
        free($1);
    }
	| argument_expression_list ',' assignment_expression
	{
        $$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
        strcpy($$, $1);
        strcat($$, ",");
        strcat($$, $3);
        free($1);
        free($3);
    }
	;

unary_expression
	: postfix_expression
	{
        $$ = (char*) malloc(strlen($1) + 1);
        strcpy($$, $1);
        free($1);
    }
	| INC_OP unary_expression
	{
		////////////////////////////////////////////////////////////////
		// Process statements such as ++i;
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(16 + strlen($2) + 3 + strlen($2) + 3 + 1);
		strcpy($$, "\npre_increment(");
        strcat($$, $2);
        strcat($$, " , ");
		strcat($$, $2);
        strcat($$, "+1)");
        free($2);
	}
	| DEC_OP unary_expression
	{
		////////////////////////////////////////////////////////////////
		// Process statements such as --i;
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(16 + strlen($2) + 3 + strlen($2) + 3 + 1);
		strcpy($$, "\npre_decrement(");
        strcat($$, $2);
        strcat($$, " , ");
		strcat($$, $2);
        strcat($$, "-1)");
	}
	| unary_operator cast_expression
	{
		////////////////////////////////////////////////////////////////
		// Process casting expressions
		////////////////////////////////////////////////////////////////
        $$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, process_cast_unary_rule($1, $2));	// DECL_FUNCTIONS.H
        free($1);
        free($2);
	}
	| SIZEOF unary_expression
	{
		////////////////////////////////////////////////////////////////
		// Process sizeof statements
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(6+1+strlen($2)+1+1);
		strcpy($$, "sizeof");
		if ($2[0] != '(')
		{
			strcat($$, "("); strcat($$, $2); strcat($$, ")");
		}
		else
		{
			strcat($$, $2);
		}
		free($2);
	}
	| SIZEOF '(' type_name ')'
	{
		////////////////////////////////////////////////////////////////
		// Process sizeof(type) statements
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(6 + 1 + STRING_LIMIT + 1 + 1);
		strcpy($$, "sizeof");
		strcat($$, "(");
		strcat($$, change_asterisk($3)); 	// DECL_FUNCTIONS.H
		strcat($$, ")");
		free($3);
	}
	;

unary_operator
	: '&'
	{
		$$ = (char*) malloc(10+1);
		strcpy($$, "address_of");

	}
	| '*'
	{
		$$ = (char*) malloc(11+1);
		strcpy($$, "dereference");
	}
	| '+'
	{
		$$ = (char*) malloc(1+1);
		strcpy($$, "+");

	}
	| '-'
	{
		$$ = (char*) malloc(1+1);
		strcpy($$, "-");
	}
	| '~'
	{
		$$ = (char*) malloc(1+1);
		strcpy($$, "~");
	}
	| '!'
	{
		$$ = (char*) malloc(11+1);
		strcpy($$, "exclamation");
	}
	;

cast_expression
	: unary_expression
	{
		////////////////////////////////////////////////////////////////
		// Surround negative numbers with ( and )
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(1 + strlen($1) + 1 + 1);
		if ($1[0] == '-')
		{
			strcpy($$, "(");
			strcat($$, $1);
			strcat($$, ")");
		}
		else
		{
			strcpy($$, $1);
		}
		free($1);
	}
	| '(' type_name ')' cast_expression
	{
		////////////////////////////////////////////////////////////////
		// Process cast expressions
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, "cast((");
		strcat($$, change_asterisk($2)); // DECL_FUNCTIONS.H
		strcat($$, "), ");
		strcat($$, $4);
		strcat($$, ")");
		free($2);
		free($4);
	}
	;

multiplicative_expression
	: cast_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| multiplicative_expression '*' cast_expression
	{
		////////////////////////////////////////////////////////////////
		// Process * - change '*' to multiply to avoid confusion with
		// the pointer dereference '*'
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(9 + strlen($1) + 2 + strlen($3) + 1 + 1);
		strcpy($$, "multiply(");
		strcat($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	| multiplicative_expression '/' cast_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "/");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| multiplicative_expression '%' cast_expression
	{
		////////////////////////////////////////////////////////////////
		// Process % - change '%' to modulo to avoid confusion with
		// the Prolog comments operator '%'
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(4 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "mod(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

additive_expression
	: multiplicative_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| additive_expression '+' multiplicative_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "+");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| additive_expression '-' multiplicative_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "-");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

shift_expression
	: additive_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| shift_expression LEFT_OP additive_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<<");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| shift_expression RIGHT_OP additive_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ">>");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

relational_expression
	: shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| relational_expression '<' shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| relational_expression '>' shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ">");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| relational_expression LE_OP shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<=");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| relational_expression GE_OP shift_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ">=");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

equality_expression
	: relational_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| equality_expression EQ_OP relational_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "==");
		strcat($$, $3);
		free($1);
		free($3);
	}
	| equality_expression NE_OP relational_expression
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "<>");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

and_expression
	: equality_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| and_expression '&' equality_expression 	// bitwise AND
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "&");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

exclusive_or_expression
	: and_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| exclusive_or_expression '^' and_expression 	// bitwise XOR
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "^");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

inclusive_or_expression
	: exclusive_or_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| inclusive_or_expression '|' exclusive_or_expression 	// bitwise OR
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, "|");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

logical_and_expression
	: inclusive_or_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| logical_and_expression AND_OP inclusive_or_expression
	{
		$$ = (char*) malloc(6 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "andop(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

logical_or_expression
	: logical_and_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| logical_or_expression OR_OP logical_and_expression
	{
		strcpy($$, "orop(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
	}
	;

conditional_expression
	: logical_or_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| logical_or_expression '?' expression ':' conditional_expression
	{
		////////////////////////////////////////////////////////////////
		// Process ternary expressions from C to Prolog
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(8 + 11 + strlen($1) + 2 + 1 + strlen($3) + 1 + 2 + 1 + strlen($5) + 1 + 1 + 1);
		strcpy($$, "ternary(");
		strcat($$, "expression(");
		strcat($$, $1);
		strcat($$, "),");
		strcat($$, "[");
		strcat($$, $3);
		strcat($$, "]");
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $5);
		strcat($$, "]");
		strcat($$, ")");
		free($1);
		free($3);
		free($5);
	}
	;

assignment_expression
	: conditional_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| unary_expression assignment_operator assignment_expression
	{
		$$ = (char*) malloc(strlen($2)+ strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, $2);
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($2);
		free($3);
	}
	;

assignment_operator
	: '='
	{
		$$ = (char*) malloc(13 + 1);
		strcpy($$, "\nassignment(");
	}
	| MUL_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nmul_assignment(");
	}
	| DIV_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\ndiv_assignment(");
	}
	| MOD_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nmod_assignment(");
	}
	| ADD_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nadd_assignment(");
	}
	| SUB_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nsub_assignment(");
	}
	| LEFT_ASSIGN
	{
		$$ = (char*) malloc(18 + 1);
		strcpy($$, "\nleft_assignment(");
	}
	| RIGHT_ASSIGN
	{
		$$ = (char*) malloc(19 + 1);
		strcpy($$, "\nright_assignment(");
	}
	| AND_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nand_assignment(");
	}
	| XOR_ASSIGN
	{
		$$ = (char*) malloc(17 + 1);
		strcpy($$, "\nxor_assignment(");
	}
	| OR_ASSIGN
	{
		$$ = (char*) malloc(16 + 1);
		strcpy($$, "\nor_assignment(");
	}
	;

expression
	: assignment_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| expression ',' assignment_expression
	{
		$$ = (char*) malloc(6 + strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, "comma(");
		strcat($$, $1);
		strcat($$, " , ");
		strcat($$, $3);
		strcat($$, ")");
	}
	;

constant_expression
	: conditional_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

declaration
	: declaration_specifiers ';'
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, struct_declaration($1));	// STRUCTURES.H
		free($1);
	}
	| declaration_specifiers init_declarator_list ';'
	{
		////////////////////////////////////////////////////////////////
		// Process declarations
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(STRING_LIMIT);
		int lenSS;
		strcpy($$, findvariabledetails($1));	// DECL_FUNCTIONS.H
		lenSS = strlen($$) - 1;

		if ($$[lenSS] != ',')
			strcat($$, ",");
		free($1);
		free($2);
	}
	;

declaration_specifiers
	: storage_class_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| storage_class_specifier declaration_specifiers
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| type_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_specifier declaration_specifiers
	{
		////////////////////////////////////////////////////////////////
		// Only append comma if not a type such as "unsigned int"
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(strlen($1) + 2 + strlen($2) + 1);

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
		free($1);
		free($2);
	}
	| type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_qualifier declaration_specifiers
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
	}
	;

init_declarator_list
	: init_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| init_declarator_list ',' init_declarator
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

init_declarator
	: declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		addvariables($1, NO);	// DECL_FUNCTIONS.H
		free($1);
	}
	| declarator '=' initializer
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		addvariabledetails($1, $3);// DECL_FUNCTIONS.H
	}
	;

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

type_specifier
	: VOID
	{
		$$ = (char*) malloc(5);
		strcpy($$, "void");
	}
	| CHAR
	{
		$$ = (char*) malloc(5);
		strcpy($$, "char");
	}
	| SHORT
	{
		$$ = (char*) malloc(6);
		strcpy($$, "short");
	}
	| INT
	{
		$$ = (char*) malloc(4);
		strcpy($$, "int");
	}
	| LONG
	{
		$$ = (char*) malloc(5);
		strcpy($$, "long");
	}
	| FLOAT
	{
		 $$ = (char*) malloc(6);
		 strcpy($$, "float");
	}
	| DOUBLE
	{
		$$ = (char*) malloc(7);
		strcpy($$, "double");
	}
	| SIGNED
	{
		$$ = (char*) malloc(7);
		strcpy($$, "signed");
	}
	| UNSIGNED
	{
		 $$ = (char*) malloc(9);
		 strcpy($$, "unsigned");
	}
	| struct_or_union_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| enum_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| TYPE_NAME
	{
		$$ = (char*) malloc(STRING_LIMIT);
		add_typedefs(change_typedef($1));// TYPEDEF_FUNCTIONS.H
		strcpy($$, change_typedef($1));	 // TYPEDEF_FUNCTIONS.H
		free($1);
	}
	;

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

		$$ = (char*) malloc(strlen($1) + 2 + strlen(struct_name) + 2 + 1 + strlen($4) + 1 + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, struct_name);
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $4);
		Pop(); 	// SCOPES.H
		strcat($$, "]");
	}
	| struct_or_union '{' struct_declaration_list '}'
	{
		$$ = (char*) malloc(strlen($1) + 3 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, ", [");
		strcat($$, $3);
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
		$$ = (char*) malloc(strlen($1) + 2 + strlen(struct_name) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, struct_name);
	}
	;

struct_or_union
	: STRUCT
	{
		$$ = (char*) malloc(8);
		strcpy($$, "struct ");
	}
	| UNION
	{
		$$ = (char*) malloc(7);
		strcpy($$, "union ");
	}
	;

struct_declaration_list
	: struct_declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| struct_declaration_list struct_declaration
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	{
		$$ = (char*) malloc(2 + strlen($1) + 3 + strlen($2) + 1 + 1);
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
			strcpy($$, "([");
			strcat($$, $2);
			strcat($$, "], ");
			strcpy($1, strip_struct($1));// STRUCTURES.H
			strcat($$, $1);
			strcat($$, ")");
		}
		free($1);
		free($2);
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
	}
	| type_specifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_qualifier specifier_qualifier_list
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

struct_declarator_list
	: struct_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		$1[0] = convert_tolower($1[0]);
		strcpy($$, $1);
		free($1);
	}
	| struct_declarator_list ',' struct_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ",");
		$3[0] = convert_tolower($3[0]);
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

struct_declarator
	: declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| ':' constant_expression
	{
		$$ = (char*) malloc(1 + strlen($2) + 1);
		strcpy($$, ":");
		strcat($$, $2);
		free($2);
	}
	| declarator ':' constant_expression
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ":");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	{ 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		$$ = (char*) malloc(7 + 1 + strlen($3) + 1 + 1);
		strcpy($$, "enum , ");
		strcat($$, "[");
		strcat($$, $3);
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

		$$ = (char*) malloc(7 + 1 + strlen(enum_name) + 1 + 2 + 1 + strlen($4) + 1 + 1);

		strcpy($$, "enum , ");
		strcat($$, "[");
		strcat($$, enum_name);
		strcat($$, "]");
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $4);
		Pop(); 					// SCOPES.H
		strcat($$, "]");
		reset_enumcounter(); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free($2);
		free($4);
		////////////////////////////////////////////////////////////////
	}
	| ENUM IDENTIFIER
	{ 	////////////////////////////////////////////////////////////////
		// Change enum name to Prolog equivalent using change_enum()
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, "enum , ");
		strcat($$, change_enum($2));	// ENUM_FUNCTIONS.H
		free($2);
		////////////////////////////////////////////////////////////////
	}
	;

enumerator_list
	: enumerator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| enumerator_list ',' enumerator
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

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

		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, enum_name);
		add_enums($1, -1);			// ENUM_FUNCTIONS.H

		free(enum_name);
		free($1);
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
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, enum_name);
		i = atoi($3);				// change string to integer
		add_enums($1, i); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free($1);
		free($3);
		////////////////////////////////////////////////////////////////
	}
	;

type_qualifier
	: CONST
	{
		$$ = (char*) malloc(6);
		strcpy($$, "const");
	}
	| VOLATILE
	{
		$$ = (char*) malloc(9);
		strcpy($$, "volatile");
	}
	;

declarator
	: pointer direct_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| direct_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

direct_declarator
	: IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| '(' declarator ')'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	| direct_declarator '[' constant_expression ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, $3);
		strcat($$, "]");
		free($1);
		free($3);
	}
	| direct_declarator '[' ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, "]");
		free($1);
	}
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
		$$ = (char*) malloc(19 + strlen($1) + 2 + 1 + strlen($3) + 1 + 2 + 2 + 1);

		$1[0] = convert_tolower($1[0]);
		strcpy($$, "function_prototype(");
		strcat($$, $1);
		strcat($$, ", ");
		strcat($$, "[");
		strcat($$, $3);
		strcat($$, "]");
		strcat($$, ", ");
		strcat($$, ").");
		free($1);
		free($3);
	}
	| direct_declarator '(' identifier_list ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	| direct_declarator '(' ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, ")");
		free($1);
	}
	;

pointer
	: '*'
	{
		$$ = (char*) malloc(2);
		strcpy($$, "*");
	}
	| '*' type_qualifier_list
	{
		$$ = (char*) malloc(1 + strlen($2) + 1);
		strcpy($$, "*");
		strcat($$, $2);
		free($2);
	}
	| '*' pointer
	{
		$$ = (char*) malloc(1 + strlen($2) + 1);
		strcpy($$, "*");
		strcat($$, $2);
		free($2);
	}
	| '*' type_qualifier_list pointer
	{
		$$ = (char*) malloc(1 + strlen($2) + strlen($3) + 1);
		strcpy($$, "*");
		strcat($$, $2);
		strcat($$, $3);
		free($2);
	}
	;

type_qualifier_list
	: type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| type_qualifier_list type_qualifier
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

parameter_type_list
	: parameter_list
	{
		$$ = (char*) malloc(strlen($1) + 1);
		int lenSS = strlen($1) - 1;
		if ($1[lenSS] == ',')
			$1[lenSS] = ' ';
		strcpy($$, $1);
		free($1);
	}
	| parameter_list ',' ELLIPSIS
	{
		$$ = (char*) malloc(strlen($1) + 1 + 3 + 1);
		strcpy($$, $1);
		strcat($$, ",");
		strcat($$, "...");
		free($1);
	}
	;

parameter_list
	: parameter_declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| parameter_list ',' parameter_declaration
	{
		$$ = (char*) malloc(strlen($1) + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

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
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, findvariabledetails($1));	// DECL_FUNCTIONS.H
		free($1);
		free($2);
	}
	| declaration_specifiers abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	| declaration_specifiers
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

identifier_list
	: IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| identifier_list ',' IDENTIFIER
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ",");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

type_name
	: specifier_qualifier_list
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| specifier_qualifier_list abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

abstract_declarator
	: pointer
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| direct_abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| pointer direct_abstract_declarator
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1);
		strcpy($$, "(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	| '[' ']'
	{
		$$ = (char*) malloc(1 + 1 + 1);
		strcpy($$, "[");
		strcat($$, "]");
	}
	| '[' constant_expression ']'
	{
		strcpy($$, "[");
		strcat($$, $2);
		strcat($$, "]");
		free($2);
	}
	| direct_abstract_declarator '[' ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, "]");
		free($1);
	}
	| direct_abstract_declarator '[' constant_expression ']'
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "[");
		strcat($$, $3);
		strcat($$, "]");
		free($1);
		free($3);
	}
	| '(' ')'
	{
		$$ = (char*) malloc(1 + 1 + 1);
		strcpy($$, "(");
		strcat($$, ")");
	}
	| '(' parameter_type_list ')'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	| direct_abstract_declarator '(' ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, ")");
		free($1);
	}
	| direct_abstract_declarator '(' parameter_type_list ')'
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1 + 1);
		strcpy($$, $1);
		strcat($$, "(");
		strcat($$, $3);
		strcat($$, ")");
		free($1);
		free($3);
	}
	;

initializer
	: assignment_expression
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| '{' initializer_list '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "[");
		strcat($$, $2);
		Pop(); 	// SCOPES.H
		strcat($$, "]");
	}
	| '{' initializer_list ',' '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1 + 1);
		strcpy($$, "{");
		strcat($$, $2);
		strcat($$, ",");
		Pop(); 	// SCOPES.H
		strcat($$, "}");
		free($2);
	}
	;

initializer_list
	: initializer
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| initializer_list ',' initializer
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ",");
		strcat($$, $3);
		free($1);
		free($3);
	}
	;

statement
	: labeled_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| compound_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| expression_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| selection_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| iteration_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| jump_statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	;

labeled_statement
	: IDENTIFIER ':' statement
	{
		$$ = (char*) malloc(strlen($1) + 1 + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, ":");
		strcat($$, $3);
		free($1);
	}
	| CASE constant_expression ':' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, case_statement($2, $4));	// SWITCH_FUNCTIONS.H
		free($2);
		free($4);
	}
	| DEFAULT ':' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, default_statement($3));  	// SWITCH_FUNCTIONS.H
		free($3);
	}
	;

compound_statement
	: '{' '}'
	{
		$$ = (char*) malloc(1 + 1 + 1);
		strcpy($$, "[");
		Pop(); 	// SCOPES.H
		strcat($$, "]");
	}
	| '{' statement_list '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + 1);
		strcpy($$, "[");
		strcat($$, $2);
		Pop();  	// SCOPES.H
		strcat($$, "]");
	}
	| '{' declaration_list '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 3 + 1);
		int lenS2 = strlen($2) - 1;
		if ($2[lenS2] == ',')
			$2[lenS2] = ' ';
		strcpy($$, "[");
		strcat($$, $2);
		Pop(); 	 // SCOPES.H
		strcat($$, "\n]");
		free($2);
	}
	| '{' declaration_list statement_list '}'
	{
		$$ = (char*) malloc(1 + strlen($2) + 1 + strlen($3) + 3 + 1);
		strcpy($$, "[");
		strcat($$, $2);
		strcat($$, $3);
		Pop(); 	 // SCOPES.H
		strcat($$, "\n]");
		free($2);
		free($3);
	}
	;

declaration_list
	: declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| declaration_list declaration
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

statement_list
	: statement
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| statement_list statement
	{
		$$ = (char*) malloc(strlen($1) + 2 + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, ", ");
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

expression_statement
	: ';'
	{
		$$ = (char*) malloc(5);
		strcpy($$, "null");
	}
	| expression ';'
	{
		$$ = (char*) malloc(21 + strlen($1) + 1 + 1);
		strcpy($$, "expression_statement(");
		strcat($$, $1);
		strcat($$, ")");
		free($1);
	}
	;

selection_statement
	: IF '(' expression ')' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, if_statement($3, $5)); 	  // IF_FUNCTIONS.H
		free($3);
		free($5);
	}
	| IF '(' expression ')' statement ELSE statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, ifelse_statement($3, $5, $7)); // IF_FUNCTIONS.H
		free($3);
		free($5);
		free($7);
	}
	| SWITCH '(' expression ')' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, switch_statement($3, $5));	  // SWITCH_FUNCTIONS.H
		free($3);
		free($5);
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, while_statement($3, $5));	 // ITERATION_FUNCTIONS.H
		free($3);
		free($5);
	}
	| DO statement WHILE '(' expression ')' ';'
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, do_statement($2, $5));	 // ITERATION_FUNCTIONS.H
		free($2);
		free($5);
	}
	| FOR '(' expression_statement expression_statement ')' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, for2_statement($3, $4, $6));	 // ITERATION_FUNCTIONS.H
		free($3);
		free($4);
		free($6);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement
	{
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, for_statement($3, $4, $5, $7));// ITERATION_FUNCTIONS.H
		free($3);
		free($4);
		free($5);
		free($7);
	}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{
		$$ = (char*) malloc(4 + strlen($2) + 1 + 1);
		strcpy($$, "goto");
		strcat($$, $2);
		strcat($$, ";");
		free($2);
	}
	| CONTINUE ';'
	{
		$$ = (char*) malloc(9);
		strcpy($$, "continue");
	}
	| BREAK ';'
	{
		$$ = (char*) malloc(6);
		strcpy($$, "break");
	}
	| RETURN ';'
	{
		$$ = (char*) malloc(7);
		strcpy($$, "return");
	}
	| RETURN expression ';'
	{
		$$ = (char*) malloc(7 + strlen($2) + 1 + 1);
		strcpy($$, "return(");
		strcat($$, $2);
		strcat($$, ")");
		free($2);
	}
	;

translation_unit
	: external_declaration
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		free($1);
	}
	| translation_unit external_declaration
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		free($1);
		free($2);
	}
	;

external_declaration
	: function_definition
	{
		$$ = (char*) malloc(strlen($1) + 1);
		strcpy($$, $1);
		printfunction($$); 	// OUTPUT_FUNCTIONS.H
		free($1);
	}
	| declaration
	{	////////////////////////////////////////////////////////////////
		// Global Variable declarations
		////////////////////////////////////////////////////////////////
		int lenS1 = strlen($1) - 1;
		$$ = (char*) malloc(20 + strlen($1) + 11 + 1);
		strcpy($$, "\nglobal_variables([");
		if($1[lenS1] == ',')
			$1[lenS1] = ' ';

		strcat($$, $1);
		strcat($$, "], void),\n");
		printfunction($$);	// OUTPUT_FUNCTIONS.H
		free($1);
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + strlen($3) + strlen($4) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		strcat($$, $3);
		strcat($$, $4);
		free($1);
		free($2);
		free($3);
		free($4);
	}
	| declaration_specifiers declarator compound_statement
	{
		////////////////////////////////////////////////////////////////
		// Function Defintions
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, process_functions($1, $2, $3));	// DECL_FUNCTIONS.H
		free($1);
		free($2);
		free($3);
	}
	| declarator declaration_list compound_statement
	{
		$$ = (char*) malloc(strlen($1) + strlen($2) + strlen($3) + 1);
		strcpy($$, $1);
		strcat($$, $2);
		strcat($$, $3);
		free($1);
		free($2);
		free($3);
	}
	| declarator compound_statement
	{
		////////////////////////////////////////////////////////////////
		// Function Prototypes
		////////////////////////////////////////////////////////////////
		$$ = (char*) malloc(STRING_LIMIT);
		strcpy($$, process_prototypes($1, $2));	// DECL_FUNCTIONS.H
		free($1);
		free($2);
	}
	;

%%
#include "lex.yy.c"		// include the lexical analyser file
