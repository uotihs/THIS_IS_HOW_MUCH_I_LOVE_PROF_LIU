#include<stdio.h>

int main()
{
    int in;
    int first =1;
    while (scanf("%d",&in)!=EOF)
    {
        if(first == 1)
        {
            first = 0;
        }
        else
        {
            putchar('\n');
        }
        int count=1,max =0,last =0;
        while (in!=0)
        {
            if(in & 1 == 1 )
            {
                if(last == 1)
                    count++;
                last = 1;
            }
            else
            {
                max = max > count ? max : count; 
                count = 1;
                last = 0;
            }
            in >>= 1;
        }
        max = max > count ? max : count; 

        printf("%d",max);
        
    }
    





}