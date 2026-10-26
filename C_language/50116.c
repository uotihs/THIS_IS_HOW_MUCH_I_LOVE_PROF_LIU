#include<stdio.h>
#include<stdbool.h>

int main()
{
    long long in;
    bool isodd=true;
    long long odd = 0;long long even = 0;
    long long digits=0;
    long long zero = 0;
    while (scanf("%lld",&in)!=EOF)
    {
        if(isodd) odd+=in;
        else even +=in;

        if(in==0)zero++;
            

        digits++;
        isodd = !isodd;
    }
    long long eleven=odd-even;
    if(eleven<0)eleven=-eleven;

    printf("%lld\n",digits);
    printf("%lld\n",!(in%2));
    printf("%lld\n",zero);
    printf("%lld",!(eleven%11));
    

    
    return 0;
}