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

	pAirline->name = readString("\nPlease enter airline name: ");

	return 1;
}

void printAirline(const Airline* pAirline)
{
	printf("\n%s airline has %d flights: ", pAirline->name, pAirline->count_flights);
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

/* returns 1 if flight added successfully to airline company */
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

/* prints how many flights the airline company have in line from-to */
void printCountFlightsInLine(Airline* pAirline, const char from[4], const char to[4])
{
	if(!pAirline || !from || !to)
	{
		printf("\nSomething went wrong printCountFlightsInLine");
		return;
	}

	int counter = getFlightsCountOfLine(pAirline->pFlights, pAirline->count_flights, from, to);
	printf("\n%s airline has %d flights from %s to %s", pAirline->name, counter, from, to);
}

/* returns 1 if flight added successfully to airline company
 airports must exist in airport manager */
int addFlightToAirline(const AirportManager* pAirMan, Airline* pAirline) // option #1 in menu
{
	if(!pAirMan || !pAirline)
	{
		printf("airport or airline isn't OK");
		return 0;
	}

	char src[4], dest[4];
	printf("\nAdd a flight to %s airline", pAirline->name);

	// read source airport from user and check if airport exist in airport manager
	strcpy(src, getStrExactLength("\nPlease enter IATA of source airport: "));
	Airport* pSrcAirport = searchAirportByCode(pAirMan, src);
	if(!pSrcAirport)
	{
		printf("couldn't find %s airport", src);
		return 0;
	}

	// read destination airport from user and check if airport exist in airport manager
	strcpy(dest, getStrExactLength("\nPlease enter IATA of destination airport: "));
	Airport* pDestAirport = searchAirportByCode(pAirMan, dest);
	if(!pDestAirport)
	{
		printf("couldn't find %s airport", dest);
		return 0;
	}

	// check that airports are not the same
	if(strcmp(src, dest) == 0)
	{
		printf("same IATA code: %s=%s. A flight cannot depart from and arrive to the same airport!", src, dest);
		return 0;
	}

	// initialize flight
	Flight* pFlight = (Flight*)malloc(sizeof(Flight));
	strcpy(pFlight->from, src);
	strcpy(pFlight->to, dest);
	if(initFlight(pFlight) == 0)
	{
		freeFlight(pFlight);
		return 0;
	}

	// add the flight to the airline company
	return addFlight(pAirline, pFlight);
}

void printCountFlightsFunction(Airline* pAirline, AirportManager* pAirMan)
{
	char* from = readAndCheckIATA(pAirMan, "Please enter source airport's IATA code: ");
	if(!from)
		return;
	char* to = readAndCheckIATA(pAirMan, "Please enter destination airport's IATA code: ");
	if(!to)
		return;
	printCountFlightsInLine(pAirline, from, to);
}
