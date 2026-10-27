#include<stdio.h>

int main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int nows[3]={0};
    int anss[3]={0};
    int nowIndex = 0;
    int in;
    while (scanf("%d",&in)!=EOF)
    {
        //function = (a*x+b)%c
        int times = 0;
        int ans = in;
        while (!(ans>=d && ans<=e))
        {
            ans = (ans*a+b)%c;
            times++;
        }
        // printf("%d ",times);
        nows[nowIndex]=in;
        anss[nowIndex]=times;
        nowIndex++;

        if(nowIndex>=3)
        {
            nowIndex=2;
            for(int i=0;i<3;i++)
            {
                if( (anss[0]==anss[2]+1 && anss[2]==anss[1]+1) || (anss[0]==anss[1]+1 && anss[1]==anss[2]+1) || (anss[1]==anss[0]+1 && anss[0]==anss[2]+1)||(anss[1]==anss[2]+1 && anss[2]==anss[0]+1) || (anss[2]==anss[1]+1 && anss[1]==anss[0]+1) || (anss[2]==anss[0]+1 && anss[0]==anss[1]+1) )
                {
                    for(int i=0;i<3;i++)
                    {
                        if(i!=0) putchar(' ');
                        printf("%d",nows[i]);
                        
                    }
                    return 0;
                }
                
            }

            for(int i=0;i<2;i++)
            {
                nows[i] = nows[i+1];
                anss[i] = anss[i+1];
            }
        }

        


        
    }
    printf("Not found");






    return 0;
}