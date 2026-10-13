#include<stdio.h>

typedef struct good
{
    int a;
    int b;
    int c;
}Good;

int colama(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
    int ans = a*e*i +d*h*c+b*f*g-g*e*c-b*d*i-a*f*h;
    return ans;
}

int recu(int i,int j,int k,Good goods[],int a,int b,int c)
{
    if(
    goods[0].a * i + goods[1].a * j + goods[2].a * k == a
    &&
    goods[0].b * i + goods[1].b * j + goods[2].b * k == b
    &&
    goods[0].c * i + goods[1].c * j + goods[2].c * k == c
    )
    return 1;


    if(i==10&&j==10&&k==10) return 0;
    if(i==10){
        if(j==10){
            return recu(i,j,k+1,goods,a,b,c);
        }
        else{
            return recu(i,j+1,k,goods,a,b,c);
        }
    }
    else
    {
        return recu(i+1,j,k,goods,a,b,c);
    }
}

int solveTheProblem(Good goods[],int a,int b,int c)
{
    int delta = colama(
        goods[0].a,goods[1].a,goods[2].a,
        goods[0].b,goods[1].b,goods[2].b,
        goods[0].c,goods[1].c,goods[2].c
    );

    int deltax = colama(
        a,goods[1].a,goods[2].a,
        b,goods[1].b,goods[2].b,
        c,goods[1].c,goods[2].c
    );
    int deltay = colama(
        goods[0].a,a,goods[2].a,
        goods[0].b,b,goods[2].b,
        goods[0].c,c,goods[2].c
    );
    int deltaz = colama(
        goods[0].a,goods[1].a,a,
        goods[0].b,goods[1].b,b,
        goods[0].c,goods[1].c,c
    );


    if(delta == 0)
    {
        if(deltax == 0 && deltay==0 && deltaz ==0)
        {
            return recu(0,0,0,goods,a,b,c);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int x = deltax / delta;
        int y = deltay / delta;
        int z = deltaz / delta;

        if(x<0 || y<0 || z<0)
        {
            return 0;
        }
        if(x*delta != deltax)
        {
            return 0;
        }
        if(y*delta != deltay)
        {
            return 0;
        }
        if(z*delta != deltaz)
        {
            return 0;
        }

        return 1;
    }
    return 0;
}

int test(int now,int testcases,Good goods[])
{
    if(now >= testcases) return 1;

    if(now!=0) putchar('\n');
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(solveTheProblem(goods,a,b,c))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }


    return test(now+1,testcases,goods);
}


int main()
{
    Good goods[3];
    scanf("%d%d%d",&(goods[0].a),&(goods[0].b),&(goods[0].c));
    scanf("%d%d%d",&(goods[1].a),&(goods[1].b),&(goods[1].c));
    scanf("%d%d%d",&(goods[2].a),&(goods[2].b),&(goods[2].c));
    int testCases;
    scanf("%d",&testCases);

    test(0,testCases,goods);


    return 0;
}