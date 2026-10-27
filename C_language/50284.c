#include <stdint.h>
#include <stdio.h>
// #define ARRAYSIZE 1000
 
// typedef struct giantUnsignedInt {
//     uint64_t array[ARRAYSIZE];
//     int n;
// } GiantUnsignedInt;


#include "numZeroBits.h"
int numZeroBits(GiantUnsignedInt *giantNum)
{
    int maxZeros = 0;
    int nowZeros = 0;
    // printf("%d",giantNum->n);
    for(int i=0;i< (giantNum->n) ;i++)
    {
        for(int j=63 ; j>=0 ; j--)
        {
            if((((giantNum->array[i]) >> j ) & 1 )== 0)
            {
                // printf("s");
                nowZeros++;
            }
            else
            {
                nowZeros=0;
            }

            if(nowZeros>maxZeros)
            {
                maxZeros = nowZeros;
            }
        }
    }
    
    return maxZeros;
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