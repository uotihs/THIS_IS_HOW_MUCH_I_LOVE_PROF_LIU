#include<stdio.h>

int main()
{
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);


    int start = 1;
    for(long long i=10000;i>=-100000;i--)
    {
        long long sum =i*i*i + i*i*a+ i*b + c;
        if(sum  == 0)
        {
            if(start)
            {
                start = 0;
                printf("%d",-i);
                
                if(3*i*i + 2*i*a + b == 0) 
                {
                printf(" %d",-i);
                if(-i*i*i == c && -i*3 == a){printf(" %d",-i);}
                }

                continue;
            }
            printf(" %d",-i);

            if(3*i*i + 2*i*a + b == 0) 
            {
                printf(" %d",-i);
                if(-i*i*i == c && -i*3 == a){printf(" %d",-i);}
            }
        }
    }





    return 0;
}