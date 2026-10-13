#include<stdio.h>

int main()
{
    int s,f,t;

    // chick+rab+crab;
    // chick+rab
    // chick*2+rab*4+crab*6;
    scanf("%d%d%d",&s,&f,&t);

    printf("%d\n%d\n%d",s - (f-2*s-6*(s-t))/2 - (s-t) ,(f-2*s-6*(s-t))/2,s-t);



    return 0;
}