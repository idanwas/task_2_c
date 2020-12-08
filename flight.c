#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"
#include "functions.h"

int initFlight(Flight* pFlight)
{
	if(!pFlight)
		return 0;

	printf("\nPlease enter the hour of this flight (0-23): ");
	scanf("%d", &pFlight->hour);
	if(pFlight->hour > 23)
		pFlight->hour %= 24;

	pFlight->date = (Date*)malloc(sizeof(Date));
	if(initDate(pFlight->date) == 0)
		return 0;

	return 1;
}

void printFlight(const Flight* pFlight)
{
	printf("\tThis flight departs from: ");
	printAirport(pFlight->pFrom);

	printf(", and arrives to: ");
	printAirport(pFlight->pTo);

	// print time and date
	printf(", at %d o'clock on ", pFlight->hour);
	printDate(pFlight->date);
}

void freeFlight(Flight* pFlight)
{
	freeDate(pFlight->date);
	freeAirport(pFlight->pTo);
	freeAirport(pFlight->pFrom);
	free(pFlight);
}

// return 1 if from=flight.from.code AND to=flight.to.code
int isFlightInLine(const Flight flight, const char from[4], const char to[4])
{
	if(!from || !to)
		return 0;

	if(strcmp(from, flight.pFrom->IATA) == 0 && strcmp(to, flight.pTo->IATA) == 0)
		return 1;
	else
		return 0;
}

int getFlightsCountOfLine(Flight** pFlights, int size, const char from[4], const char to[4])
{
	int counter = 0;
	for(int i = 0; i < size; i++)
	{
		if(pFlights[i] != NULL)
			counter += isFlightInLine(*pFlights[i], from, to);
	}
	return counter;
}

