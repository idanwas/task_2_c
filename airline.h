#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "flight.h"
#include "airport_manager.h"


typedef struct
{
	char* name;
	int count_flights;
	Flight** pFlights;
}Airline;


int initAirline(Airline* pAirline);

void printAirline(const Airline* pAirline);

void freeAirline(Airline* pAirline);

int addFlight(Airline* pAirline, Flight* pFlight);

void printCountFlightsInLine(Airline* pAirline, const char from[4], const char to[4]);

int addFlightToAirline(const AirportManager* pAirMan, Airline* pAirline);


#endif /* AIRLINE_H_ */
