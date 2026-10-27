
#include <stdio.h>
#include <stdlib.h>
#include "count_day.h"
 


void count_day(int year, int day, int month, int results[7])
{
    int map[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(year%4==0 && year%100!=0 || year%400==0)
    {
        map[1]=29;
    }

    int startDay = 0;
    for(int i=1;i<month;i++)
    {
        startDay+= map[i-1];
    }
    day = (startDay+day) % 7;
    
    //zero Sunday
    for(int i=day;i<7;i++)
    {
        results[i] = (map[month-1]-(i-day+1))/7+1;
    }
    for(int i=day-1;i>=0;i--)
    {
        results[i] = (map[month-1]-(7-(day-i-1)))/7+1;
    }


    return;
}


// int main(){
//     int year, day, month, results[7] = {0}, i;
 
//     while(scanf("%d %d %d", &year, &day, &month) == 3){
//         for(i = 0; i < 7; i++)
//             results[i] = 0;
//         count_day(year, day, month, results);
//         for(i = 0; i < 6; i++)
//             printf("%d ", results[i]);
//         printf("%d\n", results[i]);
//     }
//     return 0;
// }