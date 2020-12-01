#ifndef AIRPORT_MANAGER_H_
#define AIRPORT_MANAGER_H_

#include "airport.h"

typedef struct
{
	Airport* airports;
	int count_airports;
}AirportManager;


int addAirport(AirportManager* pAirMan, Airport* pAir);

Airport* searchAirportByCode(AirportManager* pAirMan, const char IATA[4]);


#endif /* AIRPORT_MANAGER_H_ */
