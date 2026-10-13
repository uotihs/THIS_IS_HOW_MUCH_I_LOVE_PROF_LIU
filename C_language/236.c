#include<stdio.h>


int gcd(int n1,int n2)
{
    if(n1 ==0 && n2==0) return -1;
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;


    if(n1<n2)
    {
        int tp = n1;
        n1 = n2;
        n2 = tp;
    }

    while (n2!=0)
    {
        int temp = n2;
        n2 = n1 % n2 ;
        n1 = temp ;
    }

    return n1;
    
}


int main()
{
    int in;
    scanf("%d",&in);
    int ans = in;

    while(scanf("%d",&in)!=EOF)
    {
        int fac = gcd(in,ans);
        
        int t1 = in/fac;
        int t2 = ans/fac;
        ans = t1*t2*fac;
    }
    printf("%d",ans);



    return 0;
}