#include <stdio.h>
#include <stdlib.h>

#include "airport_manager.h"
#include "airline.h"
#include "functions.h"

int main()
{
	int flag = 1, option;
	AirportManager* airportManager = (AirportManager*)malloc(sizeof(AirportManager));
	initAirportManager(airportManager);
	printAirportManager(airportManager);

	while(getchar() != '\n');

	Airline* airline = (Airline*)malloc(sizeof(Airline));
	initAirline(airline);
	//printAirline(airline);

	do{
		printMenu();
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			// add a flight to airline
			//addFlightToAirline(airportManager, airline);
			break;

		case 2:
			// add an airport to airport manager
			break;

		case 3:
			printf("\nAirline details: ");
			printAirline(airline);
			break;

		case 4:
			printf("\nAirport Manager details: ");
			printAirportManager(airportManager);
			break;

		case 5:
			//printf("");
			break;

		case 6:
			printf("EXIT");
			flag = 0;
			break;

		default:
			printf("\nWrong option. Please try again!");
			break;
		}


	}while(flag);


	freeAirline(airline);
	freeAirportManager(airportManager);

	return 0;
}
