#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "airline.h"
#include "flight.h"


int initAirline(Airline* pAirline)
{
	if(!pAirline)
		return 0;

	char* name = getStrExactLength("\nPlease enter airline name: ");
	if(!name)
		printf("\n didn't get a name");
	pAirline->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(pAirline->name, name);




	return 1;
}

void printAirline(Airline* pAirline)
{
	printf("\nAirline %s has %d flights: ");

}

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

void printCountFlightsInLine(Airline* pAirline, const char from[4], const char to[4])
{
	if(!pAirline || !from || !to)
	{
		printf("\nSomething went wrong printCountFlightsInLine");
		return;
	}

	int counter = getFlightsCountOfLine(pAirline->pFlights, pAirline->count_flights, from, to);
	printf("\nAirline %s has %d flight from %s to %s", pAirline->name, counter, from, to);
}



