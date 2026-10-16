#include<stdio.h>


int main()
{
    int year,month,dayType;

    scanf("%d%d%d",&year,&month,&dayType);

    int valid = 1;
    if(month<=0 ||month>12||dayType<0||dayType>6){valid = 0;}

    int map[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(year % 4 ==0 && year%100 != 0 || year % 400 == 0){map[1] = 29;}

    if(valid)
    {
        printf(" Su Mo Tu We Th Fr Sa\n");
        printf("=====================\n");

        int dayCount = map[month-1];
        for(int i=0;i<dayType;i++)
        {
            printf("   ");
        }
        for(int i=1;i<=dayCount;i++)
        {
            printf("%3d",i);
            if((i+dayType) % 7 == 0 || i == dayCount) putchar('\n');
        }
        printf("=====================\n");
    }
    else
    {
        printf("invalid");
    }


}