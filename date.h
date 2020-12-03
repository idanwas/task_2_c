#ifndef DATE_H_
#define DATE_H_

typedef struct
{
	int day;
	int month;
	int year;
}Date;


int initDate(Date* pDate);

void printDate(Date* date);

void freeDate(Date* pDate);

int getDateValuesFromStr(char* date, int* day, int* month, int* year);

int checkDate(Date* pDate);

#endif /* DATE_H_ */
