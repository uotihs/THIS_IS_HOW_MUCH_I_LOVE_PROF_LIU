#include"posneg.h"

void posneg(int array[5][5], int result[2])
{
    int negCount = 0,posCount = 0;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(array[i][j]>0)
            {
                posCount++;
            }
            if(array[i][j]<0)
            {
                negCount++;
            }
        }
    }

    result[0] = negCount;
    result[1] = posCount;



}
