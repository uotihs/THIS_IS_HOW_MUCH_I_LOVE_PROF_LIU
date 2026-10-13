#include<stdio.h>

int main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    long long surSum=0,volSum=0;

    surSum += a*c*2 + b*c*2+a*b*2;
    surSum += d*((a-2*e)*8+(b-2*e)*8+(c-2*e)*8);

    printf("%lld\n",surSum);

    volSum += a*b*c;
    volSum -= 2*( (a-2*e)*(b-2*e)*d + (a-2*e)*(c-2*e)*d +(c-2*e)*(b-2*e)*d );
    
    printf("%lld",volSum);

    return 0;
}