#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num);

    if(num % 3 ==0 && num % 5 ==0 && num%7 !=0)
    {
        printf("0");
    }
    else
    {
        printf("1");
    }

    return 0;
}