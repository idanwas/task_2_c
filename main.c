#include <stdio.h>
#include <stdlib.h>

#include "airport_manager.h"
#include "airline.h"

int main()
{

	AirportManager* airportManager = (AirportManager*)malloc(sizeof(AirportManager));
	initAirportManager(airportManager);
	printAirportManager(airportManager);

	Airline* airline = (Airline*)malloc(sizeof(Airline));
	initAirline(airline);
	printAirline(airline);




	freeAirportManager(airportManager);

	return 0;
}
