#include<stdio.h>
#include<stdbool.h>


int main()
{
    int row,col;
    scanf("%d%d",&row,&col);

    int map[row][col];

    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    map[i][j]=0;


    int pr,pc,energy;
    scanf("%d%d%d",&pr,&pc,&energy);
    map[pr][pc] = energy;

    int stoneCount;
    scanf("%d",&stoneCount);

    for(int i=0;i<stoneCount;i++)
    {
        int rt,ct,wt;
        scanf("%d%d%d",&rt,&ct,&wt);
        map[rt][ct] = wt;
    }

    int in;
    bool first = 1;
    while (scanf("%d",&in)!=EOF)
    {
        bool canMove = false;
        int space = -1;
        int totalObs=0;
        switch (in)
        {
        case 0: //out put the mapppppppppp

            if(first)first=0;
            else putchar('\n');
            
            for(int i=0;i<row;i++)
            {
                if(i!=0)putchar('\n');
                for(int j=0;j<col;j++)
                {
                    if(j!=0) putchar(' ');
                    printf("%d",map[i][j]);
                }
                
            }        

            break;
        case 1://x+1

            
            for(int i=pc+1;i<col;i++)
            {
                totalObs += map[pr][i];
                if(map[pr][i]==0)
                {
                    space = i;
                    canMove = true;
                    break;
                }
            }
            if(canMove && totalObs <= energy)
            {
                for(int i=space;i>pc;i--)
                {
                    map[pr][i] = map[pr][i-1];
                }
                map[pr][pc]=0;
                pc+=1;
                energy-=totalObs;
                map[pr][pc]=energy;
            }


            break;
        case 2://y+1

            
            for(int i=pr+1;i<row;i++)
            {
                totalObs += map[i][pc];
                if(map[i][pc]==0)
                {
                    space = i;
                    canMove = true;
                    break;
                }
            }
            if(canMove && totalObs <= energy)
            {
                for(int i=space;i>pr;i--)
                {
                    map[i][pc] = map[i-1][pc];
                }
                map[pr][pc]=0;
                pr+=1;
                energy-=totalObs;
                map[pr][pc]=energy;
            }

            break;
        case 3://x-1

            
            for(int i=pc-1;i>=0;i--)
            {
                totalObs += map[pr][i];
                if(map[pr][i]==0)
                {
                    space = i;
                    canMove = true;
                    break;
                }
            }
            if(canMove && totalObs <= energy)
            {
                for(int i=space;i<pc;i++)
                {
                    map[pr][i] = map[pr][i+1];
                }
                map[pr][pc]=0;
                pc-=1;
                energy-=totalObs;
                map[pr][pc]=energy;
            }

            break;
        case 4://y-1

            
            for(int i=pr-1;i>=0;i--)
            {
                totalObs += map[i][pc];
                if(map[i][pc]==0)
                {
                    space = i;
                    canMove = true;
                    break;
                }
            }
            if(canMove && totalObs <= energy)
            {
                for(int i=space;i<pr;i++)
                {
                    map[i][pc] = map[i+1][pc];
                }
                map[pr][pc]=0;
                pr-=1;
                energy-=totalObs;
                map[pr][pc]=energy;
            }


            break;
        }







    }
    






    return 0;
}