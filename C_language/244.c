#include<stdio.h>


int strcmp(char in[],char cp[])
{
    int count = 0;
    for(int i=7;i>=0;i--)
    {
        if(in[i] == cp[i])
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
    
}

int main()
{
    char specialP[3][9] = {0};
    char firstP[3][9] = {0}; 

    for(int i=0;i<3;i++)
    {
        scanf("%s",specialP[i]);
    }
    for(int i=0;i<3;i++)
    {
        scanf("%s",firstP[i]);
    }

    char in[9]={0};
    int sum = 0;
    while(scanf("%s",&in)!=EOF)
    {
        for(int i=0;i<3;i++)
        {
            if(strcmp(in,specialP[i]) == 8)
            {
                sum+= 2000000;
                continue;
            }
        }
        for(int i=0;i<3;i++)
        {
            int digits = strcmp(in,firstP[i]);
            if(digits == 8)
            {
                sum+= 200000;
                continue;
            }
            else if(digits == 7)
            {
                sum+= 40000;
                continue;
            }
            else if(digits == 6)
            {
                sum+= 10000;
                continue;
            }
            else if(digits == 5)
            {
                sum+= 4000;
                continue;
            }
            else if(digits == 4)
            {
                sum+= 1000;
                continue;
            }
            else if(digits == 3)
            {
                sum+= 200;
                continue;
            }
        }
        

    }
    printf("%d",sum);
    
// The first three lines of the input are the special prize numbers. 
//The second three lines are the first prize number. The rest of the input is the lottery numbers, one per line. All the numbers are positive integers between 10000000 and 99999999.
// You must process all numbers until the end of the file.






    return 0;
}