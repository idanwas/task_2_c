#ifndef DATE_H_
#define DATE_H_

typedef struct
{
	int day;
	int month;
	int year;
}Date;


void initDate(Date* pDate);

void printDate(Date* date);

#endif /* DATE_H_ */
