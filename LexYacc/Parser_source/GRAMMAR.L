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

void AddToScopeList(void);
void discard(void);
int check_type(char var[]);
%}

%%
"/*"                    { comment(); }
"//".*                  { discard(); }
"__pragma".*            { discard(); }

"auto"					{  return(AUTO); }
"break"					{  return(BREAK); }
"case"					{
                            if (CaseListUsed == NO)
                            {
                                Case = CreateList();	// LINKEDLISTS.H
                                CaseListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Case);	// LINKEDLISTS.H
                            return(CASE);
                        }
"char"					{  return(CHAR); }
"wchar_t"				{  return(WCHAR_T); }
"const"					{  return(CONST); }
"continue"				{  return(CONTINUE); }
"default"				{
                            if (DefaultListUsed == NO)
                            {
                                Default = CreateList();	// LINKEDLISTS.H
                                DefaultListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Default);	// LINKEDLISTS.H
                            return(DEFAULT);
                        }
"do"			        {
                            if (DoListUsed == NO)
                            {
                                Do = CreateList();	// LINKEDLISTS.H
                                DoListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Do);	// LINKEDLISTS.H
                            return(DO);
                        }
"double"				{  return(DOUBLE); }
"else"					{  return(ELSE); }
"enum"					{  return(ENUM); }
"extern"				{  return(EXTERN); }
"float"					{  return(FLOAT); }
"for"			        {
                            if (ForListUsed == NO)
                            {
                                For = CreateList();	// LINKEDLISTS.H
                                ForListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, For);	// LINKEDLISTS.H
                            return(FOR);
                        }
"goto"					{  return(GOTO); }
"if"			        {
                            if (IfListUsed == NO)
                            {
                                If = CreateList();	// LINKEDLISTS.H
                                IfListUsed = YES;	// LINKEDLISTS.H
                            }
                            IfEnded++;
                            PushList(yylineno, If);	// LINKEDLISTS.H
                            return(IF);
                        }
"inline"				{  return(INLINE); }
"__forceinline"			{  return(FORCEINLINE); }
"__inline"				{  return(INLINE); }
"__inline__"			{  return(INLINE); }
"__declspec"			{  return(DECLSPEC); }
"int"					{  return(INT); }
"__int8"				{  return(__INT8); }
"__int16"				{  return(__INT16); }
"__int32"				{  return(__INT32); }
"__int64"				{  return(__INT64); }
"__ptr32"               {  return(__PTR32); }
"__ptr64"               {  return(__PTR64); }
"__cdecl"               {  return (__CDECL); }
"__clrcall"             {  return (__CLRCALL); }
"__stdcall"             {  return (__STDCALL); }
"__fastcall"            {  return (__FASTCALL); }
"__thiscall"            {  return (__THISCALL); }
"__vectorcall"          {  return (__VECTORCALL); }
"long"					{  return(LONG); }
"register"				{  return(REGISTER); }
"restrict"				{  return(RESTRICT); }
"return"				{  return(RETURN); }
"short"					{  return(SHORT); }
"signed"				{  return(SIGNED); }
"sizeof"				{  return(SIZEOF); }
"static"				{  return(STATIC); }
"struct"				{  struct_flag = YES; return(STRUCT); }
"switch"		        {
                            if (SwitchListUsed == NO)
                            {
                                Switch = CreateList();	// LINKEDLISTS.H
                                SwitchListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, Switch);	// LINKEDLISTS.H
                            return(SWITCH);
                        }
"typedef"				{  return(TYPEDEF); }
"union"					{  return(UNION); }
"unsigned"				{  return(UNSIGNED); }
"void"					{  return(VOID); }
"volatile"				{  return(VOLATILE); }
"while"			        {
                            if (WhileListUsed == NO)
                            {
                                While = CreateList();	// LINKEDLISTS.H
                                WhileListUsed = YES;	// LINKEDLISTS.H
                            }
                            PushList(yylineno, While);	// LINKEDLISTS.H
                            return(WHILE);
                        }
"align"                 {  return ALIGN; }
"_Alignas"              {  return ALIGNAS; }
"_Alignof"              {  return ALIGNOF; }
"__alignof"             {  return ALIGNOF; }
"__unaligned"           {  return __UNALIGNED; }
"_Atomic"               {  return ATOMIC; }
"_Bool"                 {  return BOOL; }
"_Complex"              {  return COMPLEX; }
"_Generic"              {  return GENERIC; }
"_Imaginary"            {  return IMAGINARY; }
"_Noreturn"             {  return NORETURN; }
"_Static_assert"        {  return STATIC_ASSERT; }
"_Thread_local"         {  return THREAD_LOCAL; }
"__func__"              {  return FUNC_NAME; }

