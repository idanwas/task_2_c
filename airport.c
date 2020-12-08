#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "airport.h"
#include "functions.h"

int initAirport(Airport* pAirport)
{
	if(!pAirport)
	{
		printf("\n initAirport wrong");
		return 0;
	}

	// read airport's name from user and change it by the rules
	char* name = getStrExactLength("Please enter airport name: ");
	if(!name)
		printf("\n didn't get a name");
	name = fixAirportName(name);
	pAirport->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(pAirport->name, name);
	free(name);

	// read airport's country from user
/*	pAirport->country = (char*)malloc(sizeof(char));
	readString("Please enter country name: ", 0, pAirport->country);*/
	pAirport->country = readString("Please enter country name: ");

	// read airport's IATA code from user until IATA code is legal
	strcpy(pAirport->IATA, getStrExactLength("Please enter IATA code: "));
	while (!isLegalCode(pAirport->IATA))
	{
		strcpy(pAirport->IATA, getStrExactLength("Please enter IATA code: "));
	}

	return 1;
}

void printAirport(const Airport* pAirport)
{
	if(!pAirport)
	{
		printf("\nAirport isn't initialized");
		return;
	}

	printf("Airport %s, located in %s, IATA code: %s", pAirport->name, pAirport->country, pAirport->IATA);
}

void freeAirport(Airport* pAirport)
{
	free(pAirport->country);
	free(pAirport->name);
}

/* returns 1 if IATA_1 = IATA_2 */
int cmpAirports(const Airport* pA1, const Airport* pA2)
{
	if(!pA1 || !pA2)
		return 0;

	if(strcmp(pA1->IATA, pA2->IATA) == 0)
		return 1;

	return 0;
}

/* returns 1 if IATA = airport_IATA */
int isCodeEqualsAirport(const Airport* pAirport, const char IATA[4])
{
	if(!pAirport || !IATA)
		return 0;

	if(strcmp(pAirport->IATA, IATA) == 0)
		return 1;

	return 0;
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

	// take care of each word by itself
	do{
		word_length = strlen(words);
		char* word;

		if(word_length % 2 == 0)	// word has even number of letters
			word = fixEvenCharsWord(words);
		else	// word has even number of letters
		{
			if(counter == count_words)
				word = fixOddCharsWord(words, 0); // last word
			else
				word = fixOddCharsWord(words, 1); // not the last word
		}

		if(counter != 1)	// skip the first word
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

/* returns 1 if IATA code is 3 letters and all of them are upper case */
int isLegalCode(const char* IATA)
{
	int length = strlen(IATA);
	if(length != 3)
	{
		printf("IATA code must be 3 letters only! Please try again.\n");
		return 0;
	}

	for(int i = 0; i < 3; i++)
	{
		if(islower(IATA[i]))
		{
			printf("IATA code must be capitalized! Please try again.\n");
			return 0;
		}
	}

	return 1;
}
