#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "flight.h"

typedef struct
{
	char* name;
	int count_flights;
	Flight** pFlights;
}Airline;

int addFlight(Airline* pAirline, Flight* pFlight);

#endif /* AIRLINE_H_ */