{L}{A}*					{  return check_type(yytext); }

{HP}{H}+{IS}?				{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }
{NZ}{D}*{IS}?				{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }
"0"{O}*{IS}?				{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return I_CONSTANT; }

{D}+{E}{FS}?				{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{D}+"."{E}?{FS}?			{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{  yylval.id = malloc(strlen(yytext)+1); strcpy(yylval.id, yytext); return STRING_LITERAL; }

"#"			            {  discard(); 	 }
"#include"		        { discard();  }

"..."					{  return ELLIPSIS; }
">>="					{  return RIGHT_ASSIGN; }
"<<="					{  return LEFT_ASSIGN; }
"+="					{  return ADD_ASSIGN; }
"-="					{  return SUB_ASSIGN; }
"*="					{  return MUL_ASSIGN; }
"/="					{  return DIV_ASSIGN; }
"%="					{  return MOD_ASSIGN; }
"&="					{  return AND_ASSIGN; }
"^="					{  return XOR_ASSIGN; }
"|="					{  return OR_ASSIGN; }
">>"					{  return RIGHT_OP; }
"<<"					{  return LEFT_OP; }
"++"					{  return INC_OP; }
"--"					{  return DEC_OP; }
"->"					{  return PTR_OP; }
"&&"					{  return AND_OP; }
"||"					{  return OR_OP; }
"<="					{  return LE_OP; }
">="					{  return GE_OP; }
"=="					{  return EQ_OP; }
"!="					{  return NE_OP; }
";"					    {  return ';'; }
("{"|"<%")				{
                            struct_flag = NO;
                            Push(yylineno);	// SCOPES.H
                            AddToScopeList();	// GRAMMAR.L
                            return('{');
                        }
("}"|"%>")				{  return '}'; }
","					    {  return ','; }
":"					    {  return ':'; }
"="					    {  return '='; }
"("					    {  return '('; }
")"					    {  return ')'; }
("["|"<:")				{  return '['; }
("]"|":>")				{  return ']'; }
"."					    {  return '.'; }
"&"					    {  return '&'; }
"!"					    {  return '!'; }
"~"					    {  return '~'; }
"-"					    {  return '-'; }
"+"					    {  return '+'; }
"*"					    {  return '*'; }
"/"					    {  return '/'; }
"%"					    {  return '%'; }
"<"					    {  return '<'; }
">"					    {  return '>'; }
"^"					    {  return '^'; }
"|"					    {  return '|'; }
"?"					    {  return '?'; }

{WS}+					{  }
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

	int linenumber;	// find the line number 'varname' is in
	int param;	// is varname a parameter variable

	/* allocate space to the string variables used */

	if (PListFirstUse == YES)		   // PARAMETERS.H
	{
		while( !IsEmptyPList(P) )	   // PARAMETERS.H
		{
            char* varname = PopPList(P); // PARAMETERS.H

			/* search for varname in Stack - if already there + param is YES */
			/* amend it at this scope to avoid it being confused for the same */
			/* variable as it belongs to another scope */
			linenumber =  ScopeSearch(varname);	/* SCOPES.H */
			param = ParameterSearch(varname);	/* SCOPES.H */

			if(linenumber == 0 && param == 1)
				AmendVar(varname, param);	/* SCOPES.H */
			PushVar(varname, YES);			/* SCOPES.H */
            free(varname);
		}
		DisposePList(P);		   /* PARAMETERS.H */
		PListFirstUse = NO;		   /* PARAMETERS.H */
	}
}

void discard(void)
{
    /*
        This removes any lines beginning with the character '#'
        from the underlying C code file. Lines beginning with '#' may
        denote preprocessor #line directives, or comments, which do
        not have to be analysed.
    */

	char c;
	while ((c = (char)(input())) != '\n' && c != 0)	;
}

int check_type(char var[])
{
    char* typename = (char *) malloc(3 + strlen(var) + 1);
	/* Change var to its typename equivalent */
	if (isupper(var[0]))
		strcpy(typename, "uc_");
	else
		strcpy(typename, "lc_");
	strcat(typename, var);

    yylval.id = (char*) malloc(strlen(yytext)+1);
	strcpy(yylval.id, yytext);

	/*
        Search the Typedef Linked list for instance of 'typename'
	    using functions defined in TYPEDEF_FUNCTIONS.H
	    If 'typename' is present, return the TYPE_NAME token,
	    Otherwise, return the IDENTIFIER token.
	*/


	if (traverse_types(typename) == YES)
	{
        if(struct_flag == YES) {
            struct_flag = NO;
            free(typename);
        	return IDENTIFIER;
        }
   
        free(typename);
		return TYPEDEF_NAME;
	}
	else
	{
        free(typename);
		return IDENTIFIER;
	}
}