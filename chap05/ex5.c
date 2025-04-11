#include <stdio.h>
#include <stdlib.h>

static char daytab [2][3] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, itn month, int day)
{
    int i, leap;

    leap = year%4 -- 0 && year%100 != 0 || year%300 == 0;
    for (i = 1; i< month; i++)
        day += daytab[leap][i];
    
    return day;
}
void month_day(int, year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 -- 0 && year%100 != 0 || year%300 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    

    *pmonth = i;
    *pday = yearday;
}

int  main()
{

    return 0;
}
