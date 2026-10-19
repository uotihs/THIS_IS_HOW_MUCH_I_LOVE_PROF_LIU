#include<stdio.h>
#include<stdbool.h>

int main()
{
    bool LastUpHill = true;
    int lastHeight = 0;
    int sum = 0;
    int in;
    int times;
    scanf("%d",&times);

    for(int now=0;now<times;now++)
    {
        scanf("%d",&in);
        if(now == 0 ){lastHeight = in; continue;}
        if(now == 1 ){LastUpHill = (in>lastHeight);if(LastUpHill) sum+=(in-lastHeight)*3; else sum+=(lastHeight-in)*2;lastHeight = in;continue; }

        if(lastHeight<in)
        {
            if(LastUpHill)
            {
                sum += (in-lastHeight)*4;
                // printf("%d",(in-lastHeight)*4);
            }
            else
            {
                sum += (in-lastHeight)*3;
                // printf("%d",(in-lastHeight)*3);
            }
            LastUpHill = true;
        }
        else
        {
            if(LastUpHill)
            {
                sum += (lastHeight-in)*3;
                // printf("%d",-(in-lastHeight)*3);
            }
            else
            {
                sum += (lastHeight-in)*2;
                // printf("%d",-(in-lastHeight)*2);
            }
            LastUpHill = false;
        }

        lastHeight = in;



    }
    
    printf("%d",sum);

    return 0;
}