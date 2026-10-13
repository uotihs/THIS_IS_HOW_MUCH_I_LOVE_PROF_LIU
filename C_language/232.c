#include<stdio.h>


int main()
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int year,dayType;
    scanf("%d%d",&year,&dayType);

    if(year % 4 == 0 && year % 100 != 0 || year%400 == 0 )
    {month[1] = 29;}

    int numCount;
    scanf("%d",&numCount);

    for(int index = 0 ;index<numCount;index++)
    {
        int monthIn,day;

        if(index!=0)putchar('\n');

        scanf("%d%d",&monthIn,&day);

        if(!(monthIn>=1 && monthIn<=12))
        {
            printf("-1");
            continue;
        }
        else if(month[monthIn-1] < day || day<=0)
        {
            printf("-2");
            continue;
        }
        else
        {
            int daysum = 0;
            for(int i=0;i<monthIn-1;i++)
            {
                daysum += month[i];
            }

            daysum+=day;
            daysum+=dayType;

            printf("%d",(daysum-1)%7);

        }

    }


    return 0;
}