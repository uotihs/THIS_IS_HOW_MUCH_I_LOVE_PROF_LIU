#include<stdio.h>



int main()
{
    int X,Y;
    scanf("%d%d",&X,&Y);


    int balls[2][2];
    int ballsDirect[2][2];

    for(int i=0;i<2;i++)
    {
        scanf("%d%d",&(balls[i][0]),&(balls[i][1]));
    }


    for(int i=0;i<2;i++)
    {
        scanf("%d%d",&(ballsDirect[i][0]),&(ballsDirect[i][1]));
    }

    int time;
    scanf("%d",&time);


    for(int now=0;now<time;now++)
    {

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                balls[i][j] += ballsDirect[i][j];
            }

            if( balls[i][0] <1 || balls[i][0] > X )
            {
                ballsDirect[i][0] = -ballsDirect[i][0];
                balls[i][0] += 2*ballsDirect[i][0];
            }

            if( balls[i][1] <1 || balls[i][1] > Y )
            {
                ballsDirect[i][1] = -ballsDirect[i][1];
                balls[i][1] += 2*ballsDirect[i][1];
            }
        }


        if(balls[0][0]==balls[1][0] && balls[0][1]==balls[1][1])
        {
            int temp1 = ballsDirect[0][0];
            int temp2 = ballsDirect[0][1];

            
            ballsDirect[0][0] = ballsDirect[1][0];
            ballsDirect[0][1] = ballsDirect[1][1];

            ballsDirect[1][0] = temp1;
            ballsDirect[1][1] = temp2;
        }

    }
    printf("%d\n%d\n%d\n%d",balls[0][0],balls[0][1],balls[1][0],balls[1][1]);

    return 0;
}