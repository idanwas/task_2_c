
#include <stdio.h>
#include "airport.h"

int main()
{
	printf("init airport:");

	Airport a;
	initAirport(&a);
	printAirport(&a);
	freeAirport(&a);


	return 0;
}
