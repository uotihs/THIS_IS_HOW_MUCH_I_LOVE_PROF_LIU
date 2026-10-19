#include<stdio.h>

int main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    int ans = c * a* b /(a*b-d*e);
    printf("%d",ans);

    return 0;
}   