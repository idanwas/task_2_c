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
			if(addFlightToAirline(pAirMan, pAirline) == 0)
				printf("\nFlight hasn't added to airline");
			else
				printf("\nFlight added to %s airline", pAirline->name);
			break;

		case 2:
			// add an airport to airport manager
			if(addAirportToAirMan(pAirMan) == 1)
				printf("\nAirport added to airport manager");
			else
				printf("\nAirport hasn't added to airport manager");
			break;

		case 3:
			printf("\nAirline details: ");
			printAirline(pAirline);
			break;

		case 4:
			printf("\nAirport Manager details: ");
			printAirportManager(pAirMan);
			break;

		case 5:
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
