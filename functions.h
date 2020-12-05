
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define MAX_LENGTH 255
#include "airport_manager.h"
#include "airline.h"

void cleanBuffer();

char* myGets(char* buf, size_t size);

char* getStrExactLength(const char* msg, int length);

int countWords(char* str);

char* fixAirportName(char* name);

char* fixEvenCharsWord(char* word);

char* fixOddcharsWord(char* word, int flag);

void printMenu();

#endif /* FUNCTIONS_H_ */
