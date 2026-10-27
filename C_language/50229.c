#include<stdio.h>

typedef struct cup
{
    int capacity;
    int volume;
}Cup;



int main()
{
    int cupNum;
    scanf("%d",&cupNum);

    Cup cups[cupNum];

    for(int i=0;i<cupNum;i++)
        scanf("%d",&(cups[i].capacity));
    for(int i=0;i<cupNum;i++)
        scanf("%d",&(cups[i].volume));


    int op1,op2;
    while (scanf("%d%d",&op1,&op2)!=EOF)
    {
        if(op1 == cupNum && op2 < cupNum) 
        {
            cups[op2].volume = cups[op2].capacity;
            continue;
        }
        if(op2 == cupNum && op1 < cupNum)
        {
            cups[op1].volume = 0;
            continue;
        }
        if(op1 < cupNum && op2 < cupNum)
        {
            cups[op2].volume += cups[op1].volume;
            cups[op1].volume = 0;
            if(cups[op2].volume > cups[op2].capacity)
            {
                cups[op1].volume = cups[op2].volume - cups[op2].capacity;
                cups[op2].volume = cups[op2].capacity;
            }
            continue;
        }
    }
    
    for(int i=0;i<cupNum;i++)
    {
        if(i!=0) putc(' ',stdout);
        printf("%d",cups[i].volume);
    }


    return 0;
}