#include<stdio.h>



int main()
{
    int num;
    scanf("%d",&num);

    for(int i = 1;i<num+1;i++)
    {
        for(int j = 1 ; j <= i ;j++)
        {
            printf("%d",j);
        }
    }

    return 0;
}