#include <stdio.h>
#include <stdlib.h>
#include "date.h"
#include "functions.h"

int initDate(Date* pDate)
{
	if(!pDate)
	{
		printf("invalid date pointer");
		return 0;
	}
	int flag = 0;

	// read date from user until date is legal
	do {
		printf("\nPlease enter date in this format (dd/mm/yyyy): ");
		if(scanf("%d/%d/%d", &pDate->day, &pDate->month, &pDate->year) == 3)
		{
			if(!isLegalDate(pDate))
				printf("\nInvalid date! Please try again");
			else
				flag = 1;
		}
		else
		{
			printf("Invalid date format! Please try again. ");
			cleanBuffer();
		}
	} while (!flag);

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

/* returns 1 if date is legal */
int isLegalDate(const Date* pDate)
{
	if(!pDate)
		return 0;

	if(pDate->day == 0 || pDate->day > 31)
	{
		printf("There cannot be a day less than 1 or more than 31. ");
		return 0;
	}

	if(pDate->month == 2 && pDate->day > 28)
	{
		printf("There are only 28 days in February. ");
		return 0;
	}

	if(pDate->day == 31)
		if(pDate->month == 4 || pDate->month == 6 || pDate->month == 9 || pDate->month == 11)
		{
			printf("There are only 30 days in month #%d", pDate->month);
			return 0;
		}

	if(pDate->year < MIN_YEAR || pDate->year > MAX_YEAR)
	{
		printf("There can only be flights in these range of years %d-%d", MIN_YEAR, MAX_YEAR);
		return 0;
	}

	return 1;
}
