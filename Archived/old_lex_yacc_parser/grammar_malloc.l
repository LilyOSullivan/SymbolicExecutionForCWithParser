/*                                                            */
/*                                                            */
/*                GRAMMAR.L SPECIFICATION FILE                */
/*                                                            */
/*                                                            */
/*
This is the grammar specification file for the ANSI C programming
language. The original file has been sourced at the following
reference:
	J. Lee. ANSI C Lex and YACC Grammar Files, April 1985.
	FTP: ftp.uu.net, FILE: usenet/net.sources/ansi.c.grammar.Z.

This file is used as the input grammar file of the lexical analyser
generator used in the WCET Analysis Tool.
*/


/* using yylineno to elicit line number at which certain tokens are parsed */
%option yylineno
extern char yytext[];	/* using yytext to return certain tokens */

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
/* definitions used in pattern matching routines defined in original grammar file */

%{
/* FUNCTION PROTOTYPES */
void AddToScopeList(void);
void cplus_comment(void);
void count(void);
void discard(void);
void my_include(void);
void comment(void);
int check_type(char var[]);
%}
%%

"/*"			{ comment(); }
"//"			{ cplus_comment();}
"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count();
			  if (CaseListUsed == NO)
			  {
				Case = CreateList();	// LINKEDLISTS.H
				CaseListUsed = YES;	// LINKEDLISTS.H
			  }
			  PushList(yylineno, Case);	// LINKEDLISTS.H
			  return(CASE);
			}
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count();
			  if (DefaultListUsed == NO)
			  {
				Default = CreateList();	// LINKEDLISTS.H
				DefaultListUsed = YES;	// LINKEDLISTS.H
			  }
			  PushList(yylineno, Default);	// LINKEDLISTS.H
			  return(DEFAULT);
			}
"do"			{ count();
			  if (DoListUsed == NO)
			  {
				Do = CreateList();	// LINKEDLISTS.H
				DoListUsed = YES;	// LINKEDLISTS.H
			  }
			  PushList(yylineno, Do);	// LINKEDLISTS.H
			  return(DO);
			}
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"float"			{ count(); return(FLOAT); }
"for"			{ count();
			  if (ForListUsed == NO)
			  {
				For = CreateList();	// LINKEDLISTS.H
				ForListUsed = YES;	// LINKEDLISTS.H
			  }
			  PushList(yylineno, For);	// LINKEDLISTS.H
			  return(FOR);
			}
"goto"			{ count(); return(GOTO); }
"if"			{ count();
			  if (IfListUsed == NO)
			  {
				If = CreateList();	// LINKEDLISTS.H
				IfListUsed = YES;	// LINKEDLISTS.H
			  }
			  IfEnded++;
			  PushList(yylineno, If);	// LINKEDLISTS.H
			  return(IF);
			}
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count();
			  if (SwitchListUsed == NO)
			  {
				Switch = CreateList();	// LINKEDLISTS.H
				SwitchListUsed = YES;	// LINKEDLISTS.H
			  }
			  PushList(yylineno, Switch);	// LINKEDLISTS.H
			  return(SWITCH);
			}
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count();
			  if (WhileListUsed == NO)
			  {
				While = CreateList();	// LINKEDLISTS.H
				WhileListUsed = YES;	// LINKEDLISTS.H
			  }
			  PushList(yylineno, While);	// LINKEDLISTS.H
			  return(WHILE);
			}

{L}({L}|{D})*		{ count(); return(check_type(yytext)); }
0[xX]{H}+{IS}?		{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
0{D}+{IS}?		{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
{D}+{IS}?		{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
{D}+{E}{FS}?		{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(CONSTANT); }
L?\"(\\.|[^\\"])*\"	{ count(); yylval.id = malloc(strlen(yytext)+1);strcpy(yylval.id, yytext);  return(STRING_LITERAL); }

"#"			{ count(); discard(); 	 }
"#include"		{ my_include();  }
"\n"			{  }
"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count();
			  Push(yylineno);	// SCOPES.H
			  AddToScopeList();	// GRAMMAR.L
			  return('{');
			}
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }
[ \t\v\n\f]		{ count(); }
.			{ } // ignore bad characters

%%

int yywrap()
{
	return(1);
}

