#include<stdio.h>

int main()
{
    int k;
    scanf("%d",&k);
    int carry=0,n;
    int first = 1;
    while (scanf("%d",&n)!=EOF)
    {
        int output = (carry*10+n)/k;
        if(first&&output!=0) first=0;
        else if(!first) putchar('\n');

        if(!first)
        printf("%d",output);
        carry = (carry*10+n)%k;
    }
    if(first) printf("0");
    





    return 0;
}