#include<stdio.h>

int main()
{
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);

    printf("%d\n",(a+b+c+d)+(a+b+c)*e+(c+d)*f +f+e*g+g);

    printf("%d",b*e*g+a*e*g+c*f+c*e*g+d*f);

    return 0;
}