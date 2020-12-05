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

	char* name = getStrExactLength("\nPlease enter airport name: ", 0);
	if(!name)
		printf("\n didn't get a name");
	name = fixAirportName(name);
	pAirport->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(pAirport->name, name);
	free(name);

	char* country = getStrExactLength("\nPlease enter country name: ", 0);
	if(!country)
		printf("\n didn't get a country");
	pAirport->country = (char*)malloc(strlen(country) * sizeof(char));
	strcpy(pAirport->country, country);
	free(country);

	strcpy(pAirport->IATA, getStrExactLength("\nPlease enter IATA code: ", 4));

	if(!pAirport->IATA)
		printf("\n didn't get a IATA code");

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

// return 1 if IATA_1 = IATA_2
int cmpAirportports(const Airport* pA1, const Airport* pA2)
{
	if(!pA1 || !pA2)
		return 0;

	if(strcmp(pA1->IATA, pA2->IATA) == 0)
		return 1;

	return 0;
}

// return 1 if IATA = airport_IATA
int isCodeEqualsAirport(const Airport* pAirport, const char IATA[4])
{
	if(!pAirport || !IATA)
		return 0;

	if(strcmp(pAirport->IATA, IATA) == 0)
		return 1;

	return 0;
}
