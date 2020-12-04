
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define MAX_LENGTH 255
#include "airport_manager.h"
#include "airline.h"


char* myGets(char* buf, size_t size);

char* getStrExactLength(const char* msg, int length);

void printMenu();

#endif /* FUNCTIONS_H_ */
