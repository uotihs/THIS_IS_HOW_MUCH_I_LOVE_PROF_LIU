#include<stdio.h>

int main()
{
    int bigr,smlr;
    scanf("%d%d",&bigr,&smlr);
    int matrix[bigr][bigr];
    for(int i=0;i<bigr;i++)
        for(int j=0;j<bigr;j++)
            scanf("%d",&matrix[i][j]);
    int fliter[smlr][smlr];
    for(int i=0;i<smlr;i++)
        for(int j=0;j<smlr;j++)
            scanf("%d",&fliter[i][j]);

    int times = bigr-smlr+1;

    for(int i=0;i<times;i++)
    {
        if(i!=0) putchar('\n');
        for(int j=0;j<times;j++)
        {
            if(j!= 0) putchar(' ');
            long long ans = 0;
            for(int a=0;a<smlr;a++)
            {
                for(int b=0;b<smlr;b++)
                {
                    ans+= matrix[i+a][j+b]*fliter[a][b];
                }
            }
            printf("%lld",ans);
        }
    }
    
    



    return 0;
}