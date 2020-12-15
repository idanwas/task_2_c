#ifndef FLIGHT_H_
#define FLIGHT_H_
#include "airport.h"
#include "date.h"

typedef struct
{
	char from[4];
	char to[4];
	int hour;
	Date* date;
}Flight;

int initFlight(Flight* pFlight);

void printFlight(const Flight* pFlight);

void freeFlight(Flight* pFlight);

int isFlightInLine(const Flight flight, const char from[4], const char to[4]);

int getFlightsCountOfLine(Flight** pFlights, int size, const char from[4], const char to[4]);

#endif /* FLIGHT_H_ */
