#include<stdio.h>

int main()
{
    int k,limit;
    scanf("%d%d",&k,&limit);
    int first =1;
    int in;
    int count = 0;
    while (scanf("%d",&in)!=EOF)
    {
        int times = in%k;
        
        int digits=0;
        int tp =in;
        while (tp>0)
        {
            digits++;
            tp/=10;
        }

        int ans[digits];
        
        for( int i=digits-1 ; i>=0 ; i-- )
        {
            ans[i] = in%10;
            in/=10;
        }
        if(digits*times > limit)continue;

        if(digits*times > limit - count){putchar('\n');count=0;}
  
        for(int i=0;i<times;i++)
        {
            for(int j=0;j<digits;j++)
            {
                if( count == limit )
                {putchar('\n');count=0;}
                printf("%d",ans[j]);
                count++;


            }
        }
        
        
        
    }
    




}