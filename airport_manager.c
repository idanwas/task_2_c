#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "airport_manager.h"


int addAirport(AirportManager* pAirMan, Airport* pAir)
{
	if(!pAir || !pAirMan)
		return 0;

	pAirMan->count_airports++;
	int new_count = pAirMan->count_airports;

	if(new_count == 1)
		pAirMan->airports = (Airport*)malloc(sizeof(Airport));
	else
		pAirMan->airports = (Airport*)realloc(pAirMan->airports, new_count * sizeof(Airport));

	pAirMan->airports[new_count - 1] = *pAir;

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
