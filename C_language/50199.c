#include<stdio.h>

int inMap(int r,int c,int row,int col)
{
    return r>=0 && r<row && c>=0 && c<col;
}

int hasNear(int r,int c,int row,int col,int map[row][col],int num)
{
    int count = 0;
    if(inMap(r+1,c,row,col)&& map[r+1][c]==num)
        count++;
    if(inMap(r-1,c,row,col)&& map[r-1][c]==num)
        count++;
    if(inMap(r,c+1,row,col)&& map[r][c+1]==num)
        count++;
    if(inMap(r,c-1,row,col)&& map[r][c-1]==num)
        count++;

    return count;
}

int deleteAllNear(int r,int c,int row ,int col,int map[row][col],int num)
{
    map[r][c] = 0;

    if(inMap(r+1,c,row,col)&& map[r+1][c]==num)
        map[r+1][c] = 0;
    if(inMap(r-1,c,row,col)&& map[r-1][c]==num)
        map[r-1][c] = 0;
    if(inMap(r,c+1,row,col)&& map[r][c+1]==num)
        map[r][c+1] = 0;
    if(inMap(r,c-1,row,col)&& map[r][c-1]==num)
        map[r][c-1] = 0;

    return 1;
}


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

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(hasNear(i,j,row,col,map,map[i][j]) >= 2)
                deleteAllNear(i,j,row,col,map,map[i][j]);
        }
    }

    for(int i = 0 ; i < row ; i ++ )
    {
        if(i!=0)putchar('\n');
        for(int j = 0 ; j < col ; j ++ )
        {
            if(j!=0)putchar(' ');

            printf("%d",map[i][j]);
        }
    }


    
    



    return 0;
}