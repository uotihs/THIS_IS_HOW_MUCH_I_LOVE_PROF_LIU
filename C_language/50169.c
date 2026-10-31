#include<stddef.h>
#include "sumOfIntegers.h"

void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks)
{
    *numberOfBlocks = 1;
    int ansIndex = 0;
    int index = 0;
    int blockIndex = 0;
    while (!(ptrArray[index]==NULL && ptrArray[index+1]==NULL))
    {
        if(ptrArray[index]==NULL)
        {
            index++;
            blockIndex = index;
            (*numberOfBlocks)++;
            ansIndex++;
        }

        int new = 1;
        for(int i=blockIndex;i<index;i++)
        {
            if((ptrArray[index])==ptrArray[i])
            {
                new = 0;
                break;
            }
        }
        if(new) answer[ansIndex] += (*(ptrArray[index]));
        
        index++;
    }

    return;
}
