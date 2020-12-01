#ifndef AIRPORT_MANAGER_H_
#define AIRPORT_MANAGER_H_

#include "airport.h"

typedef struct
{
	int count_airports;
	Airport* airports;
}AirportManager;


int initAirportManager(AirportManager* pAirMan);

int addAirport(AirportManager* pAirMan, int index);

void printAirportManager(AirportManager* pAirMan);

void freeAirportManager(AirportManager* pAirMan);

Airport* searchAirportByCode(AirportManager* pAirMan, const char IATA[4]);


#endif /* AIRPORT_MANAGER_H_ */
