#include<stdio.h>

#define PI 3.1415926



int inCircle(long long x,long long y,long long xc,long long yc,long long r)
{
    long long xt = xc-x;
    long long yt = yc-y;
    if(xt*xt + yt*yt <= r*r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int fixIn(int x)
{
    if(x>2)
    {
        x-=3;
    }
    return x;
}

int main()
{
    int testDataCounts;
    scanf("%d",&testDataCounts);

    for(int now=0;now<testDataCounts;now++)
    {
        long long circles[3][3];
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%lld",&(circles[i][j]));
            }
        }
        
        int count=0;

        
        for(int k=0;k<3;k++)
        {
            int len = circles[k][2];
            for(int i=-len;i<=len;i++)
            {
                for(int j=-len;j<=len;j++)
                {
                    int Num = 0;
                    if(inCircle(circles[k][0]+i,circles[k][1]+j,circles[k][0],circles[k][1],circles[k][2]))
                    {
                        Num ++;
                    }

                    if(Num == 0) continue;

                    if(inCircle(circles[k][0]+i,circles[k][1]+j,circles[fixIn(k+1)][0],circles[fixIn(k+1)][1],circles[fixIn(k+1)][2]))
                    {
                        Num ++;
                    }
                    if(inCircle(circles[k][0]+i,circles[k][1]+j,circles[fixIn(k+2)][0],circles[fixIn(k+2)][1],circles[fixIn(k+2)][2]))
                    {
                        Num ++;
                    }

                    if(k==0)
                    {
                        if(Num == 3 || Num == 1)
                        {
                            count ++;
                        }
                    }
                    else
                    {
                        if(Num == 1)
                        {
                            count++;
                        }
                    }

                }
            }

        }


        
        printf("%d",count);
        if(now != testDataCounts-1) putchar('\n');

    }

    return 0;
}