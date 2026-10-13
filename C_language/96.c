#include<stdio.h>
#define PI 3.1415926

int main()
{
    double a , b , c ,sum=0;
    scanf("%lf%lf%lf",&a,&b,&c);

    sum += c*c*PI*1.0/4.0;
    if(c > a)
    {
        sum+= c*c*PI*1.0/4.0;
        sum+= (c-a)*(c-a)*PI*1.0/4.0;
    }
    else
    {
        sum += c*c*PI*1.0/4.0;
    }

    if(c > b)
    {
        sum+= c*c*PI*1.0/4.0;
        sum+= (c-b)*(c-b)*PI*1.0/4.0;
    }
    else
    {
        sum += c*c*PI*1.0/4.0;
    }

    printf("%f",sum);

    return 0;
}