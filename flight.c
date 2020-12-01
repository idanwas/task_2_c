#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flight.h"


// return 1 if from=flight.from.code AND to=flight.to.code
int isFlightInLine(Flight flight, const char from[4], const char to[4])
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

