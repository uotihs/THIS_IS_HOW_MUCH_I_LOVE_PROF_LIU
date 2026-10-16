#include<stdio.h>

int main()
{
    long long w,a,b,c,d,e;
    scanf("%lld%lld%lld%lld%lld%lld",&w,&a,&b,&c,&d,&e);

    long long ans;
    if(b!=0)
        ans = (a+b+c+2*d+2*e+2)*(a+b+c+2*d+2*e+2) + w*w;
    else
    {
        if(e>d)
            ans = (a+c+2*e+2)*(a+c+2*e+2) + w*w;
        else
            ans = (a+c+2*d+2)*(a+c+2*d+2) + w*w;
    }
    
        printf("%lld",ans);
    

    return 0;
}