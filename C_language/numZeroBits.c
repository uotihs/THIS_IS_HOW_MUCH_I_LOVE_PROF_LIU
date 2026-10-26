#include <stdint.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int numZeroBits(GiantUnsignedInt *giantNum)
{
    int len = giantNum->n;
    int zeros = 0;
    int max = 0;
    for(int i=0;i<len;i++)
    {
        for(int j=63;j>=0;j--)
        {
            int bit = ((giantNum->array[i])>> j) & 1;

            if(!bit)
            {
                zeros+=1;
            }
            else
            {
                if(max < zeros) max = zeros;
                zeros = 0;
            }
        }
    }
    if(max < zeros) max = zeros;

    return max;

}

// #include <stdio.h>
// // #include "numZeroBits.h"
 
// int main() {
//     int n;
//     while (scanf("%d", &n) != EOF) {
//         GiantUnsignedInt giantNum;
//         for (int i = 0; i<n; i++)
//             scanf("%llu", &giantNum.array[i]);
//         giantNum.n = n;
//         printf("%d\n", numZeroBits(&giantNum));
//     }
//     return 0;
// }