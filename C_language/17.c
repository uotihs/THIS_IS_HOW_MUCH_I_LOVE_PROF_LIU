#include<stdio.h>
#include<stdlib.h>

int main()
{
    int row,col;
    scanf("%d%d",&row,&col);

    int** matrix =(int **)malloc(sizeof(int*)*(size_t)row);
    for(int i=0;i<row;i++) matrix[i] = (int *)malloc(sizeof(int)*(size_t)col);

    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    scanf("%d",&(matrix[i][j]));
    
    for(int i=0;i<col;i++)
    {
        int sum =0;

        for(int j=0;j<row;j++){sum += matrix[j][i];}

        printf("%d", sum / row );

        if(i != col-1) putchar('\n');
    }


    for(int i=0;i<row;i++) free(matrix[i]);
    free(matrix);

    return 0;
}