void AddToScopeList(void)
{
/*
This function is user-defined & not available in original grammar file.
This function is called when '{' is parsed.
A new linked list for scopes is created and then this function is called.
If enteries have been added to the Parameters linked list these need to be
added to the new Scopes linked list just created and the parameter linked
list must be freed. This is to ensure that parameters are added to the
correct scope in the linked list.
*/

	/* variable declarations */
	char * varname;	// name of the variable
	int linenumber;	// find the line number 'varname' is in
	int param;	// is varname a parameter variable

	/* allocate space to the string variables used */
	varname = (char *) malloc(STRING_LIMIT);

	if (PListFirstUse == YES)		   // PARAMETERS.H
	{
		while( !IsEmptyPList(P) )	   // PARAMETERS.H
		{
			strcpy(varname, PopPList(P));	// PARAMETERS.H

			/* search for varname in Stack - if already there + param is YES */
			/* amend it at this scope to avoid it being confused for the same */
			/* variable as it belongs to another scope */
			linenumber =  ScopeSearch(varname);	/* SCOPES.H */
			param = ParameterSearch(varname);	/* SCOPES.H */

			if(linenumber == 0 && param == 1)
				AmendVar(varname, param);	/* SCOPES.H */
			PushVar(varname, YES);			/* SCOPES.H */
		}
		DisposePList(P);		   /* PARAMETERS.H */
		PListFirstUse = NO;		   /* PARAMETERS.H */
	}
}

void comment(void)
{
/*
 Comment Function - defined in original grammar file
 Unchanged here.
 This file removes any code provided as user comments in the
 underlying C code file, and writes it to standard output.
 It is not analysed.
*/
	char c, c1;
loop:
	while ((c = (char)(input())) != '*' && c != 0)
		putchar(c);
	if ((c1 = (char)(input())) != '/' && c != 0)
	{
		goto loop;
	}
	if (c != 0)
		putchar(c1);
}


void cplus_comment(void)
{
/*
 Cplus_comment Function.
 This file removes any code provided as user C++ comments in the
 underlying C code file, and writes it to standard output.
 It is not analysed.
*/
	char c;
	while ((c = (char)(input())) != '\n' && c != 0)	;
}

void discard(void)
{
/*
  Discard Function.
 This file removes any lines beginning with the character '#'
 from the underlying C code file. Lines beginning with '#' may
 denote preprocessor #line directives, or comments, which do
 not have to be analysed.
*/
	char c;
	while ((c = (char)(input())) != '\n' && c != 0)	;
}

void my_include(void)
{
/*
 My_include Function.
 This file removes any lines beginning with the character '#include'
 from the underlying C code file. Lines beginning with '#include'
 denote files that are being included into the underlying C code.
 These should be removed during preprocessing. However, if they
 could not be, for example if the header file does not exist,
 they are removed here and not analysed further.
*/
	char c;
	while ((c = (char)(input())) != '\n' && c != 0)	;
}

int column = 0;

void count(void)
{
/*
 Count Function - defined in original grammar file
 Unchanged here.
 This file maintains the tabs and spacing set in the underlying
 C code being analysed.
*/
	int i;
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

}

int check_type(char var[])
{
/*
This function is called from the following place in GRAMMAR.L:
	{L}({L}|{D})*
It will distinguish whether that sequence of characters (in 'var')
represents an IDENTIFIER or a TYPE_NAME and return the appropriate token.

'var' is TYPE_NAME if typedef_flag is 1, which means that the token "typedef"
has been parsed immediately before seeing var.
OR
'var' is TYPE_NAME if the linked list of typedefs contains a typedef of
the same name as var..this is found out by calling the function:
	int traverse_types(char typedefname[])
which is in typedef.h
Otherwise, var is IDENTIFIER and this is the token returned by this
function.

Also, if a TYPE_NAME is returned, the first letter of such is
converted to lower case - typedef names in Prolog must be in lowercase;
if IDENTIFIER is returned, the first letter of such is
converted to upper case - variable names in Prolog must be in uppercase.
*/

	/* variable declarations	*/
	char * typename;
	/* allocate space to the string variables used */
	typename = (char *) malloc(STRING_LIMIT);
	/* Change var to its typename equivalent */
	if (isupper(var[0]))
		strcpy(typename, "uc_");
	else
		strcpy(typename, "lc_");
	strcat(typename, var);

	/* Search the Typedef Linked list for instance of 'typename'
	   using functions defined in TYPEDEF_FUNCTIONS.H
	   If 'typename' is present, return the TYPE_NAME token,
	   Otherwise, return the IDENTIFIER token.
	*/
	if ( (typedef_flag == YES) || (traverse_types(typename) == YES) )
	{
		if (typedef_flag == YES)
			typedef_flag = NO;
		yylval.id = malloc(strlen(yytext)+1);
		strcpy(yylval.id, yytext);
		return TYPE_NAME;
	}
	else
	{
		yylval.id = malloc(strlen(yytext)+1);
		strcpy(yylval.id, yytext);
		return IDENTIFIER;
	}
}
