/* 
 * Filename:	date.c
 * Author:		Jess Turner
 * Date:		5-9-17
 * Licence:		GNU GPL V3
 *
 * Description: 
 *
 * Reads a date string in the form DD/MM/YYYY and determines if it is a valid date,
 * the day of the year, if that year is a leap year, and converts the date to a string
 *
 * Options:
 *	N/A
 *
 * Return/exit codes:
 *	0	EXEC_SUCCESS	- Successful execution
 *	1	MEM_ERROR		- Memory allocation error
 *	2	READ_ERROR		- fgets() error
 *
 * Todo:
 *	N/A
 *
 * Possible additions:
 *	- Add option(s) for taking different date forms (i.e. -a switches to American date formats)
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define EXEC_SUCCESS 0
#define MEM_ERROR 1
#define READ_ERROR 2

#define YEAR_MIN 1753
#define YEAR_MAX INT_MAX

typedef struct {
	int day;
	int month;
	int year;
} date_t;

const char *days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
};

const char *months[] = {
	NULL,
	"January",
	"February", 
	"March", 
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

const char *num_suffix[] = {
	"st",
	"nd",
	"rd",
	"th"
};

const int days_per_month[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

char *date_to_string(char **string, date_t date);	/* 	Converts the date in decimal form into a string
 														containing the day and name of the month */

int day_of_year(date_t date);						/*	Determines the day of the year from a given date */

inline int day_of_week(date_t date);				/*	Determines the numerical value of the day of the week
														(taking Sunday as the first day), only works on dates 
														after 14/09/1752 due to the adoption of the Gregorian
														calendar in the UK */

inline bool is_valid_date(date_t date);				/*	Checks if the specified day, month, and year values 
														make sense */

inline bool is_leap_year(date_t date);				/*	Determines whether or not the date occurs on a leap 
														year */

int main()
{
	date_t date;
	char *date_string;
	char input[128];
	char *format[] = { 
		"%d/%d/%d",
		"%d-%d-%d",
		"%d.%d.%d",
		"%d,%d,%d",
		"%d %d %d"
	};
	
	printf("Note: day of week only accurate after 14/09/1752\n");
	
	for(;;) {
		printf("\nEnter date: ");
		
		date = (const date_t){ 0 };
		
		if(!fgets(input, sizeof(input), stdin)) {
			fprintf(stderr, "\nError: fgets() read faliure!\n");
			return READ_ERROR;
		}
		
		for(int i = 0; i != 5; ++i)
			if(sscanf(input, format[i], &date.day, &date.month, &date.year) == 3)
				break;
	
		
		if(!is_valid_date(date)) {
			printf("Invalid date!\n");
			continue;
		}
		
		if(!date_to_string(&date_string, date)) {
			fprintf(stderr, "\nError: Memory allocation faliure!\n");
			return MEM_ERROR;
		}
		
		printf(	"The %s is a %s and is day %d of the year %d, which is %sa leap year\n",
				date_string,
				days[day_of_week(date)],
				day_of_year(date),
				date.year,
				is_leap_year(date) ? "" : "not "
		);
		
		free(date_string);
	}
	
	return EXEC_SUCCESS;
}

char *date_to_string(char **string, date_t date)
{
	char date_str[48] = { '\0' };
		
	sprintf(date_str,
			"%d%s of %s %d",
			date.day,
			num_suffix[	(date.day == 1 || date.day == 21 || date.day == 31) ? 0 :
						(date.day == 2 || date.day == 22)					? 1 :
						(date.day == 3 || date.day == 23)					? 2 : 3],
			months[date.month],
			date.year
	);

	if(!(*string = malloc((strlen(date_str) + 1) * sizeof(**string))))
		return NULL;
	
	strcpy(*string, date_str);
	
	return *string;
}

int day_of_year(date_t date)
{
	int day;
	int month;
	bool leap;
	
	leap = is_leap_year(date);
	
	for(day = 0, month = 1; month < date.month; month++)
		day += *(*(days_per_month + leap) + month);
	
	day += date.day;
	
	return day;
}

bool is_valid_date(date_t date)
{
	return	(date.year >= YEAR_MIN && date.year <= YEAR_MAX) && ((date.month > 0 && date.month < 13) && 
			((date.day > 0 && date.day <= days_per_month[0][date.month]) || 
			(date.day == 29 && date.month == 2 && is_leap_year(date))));
}

bool is_leap_year(date_t date)
{
	return	((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0);
}

int day_of_week(date_t date)
{
	return	(date.day += date.month < 3 ? date.year-- : date.year - 2, 23 * date.month / 9 + date.day + 4 +
			date.year / 4 - date.year / 100 + date.year / 400) % 7;  
}