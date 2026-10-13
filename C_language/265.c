#include<stdio.h>
#include<stdlib.h>


int main()
{

    int xlow = 10001,xhigh = -10001,ylow = 10000 ,yhigh = -10001;
    int inx,iny;

    while(scanf("%d%d",&inx,&iny)!=EOF)
    {
        xlow = xlow < inx ? xlow : inx;
        xhigh = xhigh > inx ? xhigh : inx;
        ylow = ylow < iny ? ylow : iny ;
        yhigh = yhigh > iny ? yhigh : iny ;
    }
    printf("%lld" , (xhigh - xlow )*(yhigh - ylow));
    


    return 0;
}