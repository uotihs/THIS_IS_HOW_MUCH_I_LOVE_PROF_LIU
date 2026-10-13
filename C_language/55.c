#include<stdio.h>

typedef struct pos{
    long long x;
    long long y;
}Pos;


int main()
{
    long long m,n;
    scanf("%lld%lld",&m,&n);

    Pos p1,p2;
    scanf("%lld%lld",&(p1.x),&(p1.y));

    long long e1,n1,f1;
    scanf("%lld%lld%lld",&e1,&n1,&f1);

    scanf("%lld%lld",&(p2.x),&(p2.y));

    long long e2,n2,f2;
    scanf("%lld%lld%lld",&e2,&n2,&f2); 

    long long go1[2]={0};
    long long go2[2]={0};
    long long time = 1;
    while (f1>0 || f2>0)
    {
        for(int i=0;i<2;i++){go1[i] =0; go2[i]=0;}

        if((time-1) % (e1 + n1) < n1)
        {
            go1[1] = 1;
        }
        else
        {
            go1[0] = 1;
        }

        if((time-1) % (e2 + n2) < e2)
        {
            go2[0] = 1;
        }
        else
        {
            go2[1] = 1;
        }
        

        if(f1 > 0)
        {
            p1.x += go1[0];
            p1.y += go1[1];

            if(p1.x == m) p1.x = 0;
            if(p1.y == n) p1.y = 0;


            f1--;
        }

        if(f2 > 0)
        {
            p2.x += go2[0];
            p2.y += go2[1];

            if(p2.x == m) p2.x = 0;
            if(p2.y == n) p2.y = 0;

            f2--;
        }




        if(p1.x == p2.x && p1.y == p2.y)
        {
            printf("robots explode at time %lld",time);
            return 0;
        }

        time++;
    }
    
    printf("robots will not explode");

    return 0;
}