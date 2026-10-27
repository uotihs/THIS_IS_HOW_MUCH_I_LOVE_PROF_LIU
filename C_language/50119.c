#include<stdio.h>
#include<stdbool.h>

int main()
{
    int x0,ax,bx,cx;
    scanf("%d%d%d%d",&x0,&ax,&bx,&cx);
    int y0,ay,by,cy;
    scanf("%d%d%d%d",&y0,&ay,&by,&cy);    
    int n;
    scanf("%d",&n);


    for(int rounds=0;rounds<n;rounds++)
    {        
        bool xWin = 0;
        bool yWin = 0;
        int Rounds = 0;
        while (!xWin&&!yWin)
        {
            Rounds++;
            if(x0%3 == 0 && y0%3 == 1)
            {
                yWin = true;
            }
            else if(x0%3 == 1 && y0%3 == 2)
            {
                yWin = true;
            }
            else if(x0%3 == 2 && y0%3 == 0)
            {
                yWin = true;
            }
            else if(y0%3 == 0 && x0%3 == 1)
            {
                xWin = true;
            }
            else if(y0%3 == 1 && x0%3 == 2)
            {
                xWin = true;
            }
            else if(y0%3 == 2 && x0%3 == 0)
            {
                xWin = true;
            }



            x0 = (ax*x0 + bx )% cx;
            y0 = (ay*y0 + by )% cy;            
        }

        if(rounds!=0)putchar('\n');

        if(xWin)
        {
            printf("%d %d",0,Rounds);
        }
        else if(yWin)
        {
            printf("%d %d",1,Rounds);
        }


    }


    return 0;
}