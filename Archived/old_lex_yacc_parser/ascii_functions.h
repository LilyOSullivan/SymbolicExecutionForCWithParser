////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- ASCII_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
The main function in this header program:
	char * ascii_function(char inputconstant[]);
is called from the following place in the Grammar.y file:
	primary_expression
		: IDENTIFIER
		| CONSTANT		--- CALL ascii_function();
		| STRING_LITERAL
		| '(' expression ')'
		;
This function will call the appropriate function, declared in this header file,
to convert characters to their decimal (ascii) equivalent and return this number
as a string so that it can be appended to pseudo-variable $$.


The ASCII Values used are taken from the ASCII table in the following book:
Title:		"C: A Reference Manual" (Fifth Edition)
By:			Samuel P. Harbison & Guy L. Steele Jr.
ISBN: 		0-13-089592-X
Publisher:	Pearson Education Prentice Hall 2002

The table is as follows:

DECIMAL (ASCII)		CHAR	NAME	OTHER		HEX		OCTAL
*************************************************************
	0				^@		NUL					0		0
	1				^A		SOH					1		1
	2				^B		STX					2		2
	3				^C		ETX					3		3
	4				^D		EOT					4		4
	5				^E		ENQ					5		5
	6				^F		ACK					6		6
	7				^G		BEL		\a			7		7
	8				^H		BS		\b			8		010
	9				^I		TAB		\t			9		011
	10				^J		LF		\n			0xA		012
	11				^K		VT		\v			0xB		013
	12				^L		FF		\f			0xC		014
	13				^M		CR		\r			0xD		015
	14				^N		SO					0xE		016
	15				^O		SI					0xF		017
	16				^P		DLE					0x10	020
	17				^Q		DC1					0x11	021
	18				^R		DC2					0x12	022
	19				^S		DC3					0x13	023
	20				^T		DC4					0x14	024
	21				^U		NAK					0x15	025
	22				^V		SYN					0x16	026
	23				^W		ETB					0x17	027
	24				^X		CAN					0x18	030
	25				^Y		EM					0x19	031
	26				^Z		SUB					0x1A	032
	27				^[		ESC					0x1B	033
	28				^\		FS					0x1C	034
	29				^]		GS					0x1D	035
	30				^^		RS					0x1E	036
	31				^_		US					0x1F	037
	32						SP
	33				!
	34				"
	35				#
	36				$
	37				%
	38				&
	39				'
	40				(
	41				)
	42				*
	43				+
	44				,
	45				-
	46				.
	47				/
	48				0
	49				1
	50				2
	51				3
	52				4
	53				5
	54				6
	55				7
	56				8
	57				9
	58				:
	59				;
	60				<
	61				=
	62				>
	63				?
	64				@
	65				A
	:				:
	:				:
	90				Z
	91				[
	92				\
	93				]
	94				^
	95				_
	96				'
	97				a
	:				:
	:				:
	122				z
	123				{
	124				|
	125				}
	126				~
	127				DEL
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * ascii_function(char inputconstant[]);
char * convertascii(char inputconstant[]);
char * specialascii(char inputconstant[]);
char * controlascii(char inputconstant[]);
char * escapeascii(char inputconstant[]);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * ascii_function(char inputconstant[])
{
////////////////////////////////////////////////////////////////
/*
This function will call the appropriate function that will convert characters
to their decimal (ascii) equivalent and return this number as a string so
that it can be appended to pseudo-variable $$.
*/
////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations


	/////////////////////////////////////////////////////////////////
	// If the first character if inputconstant begins with a "'",
	// process the character to return its decimal equivalent,
	// otherwise, return inputconstant unchanged
	if (inputconstant[0] == SINGLEQUOTE)
	{
		/////////////////////////////////////////////////////////////////
		// Process a normal character string, e.g. 'a'
		if (strlen(inputconstant) == 3)
			strcpy(inputconstant, convertascii(inputconstant));
		/////////////////////////////////////////////////////////////////
		// Process a character string such as '^J'
		else if ( (strlen(inputconstant) == 4) && (inputconstant[1] == CARET) )
			strcpy(inputconstant, controlascii(inputconstant));
		/////////////////////////////////////////////////////////////////
		// Process a character string such as '\t'
		else if ( (strlen(inputconstant) == 4) && (inputconstant[1] == ESCAPE) )
			strcpy(inputconstant, specialascii(inputconstant));
		/////////////////////////////////////////////////////////////////
		// Process a character string such as '^\\'
		else if (strlen(inputconstant) == 5  && (inputconstant[2] == ESCAPE))
			strcpy(inputconstant, escapeascii(inputconstant));
		/////////////////////////////////////////////////////////////////
		// Process a character string such as  '98'
		else
			strcpy(inputconstant, convertascii(inputconstant));
	}

	////////////////////////////////////////////////////////////////
	// successfully leaving the function
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	char * returnstr = (char *) malloc(strlen(inputconstant));
	strcpy(returnstr, inputconstant);
	return returnstr;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * convertascii(char inputconstant[])
{
////////////////////////////////////////////////////////////////
/*
Given an inputconstant, this function will return the ascii value of the inputconstant
as a string. In this function the ascii values of all letters (a-z and A-Z) and any single
character representation are coded.
*/
////////////////////////////////////////////////////////////////

	switch(inputconstant[1])
	{
		case ' ':	strcpy(inputconstant, "32"); break;
		case '!':	strcpy(inputconstant, "33"); break;
		case '"':	strcpy(inputconstant, "34"); break;
		/* 	the double quote " has the ascii value 34
			this character can also be declared using the escape
			character \, so it is also included in specialascii()
		*/

		case '#':	strcpy(inputconstant, "35"); break;
		case '$':	strcpy(inputconstant, "36"); break;
		case '%':	strcpy(inputconstant, "37"); break;
		case '&':	strcpy(inputconstant, "38"); break;
		/* 	ascii value 39 (single quote ') should go here
			but this character has to use the escape char \
			so it is included in specialascii() instead
		*/

		case '(':	strcpy(inputconstant, "40"); break;
		case ')':	strcpy(inputconstant, "41"); break;
		case '*':	strcpy(inputconstant, "42"); break;
		case '+':	strcpy(inputconstant, "43"); break;
		case ',':	strcpy(inputconstant, "44"); break;
		case '-':	strcpy(inputconstant, "45"); break;
		case '.':	strcpy(inputconstant, "46"); break;
		case '/':	strcpy(inputconstant, "47"); break;

		case '0':	strcpy(inputconstant, "48"); break;
		case '1':	strcpy(inputconstant, "49"); break;
		case '2':	strcpy(inputconstant, "50"); break;
		case '3':	strcpy(inputconstant, "51"); break;
		case '4':	strcpy(inputconstant, "52"); break;
		case '5':	strcpy(inputconstant, "53"); break;
		case '6':	strcpy(inputconstant, "54"); break;
		case '7':	strcpy(inputconstant, "55"); break;
		case '8':	strcpy(inputconstant, "56"); break;
		case '9':	strcpy(inputconstant, "57"); break;

		case ':':	strcpy(inputconstant, "58"); break;
		case ';':	strcpy(inputconstant, "59"); break;
		case '<':	strcpy(inputconstant, "60"); break;
		case '=':	strcpy(inputconstant, "61"); break;
		case '>':	strcpy(inputconstant, "62");  break;
		case '?':	strcpy(inputconstant, "63"); break;
		/* 	the question mark ? has the ascii value 63
			this character can also be declared using the escape
			character \, so it is also included in specialascii()
		*/

		case '@':	strcpy(inputconstant, "64"); break;

		case 'A':	strcpy(inputconstant, "65"); break;
		case 'B':	strcpy(inputconstant, "66"); break;
		case 'C':	strcpy(inputconstant, "67"); break;
		case 'D':	strcpy(inputconstant, "68"); break;
		case 'E':	strcpy(inputconstant, "69"); break;
		case 'F':	strcpy(inputconstant, "70"); break;
		case 'G':	strcpy(inputconstant, "71"); break;
		case 'H':	strcpy(inputconstant, "72"); break;
		case 'I':	strcpy(inputconstant, "73"); break;
		case 'J':	strcpy(inputconstant, "74"); break;
		case 'K':	strcpy(inputconstant, "75"); break;
		case 'L':	strcpy(inputconstant, "76"); break;
		case 'M':	strcpy(inputconstant, "77"); break;
		case 'N':	strcpy(inputconstant, "78"); break;
		case 'O':	strcpy(inputconstant, "79"); break;
		case 'P':	strcpy(inputconstant, "80"); break;
		case 'Q':	strcpy(inputconstant, "81"); break;
		case 'R':	strcpy(inputconstant, "82"); break;
		case 'S':	strcpy(inputconstant, "83"); break;
		case 'T':	strcpy(inputconstant, "84"); break;
		case 'U':	strcpy(inputconstant, "85"); break;
		case 'V':	strcpy(inputconstant, "86"); break;
		case 'W':	strcpy(inputconstant, "87"); break;
		case 'X':	strcpy(inputconstant, "88"); break;
		case 'Y':	strcpy(inputconstant, "89"); break;
		case 'Z':	strcpy(inputconstant, "90"); break;

		case '[':	strcpy(inputconstant, "91");  break;

		/* 	ascii value 92 (backslash \) should go here
			but this character has to use the escape char \
			so it is included in specialascii() instead
		*/

		case ']':	strcpy(inputconstant, "93");  break;
		case '^':	strcpy(inputconstant, "94");  break;
		case '_':	strcpy(inputconstant, "95");  break;
		case '`':	strcpy(inputconstant, "96");  break;

		case 'a':	strcpy(inputconstant, "97");  break;
		case 'b':	strcpy(inputconstant, "98");  break;
		case 'c':	strcpy(inputconstant, "99");  break;
		case 'd':	strcpy(inputconstant, "100"); break;
		case 'e':	strcpy(inputconstant, "101"); break;
		case 'f':	strcpy(inputconstant, "102"); break;
		case 'g':	strcpy(inputconstant, "103"); break;
		case 'h':	strcpy(inputconstant, "104"); break;
		case 'i':	strcpy(inputconstant, "105"); break;
		case 'j':	strcpy(inputconstant, "106"); break;
		case 'k':	strcpy(inputconstant, "107"); break;
		case 'l':	strcpy(inputconstant, "108"); break;
		case 'm':	strcpy(inputconstant, "109"); break;
		case 'n':	strcpy(inputconstant, "110"); break;
		case 'o':	strcpy(inputconstant, "111"); break;
		case 'p':	strcpy(inputconstant, "112"); break;
		case 'q':	strcpy(inputconstant, "113"); break;
		case 'r':	strcpy(inputconstant, "114"); break;
		case 's':	strcpy(inputconstant, "115"); break;
		case 't':	strcpy(inputconstant, "116"); break;
		case 'u':	strcpy(inputconstant, "117"); break;
		case 'v':	strcpy(inputconstant, "118"); break;
		case 'w':	strcpy(inputconstant, "119"); break;
		case 'x':	strcpy(inputconstant, "120"); break;
		case 'y':	strcpy(inputconstant, "121"); break;
		case 'z':	strcpy(inputconstant, "122"); break;

		case '{':	strcpy(inputconstant, "123"); break;
		case '|':	strcpy(inputconstant, "124"); break;
		case '}':	strcpy(inputconstant, "125"); break;
		case '~':	strcpy(inputconstant, "126"); break;
	}
	////////////////////////////////////////////////////////////////
	// successfully leaving the function
	return inputconstant;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * specialascii(char inputconstant[])
{
////////////////////////////////////////////////////////////////
/*
Given an inputconstant, this function will return the ascii value of the inputconstant
as a string. In this function the ascii values for any characters that follow the backslash
symbol \ are coded. For Example: '\t'	is the tab character, ascii value 9
*/
////////////////////////////////////////////////////////////////
	switch(inputconstant[2])
	{
		case '0':	strcpy(inputconstant, "0");  break;	// NULL '\0'
		case 'a':	strcpy(inputconstant, "7");  break;	// audible alert
		case 'b':	strcpy(inputconstant, "8");  break;	// backspace
		case 't':	strcpy(inputconstant, "9");  break; // horizontal tab
		case 'n':	strcpy(inputconstant, "10"); break; // newline
		case 'v':	strcpy(inputconstant, "11"); break; // vertical tab
		case 'f':	strcpy(inputconstant, "12"); break; // formfeed
		case 'r':	strcpy(inputconstant, "13"); break; // carriage return

		case '"':	strcpy(inputconstant, "34"); break;
		// 34 is the ascii value for the double quote "
		case 39 :	strcpy(inputconstant, "39"); break;
		// 39 is the ascii value for the single quote '
		case 92 :	strcpy(inputconstant, "92"); break;
		// 92 is the ascii value for the backslash \
	}
	////////////////////////////////////////////////////////////////
	// successfully leaving the function
	return inputconstant;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * controlascii(char inputconstant[])
{
////////////////////////////////////////////////////////////////
/*
Given an inputconstant, this function will return the ascii value of the inputconstant
as a string. In this function the ascii values for any characters that follow the caret
symbol ^ are coded. For Example: ^@ is the NULL character '\0'
*/
////////////////////////////////////////////////////////////////
	switch(inputconstant[2])
	{
		case '@':	strcpy(inputconstant, "0");  break; // NUL
		case 'A':	strcpy(inputconstant, "1");  break; // SOH
		case 'B':	strcpy(inputconstant, "2");  break; // STX
		case 'C':	strcpy(inputconstant, "3");  break; // ETX
		case 'D':	strcpy(inputconstant, "4");  break; // EOT
		case 'E':	strcpy(inputconstant, "5");  break; // ENQ
		case 'F':	strcpy(inputconstant, "6");  break; // ACK
		case 'G':	strcpy(inputconstant, "7");  break; // BEL, \a
		case 'H':	strcpy(inputconstant, "8");  break; // BS,  \b
		case 'I':	strcpy(inputconstant, "9");  break; // TAB, \t
		case 'J':	strcpy(inputconstant, "10"); break; // LF,  \n
		case 'K':	strcpy(inputconstant, "11"); break; // VT,  \v
		case 'L':	strcpy(inputconstant, "12"); break; // FF,  \f
		case 'M':	strcpy(inputconstant, "13"); break; // CR,  \r
		case 'N':	strcpy(inputconstant, "14"); break; // SO
		case 'O':	strcpy(inputconstant, "15"); break; // SI
		case 'P':	strcpy(inputconstant, "16"); break; // DLE
		case 'Q':	strcpy(inputconstant, "17"); break; // DC1
		case 'R':	strcpy(inputconstant, "18"); break; // DC2
		case 'S':	strcpy(inputconstant, "19"); break; // DC3
		case 'T':	strcpy(inputconstant, "20"); break; // DC4
		case 'U':	strcpy(inputconstant, "21"); break; // NAK
		case 'V':	strcpy(inputconstant, "22"); break; // SYN
		case 'W':	strcpy(inputconstant, "23"); break; // ETB
		case 'X':	strcpy(inputconstant, "24"); break; // CAN
		case 'Y':	strcpy(inputconstant, "25"); break; // EM
		case 'Z':	strcpy(inputconstant, "26"); break; // SUB
		case '[':	strcpy(inputconstant, "27"); break; // ESC
		// ascii 28 is catered for in escapeascii() function
		case ']':	strcpy(inputconstant, "29"); break; // GS
		case '^':	strcpy(inputconstant, "30"); break; // RS
		case '_':	strcpy(inputconstant, "31"); break; // US
	}
	////////////////////////////////////////////////////////////////
	// successfully leaving the function
	return inputconstant;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * escapeascii(char inputconstant[])
{
////////////////////////////////////////////////////////////////
/*
Given an inputconstant, this function will return the ascii value of the inputconstant
as a string. In this function the ascii values for '^\\' is coded.
*/
////////////////////////////////////////////////////////////////
	strcpy(inputconstant, "28");	//FS
	////////////////////////////////////////////////////////////////
	// successfully leaving the function
	return inputconstant;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- ASCII_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////