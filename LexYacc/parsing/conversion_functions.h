////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- CONVERSION_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/* 
This header file contains the function
	char * check_number(char constant[]);
This function is called from the following place in the grammar file:
primary_expression
	: IDENTIFIER
	| CONSTANT			--- CALL check_number()
	| STRING_LITERAL
	| '(' expression ')'
	;
The purpose of this function is to check if the constant passed as
parameter to it is a hexadecimal or octal number. If it is either,
check_number() calls on the appropriate function declared in this
header file, to convert the constant to its decimal equivalent.
The reason they are converted is that only decimal numbers can be passed
to the PTC SOLVER, and it is easier to convert them at parsing stage.
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * check_number(char constant[]);
char * hex_to_decimal(char constant[]);
char * octal_to_decimal(char constant[]);
char * convert_to_decimal(char string[], int base);
int convert_letter(char ch);
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * check_number(char constant[])
{
/* 
This function converts the number passed as parameter to its decimal
equivalent, if necessary.
If number is hexadecimal the following function is called to convert it:
	char * hex_to_decimal(char constant[]);
Else if number is octal the following function is called to convert it:
	char * octal_to_decimal(char constant[])
Else no action is taken, constant is returned as it was.
*/

	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;				// return string of the function
	int i = 0;						// index to first letter in constant
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	returnstr = (char *) malloc(STRING_LIMIT);
	
	/////////////////////////////////////////////////////////////////
	// Check for HEXADECIMAL number . . . 	
	if (strstr(constant, "0x") || strstr(constant, "0X"))
			strcpy(returnstr, hex_to_decimal(constant));
	/////////////////////////////////////////////////////////////////
	// Check for OCTAL number . . . 	
	// It is an octal number if first letter is '0' and it is not followed
	// by a decimal point or is not just '0'
	else if (constant[i] == '0' && constant[i+1] != '.' && strlen(constant) > 1)
		strcpy(returnstr, octal_to_decimal(constant));
	else
	/////////////////////////////////////////////////////////////////
	// Not HEXADECIMAL or OCTAL - no change required
		strcpy(returnstr, constant);
	
	////////////////////////////////////////////////////////////////
	// successfully leaving the function	
	return returnstr;				/* return the converted string		 */
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * hex_to_decimal(char constant[])
{
////////////////////////////////////////////////////////////////
/*	
This function is called from:
	char * check_number(char constant[])
when a hexadecimal number is seen.

The "0x" part of the constant string is removed & the result is stored
into hexstring. Hexstring and the base for hexadecimal numbers (HEX 16)
is passed as parameter to the function:
	char * convert_to_decimal(char string[], int base)
where the string is converted to its decimal equiavlent and returned.
*/
////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;			// return string of the function
	int index = 0;				// index to hexstring
	unsigned int constindex = HEX_LENGTH;
								// begin constant index at 2 since we bypass "0x"
	char hexstring[STRING_LIMIT];		
								// constant string less the "0x"
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
  	strcpy(hexstring, initialisestring(hexstring, STRING_LIMIT));
	returnstr = (char *) malloc(STRING_LIMIT);	

	/////////////////////////////////////////////////////////////////	
	// Copy the string constant to hexstring, bypassing "0x"
	while (constindex < strlen(constant))
	{
		hexstring[index] = constant[constindex];
		index++;
		constindex++;
	}

	/////////////////////////////////////////////////////////////////
	// Call the function to convert the hexadecimal number to decimal format
	strcpy(returnstr, convert_to_decimal(hexstring, HEX));
			
	////////////////////////////////////////////////////////////////
	// successfully leaving the function			
	return returnstr;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * octal_to_decimal(char constant[])
{
////////////////////////////////////////////////////////////////
/*	
This function is called from:
	char * check_number(char constant[])
when an octal number is seen.

The "0" part of the constant string is removed and the result is stored
into octalstring. octalstring and the base for octal numbers (OCTAL 8)
is passed as parameter to the function:
	char * convert_to_decimal(char string[], int base)
where the string is converted to its decimal equiavlent and returned.
*/
////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;			// return string of the function
	int index = 0;				// index to octalstring
	unsigned int constindex = OCTAL_LENGTH;
								// begin constant index at 1 since we bypass "0"
	char octalstring[STRING_LIMIT];	
								// constant string less the "0"

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
  	strcpy(octalstring, initialisestring(octalstring, STRING_LIMIT));
	returnstr = (char *) malloc(STRING_LIMIT);	

	/////////////////////////////////////////////////////////////////	
	// Copy the string constant to octalstring, bypassing "0"
	while (constindex < strlen(constant))
	{
		octalstring[index] = constant[constindex];
		index++;
		constindex++;
	}
	
	/////////////////////////////////////////////////////////////////
	// Call the function to convert the hexadecimal number to decimal format
	strcpy(returnstr, convert_to_decimal(octalstring, OCTAL));
	returnstr = convert_to_decimal(octalstring, OCTAL);

	////////////////////////////////////////////////////////////////
	// successfully leaving the function				
	return returnstr;		
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * convert_to_decimal(char string[], int base)
{
////////////////////////////////////////////////////////////////
/*	
This function is called from:
	char * hex_to_decimal(char constant[])
	char * octal_to_decimal(char constant[])

It is given as parameter a string, which is either a hex or octal string
and a base, which is either 16 (if hex string) or 8 (if octal string).

Taking for example string = "FF32" and base = 16

First, the string is reversed so revstring = "23FF"

Next, for each letter in revstring the following occurs:
-- 	the letter is copied into the string singlechar
-- 	the numerical equivalent of singlechar is found and copied into num
-- 	if num is 0 this may be because singlechar is either "0" or a letter
	and cannot be converted, function int convert_letter(char ch)
	is called to find the correct numeric value and this is put into num.
	newnum is num * base to the power of i and this is added to totalnum.

Example of for loop:
	Iteration 1:					Iteration 2:
	************					************
	i = 0							i = 1
	singlechar = "2"				singlechar = "3"
	num = 2							num = 3
	newnum = 2 * 16^0 = 2			newnum = 3 * 16^1 = 48
	totalnum = 0 + 2 = 2			totalnum = 2 + 48 = 50

	Iteration 3:					Iteration 4:
	************					************
	i = 2							i = 3
	singlechar = "F"				singlechar = "F"
	num = 15						num = 15
	newnum = 15 * 16^2 = 3840		newnum = 15 * 16^3 = 61440
	totalnum = 50 + 3840 = 3890		totalnum = 3890 + 61440 = 65330

Finally, totalnum is converted to its string equivalent and returned by
the function. (65330 becomes "65330")
*/
////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;		// return string of the function	
	int index;				// index for the string parameter	
	int revindex = 0;		// index for the reversed string	
	char revstring[STRING_LIMIT];		
							// the reverse of string parameter	
	int numdigits;			// number of letters in revstring	
	int i;					// control variable for for loop & used in pow()
	char * singlechar;		// single letter of revstring 				
	int num;				// this is numerical equivalent of singlechar	
	unsigned long newnum;	// newnum is num * base^i			
	char * numstr;			// string equivalent of the number totalnum		
	unsigned long totalnum = 0;	
							// the total of the decimal number		

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
  	strcpy(revstring, initialisestring(revstring, STRING_LIMIT));
  	returnstr 	= (char *) malloc(STRING_LIMIT);	
	numstr 		= (char *) malloc(STRING_LIMIT);	
	singlechar 	= (char *) malloc(STRING_LIMIT);

	////////////////////////////////////////////////////////////////
	// Reverse the parameter string
	// Processing is achieved on reverse string
	index = strlen(string) - 1;
	while (index >= 0)
	{
		revstring[revindex] = string[index];
		revindex++;
		index--;
	}
	
	////////////////////////////////////////////////////////////////
	// Convert the string to its decimal equivalent			
	////////////////////////////////////////////////////////////////
	// For each character in revstring: 
	// -- Isolate character to singlechar;
	// -- Get the numerical value usins atoi();
	//		If this is zero, then singlechar is not a number, 
	//		use convert_letter() to get numeric value.
	// -- Convert num to its decimal value, add to totalnum.
	numdigits = strlen(revstring);
	for (i = 0; i < numdigits; i++)
	{
		strcpy(singlechar, copystring(revstring, i, 0));
		num = atoi(singlechar);
		if (num == 0)
			num = convert_letter(revstring[i]);
		newnum = (unsigned long)(num * pow(base, i));
		totalnum = totalnum + newnum;
	}

	////////////////////////////////////////////////////////////////
	// Convert the number to a string using the ultoa() C function
	ultoa(totalnum, numstr, RADIX);										

	////////////////////////////////////////////////////////////////
	// successfully leaving the function	
	strcpy(returnstr, numstr);	
	return returnstr;		
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int convert_letter(char ch)
{
////////////////////////////////////////////////////////////////
/*	
This function is called from
	char * convert_to_decimal(char string[], int base)
whenever the a call to function atoi (with ch as parameter) returns 0.
If the character ch is A-F or a-f then the apprpriate value for these
hexadecimal numbers is returned, otherwise the number 0 is returned.
*/
////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////
	// variable declarations		
	int return_number;			// return number of the function

	/////////////////////////////////////////////////////////////////
	// Find the decimal equivalent of the HEXADECIMAL letter
	switch(ch)
	{
		case 'a': case 'A':	{ return_number = 10; break; }	// hex A||a = 10	
		case 'b': case 'B':	{ return_number = 11; break; }	// hex B||b = 11
		case 'c': case 'C':	{ return_number = 12; break; }	// hex C||c = 12
		case 'd': case 'D':	{ return_number = 13; break; }	// hex D||d = 13
		case 'e': case 'E':	{ return_number = 14; break; }	// hex E||e = 14
		case 'f': case 'F':	{ return_number = 15; break; }	// hex F||f = 15
		default:  			{ return_number = 0; break;  }
	}
	////////////////////////////////////////////////////////////////
	// successfully leaving the function		
	return return_number;	
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- CONVERSION_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////