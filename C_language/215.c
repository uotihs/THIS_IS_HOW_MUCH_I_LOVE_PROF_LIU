#include<stdio.h>

int main()
{
    long long s,f,t;

    // chick+rab+crab;
    // chick+rab
    // chick*2+rab*4+crab*6;
    scanf("%lld%lld%lld",&s,&f,&t);

    if(s<0 || f <0 || t<0 || s-t < 0 || (f-2*s-6*(s-t))%2 !=0 || s - (f-2*s-6*(s-t))/2 - (s-t) <0){
        printf("0");
        return 0;
    }
    else{
        printf("%lld\n%lld\n%lld",s - (f-2*s-6*(s-t))/2 - (s-t) ,(f-2*s-6*(s-t))/2,s-t);
    }
    



    return 0;
}