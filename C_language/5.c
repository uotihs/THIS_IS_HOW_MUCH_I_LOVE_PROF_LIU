#include<stdio.h>


int main()
{
    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);

    printf("%lld\n",2*(a*b+b*c+c*a));

    printf("%lld",a*b*c);


    return 0;
}