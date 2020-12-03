

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

int addFlightToAirline(AirportManager* pAirMan, Airline* pAirline)
{
	if(!pAirMan || !pAirline)
		return 0;

	char* src = NULL, dest = NULL;
	printf("\nAdd a flight to %s airline", pAirline->name);
	getchar();
	printf("\nPlease enter IATA of source airport: ");
	fgets(src, 4 , stdin);
	while(getchar() != '\n');

	Airport* pSrcAirport = (Airport*)malloc(sizeof(Airport));
	pSrcAirport = searchAirportByCode(pAirMan, src);
	if(!pSrcAirport)
	{
		printf("couldn't find %s airport", src);
		return 0;
	}

	printf("\nPlease enter IATA of destination airport: ");
	fgets(dest, 4 , stdin);
	while(getchar() != '\n');

	Airport* pDestAirport = (Airport*)malloc(sizeof(Airport));
	pDestAirport = searchAirportByCode(pAirMan, dest);
	if(!pDestAirport)
	{
		printf("couldn't find %s airport", dest);
		return 0;
	}

	Flight* flight = (Flight*)malloc(sizeof(Flight));

	return 1;
}

char* readIATA(char* msg)
{
	char* IATA = NULL;
	printf("%s", msg);
	fgets(IATA, 4, stdin);
	while(getchar() != '\n');
	return IATA;
}
