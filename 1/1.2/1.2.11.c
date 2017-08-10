#include <stdlib.h>
#include <stdio.h>

typedef struct date
{
    int year;
    int month;
    int day;

    void (*init)(struct date *today , int year , int month , int day);
}date;

int get_day(int year)
{
    if( (year % 4 == 0&& year % 100 != 0) || (year % 400) == 0 )
        return 29;
    else
        return 28;
}

void init(date *today , int year , int month , int day)
{
    if(year <= 0)
    {
        puts("year error");
        exit(EXIT_FAILURE);
    }
    else
        today->year = year;

    if(month < 1 || month > 12)
    {
        puts("month error");
        exit(EXIT_FAILURE);
    }
    else
        today->month = month;

    int month_day[13] = {-1 , 31 , -1 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
    month_day[2] = get_day(year);

    if(day < 0 || day > month_day[month])
    {
        puts("day error");
        exit(EXIT_FAILURE);
    }
    else
        today->day = day;
}

int main(void)
{
    int y;
    int m;
    int d;

    scanf("%d%d%d", &y,&m,&d);

    date today;
    today.init = init;
    today.init( &today , y , m , d);

    return 0;
}
