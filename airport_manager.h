#ifndef AIRPORT_MANAGER_H_
#define AIRPORT_MANAGER_H_

#include "airport.h"

typedef struct
{
	int count_airports;
	Airport* airports;
}AirportManager;


int initAirportManager(AirportManager* pAirMan);

void printAirportManager(const AirportManager* pAirMan);

void freeAirportManager(AirportManager* pAirMan);

int addAirport(AirportManager* pAirMan, int index);

Airport* searchAirportByCode(const AirportManager* pAirMan, const char IATA[4]);

int addAirportToAirMan(AirportManager* pAirMan);

#endif /* AIRPORT_MANAGER_H_ */
