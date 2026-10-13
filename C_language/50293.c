#include<stdio.h>


int main()
{
    int nums;
    scanf("%d",&nums);

    int powerLast=0,peopleCount=0,last = 0,now = 0,nowpower;

    int first = 2,firstcount = 0,firstpower = 0;
    int anotherCheck = 0;
    for(int index = 0 ;index < nums ; index++)
    {
        int in;
        scanf("%d",&in);

        if(in == last)
        {
            nowpower = in;
            now++;
        }
        else
        {
            if(first)
            {
                firstcount = now;
                firstpower = nowpower;
                first -= 1;
            }
            nowpower = in;
            now = 1;
        }
    

        if(nowpower*now > powerLast*peopleCount || nowpower*now == powerLast*peopleCount && nowpower < powerLast)
        {
            powerLast = nowpower;
            peopleCount = now;
            if(nowpower == firstpower && index == nums -1)
            {
                anotherCheck = 1;
            } 
        }
        last = in;
    }

    if(powerLast != firstpower)
    {
        int newcount = now+firstcount;
        
        if(nowpower*newcount > powerLast*peopleCount || nowpower*newcount == powerLast*peopleCount && nowpower < powerLast)
        {
            powerLast = nowpower;
            peopleCount = newcount; 
        }
        
    }
    else if(powerLast == firstpower && anotherCheck)
    {
        peopleCount += firstcount;
    }

    printf("%d %d",powerLast,peopleCount);



    return 0;
}