#include<stdio.h>
#include<stdbool.h>

int main()
{

    int row,col;
    scanf("%d%d",&row,&col);

    int matrix[row][col];

    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    scanf("%d",&(matrix[i][j]));


    int x[4] = {0,0,1,-1};
    int y[4] = {1,-1,0,0};
    bool isFirst = true;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            bool isLarger = true;
            for(int k=0;k<4;k++)
            {
                if( (i + x[k]) < row && (i + x[k]) >= 0 && (j + y[k]) < col  && (j + y[k]) >= 0)
                {
                    if(matrix[i+x[k]][j+y[k]] >= matrix[i][j]) 
                    {
                        isLarger = false;
                        break;
                    }
                }
            }
            if(!isFirst && isLarger) putchar('\n');
            if(isLarger) {printf("%d", matrix[i][j]); isFirst = false;}

        }
    }



    return 0;
}