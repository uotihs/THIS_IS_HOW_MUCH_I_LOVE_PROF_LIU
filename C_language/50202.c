#include<stdio.h>

int main()
{
    int r,c,n;
    scanf("%d%d%d",&r,&c,&n);

    int ans[r-2*n+2][c-2*n+2];

    int in;
    int RowInd ;
    int colInd ;

    for(int i=0;i<r-2*n+2;i++)
    {
        for(int j=0;j<c-2*n+2;j++)
        {
            ans[i][j] = 0;
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&in);
            //  printf("pos = %d %d\n",i,j);
            for(int k=0;k<2*n-1;k++)
            {
                for(int l=0;l<2*n-1;l++)
                {
                    int rd = k-n+1; if(rd<0) rd = -rd;
                    int cd = l-n+1; if(cd<0) cd = -cd;
                    if(rd + cd == n-1)
                    {
                       
                        // printf("indexs = %d %d\n",i+k-n+1,j+l-n+1);
                        if( (i+k-n+1- (n-1)) >= 0 && (i+k-n+1- (n-1)) < (r-2*n+2) && (j+l-n+1- (n-1))>=0 && (j+l-n+1- (n-1))<(c-2*n+2) )
                        {
                            ans[i+k-n+1  - (n-1) ][j+l-n+1- (n-1)] += in;
                            // printf("pos = %d %d\n",i,j);
                            // printf("indexs = %d %d\n",i+k-n+1,j+l-n+1);
                        }
                    }
                        
                }
            }
        }
    }

    // printf("o%d",r-2*n+2);

    int max = -1;
    for(int i=0;i<(r-2*n+2);i++)
    {
        for(int j=0;j<(c-2*n+2);j++)
        {
            if(ans[i][j]>max) 
                max = ans[i][j];
            // else
            //     printf("?");
        }
    }
    printf("%d",max);

    // int map[r][c];
    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<c;j++)
    //     {
    //         scanf("%d",&map[i][j]);
    //     }
    // }

    // int ans = __INT32_MAX__+1;
    // for(int i=0;i<r-2*n+2;i++)
    // {
    //     for(int j=0;j<c-2*n+2;j++)
    //     {
    //         int anstp =0;
    //         for(int k=0;k<2*n-1;k++)
    //         {
    //             for(int l=0;l<2*n-1;l++)
    //             {
    //                 int rd = k-n+1; if(rd<0) rd = -rd;
    //                 int cd = l-n+1; if(cd<0) cd = -cd;
    //                 if(rd + cd == n-1)
    //                     anstp += map[i+k][j+l];
    //             }
    //         }

    //         if(anstp > ans) ans = anstp;
    //     }
    // }
    // printf("%d",ans);





    return 0;
}