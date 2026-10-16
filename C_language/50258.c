#include<stdio.h>   

int main()
{
    int x1,y1,r1;
    int x2,y2,r2;
    scanf("%d%d%d",&x1,&y1,&r1);
    scanf("%d%d%d",&x2,&y2,&r2);

    int in1,in2;
    int in = 0,out = 0,on = 0;
    int first = 1;
    while (scanf("%d%d",&in1,&in2)!=EOF)
    {
        in = 0;out = 0;on = 0;

        if(first == 1)
        {
            first = 0;
        }
        else 
        {
            putchar('\n');
        }

        int distance1 =  (in1-x1) * (in1-x1) + (in2-y1) * (in2-y1);
        if(distance1 == r1*r1)
        {
            on = 1;
        }
        else if(distance1 <= r1*r1)
        {
            in = 1;
        }
        int distance2 =  (in1-x2) * (in1-x2) + (in2-y2) * (in2-y2);
        if(distance2 == r2*r2)
        {
            on = 1;
        }
        else if(distance2 <= r2*r2)
        {
            in = 1;
        }

        if(in == 1)
        {
            printf("In");
        }
        else if(on == 1)
        {
            printf("On");
        }
        else
        {
            printf("Out");
        }

    }
    return 0;
}