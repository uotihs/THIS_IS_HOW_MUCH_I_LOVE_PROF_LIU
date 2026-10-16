#include<stdio.h>

int main()
{
    int row,col,n;
    scanf("%d%d%d",&row,&col,&n);

    int x = row > col ? col : row;

    int index = 0;
    for(int i=0;i<x;i++)
    {
        index ++;
        if(index == n)
        {
            printf("%d %d",i+1,i+1);
        }

        for(int j=i+1;j<col;j++)
        {
            index++;
            if(index == n)
            {
                printf("%d %d",i+1,j+1);
            }
        }
        for(int j=i+1;j<row;j++)
        {
            index++;
            if(index == n)
            {
                printf("%d %d",j+1,i+1);
            }
        }
    }



    return 0;
}