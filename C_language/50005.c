#include<stdio.h>

int main()
{
    int bigLen,smlLen,misMatchLimit,diffLimit;
    scanf("%d%d%d%d",&bigLen,&smlLen,&misMatchLimit,&diffLimit);

    int bigMatrix[bigLen][bigLen];
    for(int i=0;i<bigLen;i++)
    {
        for(int j=0;j<bigLen;j++)
        {
            scanf("%d",&bigMatrix[i][j]);
        }
    }

    int smlMatrixSum = 0;
    int smlMatrix[smlLen][smlLen];
    for(int i=0;i<smlLen;i++)
    {
        for(int j=0;j<smlLen;j++)
        {
            scanf("%d",&smlMatrix[i][j]);
            smlMatrixSum+=smlMatrix[i][j];
        }
    }



    int leftUpR = -1,leftUpC = -1;
    for(int i=0;i<=bigLen-smlLen;i++)
    {
        for(int j=0;j<=bigLen-smlLen;j++)
        {

            int misMatchCount = 0;
            int sumTemp=0;

            for(int a=0;a<smlLen;a++)
            {
                for(int b=0;b<smlLen;b++)
                {
                    if(bigMatrix[i+a][j+b]==smlMatrix[a][b])
                    {

                    }
                    else
                    {
                        misMatchCount++;
                    }

                    sumTemp += bigMatrix[i+a][j+b];

                    if(misMatchCount>misMatchLimit) break;
                }
                if(misMatchCount>misMatchLimit) break;

            }

            if(misMatchCount>misMatchLimit) continue;



            if(sumTemp - smlMatrixSum <= diffLimit && -(sumTemp - smlMatrixSum) <= diffLimit)
            {
                leftUpR = i;leftUpC = j;
            }
        }
    }


    printf("%d %d",leftUpR,leftUpC);





    return 0;
}