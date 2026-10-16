#include<stdio.h>

int gcd(int x,int y)
{
    if(x==0&&y==0)return 1;
    if(x==0) return y;
    if(y==0) return x;

    if(x < y) return gcd(y,x);

    while (y!=0)
    {
        int tp = y;
        x = x % y;
        y = x;
        x = tp;
    }
    return x;
    
}

int main()
{
    int array[4] = {0};
    int first = 1;
    while(scanf("%d",&array[0])!=EOF)
    {
        if(first == 1)
        {
            first = 0;
        }
        else
        {
            putchar('\n');
        }
        int max = array[0];
        for(int i=1;i<4;i++)
        {
            scanf("%d",&array[i]);
            if(array[i] > max) max = array[i];
        }
        int sum = 1;
        int tp = gcd(array[0],array[1]);
        sum *= (array[0])*( array[1] / tp);
        tp = gcd(sum,array[2]);
        sum *= array[2]/tp;
        tp = gcd(sum,array[3]);
        sum *= array[3]/tp;

        sum/=max;
        printf("%d",sum);
    }

    

    


    return 0;
}