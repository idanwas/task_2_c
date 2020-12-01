#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "airline.h"


int addFlight(Airline* pAirline, Flight* pFlight)
{
	if(!pAirline || !pFlight)
		return 0;

	pAirline->count_flights++;
	int new_count = pAirline->count_flights;

	if(new_count == 1)
		pAirline->pFlights = (Flight**)malloc(sizeof(Flight*));
	else
		pAirline->pFlights = (Flight**)realloc(pAirline->pFlights, new_count * sizeof(Flight*));

	pAirline->pFlights[new_count - 1] = pFlight;

	return 1;
}

