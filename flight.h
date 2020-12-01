#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "airport.h"
#include "date.h"

typedef struct
{
	Airport* pFrom;
	Airport* pTo;
	int hour;
	Date* date;
}Flight;


int initFlight(Flight* pFlight);

void printFlight(Flight* pFlight);

void freeFlight(Flight* pFlight);

int isFlightInLine(Flight flight, const char from[4], const char to[4]);

int getFlightsCountOfLine(Flight** pFlights, int size, const char from[4], const char to[4]);

#endif /* FLIGHT_H_ */
