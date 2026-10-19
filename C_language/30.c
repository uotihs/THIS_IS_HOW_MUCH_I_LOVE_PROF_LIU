#include<stdio.h>

void go(int r,int c,int row,int col,int map[row][col],int* count)
{
    if(map[r][c]==0)return;
    if(r<0 || c >= col) return;
    if(r==0 && c== col-1){(*count)++;return;}

    go(r-1,c,row,col,map,count);

    go(r,c+1,row,col,map,count);

}


int main()
{
    int row,col;
    scanf("%d%d",&row,&col);

    int map[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }

    int count = 0 ;
    go(row-1,0,row,col,map,&count);
    printf("%d",count);



    return 0;
}