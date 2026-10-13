#include"intersection.h"
#include<stdio.h>

void intersection(int map[100][100], int result[4])
{
    for(int i=0;i<4;i++)
    {
        result[i] = 0;
    }
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,1,-1};

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(map[i][j] == 0) continue;

            int count = 0;
            int vertiLine = 1;
            int horiLine = 1;

            for(int k=0;k<4;k++)
            {
                if((i+x[k])>=0 && (i+x[k])<100 && (j+y[k])>=0 &&(j+y[k])<100)
                {
                    if(map[i+x[k]][j+y[k]] == 1)
                    {
                        count ++;
                    }

                    if(k<2)
                    {
                        if(map[i+x[k]][j+y[k]] == 0)
                        {
                            horiLine = 0;
                        }
                    }
                    else if(k<4)
                    {
                        if(map[i+x[k]][j+y[k]] == 0)
                        {
                            vertiLine = 0;
                        }
                    }
                }
                else
                {
                    if(k<2)
                    {
                        horiLine = 0;
                    }
                    else if(k<4)
                    {
                        vertiLine = 0;
                    }
                }
                
            }
            

// A cell is an intersection if it is 1, and all of its four neighbors are also 1.
// A cell is a T-junction, if it is 1, and exactly three of its neighbors are also 1.
// A cell is a turn if it is 1 and exactly two of its neighbors are 1, and these two neighbors do not form a straight line with the cell.
// A cell is a dead end if it is 1, and exactly one of its neighbors is 1.
            if(count == 4)
            {
                result[0] ++;
            }
            else if(count == 3)
            {
                result[1] ++;
            }
            else if(count == 2)
            {
                if(vertiLine || horiLine)
                {
                    
                }
                else
                {
                    result[2] ++;
                }
            }
            else if(count == 1)
            {
                result[3] ++;
            }

        }
    }
}