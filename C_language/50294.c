#include<stdio.h>
#include<stdbool.h>

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);

    int checkupdownCount = 0;
    bool down = true;

    int lastCountUp = 0;
    int lastCountDown = 0;
    int nowCountUp = 0;
    int nowCountDown = 0;
    int lastinDown;
    int lastinUp;
    bool UpisLian = 0;

    for(int now = 0 ; now < n*(2*a-b); now ++)
    {
        int nowin;
        scanf("%d",&nowin);
        checkupdownCount++;


        if(now == 0)
        {
            lastinDown = nowin;
        }
        else if(now == b+1)
        {
            lastinUp = nowin;
        }


        if(checkupdownCount <= b)
        {
            down = true;
        }
        else
        {
            if((checkupdownCount - b) % 2 ==0)
            {
                down = !down;
            }
        }


        if(down)
        {
            //down
            if(nowin != lastinDown)
            {
                //save
                if(nowCountDown > lastCountDown)
                {
                    lastCountDown = nowCountDown;
                }


                nowCountDown = 1;
            }
            else
            {
                nowCountDown++;
            }

            lastinDown = nowin;
        }
        else
        {
            //up
            if(nowin != lastinUp || !UpisLian )
            {
                // save
                if(nowCountUp > lastCountUp)
                {
                    lastCountUp = nowCountUp;
                }

                nowCountUp = 1;
            }
            else
            {
                nowCountUp ++;
            }

            lastinUp = nowin;
        }



        // printf("now(0) up or down(1) %d\n",down);
        // printf("in %d\n",nowin);
        // printf("up %d down %d\n",lastinUp,lastinDown);
        // printf("up %d down %d\n\n",nowCountUp,nowCountDown);

        if(checkupdownCount == 2*a-b)
        {
            checkupdownCount=0;
            UpisLian = 0;
        }
        if(checkupdownCount == b+2)
        {
            UpisLian = 1;
        }

    }
    nowCountDown = nowCountDown > lastCountDown ? nowCountDown : lastCountDown;
    nowCountUp = nowCountUp > lastCountUp ? nowCountUp : lastCountUp;
    
    int total = nowCountDown > nowCountUp ? nowCountDown : nowCountUp;

    printf("%d",total);
    return 0;
}