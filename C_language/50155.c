#include<stdio.h>

int main()
{
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);


    if(a*b*d>(a*b-e*f)*g)
    {
        if((a*b*d-(a*b-e*f)*g) / (a * b) > c - d)
        {
            printf("%d",c);
        }
        else
        {

            printf("%d",g+(a*b*d-(a*b-e*f)*g)/(a*b));
        }

    }
    else
    {
        printf("%d",a*b*d / (a*b-e*f));
    }
    return 0;
}