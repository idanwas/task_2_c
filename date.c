
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
	while(getchar() != '\n');

	/*char* date = getStrExactLength("\nPlease enter date in this format (dd/mm/yyyy): ", 0);
	if(!date)
		printf("\n something wrong with date");

	if(!getDateValuesFromStr(date, &pDate->day, &pDate->month, &pDate->year))
	{
		printf("wrong date format");
		return 0;
	}

	if(!checkDate(pDate))
		return 0;
*/

	printf("\nPlease enter date in this format (dd/mm/yyyy): ");
	if(scanf("%d/%d/%d", &pDate->day, &pDate->month, &pDate->year) == 3)
	{
		if(!checkDate(pDate))
			return 0;
	}
	else
		return 0;


	return 1;
}

void printDate(const Date* pDate)
{
	printf("%2d/%2d/%4d", pDate->day, pDate->month, pDate->year);
}

void freeDate(Date* pDate)
{
	if(!pDate)
		return;
	free(pDate);
}

/*int getDateValuesFromStr(char* date, int* pDay, int* pMonth, int* pYear)	// length("dd/mm/yyyy\0") = 11
{
	if(!date || strlen(date) != 11 || (date[2] != '/' && date[5] != '/'))
		return 0;

	if(!(isdigit(date[0]) && isdigit(date[1]) && isdigit(date[3]) && isdigit(date[4]) && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9])))
		return 0;

	*pDay = 10 * (date[0] - '0') + (date[1] - '0');
	*pMonth = 10 * (date[3] - '0') + (date[4] - '0');
	*pYear = 1000 * (date[6] - '0') + 100 * (date[7] - '0') + 10 * (date[8] - '0') + (date[9] - '0');

	return 1;
}*/

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
