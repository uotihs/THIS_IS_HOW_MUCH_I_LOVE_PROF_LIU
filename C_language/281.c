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
        int count=0;
        while (in!=0)
        {
            if(in & 1 == 1)
            {
                count++;
            }
            in >>= 1;
        }
        printf("%d",count);
        
    }
    





}