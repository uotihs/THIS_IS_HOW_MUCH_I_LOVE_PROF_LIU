#include<stdio.h>

int gcd(int n1,int n2)
{
    if(n1 ==0 && n2==0) return -1;
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;


    if(n1<n2)
    {
        int tp = n1;
        n1 = n2;
        n2 = n1;
    }

    while (n2!=0)
    {
        int temp = n2;
        n2 = n1 % n2 ;
        n1 = temp ;
    }

    return n1;
    


}



typedef struct fraction{
    int up;
    int down;
} Fract;

void fractionAdd(Fract f1,Fract f2)
{
    int up = f1.up * f2.down + f2.up * f1.down;
    int down = f1.down * f2.down;

    if (up <  0 )
    {
        up = -up;
        int fa = gcd(up,down);
        up/=fa;
        down/=fa;
        
        printf("%d\n%d\n%d",-(up/down),up%down,down);
    }
    else
    {
        int fa = gcd(up,down);
        up/=fa;
        down/=fa;
        printf("%d\n%d\n%d",(up/down),up%down,down);
    }
}

void fractionTime(Fract f1,Fract f2)
{
    int up = f1.up * f2.up;
    int down =f1.down * f2.down;


    if (up <  0 )
    {
        up = -up;
        int fa = gcd(up,down);
        up/=fa;
        down/=fa;
        
        printf("%d\n%d\n%d",-(up/down),up%down,down);
    }
    else
    {
        int fa = gcd(up,down);
        up/=fa;
        down/=fa;
        printf("%d\n%d\n%d",(up/down),up%down,down);
    }

    

}




int main()
{
    Fract in1,in2;

    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    in1.up = (a > 0) ? a*c+b : a*c-b;
    in1.down = c;


    int op;
    scanf("%d",&op);


    scanf("%d%d%d",&a,&b,&c);
    in2.up = (a > 0) ? a*c+b : a*c-b;
    in2.down = c;

    // input fractions

    


    switch (op)
    {
        case 0:
            fractionAdd(in1,in2);
            break;
        case 1:
            in2.up = -in2.up;
            fractionAdd(in1,in2);
            break;

        case 2:
            fractionTime(in1,in2);
            break;

        case 3:
            Fract in3 = {in2.down , in2.up};
            if(in2.up < 0)
            {
                in3.up = - in3.up;
                in3.down = - in3.down;
            }
            fractionTime(in1,in3);
            break;
    }




    return 0;
}