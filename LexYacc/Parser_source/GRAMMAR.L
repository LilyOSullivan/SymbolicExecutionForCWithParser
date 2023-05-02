%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

%option yylineno
extern char yytext[];

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{
/* https://www.quut.com/c/ANSI-C-grammar-l-2011.html */
#include <stdio.h>

extern void yyerror(const char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

static void comment(void);
// static int check_type(void);

void count(void);
void AddToScopeList(void);
void discard(void);
int check_type(char var[]);
%}

%%
"/*"                    { comment(); }
"//".*                  { discard(); }
"__pragma".*            { discard(); }

"auto"					{ count(); return(AUTO); }
"break"					{ count(); return(BREAK); }
"case"					{   count();
                            if (CaseListUsed == NO)
                            {
                                Case = CreateList();	// LINKEDLISTS.H
                                CaseListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Case);	// LINKEDLISTS.H
                            return(CASE);
                        }
"char"					{ count(); return(CHAR); }
"const"					{ count(); return(CONST); }
"continue"				{ count(); return(CONTINUE); }
"default"				{   count();
                            if (DefaultListUsed == NO)
                            {
                                Default = CreateList();	// LINKEDLISTS.H
                                DefaultListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Default);	// LINKEDLISTS.H
                            return(DEFAULT);
                        }
"do"			        {   count();
                            if (DoListUsed == NO)
                            {
                                Do = CreateList();	// LINKEDLISTS.H
                                DoListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Do);	// LINKEDLISTS.H
                            return(DO);
                        }
"double"				{ count(); return(DOUBLE); }
"else"					{ count(); return(ELSE); }
"enum"					{ count(); return(ENUM); }
"extern"				{ count(); return(EXTERN); }
"float"					{ count(); return(FLOAT); }
"for"			        {   count();
                            if (ForListUsed == NO)
                            {
                                For = CreateList();	// LINKEDLISTS.H
                                ForListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, For);	// LINKEDLISTS.H
                            return(FOR);
                        }
"goto"					{ count(); return(GOTO); }
"if"			        {   count();
                            if (IfListUsed == NO)
                            {
                                If = CreateList();	// LINKEDLISTS.H
                                IfListUsed = YES;	// LINKEDLISTS.H
                            }
                            IfEnded++;
                            PushList(yylineno, If);	// LINKEDLISTS.H
                            return(IF);
                        }
"inline"				{ count(); return(INLINE); }
"__inline__"			{ count(); return(INLINE); }
"__declspec"			{ count(); return(DECLSPEC); }
"int"					{ count(); return(INT); }
"__int8"				{ count(); return(__INT8); }
"__int16"				{ count(); return(__INT16); }
"__int32"				{ count(); return(__INT32); }
"__int64"				{ count(); return(__INT64); }
"__cdecl"               { count(); return (__CDECL); }
"__clrcall"             { count(); return (__CLRCALL); }
"__stdcall"             { count(); return (__STDCALL); }
"__fastcall"            { count(); return (__FASTCALL); }
"__thiscall"            { count(); return (__THISCALL); }
"__vectorcall"          { count(); return (__VECTORCALL); }
"long"					{ count(); return(LONG); }
"register"				{ count(); return(REGISTER); }
"restrict"				{ count(); return(RESTRICT); }
"return"				{ count(); return(RETURN); }
"short"					{ count(); return(SHORT); }
"signed"				{ count(); return(SIGNED); }
"sizeof"				{ count(); return(SIZEOF); }
"static"				{ count(); return(STATIC); }
"struct"				{ count(); return(STRUCT); }
"switch"		        {   count();
                            if (SwitchListUsed == NO)
                            {
                                Switch = CreateList();	// LINKEDLISTS.H
                                SwitchListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Switch);	// LINKEDLISTS.H
                            return(SWITCH);
                        }
"typedef"				{ count(); return(TYPEDEF); }
"union"					{ count(); return(UNION); }
"unsigned"				{ count(); return(UNSIGNED); }
"void"					{ count(); return(VOID); }
"volatile"				{ count(); return(VOLATILE); }
"while"			        {   count();
                            if (WhileListUsed == NO)
                            {
                                While = CreateList();	// LINKEDLISTS.H
                                WhileListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, While);	// LINKEDLISTS.H
                            return(WHILE);
                        }
"_Alignas"              { count(); return ALIGNAS; }
"_Alignof"              { count(); return ALIGNOF; }
"_Atomic"               { count(); return ATOMIC; }
"_Bool"                 { count(); return BOOL; }
"_Complex"              { count(); return COMPLEX; }
"_Generic"              { count(); return GENERIC; }
"_Imaginary"            { count(); return IMAGINARY; }
"_Noreturn"             { count(); return NORETURN; }
"_Static_assert"        { count(); return STATIC_ASSERT; }
"_Thread_local"         { count(); return THREAD_LOCAL; }
"__func__"              { count(); return FUNC_NAME; }

{L}{A}*					{ count(); return check_type(yytext); }

{HP}{H}+{IS}?				{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }
{NZ}{D}*{IS}?				{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }
"0"{O}*{IS}?				{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }

{D}+{E}{FS}?				{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{D}+"."{E}?{FS}?			{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ count(); yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return STRING_LITERAL; }

"#"			            { count(); discard(); 	 }
"#include"		        { discard();  }

"..."					{ count(); return ELLIPSIS; }
">>="					{ count(); return RIGHT_ASSIGN; }
"<<="					{ count(); return LEFT_ASSIGN; }
"+="					{ count(); return ADD_ASSIGN; }
"-="					{ count(); return SUB_ASSIGN; }
"*="					{ count(); return MUL_ASSIGN; }
"/="					{ count(); return DIV_ASSIGN; }
"%="					{ count(); return MOD_ASSIGN; }
"&="					{ count(); return AND_ASSIGN; }
"^="					{ count(); return XOR_ASSIGN; }
"|="					{ count(); return OR_ASSIGN; }
">>"					{ count(); return RIGHT_OP; }
"<<"					{ count(); return LEFT_OP; }
"++"					{ count(); return INC_OP; }
"--"					{ count(); return DEC_OP; }
"->"					{ count(); return PTR_OP; }
"&&"					{ count(); return AND_OP; }
"||"					{ count(); return OR_OP; }
"<="					{ count(); return LE_OP; }
">="					{ count(); return GE_OP; }
"=="					{ count(); return EQ_OP; }
"!="					{ count(); return NE_OP; }
";"					    { count(); return ';'; }
("{"|"<%")				{ count();
                            Push(yylineno);	// SCOPES.H
                            AddToScopeList();	// GRAMMAR.L
                            return('{');
                        }
("}"|"%>")				{ count(); return '}'; }
","					    { count(); return ','; }
":"					    { count(); return ':'; }
"="					    { count(); return '='; }
"("					    { count(); return '('; }
")"					    { count(); return ')'; }
("["|"<:")				{ count(); return '['; }
("]"|":>")				{ count(); return ']'; }
"."					    { count(); return '.'; }
"&"					    { count(); return '&'; }
"!"					    { count(); return '!'; }
"~"					    { count(); return '~'; }
"-"					    { count(); return '-'; }
"+"					    { count(); return '+'; }
"*"					    { count(); return '*'; }
"/"					    { count(); return '/'; }
"%"					    { count(); return '%'; }
"<"					    { count(); return '<'; }
">"					    { count(); return '>'; }
"^"					    { count(); return '^'; }
"|"					    { count(); return '|'; }
"?"					    { count(); return '?'; }

{WS}+					{ count(); }
.					{ /* discard bad characters */ }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
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
    char * typename;
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
	if (traverse_types(typename) == YES)
	{
		yylval.id = malloc(strlen(yytext)+1);
		strcpy(yylval.id, yytext);
		return TYPEDEF_NAME;
	}
	else
	{
		yylval.id = malloc(strlen(yytext)+1);
		strcpy(yylval.id, yytext);
		return IDENTIFIER;
	}
}