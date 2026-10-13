#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    double matrix[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lf",&matrix[i][j]);
        }
    }


    double y[n];

    for(int i=0;i<n;i++)
    {
        scanf("%lf",&y[i]);
    }

    double ans[n] ;

    ans[n-1] =  y[n-1]/matrix[n-1][n-1] ;

    for(int i=n-2;i>=0;i--)
    {
        //Ax = y 
        double tp = y[i];
        for(int j=n-1;j>i;j--)
        {
            tp -= matrix[i][j] * ans[j];
        }
        tp /= matrix[i][i];

        ans[i] = tp;
    }

    for(int i=0;i<n;i++)
    {
        if(i!=0) putchar('\n');
        printf("%f",ans[i]);
    }


    return 0;
}