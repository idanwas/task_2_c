#ifndef DATE_H_
#define DATE_H_
#define MIN_YEAR 2000
#define MAX_YEAR 2030

typedef struct
{
	int day;
	int month;
	int year;
}Date;

int initDate(Date* pDate);

void printDate(const Date* date);

void freeDate(Date* pDate);

int isLegalDate(const Date* pDate);

#endif /* DATE_H_ */
