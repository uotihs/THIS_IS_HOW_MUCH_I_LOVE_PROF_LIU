#include<stdio.h>

long long getAns(long long sum,long long a,long long b,long long c,long long a1,long long b1,long long c1)
{

    for(long long i=0;i<=a;i++)
    {
        for(long long j=0;j<=b;j++)
        {
            for(long long k=0;k<=c;k++)
            {
                if(i*a1 + j*b1 + k*c1 == sum)
                {
                    return 1;
                }
            }
        }
    }


    return 0;


}



int main()
{
    long long testCases;
    scanf("%lld",&testCases);

    for(long long i=0;i<testCases;i++)
    {
        if(i!=0) putchar('\n');

        long long sum,a,b,c,d,e,f;
        scanf("%lld%lld%lld%lld%lld%lld%lld",&sum,&a,&b,&c,&d,&e,&f);

        if(getAns(sum,a,b,c,d,e,f))
        {
            printf("yes");
        }
        else 
        {
            printf("no");
        }

        
    }

 



    return 0;
}