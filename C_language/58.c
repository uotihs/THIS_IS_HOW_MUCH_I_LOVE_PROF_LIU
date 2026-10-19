#include<stdio.h>

int inRect(int r,int c,int row,int col)
{
    return r>=0 && r<row && c>=0 && c<col;
}

void getLake(int r,int c,int row,int col,int map[row][col],int* count)
{
    if(inRect(r,c,row,col) == 0) return;
    if(map[r][c]==0) return;
    if(map[r][c]==1)
    {
        map[r][c] = 0;
        (*count) ++;
    }

    getLake(r+1,c,row,col,map,count);
    getLake(r-1,c,row,col,map,count);
    getLake(r,c+1,row,col,map,count);
    getLake(r,c-1,row,col,map,count);
    // getLake(r,c,row,col,map);
    // getLake(r,c,row,col,map);
    // int x[4] ={0,0,1,-1};
    // int y[4] ={1,-1,0,0};
    // for(int i=0;i<row;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     {

    //     }


    // }
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

    int ans[row*col/2];
    int index = 0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int count = 0;
            getLake(i,j,row,col,map,&count);
            if(count!=0)
            {
                ans[index] = count;
                index++;
            }
        }
    }
    for(int i=0;i<index;i++)
    {
        for(int j=1;j<index;j++)
        {
            if(ans[j]>ans[j-1])
            {
                int tp = ans[j-1];
                ans[j-1] = ans[j];
                ans[j] = tp;
            }
        }
    }
    for(int i=0;i<index;i++)
    {
        if(i!=0)putchar('\n');
        printf("%d",ans[i]);
    }

    return 0;
}