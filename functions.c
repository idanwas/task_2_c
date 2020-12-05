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

char* fixAirportName(char* name)
{
	int count_words = countWords(name), word_length, new_length, old_length = 0, counter = 1;
	if(count_words == 0)
	{
		printf("0 words");
		return NULL;
	}


	char* del = " ";
	char* words = strtok(name, del);
	word_length = strlen(words);
	char* fixed = (char*)malloc(word_length * sizeof(char));

	do{
		word_length = strlen(words);
		char* word;
		if(word_length % 2 == 0)
			word = fixEvenCharsWord(words);
		else
		{
			if(counter == count_words)
				word = fixOddcharsWord(words, 0); // last word
			else
				word = fixOddcharsWord(words, 1);
		}

		if(counter != 1)
		{
			old_length = strlen(fixed);
			new_length = old_length + 2 + strlen(word);
			fixed = realloc(fixed, new_length * sizeof(char));
			fixed[old_length] = ' ';
			fixed[old_length + 1] = ' ';
		}
		strcat(fixed, word);
		words = strtok(NULL, del);
		counter++;
	}while(words != NULL);


	free(name);
	return fixed;
}

char* fixOddcharsWord(char* word, int flag)
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
