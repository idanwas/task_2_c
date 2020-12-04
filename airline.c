#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "airline.h"
#include "airport_manager.h"
#include "airport.h"
#include "flight.h"
#include "functions.h"


int initAirline(Airline* pAirline)
{
	if(!pAirline)
		return 0;

	char* name = getStrExactLength("\nPlease enter airline name: ", 0);
	if(!name)
		printf("\n didn't get a name");
	pAirline->name = (char*)malloc(strlen(name) * sizeof(char));
	strcpy(pAirline->name, name);

	return 1;
}

void printAirline(const Airline* pAirline)
{
	printf("\nAirline %s has %d flights: ", pAirline->name, pAirline->count_flights);
	for(int i = 0; i < pAirline->count_flights; i++)
	{
		printf("\nFlight #%d", i+1);
		printFlight(pAirline->pFlights[i]);
	}

}

void freeAirline(Airline* pAirline)
{
	if(!pAirline)
		return;

	for(int i = 0; i < pAirline->count_flights; i++)
	{
		freeFlight(pAirline->pFlights[i]);
	}
	free(pAirline->name);
	free(pAirline);
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

int addFlightToAirline(const AirportManager* pAirMan, Airline* pAirline)
{
	if(!pAirMan || !pAirline)
	{
		printf("airport or airline isnt ok");
		return 0;
	}

	while(getchar() != '\n');
	char src[4], dest[4];
	printf("\nAdd a flight to %s airline", pAirline->name);


	strcpy(src, getStrExactLength("\nPlease enter IATA of source airport: ", 4));
	while(getchar() != '\n');
	Airport* pSrcAirport = (Airport*)malloc(sizeof(Airport));
	pSrcAirport = searchAirportByCode(pAirMan, src);
	if(!pSrcAirport)
	{
		printf("couldn't find %s airport", src);
		return 0;
	}

	strcpy(dest, getStrExactLength("\nPlease enter IATA of destination airport: ", 4));

	if(strcmp(src, dest) == 0)
	{
		printf("same IATA code: %s=%s. A flight cannot depart from and arrive to the same airport!", src, dest);
		return 0;
	}

	Airport* pDestAirport = (Airport*)malloc(sizeof(Airport));
	pDestAirport = searchAirportByCode(pAirMan, dest);
	if(!pDestAirport)
	{
		printf("couldn't find %s airport", dest);
		return 0;
	}


	Flight* pFlight = (Flight*)malloc(sizeof(Flight));
	pFlight->pFrom = pSrcAirport;
	pFlight->pTo = pDestAirport;
	if(initFlight(pFlight) == 0)
	{
		printf("wrong");
		return 0;
	}

	return addFlight(pAirline, pFlight);
}



