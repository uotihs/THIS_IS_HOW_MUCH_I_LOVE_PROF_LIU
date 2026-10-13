#include<stdio.h>


int main()
{
    int num,pow;
    scanf("%d%d",&num,&pow);

    long long sum =1;
    for(int i =0 ;i<pow;i++)
    {
        sum *= num;
    }

    printf("%lld",sum);


    return 0;
}