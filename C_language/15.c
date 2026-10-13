#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num);

    for(int i =num;i>=1;i--)
    {
        if(i!=num)putchar('\n');
        printf("%d",i);
        
    }

    return 0;
}