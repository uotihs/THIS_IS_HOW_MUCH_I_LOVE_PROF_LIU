#include<stdio.h>


int main()
{
    int a,b,x;
    int first = 1;
    while (scanf("%d%d%d",&a,&b,&x)!=EOF)
    {
        if(first) first = 0;
        else putchar('\n');

        int twoDif = 0;
        
        while (!twoDif)
        {
            int map[10] = {0};
            int tp = x;
            while (tp > 0)
            {
                map[tp%10]++;
                tp/=10;
            }
            int count = 0;
            for(int i=0;i<10;i++)
            {
                if(map[i])
                    count++;
            }
            if(count<=2) break;
            
            x=(a*x) % b;
            

        }
        printf("%d",x);
        
    }
    


    return 0;
}