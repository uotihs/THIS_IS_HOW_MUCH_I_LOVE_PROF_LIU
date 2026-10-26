#include<stdio.h>

int main()
{
    int width,height;
    scanf("%d%d",&width,&height);
    int x=0,y=0;
    int in;
    int first = 1;
    
    while (scanf("%d",&in)!=EOF)
    {
        if(first)
        {
            first = 0;
            printf("%d\n%d",x,y);
        }

        int dire = in%5;

        if(dire==0)
        {
            continue;
        }
        else if(dire==1)
        {
            if(x+in<width)
                x+=in;
            else
                continue;
        }
        else if(dire==2)
        {
            if(x-in>=0)
                x-=in;
            else
                continue;
        }
        else if(dire==3)
        {
            if(y+in<height)
                y+=in;
            else
                continue;
        }
        else if(dire==4)
        {
            if(y-in>=0)
                y-=in;
            else
                continue;
        }

        if(!first)
        {putchar('\n');}

        printf("%d\n%d",x,y);
    }
    




    return 0;
}