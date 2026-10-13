#include<stdio.h>

int main()
{
    int M;
    scanf("%d",&M);

    if(M>0 && M%2 ==0 && (M>10000 || M<1000))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }


    return 0;
}