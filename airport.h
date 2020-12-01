
#ifndef AIRPORT_H_
#define AIRPORT_H_

typedef struct
{
	char* name;
	char* country;
	char IATA[4];
}Airport;

void initAirport(Airport* pAir);

void printAirport(Airport* pAir);

void freeAirport(Airport* pAir);

int cmpAirports(Airport* a1, Airport* a2);

int isCodeEqualsAirport(Airport* pA, const char IATA[4]);

#endif /* AIRPORT_H_ */
