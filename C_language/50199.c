#include<stdio.h>




int main()
{
    int row,col;
    scanf("%d%d",&row,&col);

    int map[row][col];
    for(int i = 0 ; i < row ; i ++ )
    {
        for(int j = 0 ; j < col ; j ++ )
        {
            scanf("%d",&map[i][j]);
        }
    }


    
    



    return 0;
}