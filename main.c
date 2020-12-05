#include <stdio.h>
#include <stdlib.h>
#include "airport_manager.h"
#include "airline.h"
#include "functions.h"

int main()
{
	int flag = 1, option;
	AirportManager* pAirMan = (AirportManager*)malloc(sizeof(AirportManager));
	initAirportManager(pAirMan);
	printAirportManager(pAirMan);

	while(getchar() != '\n');

	Airline* pAirline = (Airline*)malloc(sizeof(Airline));
	initAirline(pAirline);
	//printAirline(airline);

	do{
		printMenu();
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			// add a flight to airline
			if(addFlightToAirline(pAirMan, pAirline) == 0)
				printf("flight hasnt added to airline");
			else
				printf("\nFlight added to %s airline", pAirline->name);
			break;

		case 2:
			// add an airport to airport manager
			if(addAirportToAirMan(pAirMan) == 1)
				printf("\nAirport added to airport manager");
			else
				printf("airport has not added to airport manager");
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
		cleanBuffer();


	}while(flag);


	freeAirline(pAirline);
	freeAirportManager(pAirMan);

	return 0;
}
