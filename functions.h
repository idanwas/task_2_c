
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define MAX_LENGTH 255
#include "airport_manager.h"
#include "airline.h"

void cleanBuffer();

char* myGets(char* buf, size_t size);

char* getStrExactLength(const char* msg);

int countWords(char* str);

char* fixEvenCharsWord(char* word);

char* fixOddCharsWord(char* word, int flag);

char* readString(char* msg);

void printMenu();

#endif /* FUNCTIONS_H_ */
