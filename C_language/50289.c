#include<stdio.h>

int gcd(int n1,int n2)
{
    if(n1==0 && n2==0) return 1;
    if(n1==0) return n2;
    if(n2==0) return n1;

    if(n2 > n1) return gcd(n2,n1);

    while(n2!=0)
    {
        int temp = n2;
        n2 = n1%n2;
        n1 = temp;
    }

    return n1;
    
}


int main()
{
    int L,M;
    scanf("%d%d",&L,&M);
    int l,m;
    scanf("%d%d",&l,&m);


    printf("%d\n%d", (L/l) * (M/m), L*M -(L/l) * (M/m) * l * m);
    


}