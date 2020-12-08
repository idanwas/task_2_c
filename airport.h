#ifndef AIRPORT_H_
#define AIRPORT_H_

typedef struct
{
	char* name;
	char* country;
	char IATA[4];
}Airport;

int initAirport(Airport* pAir);

void printAirport(const Airport* pAir);

void freeAirport(Airport* pAir);

int cmpAirports(const Airport* a1, const Airport* a2);

int isCodeEqualsAirport(const Airport* pA, const char IATA[4]);

char* fixAirportName(char* name);

int isLegalCode(const char* IATA);

#endif /* AIRPORT_H_ */
