#include<stdio.h>   


int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    int firsta,firstb;
    int a,b;
    scanf("%d%d",&a,&b);
    firsta =a; firstb = b;

    for(int i=1;i<n;i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);

        int temp = a*d - b*c;
        ans += temp;

        a = c;
        b = d;
    }

    int temp = a*firstb - b*firsta;
    ans += temp;
    printf("%d",ans);


    return 0;
}