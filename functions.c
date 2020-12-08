#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

void cleanBuffer()
{
	while(getchar() != '\n');
}

char* myGets(char* buf, size_t size)
{
	if(buf != NULL && size > 0)
	{
		if(fgets(buf, size, stdin))
		{
			buf[strcspn(buf,"\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
}

char* getStrExactLength(const char* msg)
{
	char* theStr = NULL;
	char inpStr[MAX_LENGTH];

	// ask for a string from the user using the message
	printf("%s", msg);

	myGets(inpStr, sizeof(inpStr));

	// find string size and add 1 for the '\0'
	int length = strlen(inpStr) + 1;
	// allocate a place for the string
	theStr = (char*)malloc(length * sizeof(char));
	// copy the string to the right location
	if(theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

char* fixOddCharsWord(char* word, int flag)
{
	// if flag is 0 then word is the last
	int length = strlen(word);
	char* temp = (char*)malloc(length * sizeof(char));
	strcpy(temp, word);
	if(flag)
		temp[0] = toupper(word[0]);
	else
		temp[0] = tolower(word[0]);
	for(int i = 1; i < length; i++)
	{
		temp[i] = tolower(word[i]);
	}
	return temp;
}

char* fixEvenCharsWord(char* word)
{
	int length = strlen(word);
	char* temp = (char*)malloc(length * sizeof(char));
	for(int i = 0; i < length; i+=2)
	{
		temp[i] = toupper(word[i]);
		temp[i+1] = tolower(word[i+1]);
	}
	return temp;
}

/* returns the number of words in a string */
int countWords(char* str)
{
	int count = 0;
	while(*str)
	{
		while(*str && isspace(*str))
			str++;
		if(*str)
			count++;
		while(*str && !isspace(*str))
			str++;
	}
	return count;
}

char* readString(char* msg)
{
	char* str = getStrExactLength(msg);
	if(!str)
		return NULL;
	return str;
}

void printMenu()
{
	printf("\n\nMain Menu: (please choose an option)\n"
			"1)\tAdd a flight to airline\n"
			"2)\tAdd an airport to airport manager\n"
			"3)\tPrint airline details\n"
			"4)\tPrint airport manager details\n"
			"5)\tHow many flights in a specific line?\n"
			"6)\tExit\n"
			"Your option: ");
}
