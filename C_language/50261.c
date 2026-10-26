#include<stdio.h>
// #define MAX 2000 + 1

void dividePolynomial(int f[], int g[])
{
    int fLen = f[0]+1;
    int gLen = g[0]+1;

    // int q = fLen - gLen + 1;
    int q[fLen-gLen+1],r[gLen];
    int qIndex = 0,gIndex = 0;
    for(int i=1;i<fLen+1;i++)
    {
        if(fLen+1-i < gLen) break;

        int times = f[i]/g[1];

        for(int j=1;j<gLen+1;j++)
        {
            f[i+j-1] -= g[j]*times;
        }

        q[qIndex] = times;
        qIndex ++;
    }
    // printf("\n");

    int index = 1;
    while (f[index]==0)
    {
        index++;
    }
    // printf("i%d",index);
    for(int i=index;i<=fLen;i++)
    {
        g[i-index+1] = f[i];
    }
    if(fLen-index < 0)
    {g[0]=0;g[1]=0;}
    else
    g[0] = fLen-index;


    
    for(int i=0;i<qIndex;i++)
    {
        f[i+1]=q[i];
    }
    f[0] = qIndex-1;


}

// #include <stdio.h>
// // #include "dividePolynomial.h"
 

 
// void readPolynomial(int p[]) {
//     scanf("%d", &p[0]);
//     for (int i = 1; i<=p[0]+1; i++)
//         scanf("%d", &p[i]);
// }
 
// void printPolynomial(int p[]) {
//     for (int i = 0; i<=p[0]; i++)
//         printf("%d ", p[i]);
//     printf("%d", p[p[0]+1]);
// }
 
// int main() {
//     int n, f[MAX], g[MAX];
//     scanf("%d", &n);
//     while (n--) {
//         readPolynomial(f);
//         readPolynomial(g);
 
//         dividePolynomial(f, g);
 
//         printPolynomial(f);
//         printf("\n");
//         printPolynomial(g);
//         if (n) printf("\n");
//     }
//     return 0;
// }