#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "airport_manager.h"

int initAirportManager(AirportManager* pAirMan)
{
	if(!pAirMan)
		return 0;

	printf("Please enter how many airports for this airport manager: ");
	scanf("%d", &pAirMan->count_airports);

	pAirMan->airports = (Airport*)malloc(pAirMan->count_airports * sizeof(Airport));
	cleanBuffer();
	for(int i = 0; i < pAirMan->count_airports; i++)
	{
		if(addAirportByIndex(pAirMan, i) == 0)
			printf("wrong");
	}
	return 1;
}

void printAirportManager(const AirportManager* pAirMan)
{
	printf("\nAirport Manager details: ");
	printf("\nThis airport manager have %d airports: ", pAirMan->count_airports);
	for(int i = 0; i < pAirMan->count_airports; i++)
	{
		printf("\n#%d ", i+1);
		printAirport(&pAirMan->airports[i]);
	}
}

void freeAirportManager(AirportManager* pAirMan)
{
	for(int i = 0; i < pAirMan->count_airports; i++)
	{
		freeAirport(&pAirMan->airports[i]);
	}
	free(pAirMan);
}

int addAirportByIndex(AirportManager* pAirMan, int index)
{
	if(!pAirMan)
		return 0;

	// initialize airport
	printf("Airport #%d:\n", index+1);
	if(!initAirport(&(pAirMan->airports[index])))
		return 0;

	while(!isUniqueIATA(pAirMan, index, pAirMan->airports[index].IATA))
	{
		// read airport's IATA code from user until IATA code is legal
		strcpy(pAirMan->airports[index].IATA, getStrExactLength("Please enter IATA code: "));
		while (!isLegalCode(pAirMan->airports[index].IATA))
		{
			strcpy(pAirMan->airports[index].IATA, getStrExactLength("Please enter IATA code: "));
		}
	}
	return 1;
}

/* returns airport's pointer in the airport manager with that IATA code */
Airport* searchAirportByCode(const AirportManager* pAirMan, const char IATA[4])
{
	if(!pAirMan || !pAirMan->airports)
		return NULL;

	for(int i = 0; i < pAirMan->count_airports; i++)
	{
		if(strcmp(pAirMan->airports[i].IATA, IATA) == 0)
			return &(pAirMan->airports[i]);
	}

	return NULL;
}

/* returns 1 if airport added successfully to the airport manager */
int addAirportToAirMan(AirportManager* pAirMan) // option #2 in menu
{
	if(!pAirMan)
		return 0;

	// initialize airport
	printf("\nAdd airport to airport manager:\n");
	Airport* pAirport = (Airport*)malloc(sizeof(Airport));
	if(!initAirport(pAirport))
	{
		printf("airport wrong");
		return 0;
	}

	// check that airport has unique IATA code
	if(searchAirportByCode(pAirMan, pAirport->IATA))
	{
		printf("\nThere is already an airport with this IATA code: %s", pAirport->IATA);
		freeAirport(pAirport);
		return 0;
	}

	// add airport to airport manager
	int old_size = pAirMan->count_airports;
	pAirMan->airports = (Airport*)realloc(pAirMan->airports, (old_size + 1) * sizeof(Airport));
	pAirMan->airports[old_size] = *pAirport;
	pAirMan->count_airports++;

	return 1;
}

/* returns IATA code that read from user and checked if legal */
char* readAndCheckIATA(AirportManager* pAirMan, char* msg)
{
	if(!pAirMan)
		return NULL;

	char* IATA = readString(msg);
	if(!isLegalCode(IATA))
		return NULL;

	return IATA;
}

/* returns 1 if IATA code is unique in airport manager */
int isUniqueIATA(AirportManager* pAirMan, int index, const char IATA[4])
{
	for(int i = 0; i < index; i++)
	{
		if(!strcmp(pAirMan->airports[i].IATA, pAirMan->airports[index].IATA))
		{
			printf("\nThere is already an airport with this IATA code: %s", pAirMan->airports[index].IATA);
			printf("\nPlease try again!\n");
			return 0;
		}
	}
	return 1;
}
