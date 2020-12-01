#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "airport_manager.h"

int initAirportManager(AirportManager* pAirMan)
{
	if(!pAirMan)
		return 0;

	printf("\nPlease enter how many airports for this airport manager: ");
	scanf("%d", &pAirMan->count_airports);

	pAirMan->airports = (Airport*)malloc(pAirMan->count_airports * sizeof(Airport));

	for(int i = 0; i < pAirMan->count_airports; i++)
	{
		while(getchar() != '\n');
		if(addAirport(pAirMan, i) == 0)
			printf("wrong");
	}
	return 1;
}

void printAirportManager(AirportManager* pAirMan)
{
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

int addAirport(AirportManager* pAirMan, int index)
{
	if(!pAirMan)
		return 0;

	if(initAirport(&(pAirMan->airports[index])) == 0)
		return 0;

	return 1;
}

Airport* searchAirportByCode(AirportManager* pAirMan, const char IATA[4])
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
