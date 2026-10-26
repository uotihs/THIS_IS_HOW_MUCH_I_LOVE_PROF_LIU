#include<stdio.h>
#define GRIDLEN 4
#include<stdbool.h>


bool Move_The_Matrix(int map[GRIDLEN][GRIDLEN],int move,int* remR,int* remC)
{
    


}

bool isInMatrix(int r,int c)
{
    return r>=0 && r<GRIDLEN && c>=0 && c<GRIDLEN;
}



int main()
{
    int matrix[GRIDLEN][GRIDLEN];
    int remR,remC;
    for(int i = 0 ; i < GRIDLEN ; i++)
    {                
                      
        for(int j = 0 ; j < GRIDLEN ; j++)
        {
            scanf("%d",&(matrix[i][j]));

            if(matrix[i][j]==0)
            {
                remR = i;
                remC = j;
            }
        }
    }
        
    int checkR[4] = {0,0,1,-1};
    int checkC[4] = {1,-1,0,0};
    
    int in;
    while (scanf("%d",&in)!=EOF)
    {
        if(in == 0) break;

        for(int i = 0 ; i < 4 ; i ++)
        {
            if(!isInMatrix(remR + checkR[i],remC + checkC[i])) continue;
            if(matrix[remR + checkR[i]][remC + checkC[i]]!=in) continue;

            
            matrix[remR + checkR[i]][remC + checkC[i]] = 0;
            matrix[remR][remC] = in;

            remR = remR + checkR[i];
            remC = remC + checkC[i];

            break;
        }

        bool win = true;
        for(int i=0;i<GRIDLEN;i++)
        { 
            for(int j=0;j<GRIDLEN;j++)
            {
                
                if(matrix[i][j] != i*GRIDLEN+j+1 )
                {
                    if(!(i==GRIDLEN-1 && j==GRIDLEN-1))
                        win = false;
                }
            }
        }

        if(win)
        {
            for(int i=0;i<GRIDLEN;i++)
            {
                if(i!=0) putchar('\n');
                for(int j=0;j<GRIDLEN;j++)
                {
                    if(j!=0) putchar(' ');
                    printf("%d",matrix[i][j]);
                }
            }
            putchar('\n');

            printf("%d",win);

            putchar(' ');

            printf("%d",in);

            return 0;

        }

    }

    bool win = true;
    for(int i=0;i<GRIDLEN;i++)
    {
        if(i!=0) putchar('\n');
        for(int j=0;j<GRIDLEN;j++)
        {
            if(j!=0) putchar(' ');
            printf("%d",matrix[i][j]);

            if(matrix[i][j] != i*GRIDLEN+j+1 )
            {
                if(!(i==GRIDLEN-1 && j==GRIDLEN-1))
                    win = false;
            }
        }
    }

    printf("\n%d",win);
    


    return 0;
}