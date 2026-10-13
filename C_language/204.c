#include<stdio.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef struct pos
{
    int row;
    int col;
    int direction;
}Pos;

typedef struct dire
{
    int r;
    int c;
}Dire2D;

int turn_if_mirror(int direction)
{
    if(direction == UP ) return RIGHT;
    if(direction == DOWN) return LEFT;
    if(direction == LEFT) return DOWN;
    if(direction == RIGHT) return UP;
}

Pos InWindow(int in, int row ,int col)
{
    Pos ret;
    if(in >= row +2*col)
    {
        ret.row = in - (row + 2*col);
        ret.col = 0;
        ret.direction = RIGHT;
        //r = in - (row + 2*col )
        //c = 0
    }
    else if(in >= row+col)
    {
        ret.row = 0;
        ret.col = -(in - (row + 2*col-1));
        ret.direction = DOWN;
        //r = 0
        //c = -(in - (row + 2*col-1))
    }
    else if(in >=col)
    {
        ret.row = -(in-(col+row-1));
        ret.col = col-1;
        ret.direction = LEFT;
        //r = -(in-(col+row-1))
        //c = col-1
    }
    else
    {
        ret.row = row-1;
        ret.col = in;
        ret.direction = UP;
        //r = row -1
        //c = in
    }

    return ret;
}

int OutWindow(int row , int col , int direction,int rowAll,int colAll)
{
    if(direction == UP)
    {
        return colAll-col+rowAll+colAll-1;
    }
    else if(direction == DOWN)
    {
        return col;
    }
    else if(direction == LEFT)
    {
        return 2*colAll+rowAll+row;
    }
    else
    {
        return colAll+rowAll-1-row;
    }
}

Dire2D turn_2_dire(int turn)
{
    Dire2D ret;
    if(turn == UP)
    {
        ret.r = -1;
        ret.c = 0;
    }
    if(turn == DOWN)
    {
        ret.r = 1;
        ret.c = 0;
    }
    if(turn == LEFT)
    {
        ret.r = 0;
        ret.c = -1;
    }
    if(turn == RIGHT)
    {
        ret.r = 0;
        ret.c = 1;
    }

    return ret;
}

int InMap(int r,int c,int row,int col)
{
    return r>=0 && r<row && c>=0 && c<col;
}

int main()
{
    // for(int i = 0;i<18;i++)
    // {
    //     Pos out ;
    //     out = InWindow(i,4,5);
    //     printf("index[%d] = %d %d\n",i,out.row,out.col);

    // }




    int row,col;
    scanf("%d%d",&col,&row);

    int map[row][col];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&(map[i][j]));
        }
    }

    for(int window = 0 ; window < 2*(row + col) ; window++)
    {
        Pos now = InWindow(window,row,col);
        

        


        while ((InMap(now.row,now.col,row,col)))
        {
            Dire2D next;

            if(map[now.row][now.col] == 1)
            {
                // printf("ooooorow = %d , col = %d , direct = %d \n",now.row,now.col,now.direction);
                int newDirect = turn_if_mirror(now.direction);
                now.direction = newDirect;
            }

            next = turn_2_dire(now.direction);

            now.row += next.r;
            now.col += next.c;
        }
        Dire2D fix;
        fix = turn_2_dire(now.direction);
        now.row -= fix.r;
        now.col -= fix.c;

        if(window != 0) putchar('\n');

        // printf("row = %d , col = %d , direct = %d \n",now.row,now.col,now.direction);
        printf("%d",OutWindow(now.row,now.col,now.direction,row,col));

        





    }





    return 0;
}