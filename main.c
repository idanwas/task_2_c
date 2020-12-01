
#include <stdio.h>
#include "airport.h"

int main()
{
	printf("init airport:");

	Airport a;
	initAirport(&a);
	printAirport(&a);

	getchar();

	Airport b;
	initAirport(&b);
	printAirport(&b);

	if(isCodeEqualsAirport(&a, "LAX"))
		printf("same");

	freeAirport(&a);
	freeAirport(&b);


	return 0;
}
