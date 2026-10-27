#include<stdio.h>


int main()
{
    int arrival,consumeA,consumeB;
    int first = 1;
    int Anow=0,Bnow=0;
    while (scanf("%d%d%d",&arrival,&consumeA,&consumeB)!=EOF)
    {
        if(arrival>=Anow)
        {
            Anow= arrival+consumeA;
        }
        else if(arrival>=Anow+consumeA)
        {
            Anow= arrival+consumeA;
        }
        else{
            // printf("a what");
            Anow+=consumeA;
        }

        if(Bnow<Anow) Bnow = Anow;

        if(arrival>=Bnow)
        {
            Bnow= arrival+consumeB;
        }
        else if(arrival>=Bnow+consumeB)
        {
            Bnow= arrival+consumeB;
        }
        else{
            // printf("b what");
            Bnow= Bnow+consumeB;
        }
        
        if(first)first=0;
        else putchar('\n');
        printf("%d",Bnow);
    }
    





    return 0;
}
