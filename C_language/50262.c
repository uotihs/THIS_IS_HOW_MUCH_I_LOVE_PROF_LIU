#include<stdio.h>

int main()
{
    int testCase;
    scanf("%d",&testCase);
    int pos[testCase][2];
    for(int i=0;i<testCase;i++)
    {
        scanf("%d%d",&pos[i][0],&pos[i][1]);
    }

    int y[2];
    scanf("%d%d",&y[0],&y[1]);

    long long min = __INT64_MAX__;
    long long distance[testCase];
    for(int i=0;i<testCase;i++)
    {
        distance[i] = (pos[i][0]-y[0])*(pos[i][0]-y[0]) + (pos[i][1]-y[1])*(pos[i][1]-y[1]);
    }

    for(int i=0;i<testCase;i++)
    {
        if(distance[i] < min) min = distance[i];
    }

    int first = 1;
    for(int i=0;i<testCase;i++)
    {
        if(distance[i]==min) 
        {
            if(first == 1)
            {
                first = 0;
            }    
            else
            {
                putchar('\n');
            }
            printf("%d",i);
        }
    }


    return 0;
}