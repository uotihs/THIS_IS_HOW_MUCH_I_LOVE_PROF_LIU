#include<stdio.h>

int main()
{
    int in,last;
    int first = 1;
    int count = 0;
    while (scanf("%d",&in)!=EOF)
    {
        if(first)
        {
            last = in > 0 ? 1 : 0;
            first = 0;
        }

        if(last && in > 0)
        {
            count++;
        }
        else if(last == 0 && in < 0)
        {
            count++;
        }
        else 
        {
            if(last)
            printf("%d ",count);
            else
            printf("%d ",-count);

            count = 1;
        }


        last = in > 0 ? 1 : 0 ;
    }
    if(last)
    printf("%d",count);
    else
    printf("%d",-count);

    
    return 0;
}