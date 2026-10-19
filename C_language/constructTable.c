#include<stdio.h>
#include<stdlib.h>

int ***constructTable(int A[], int B[])
{
    int tableCounts =0;
    while (A[tableCounts]!=0)
    {
        tableCounts++;
    }
    

    int*** ans = (int ***)malloc(sizeof(int **)*(tableCounts+1));
    int pos = 0;
    for(int i=0;i<tableCounts;i++)
    {
        ans[i] = (int **)malloc(sizeof(int *)*(A[i]+1));
        for(int j=0;j<A[i];j++)
        {
            ans[i][j] = &(B[pos]);
            
            while (B[pos]!=0)
            {
                pos++;
            }
            pos++;
        }
        ans[i][A[i]] = NULL;
    }
    ans[tableCounts]=NULL;
    return ans;
}

// #include <stdio.h>
// // #include "constructTable.h"
 
// int main(){
//     int N, M;
//     int A[100] = {}, B[500] = {};
//     scanf("%d%d", &N, &M);
//     for(int i = 0; i < N; i++)
//         scanf("%d", &A[i]);
//     for(int i = 0; i < M; i++)
//         scanf("%d", &B[i]);
 
//     int ***ptr;
//     ptr = constructTable(A, B);
//     for(int i = 0; *(ptr+i) != NULL; i++)
//         for(int j = 0; j < A[i]; j++)
//             for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
//                 printf("%d ", *(*(*(ptr+i)+j)+k));
//     return 0;
// }