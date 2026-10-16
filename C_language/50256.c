#include<stdio.h>

long long AreaOfRect(int a,int b,int c,int d)
{
    return (c*d);
}


int main()
{
    int testCases;
    long long sum = 0;
    scanf("%d",&testCases);

    int Rect1[4];
    for(int i=0;i<4;i++)
    {
        scanf("%d",&(Rect1[i]));
    }
    sum += AreaOfRect(Rect1[0],Rect1[1],Rect1[2],Rect1[3]);

    for(int i=1;i<testCases;i++)
    {
        int Rect2[4];
        for(int i=0;i<4;i++)
        {
            scanf("%d",&(Rect2[i]));
        }
        sum += AreaOfRect(Rect2[0],Rect2[1],Rect2[2],Rect2[3]);

        sum -= AreaOfRect(Rect2[0],Rect2[1],Rect2[0]-(Rect1[0]+Rect1[2]),Rect2[1]-(Rect1[1]+Rect1[3]));



        for(int i=0;i<4;i++)
        {
            Rect1[i] = Rect2[i];
        }

    }
    printf("%lld",sum);


    return 0;
}