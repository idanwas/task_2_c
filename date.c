
#include <stdio.h>

#include "date.h"


void initDate(Date* pDate)
{
	if(!pDate)
	{
		printf("invalid date pointer");
		return;
	}

	printf("\nPlease enter a day (1-Sunday,.. 7-Saturday): ");
	scanf("%d", &pDate->day);
	if(pDate->day > 7 || pDate->day < 1)
		pDate->day = pDate->day % 7 + 1;

	printf("\nPlease enter a month (1-January,.. 12-December): ");
	scanf("%d", &pDate->month);
	if(pDate->month > 12 || pDate->month < 1)
		pDate->month = pDate->month % 12 + 1;

	printf("\nPlease enter an year (2010-2030): ");
	scanf("%d", &pDate->year);
	if(pDate->year > 2030 || pDate->year < 2010)
		pDate->year = 2020;
}

void printDate(Date* pDate)
{
	printf("%2d/%2d/%4d", pDate->day, pDate->month, pDate->year);
}
