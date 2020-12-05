
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "date.h"
#include "functions.h"


int initDate(Date* pDate)
{
	if(!pDate)
	{
		printf("invalid date pointer");
		return 0;
	}

	printf("\nPlease enter date in this format (dd/mm/yyyy): ");
	if(scanf("%d/%d/%d", &pDate->day, &pDate->month, &pDate->year) == 3)
	{
		if(!checkDate(pDate))
		{
			printf("\nInvalid date!");
			return 0;
		}
	}
	else
	{
		printf("\nInvalid date!");
		return 0;
	}

	return 1;
}

void printDate(const Date* pDate)
{
	printf("%d/%d/%d", pDate->day, pDate->month, pDate->year);
}

void freeDate(Date* pDate)
{
	if(!pDate)
		return;
	free(pDate);
}

int checkDate(const Date* pDate)
{
	if(!pDate)
		return 0;

	if(pDate->day == 0 || pDate->day > 31)
		return 0;
	if(pDate->month == 2 && pDate->day > 28)
		return 0;
	if(pDate->day == 31)
		if(pDate->month == 4 || pDate->month == 6 || pDate->month == 9 || pDate->month == 11)
			return 0;

	return 1;
}
