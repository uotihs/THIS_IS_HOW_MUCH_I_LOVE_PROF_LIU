#include<stdio.h>
#include<stdbool.h>

int main()
{
    int in;
    int indexEnd = 0;
    int index = 0;
    int min = __INT32_MAX__;
    int max = __INT32_MAX__+1;
    bool isComplete = 0;
    bool first = 1;
    scanf("%d",&indexEnd);

    while (scanf("%d",&in)!=EOF)
    {


        if(isComplete)
        {    
            
            index = 0;
            isComplete = 0;
            max = in;
            min = in;
        }
        if(index < indexEnd)
        {index++;}

        if(in > max)
        {max = in;}
        if(in < min)
        {min = in;}



        if(index == indexEnd)
        {
            isComplete = 1;
            if(first) first = 0;
            else {putchar('\n');}
            printf("%d",max);
            if(scanf("%d",&indexEnd)==EOF) break;
        }
    }
    if(index!=indexEnd)
    {
        putchar('\n');
        printf("%d",min);
    }
        
    

    return 0;
}