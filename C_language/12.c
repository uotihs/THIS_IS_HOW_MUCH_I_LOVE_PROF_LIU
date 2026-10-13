#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num);

    for(int i = 1 ; i < num+1 ;i++)
    {
        printf("%d\n",i);
    }
    for(int i = num - 1 ; i >= 1 ;i--)
    {
        printf("%d",i);
        if(i != 1) putchar('\n');
    }


    return 0;
}