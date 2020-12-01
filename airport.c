#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "airport.h"
#include "functions.h"


void initAirport(Airport* pAir)
{
	char* name = getStrExactLength("\nPlease enter airport name: ");
	if(!name)
		printf("\n didn't get a name");
	pAir->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(pAir->name, name);

	//getchar();

	char* country = getStrExactLength("\nPlease enter country name: ");
	if(!country)
		printf("\n didn't get a country");
	pAir->country = (char*)malloc(strlen(country) * sizeof(char));
	strcpy(pAir->country, country);

	printf("\nPlease enter IATA code: ");
	fgets(pAir->IATA, 4 , stdin);
	if(!country)
		printf("\n didn't get a IATA code");
}

void printAirport(Airport* pAir)
{
	if(!pAir)
	{
		printf("\nAirport isn't initialized");
		return;
	}

	printf("\nAirport %s, located in %s, IATA code: %s", pAir->name, pAir->country, pAir->IATA);
}

void freeAirport(Airport* pAir)
{
	free(pAir->country);
	free(pAir->name);
}

// return 1 if IATA_1 = IATA_2
int cmpAirports(Airport* pA1, Airport* pA2)
{
	if(!pA1 || !pA2)
		return 0;

	if(strcmp(pA1->IATA, pA2->IATA) == 0)
		return 1;

	return 0;
}

// return 1 if IATA = airport_IATA
int isCodeEqualsAirport(Airport* pAir, const char IATA[4])
{
	if(!pAir || !IATA)
		return 0;

	if(strcmp(pAir->IATA, IATA) == 0)
		return 1;

	return 0;
}
