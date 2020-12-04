

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



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

char* getStrExactLength(const char* msg, int length)
{
	char* theStr = NULL;
	char inpStr[MAX_LENGTH];

	// ask for a string from the user using the message
	printf("%s", msg);

	if(length > 0)
	{
		fgets(inpStr, length, stdin);
	}
	else
	{
		myGets(inpStr, sizeof(inpStr));

		// find string size and add 1 for the '\0'
		length = strlen(inpStr) + 1;
	}
	// allocate a place for the string
	theStr = (char*)malloc(length * sizeof(char));
	// copy the string to the right location
	if(theStr != NULL)
		strcpy(theStr, inpStr);
	return theStr;
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
			"Your option:");
}
