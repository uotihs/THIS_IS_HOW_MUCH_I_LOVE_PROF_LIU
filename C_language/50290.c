#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    int CPU = (a + b + c)/2 - b;
    int GPU = (a + b + c)/2 - c;
    int disk = (a + b + c)/2 - a;

    printf("%d\n%d\n%d",disk,CPU,GPU);

    return 0;
}