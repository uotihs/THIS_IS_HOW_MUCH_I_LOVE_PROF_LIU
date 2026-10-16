#include<stdio.h>

int main()
{
    int testcases;
    scanf("%d",&testcases);
    double miu = 0.0;
    double sigma = 0.0;
    double rem[testcases];
    for( int i = 0 ; i < testcases ; i++ )
    {
        scanf("%lf",&rem[i]);
        miu += rem[i];
    }
    miu /= testcases;
    for( int i = 0 ; i < testcases ; i++ )
    {
        sigma += (rem[i] - miu)*(rem[i] - miu);
    }
    sigma /= testcases;

    printf("%lf\n%lf",miu,sigma);

    return 0;
}