#include<stdio.h>

int roads(int x,int y,int r,int c,int* count)
{
    if(x==r-1&&y==c-1)
    {
        (*count) ++;
        return 0;
    }
    if(x>=r||y>=c) return 0;

    roads(x+1,y,r,c,count);

    roads(x,y+1,r,c,count);



}

int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int count = 0;

    roads(0,0,row,col,&count);

    printf("%d",count);


    return 0;
}