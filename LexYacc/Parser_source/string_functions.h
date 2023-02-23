////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** HEADER FILE -- STRING_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This Header File contains an assortment of user-defined functions,
used to manipulate strings. These functions are used throughout 
the header files and grammar files, for string manipulation.
*/
				
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * upper(char string[]);
char * lower(char string[]);
char convert_tolower(char ch);
char convert_toupper(char ch);
char *last_strstr(char * s1, char * s2);
int mystrstrcount(char *string, char substring);
int strstrcount(char *string, char *substring);
char * initialisestring(char string[], int limit);
char * copystring(char * source, int begin, int howmany);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * upper(char string[])
{
////////////////////////////////////////////////////////////////
/* 	
This function takes as parameter a string and converts that its to
its uppercase equivalent.
*/
////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////
	// variable declarations		
	unsigned int i = 0;					// control variable of the while loop
	char newstring[STRING_LIMIT];		// temporary holding string	
	char * returnstr;					// return string of the function

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
  	strcpy(newstring, initialisestring(newstring, STRING_LIMIT));
	returnstr 	 = (char *) malloc(STRING_LIMIT);					

	/////////////////////////////////////////////////////////////////
	// Convert the string to UPPER CASE
	while (i < strlen(string))
	{
		if (string[i] >= LOWER_START && string[i] <= LOWER_END)
			newstring[i] = (char)(string[i] - ASCII_DIFF);
		else
			newstring[i] = string[i];
		i++;
	}
	
	////////////////////////////////////////////////////////////////
	// successfully leaving the function		
	strcpy(returnstr, newstring);
   	return returnstr;			
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * lower(char string[])
{
////////////////////////////////////////////////////////////////
/* 	
This function takes as parameter a string and converts that its to
its lowercase equivalent.
*/
////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////
	// variable declarations		
	unsigned int i = 0;					// control variable of the while loop
	char newstring[STRING_LIMIT];		// temporary holding string	
	char * returnstr;					// return string of the function

	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
  	strcpy(newstring, initialisestring(newstring, STRING_LIMIT));
	returnstr 	 = (char *) malloc(STRING_LIMIT);					

	/////////////////////////////////////////////////////////////////
	// Convert the string to LOWER CASE
	while (i < strlen(string))
	{
		if (string[i] >= UPPER_START && string[i] <= UPPER_END)
			newstring[i] = (char)(string[i] - ASCII_DIFF);
		else
			newstring[i] = string[i];
		i++;
	}
	
	////////////////////////////////////////////////////////////////
	// successfully leaving the function		
	strcpy(returnstr, newstring);
   	return returnstr;			
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char convert_tolower(char ch)
{
////////////////////////////////////////////////////////////////
/* 	
This function takes as parameter a char and converts this char to its lowercase
equivalent if it is upper case, otherwise it will be unchanged.
There is a pre-existing C function called tolower() that will perform the same
task but this function results in the following warning:
	Conversion may lose significant digits
This is because the parameter and return of this function is of type int and for
the purposes of this program we need to convert characters.
*/
////////////////////////////////////////////////////////////////
   	if (ch >= UPPER_START && ch <= UPPER_END)
   		ch = (char)(ch + ASCII_DIFF);
   	return ch;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char convert_toupper(char ch)
{
////////////////////////////////////////////////////////////////
/* 	
This function takes as parameter a char and converts this char to its uppercase
equivalent if it is lower case, otherwise it will be unchanged.
There is a pre-existing C function called toupper() that will perform the same
task but this function results in the following warning:
	Conversion may lose significant digits
This is because the parameter and return of this function is of type int and for
the purposes of this program we need to convert characters.
*/
////////////////////////////////////////////////////////////////
	if (ch >= LOWER_START && ch <= LOWER_END)
   		ch = (char)(ch - ASCII_DIFF);
   	return ch;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char *last_strstr(char * s1, char * s2)
{
////////////////////////////////////////////////////////////////
/*	
This function takes as parameter two strings s1 and s2. It will return a pointer
to the last occurance of s2 in s1 or NULL if it is not in s1
This code is taken from:
Title:		Jamsa's C/C++ Programmer's Bible (page 194)
By:			Kris Jamsa and Lars Klander
ISBN:		1-884133-25-8
Publisher:	Jamsa Press
*/
////////////////////////////////////////////////////////////////
	int i, j, k, left = 0;

	for (i = 0; s1[i]; i++)
		for(j = i, k = 0; s1[j] == s2[k]; j++, k++)
			if(! s2[k+1])
				left = i;

	return ((left) ? s1+left : NULL);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int mystrstrcount(char *string, char substring)
{
////////////////////////////////////////////////////////////////
/* 	
This function takes as parameter one string string and one substring, 
which is a single character. It counts the number of occurances of substring in string
and returns this number.
*/
////////////////////////////////////////////////////////////////
	int i = 0; 
	int count = 0;

	while (string[i] != '\0')
	{
		if (string[i] == substring)
			count++;
		i++;
	}
	return (count);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int strstrcount(char *string, char *substring)
{
////////////////////////////////////////////////////////////////
/* 	
This function takes as parameter two strings string and substring. It counts the
number of occurances of substring in string	and returns this number.
This code is taken from:
Title:		Jamsa's C/C++ Programmer's Bible (page 192)
By:			Kris Jamsa and Lars Klander
ISBN:		1-884133-25-8
Publisher:	Jamsa Press
*/
////////////////////////////////////////////////////////////////
	int i, j, k, count = 0;
	for (i = 0; string[i]; i++)
		for(j = i, k = 0; string[j] == substring[k]; j++, k++)

			if(! substring[k+1])
				count++;
	return (count);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

char * initialisestring(char string[], int limit)
{
////////////////////////////////////////////////////////////////
/*	
This function takes as parameter a character array (string) and the amount of
characters in this character array (limit) and it will return the string having
first initialised all the positions in the string to NULL - to prevent any random
characters.
*/
////////////////////////////////////////////////////////////////
	int index;
	for (index=0; index < limit; index++)
	{
		string[index] = '\0';
	}
	return string;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
char * copystring(char * source, int begin, int howmany)
{
////////////////////////////////////////////////////////////////
/*	
This function takes as parameter a source string. It returns a
string which is a substring of 'source', starting at 'begin' 
and taking in 'howmany' characters.
For example:
	source = "hello there"
	begin = 3;
	howmany = 7;
	returns string = "llo the"
*/
////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////
	// variable declarations	
	char * returnstr;
	char holdstr[STRING_LIMIT];
	int index = 0;
	/////////////////////////////////////////////////////////////////
	// allocate space to the string variables used
	returnstr 	 = (char *) malloc(STRING_LIMIT);	
  	strcpy(holdstr, initialisestring(holdstr, STRING_LIMIT));

	/////////////////////////////////////////////////////////////////
	// Copy the string, beginning at 'begin' for 'howmany' characters
	while (index <= howmany)
	{
		holdstr[index] = source[begin];
		index++;
		begin++;
	}
	
	////////////////////////////////////////////////////////////////
	// successfully leaving the function		
	strcpy(returnstr, holdstr);
	return returnstr;
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END HEADER FILE -- STRING_FUNCTIONS.H
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////