#include<stdio.h>
#include<stdbool.h>

bool check_Legal(int r,int c,int row,int col)
{
    if(r<row&&c<col&&r>=0&&c>=0)
    {
        return true;
    }
    return false;
}

int check_legal_go(int Gor,int Goc)
{
    if(Goc == 0) return true;
    if(Gor == 0) return true;
    if(Goc == Gor) return true;

    return false;
}

int main()
{
    int lines,row,col;
    scanf("%d%d%d",&lines,&row,&col);
    
    int map[row][col];

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            map[i][j]=0;


    for(int i=0;i<lines;i++)
    {
        int pointsCount;
        scanf("%d",&pointsCount);
        
        int points[pointsCount][2];

        for(int j=0;j<pointsCount;j++)
        {
            scanf("%d%d",&(points[j][1]),&(points[j][0]));

            points[j][0] = row-points[j][0]-1;

            if(!check_Legal(points[j][0],points[j][1],row,col))
            {

            }
        }
            


        for(int j=1;j<pointsCount;j++)
        {
            int dr = 1,dc = 1;
            int GOr = points[j][0]-points[j-1][0];
            int GOc = points[j][1]-points[j-1][1];

            if(GOr < 0 ) { GOr = -GOr; dr = -1; } else if(GOr == 0 ) { dr = 0; }
            if(GOc < 0 ) { GOc = -GOc; dc = -1; } else if(GOc == 0 ) { dc = 0; }

            if(!check_legal_go(GOr,GOc))
            {
                
            }



            for( int k=0 ; k<=GOr || k<= GOc ; k++ )
            {
                map[points[j-1][0] + dr*k][points[j-1][1] + dc*k] = 1;
            }
        }

    }

    for(int i=0;i<row;i++)
    {
        if(i!=0) putchar('\n');

        for(int j=0;j<col;j++)
        {
            printf("%d",map[i][j]);
        }
    }

    return 0;
}