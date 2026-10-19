#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int first = 1;

    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    if(i-j>=0 && i-j > n )continue;
                    if(j-i>=0 && j-i > n )continue;
                    if(j-k>=0 && j-k > n )continue;
                    if(k-j>=0 && k-j > n )continue;
                    if(k-l>=0 && k-l > n )continue;
                    if(l-k>=0 && l-k > n )continue;

                    if(first == 1)
                    {
                        first = 0;
                    }
                    else
                    {
                        putchar('\n');
                    }
                    printf("%d%d%d%d",i,j,k,l);


                }
            }
        }
    }


    return 0;
}