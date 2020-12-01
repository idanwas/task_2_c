#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "airport.h"
#include "functions.h"


int initAirport(Airport* pAirport)
{
	if(!pAirport)
	{
		printf("\n initAirport wrong");
		return 0;
	}
	// get name need a fix !!!!!!!!!!!!!!!
	//
	//
	char* name = getStrExactLength("\nPlease enter airport name: ");
	if(!name)
		printf("\n didn't get a name");
	pAirport->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(pAirport->name, name);
	//
	//

	//getchar();

	char* country = getStrExactLength("\nPlease enter country name: ");
	if(!country)
		printf("\n didn't get a country");
	pAirport->country = (char*)malloc(strlen(country) * sizeof(char));
	strcpy(pAirport->country, country);

	printf("\nPlease enter IATA code: ");
	fgets(pAirport->IATA, 4 , stdin);
	if(!country)
		printf("\n didn't get a IATA code");

	return 1;
}

void printAirport(Airport* pAirport)
{
	if(!pAirport)
	{
		printf("\nAirport isn't initialized");
		return;
	}

	printf("\nAirport %s, located in %s, IATA code: %s", pAirport->name, pAirport->country, pAirport->IATA);
}

void freeAirport(Airport* pAirport)
{
	free(pAirport->country);
	free(pAirport->name);
}

// return 1 if IATA_1 = IATA_2
int cmpAirportports(Airport* pA1, Airport* pA2)
{
	if(!pA1 || !pA2)
		return 0;

	if(strcmp(pA1->IATA, pA2->IATA) == 0)
		return 1;

	return 0;
}

// return 1 if IATA = airport_IATA
int isCodeEqualsAirport(Airport* pAirport, const char IATA[4])
{
	if(!pAirport || !IATA)
		return 0;

	if(strcmp(pAirport->IATA, IATA) == 0)
		return 1;

	return 0;
}
