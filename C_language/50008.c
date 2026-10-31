#include <stdio.h>
#include "setmatrix.h"
 
void processSetMatrix(int ***ptr) {
    int first = 1;
    int index = 0;
    while(ptr[index]!=NULL)
    {
        int smallIndex = 0;
        while (ptr[index][smallIndex]!=NULL)
        {
            int tinyIndex=0;
            while (ptr[index][smallIndex][tinyIndex]!=0)
            {
                if(first) first=0;
                else putchar(' ');
                printf("%d",ptr[index][smallIndex][tinyIndex]);

                tinyIndex++;
            }
            


            smallIndex++;
        }
        


        index++;
    }
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <assert.h>
// // #include "setmatrix.h"
 
// int main() {
//     int n;
//     scanf("%d", &n);
//     {
//         int ***setmtx = (int ***) malloc(sizeof(int**) * (n + 1));
//         int setarr_sz, set_sz;
//         setmtx[n] = NULL;
//         for (int i = 0; i < n; i++) {
//             scanf("%d", &setarr_sz);
//             setmtx[i] = (int **) malloc(sizeof(int *) * (setarr_sz + 1));
//             setmtx[i][setarr_sz] = NULL;
//             for (int j = 0; j < setarr_sz; j++) {
//                 scanf("%d", &set_sz);
//                 setmtx[i][j] = (int *) malloc(sizeof(int) * (set_sz + 1));
//                 setmtx[i][j][set_sz] = 0;
//                 for (int k = 0; k < set_sz; k++) {
//                     scanf("%d", &setmtx[i][j][k]);
//                     assert(setmtx[i][j][k] != 0);
//                 }
//             }
//         }
//         processSetMatrix(setmtx);
 
//     }
//     return 0;
// }