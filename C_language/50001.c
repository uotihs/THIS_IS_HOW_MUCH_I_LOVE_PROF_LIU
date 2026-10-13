#include<stdio.h>

typedef struct pos{
    int x;
    int y;
}Pos;


int get_go(int x,int y,int a,int b)
{
    int ans = a*x+b*y;
    if(ans<0) ans= -ans;

    return ans%4;
}

int get_gold(int x,int y,int c,int d,int e)
{
    int ans = c*x+d*y;
    if(ans<0) ans = -ans;

    return ans%e;
}

int go_2_x(int go)
{
    if(go==1)return 1;
    if(go==3)return -1;
    return 0;
}

int go_2_y(int go)
{
    if(go==0)return 1;
    if(go==2)return -1;
    return 0;
}

int main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

    Pos tel1;
    Pos tel2;
    scanf("%d%d",&(tel1.x),&(tel1.y)); 
    scanf("%d%d",&(tel2.x),&(tel2.y)); 

    int x,y;
    scanf("%d%d",&x,&y);

    int fuel;
    scanf("%d",&fuel);

    int gold = 0;
    for(int i=fuel;i>=0;i--)
    {
        if(x==tel1.x&&y==tel1.y)
        {
            x= tel2.x;y=tel2.y;
        }
        else if(x==tel2.x&&y==tel2.y)
        {
            x= tel1.x;y=tel1.y;
        }
        else
        {
            gold += get_gold(x,y,c,d,e);
        }

        if(i<=0) break;

        int go = get_go(x,y,a,b);

        x  += go_2_x(go);
        y  += go_2_y(go);

    }

    printf("%d\n%d %d",gold,x,y);


    return 0;
}