#include<stdio.h>
#include<string.h>
void cal_tzolkin(int h_day, char* h_mon, int h_year);
int find_index(const char* str);
int main()
{
    int i=0, num, haab_day, haab_year;
    char haab_mon[10];
    scanf("%d", &num);
    printf("%d\n", num);
    
    while ( i++ < num )
    {
        scanf("%d. %s %d", &haab_day, haab_mon, &haab_year);
        cal_tzolkin(haab_day, haab_mon, haab_year);        
    }

    return 0;
}

void cal_tzolkin(int h_day, char* h_mon, int h_year)
{
    char* tzolkin_days[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    int index, total_days, days_of_year, year;
    char day[10];

    //convert to the time stamp, and then transform together.
    total_days = h_year*365 + find_index(h_mon)*20 + h_day;
    year = total_days / 260;
    days_of_year = total_days % 260;
    strcpy(day,tzolkin_days[(days_of_year) % 20]); 
    printf("%d %s %d\n", (days_of_year) % 13 + 1, day, year); 
}

int find_index(const char* str)
{
    char* haab_mons[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    int i=0;
    for(; i<19; i++)
        if(strcmp(haab_mons[i], str) == 0)
            return i;
    return -1;
}
