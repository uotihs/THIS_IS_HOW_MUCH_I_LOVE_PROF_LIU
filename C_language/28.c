#include<stdio.h>

unsigned long long square(unsigned long long now,unsigned long long end)
{
    if(now > end)
        return 0;
    
    return now*now + square(now+1,end);
}


int main()
{

    unsigned long long in;
    scanf("%llu",&in);
    printf("%llu",square(1,in));


    return 0;
}