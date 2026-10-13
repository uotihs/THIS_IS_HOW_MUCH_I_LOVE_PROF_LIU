#include"rotate.h"

void rotate(int *P[MAX][MAX], int n)
{
    int* temp[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i][j] =P[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            P[i][j] = temp[n-j-1][i];
        }
    }



}
