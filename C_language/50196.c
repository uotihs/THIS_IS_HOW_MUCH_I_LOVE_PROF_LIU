/*
We have a secret expression as a sequence of digits from 0 to 9.
To get the secret we replace 8 with '+', 9 with '*', and 0 with '='. 
For example, 1 2 8 2 4 9 3 0 means 12+24*3=. 
Please write a program to compute the answer. 
Note that we need to multiply first, then do the addition.
*/
#include<stdio.h>

int main()
{
    int n1=0,n2=0,tp=1;
    int in;
    while (scanf("%d",&in)!=EOF)
    {
        if(in==0) break;

        if(in!=0 && in!=8 && in!=9)
        {
            n2*=10;
            n2 += in;
        }

        if(in ==8)
        {
            n1 += tp*n2;
            n2=0;
            tp=1;
        }
        if(in ==9)
        {
            tp *= n2;
            n2=0;
        }
        // printf("%d %d %d\n",n1,n2,tp);
    }
    n1 += tp*n2;
    tp=1;
    n2=0;

    printf("%d",n1);



    return 0;
}