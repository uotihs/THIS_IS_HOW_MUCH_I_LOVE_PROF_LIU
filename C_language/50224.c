#include<stdio.h>

int main()
{
    int max = 0;
    int maxNum = 0;
    int maxIndex = 0;
    int in;
    while(scanf("%d",&in)!= EOF)
    {
        int sum = 0;
        int tp = in;
        int index = 0;
        while (in > 0)
        {
            sum += in % 10;
            index ++;
            in /= 10;
        }
        

        if(sum > max)
        {
            max = sum;
            maxNum = tp;
            maxIndex = index;
        }
        else if(sum == max)
        {
            if(index < maxIndex)
            {
                maxNum = tp;
                maxIndex = index;
            }
            else if(index == maxIndex)
            {
                if( tp > maxNum)
                {
                    maxNum = tp;
                }
            }
        }

    }
    printf("%d",maxNum);




}