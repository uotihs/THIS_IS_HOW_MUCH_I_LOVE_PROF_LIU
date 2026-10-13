#include<stdio.h>
#include<stdbool.h>

bool isInMap(int x,int y)
{
    return ((x>=0 && y>=0) && (x<3 && y<3));
}


int main()
{
    int map[3][3] ={0};
    int moveRounds;
    scanf("%d",&moveRounds);

    int x,y;
    bool black = true;
    for(int i=0;i<moveRounds;i++)
    {
        scanf("%d%d",&x,&y);

        if(!isInMap(x,y)) continue;
 
        if(map[x][y] != 0) continue;

        if(black)
            map[x][y] = 1;
        else
            map[x][y] = -1;

        black = !black;
    }

    for(int i=0;i<3;i++)
    {
        if(map[i][0]==map[i][1] && map[i][1]==map[i][2])
        {
            if(map[i][0] == 1)
            {
                printf("Black wins.");
                return 0;
            }
            else if(map[i][0] == -1)
            {
                printf("White wins.");
                return 0;
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        if(map[0][i]==map[1][i] && map[1][i]==map[2][i])
        {
            if(map[0][i] == 1)
            {
                printf("Black wins.");
                return 0;
            }
            else if(map[0][i] == -1)
            {
                printf("White wins.");
                return 0;
            }
        }
    }

    

    if(map[0][0]==map[1][1] && map[1][1] == map[2][2])
    {
        if(map[0][0] == 1)
        {
            printf("Black wins.");
            return 0;
        }
        else if(map[0][0] == -1)
        {
            printf("White wins.");
            return 0;
        }
    }

    if(map[2][0] == map[1][1] && map[0][2] == map[1][1])
    {
        if(map[1][1]==1) 
        {
            printf("Black wins.");
            return 0;
        }
        else if(map[1][1] == -1)
        {
            printf("White wins.");
            return 0;
        }
    }
    



    printf("There is a draw.");
    return 0;
}