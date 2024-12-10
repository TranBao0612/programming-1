#include <time.h>
#include <stdio.h>

void sprint_time(char* outstr, struct tm* info)
{
    char buffer[50];
    sprintf(buffer, outstr, info->tm_hour, info->tm_min, info->tm_sec);

    printf("%s\n", buffer);
}

void sprint_date(char* outstr, struct tm* info)
{
    char buffer[50];
    char *weekday[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char *wday = weekday[info->tm_wday];
    sprintf(buffer, outstr, wday, info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);

    printf("%s\n", buffer);
}

int main()
{
    time_t current_time = time(NULL);
    struct tm* info = localtime(&current_time);

    // print current time
    info->tm_hour; // hour
    info->tm_min; // minute
    info->tm_sec; // second

    // print current date
    info->tm_mday; // day
    info->tm_mon + 1; // month
    info->tm_year + 1900; // year

    info->tm_wday; // day of the week: 0 -> Sun, 1 -> Mon, ...


    char outstr1[50] = "Current time is: %.2d:%.2d:%.2d";
    char outstr2[50] = "Today is %s, %.2d/%.2d/%.4d";

    sprint_time(outstr1, info);
    sprint_date(outstr2, info);


    return 0;
}

