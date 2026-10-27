#include<stdio.h>

enum TYPES{GOOD,R2SML,R2BIG,C2SML,C2BIG,RIGHTUP};

int inMap(int r,int c,int N)
{
    return (r>=0 && c>=0 && r<N && c<N);
}

int main()
{
    int N,k,r,c;
    scanf("%d%d%d%d",&N,&k,&r,&c);
    
    int map[N][N];
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    map[i][j]=0;
    
    int nowR=r,nowC=c;
    for(int i=k;i>=1;i--)
    {
        map[nowR][nowC] = i;

        int tpnowR,tpnowC;
        tpnowR=nowR+1;
        tpnowC=nowC-1;
        if(inMap(tpnowR,tpnowC,N))
        {

        }
        else
        {
            if(tpnowR<0) tpnowR=N-1;
            if(tpnowR>=N) tpnowR=0;
            if(tpnowC<0) tpnowC=N-1;
            if(tpnowC>=N) tpnowC=0;
        }

        if(map[tpnowR][tpnowC]!=0)
        {
            tpnowR = nowR-1;
            tpnowC = nowC;
            if(inMap(tpnowR,tpnowC,N))
            {

            }
            else
            {
                if(tpnowR<0) tpnowR=N-1;
                if(tpnowR>=N) tpnowR=0;
                if(tpnowC<0) tpnowC=N-1;
                if(tpnowC>=N) tpnowC=0;
            }
        }
        nowR=tpnowR;
        nowC=tpnowC;
    }

    nowR=r;nowC=c;
    for(int i=k;i<=N*N;i++)
    {
        map[nowR][nowC] = i;

        int tpnowR,tpnowC;
        tpnowR=nowR-1;
        tpnowC=nowC+1;
        if(inMap(tpnowR,tpnowC,N))
        {

        }
        else
        {
            if(tpnowR<0) tpnowR=N-1;
            if(tpnowR>=N) tpnowR=0;
            if(tpnowC<0) tpnowC=N-1;
            if(tpnowC>=N) tpnowC=0;
        }

        if(map[tpnowR][tpnowC]!=0)
        {
            tpnowR = nowR+1;
            tpnowC = nowC;
            if(inMap(tpnowR,tpnowC,N))
            {

            }
            else
            {
                if(tpnowR<0) tpnowR=N-1;
                if(tpnowR>=N) tpnowR=0;
                if(tpnowC<0) tpnowC=N-1;
                if(tpnowC>=N) tpnowC=0;
            }
        }
        nowR=tpnowR;
        nowC=tpnowC;
    }



    for(int i=0;i<N;i++)
    {
        if(i!=0) putchar('\n');
        for(int j=0;j<N;j++)
        {
            if(j!=0) putchar(' ');
            printf("%d" ,map[i][j]);
        }

    }





    return 0;
}