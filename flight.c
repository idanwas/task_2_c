#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"
#include "functions.h"

int initFlight(Flight* pFlight)
{
	if(!pFlight)
		return 0;

	// read hour from user until hour is OK
	int flag = 0;
	do {
		printf("\nPlease enter the hour of this flight (0-23): ");
		scanf("%d", &pFlight->hour);
		if(pFlight->hour < 24 && pFlight->hour >= 0)
			flag = 1;
		else
			printf("Invalid hour! Please try again.");
	} while (!flag);

	// initialize date
	pFlight->date = (Date*)malloc(sizeof(Date));
	if(initDate(pFlight->date) == 0)
		return 0;

	return 1;
}

void printFlight(const Flight* pFlight)
{
	// print from & to airports
	printf("\tThis flight departs from: %s", pFlight->from);
	printf(", and arrives to: %s", pFlight->to);

	// print time and date
	printf(", at %d o'clock on ", pFlight->hour);
	printDate(pFlight->date);
}

void freeFlight(Flight* pFlight)
{
	freeDate(pFlight->date);
	free(pFlight);
}

/* returns 1 if from = flight.from.code AND to = flight.to.code */
int isFlightInLine(const Flight flight, const char from[4], const char to[4])
{
	if(!from || !to)
		return 0;

	if(strcmp(from, flight.from) == 0 && strcmp(to, flight.to) == 0)
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
