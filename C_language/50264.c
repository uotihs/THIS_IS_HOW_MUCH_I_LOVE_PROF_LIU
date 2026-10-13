#include<stdio.h>


int main()
{
    int N, M, L, W;
    scanf("%d%d%d%d",&N,&M,&L,&W);
    int sun[N][M];

    int shadowr,shadowc,x,y;
    scanf("%d%d",&x,&y);
    shadowr = N - y -1;
    shadowc = x ;
    

    int stepLength,steps;
    scanf("%d%d",&stepLength,&steps);


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d",&(sun[i][j]));
        }
    }
    
    int first = 1;
    
    for(int i=0;i<=steps;i++)
    {
        if(0>shadowr || N<=shadowr-L+1 || M <= shadowc ||  0 > shadowc+W-1)
        {
            shadowc -= stepLength;
            shadowr += stepLength;
            continue;
        }
        
        if(i!=0 && !first)
        {
            putchar('\n');putchar('\n');
        }

        for(int j=0;j<N;j++)
        {
            if(j!=0) putchar('\n');

            for(int k=0;k<M;k++)
            {
                if(k!=0) putchar(' ');
                
                if(j<=shadowr && j>=shadowr-L+1 && k >= shadowc && k <= shadowc+W-1)
                {
                    printf("0");
                }
                else
                {
                    printf("%d",sun[j][k]);
                }
            }
            first =0;
        }
        

        shadowc -= stepLength;
        shadowr += stepLength;
        
    }




    return 0;
}