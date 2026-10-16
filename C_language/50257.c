#include<stdio.h>

int main()
{
    int in;
    scanf("%d",&in);

    printf("%d\n",in);
    while (in != 1)
    {

        if(in % 2 != 0) in = in*3 + 1;
        else in /= 2;

        if(in == 1)
        printf("%d",in);
        else 
        printf("%d\n",in);
    }
    

    return 0;
}