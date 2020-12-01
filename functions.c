

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

char* getStrExactLength(char* msg)
{
	char* theStr = NULL;
	int length;
	char inpStr[MAX_LENGTH];

	// ask for a string from the user using the message
	printf("%s", msg);
	myGets(inpStr, sizeof(inpStr));

	// find string size and add 1 for the '\0'
	length = strlen(inpStr) + 1;
	// allocate a place for the string
	theStr = (char*)malloc(length * sizeof(char));
	// copy the string to the right location
	if(theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}
