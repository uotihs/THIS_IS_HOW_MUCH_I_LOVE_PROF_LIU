#include <stdint.h>
#include "BubbleSort.h"
#include <stdio.h>
void BubbleSort(uint64_t input, uint64_t output[63])
{
    uint64_t twos[64];
    uint64_t tp = 1;
    for(int i=0;i<64;i++)
    {
        twos[i] = tp;
        tp*=2;
    }

    for(int a=0;a<63;a++)
    {
        for(int i=62;i>=0;i--)
        {
            if( (( input >> (i)) & 1ULL )==0 &&  ((input >> (i+1)) & 1ULL )==1 )
            {
                input |= twos[i];
                input &= ~(twos[i+1]);
            }
        }

        output[a] = input;
    }
}

