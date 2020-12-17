#include <stdio.h>
#include <stdlib.h>
#include "airport_manager.h"
#include "airline.h"
#include "functions.h"

int main()
{
	int flag = 1, option;

	// initialize airport manager
	AirportManager* pAirMan = (AirportManager*)malloc(sizeof(AirportManager));
	initAirportManager(pAirMan);

	// initialize airline company
	Airline* pAirline = (Airline*)malloc(sizeof(Airline));
	initAirline(pAirline);

	// present menu
	do{
		printMenu();
		scanf("%d",&option);	// read option from user
		cleanBuffer();
		switch(option)
		{
		case 1:
			// add a flight to airline
			if(addFlightToAirline(pAirMan, pAirline))
				printf("\nFlight added successfully to %s airline", pAirline->name);
			else
				printf("\nFlight hasn't added to airline");
			break;

		case 2:
			// add an airport to airport manager
			if(addAirportToAirMan(pAirMan))
				printf("\nAirport added successfully to airport manager");
			else
				printf("\nAirport hasn't added to airport manager");
			break;

		case 3:
			// print airline details
			printAirline(pAirline);
			break;

		case 4:
			// print airport manager details
			printAirportManager(pAirMan);
			break;

		case 5:
			// print how many flights in a specific line
			printCountFlightsFunction(pAirline, pAirMan);
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

	// free memory allocations
	freeAirline(pAirline);
	freeAirportManager(pAirMan);

	return 0;
}
