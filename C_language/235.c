#include<stdio.h>

long long gcd(long long a,long long b)
{
    if(a==0 && b==0) return 1;
    else if(b==0) return a; 
    else if(a==0) return b;
    

    long long temp ;
    while (a % b != 0)
    {
        temp =b;
        
        b = a % b;
        a = temp;
    }

    return b;
    
}


int main()
{
    int Rows;
    scanf("%d",&Rows);
    int allNodes = Rows * (Rows+1) /2;

    if(Rows == 0)
    {
        printf("1/1");
        return 0;
    }

    long long nodes[allNodes][4] ;


    for(int i=0;i<allNodes;i++)
    {
        scanf("%lld%lld",&nodes[i][0],&nodes[i][1]);

        long long fac = gcd(nodes[i][0], nodes[i][1]);
        nodes[i][0] /= fac;
        nodes[i][1] /= fac;

        nodes[i][2] = nodes[i][0]+nodes[i][1];
        nodes[i][3] = nodes[i][0]+nodes[i][1];

        
    }


    
    for(int i=1;i<Rows;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int nowIndex =  i*(i+1)/2+j ;
            int upIndex =   i*(i-1)/2+j-1;

            if(j==0)
            {
                upIndex++;
                
                nodes[nowIndex][1] *= nodes[upIndex][0];
                nodes[nowIndex][0] *= nodes[upIndex][0];
                nodes[nowIndex][2] *= nodes[upIndex][2];
                nodes[nowIndex][3] *= nodes[upIndex][2];
            }
            else if(j==i)
            {
                nodes[nowIndex][1] *= nodes[upIndex][1];
                nodes[nowIndex][0] *= nodes[upIndex][1];
                nodes[nowIndex][2] *= nodes[upIndex][3];
                nodes[nowIndex][3] *= nodes[upIndex][3];
            }
            else
            {
                long long up,down;
                up = nodes[upIndex][1]* nodes[upIndex+1][2] + nodes[upIndex+1][0] * nodes[upIndex][3];
                down = nodes[upIndex][3] * nodes[upIndex+1][2]; 
                long long fac;
                fac = gcd(up ,down);
                
                up /= fac;
                down /= fac;
                

                nodes[nowIndex][0] = nodes[nowIndex][0]* up;
                nodes[nowIndex][1] = nodes[nowIndex][1]* up;
                nodes[nowIndex][2] = nodes[nowIndex][2]* down;
                nodes[nowIndex][3] = nodes[nowIndex][3]* down;

                fac = gcd(nodes[nowIndex][0],nodes[nowIndex][2]);
                nodes[nowIndex][0]/=fac;
                nodes[nowIndex][2]/=fac;

                fac = gcd(nodes[nowIndex][1],nodes[nowIndex][3]);
                nodes[nowIndex][1]/=fac;
                nodes[nowIndex][3]/=fac;

                if(nodes[nowIndex][1]>nodes[nowIndex][3])printf("!!!%d\n\n",nowIndex);
                if(nodes[nowIndex][0]>nodes[nowIndex][2])printf("!!!%d\n\n",nowIndex);
            }
        }
    }

    
    int now = Rows*(Rows-1)/2;
    for(int i=0;i<Rows+1;i++)
    {
        if(i == 0)
        {
            long long up = nodes[now+i][0], down = nodes[now+i][2];

            long long fac = gcd(up,down);

            up/=fac;
            down/=fac;
            
            printf("%lld/%lld",up,down);
        }
        else if(i == Rows)
        {
            long long up = nodes[now+i-1][1];
            long long down = nodes[now+i-1][3];

            long long fac = gcd(up,down);

            up/=fac;
            down/=fac;
            
            printf("%lld/%lld",up,down);
        }
        else
        {
            long long up = nodes[now+i-1][1]*nodes[now+i-1+1][2] + nodes[now+i-1+1][0]*nodes[now+i-1][3];
            long long down = nodes[now+i-1][3]*nodes[now+i-1+1][2];

            long long fac = gcd(up,down);

            up/=fac;
            down/=fac;

            printf("%lld/%lld",up,down);
        }

        if(i!= Rows) putchar('\n');
    }


    return 0;

}