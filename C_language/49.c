#include<stdio.h>


int main()
{
    int all,mod;
    scanf("%d%d",&all,&mod);

    int answers[mod][3];

    for(int i=0;i<mod;i++)
    {
        answers[i][0]=-1;
        answers[i][1]=10001;
        answers[i][2]=0;
    }

    int in;
    for(int i=0;i<all;i++)
    {
        scanf("%d",&in);
        int theMod = in%mod;

        answers[theMod][2] += in;
        if(in < answers[theMod][1]) answers[theMod][1] = in;
        if(in > answers[theMod][0]) answers[theMod][0] = in;
    }

    for(int i=0;i<mod;i++)
    {
        printf("%d %d %d",answers[i][2],answers[i][0],answers[i][1]);
        if(i != mod-1) putchar('\n');
    }
    
    return 0;
}