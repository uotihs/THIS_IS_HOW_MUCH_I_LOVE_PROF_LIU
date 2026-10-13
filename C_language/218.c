#include<stdio.h>

long long Cmn(int m,int n)
{
    if(n==1) return m;
    if(n==0) return 1;
    if(m==n) return 1;

    return Cmn(m-1,n)+Cmn(m-1,n-1);
}

int main()
{

    int n,m;
    scanf("%d%d",&m,&n);

    long long sum = 0;
    for(int i=0;i<=n;i++)
    {
        sum += Cmn(m,i);
    }
    printf("%lld",sum);



}