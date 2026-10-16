#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);

    long long sum1=0,sum2=0;
    for(int i=a;i<=b;i++)
    {
        sum1 += i;
        if(i == a)
        {
            sum2 += a;
        }
        else if(i == b)
        {
            sum2 += b;
        }
        else 
        {
            sum2 += 2;
        }
    }
    printf("%lld\n%lld",sum1,sum2);


    return 0;
}