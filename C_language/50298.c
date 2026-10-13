#include<stdio.h>

typedef struct point{
    long long  x;
    long long  y;
}Point;

typedef struct rect
{
    Point leftdown;
    Point rightup;
}Rect;

long long  get_rect_area(Rect r1)
{
    return ((r1.rightup.x - r1.leftdown.x) * (r1.rightup.y - r1.leftdown.y));
}

Rect get_overlap_rect(Rect r1,Rect r2)
{
    Rect ans;

    ans.rightup.x = r1.rightup.x < r2.rightup.x ? r1.rightup.x : r2.rightup.x;
    ans.rightup.y = r1.rightup.y < r2.rightup.y ? r1.rightup.y : r2.rightup.y;
    ans.leftdown.x = r1.leftdown.x > r2.leftdown.x ? r1.leftdown.x : r2.leftdown.x;
    ans.leftdown.y = r1.leftdown.y > r2.leftdown.y ? r1.leftdown.y : r2.leftdown.y;

    if(ans.rightup.x > ans.leftdown.x && ans.rightup.y>ans.leftdown.y)
    {}
    else
    {ans.rightup.x =0;ans.rightup.y=0;ans.leftdown.x=0;ans.leftdown.y=0;}

    return ans;
}

int main()
{
    Rect in1,in2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&(in1.leftdown.x),&(in1.leftdown.y),&(in1.rightup.x),&(in1.rightup.y),&(in2.leftdown.x),&(in2.leftdown.y),&(in2.rightup.x),&(in2.rightup.y));

    
    // long long  a = get_rect_area(in1);
    // long long  b= get_rect_area(in2);
    // long long  ab = get_rect_area(get_overlap_rect(in1,in2));
    //for 1
    Rect tp1 = {{0,0},{(in1.rightup.x),(in1.rightup.y)}};
    Rect tp2 = {{0,0},{(in2.rightup.x),(in2.rightup.y)}};
    if(tp1.rightup.x < 0 || tp1.rightup.y < 0 )
    {
        tp1.rightup.x = 0;
        tp1.rightup.y = 0;
    }
    if(in1.leftdown.x>0) tp1.leftdown.x = in1.leftdown.x;
    if(in1.leftdown.y>0) tp1.leftdown.y = in1.leftdown.y;
    if(tp2.rightup.x < 0 || tp2.rightup.y < 0 )
    {
        tp2.rightup.x = 0;
        tp2.rightup.y = 0;
    }
    if(in2.leftdown.x>0) tp2.leftdown.x = in2.leftdown.x;
    if(in2.leftdown.y>0) tp2.leftdown.y = in2.leftdown.y;
    
    printf("%lld\n",get_rect_area(tp1)+get_rect_area(tp2)-get_rect_area(get_overlap_rect(tp1,tp2)));

    
    
    Rect tp3 = {{in1.leftdown.x,0},{0,in1.rightup.y}};
    Rect tp4 = {{in2.leftdown.x,0},{0,in2.rightup.y}};
    if(tp3.leftdown.x > 0 || tp3.rightup.y < 0 )
    {
        tp3.leftdown.x =0;
        tp3.rightup.y =0;
    }
    if(in1.leftdown.y > 0 ) tp3.leftdown.y = in1.leftdown.y;
    if(in1.rightup.x < 0 ) tp3.rightup.x = in1.rightup.x;

    if( tp4.leftdown.x > 0 || tp4.rightup.y < 0  )
    {
        tp4.leftdown.x =0;
        tp4.rightup.y =0;
    }    

    if(in2.leftdown.y > 0 ) tp4.leftdown.y = in2.leftdown.y;
    if(in2.rightup.x < 0 ) tp4.rightup.x = in2.rightup.x;
    
    printf("%lld\n",get_rect_area(tp3)+get_rect_area(tp4)-get_rect_area(get_overlap_rect(tp3,tp4)));

    Rect tp5 = {{in1.leftdown.x,in1.leftdown.y},{0,0}};
    Rect tp6 = {{in2.leftdown.x,in2.leftdown.y},{0,0}};
    if(tp5.leftdown.x > 0 || tp5.leftdown.y > 0)
    {
        tp5.leftdown.x = 0;
        tp5.leftdown.y = 0;
    }
    if(in1.rightup.x<0) tp5.rightup.x = in1.rightup.x;
    if(in1.rightup.y<0) tp5.rightup.y = in1.rightup.y;

    if( tp6.leftdown.x > 0 || tp6.leftdown.y > 0 )
    {
        tp6.leftdown.x = 0;
        tp6.leftdown.y = 0;
    }
    if(in2.rightup.x<0) tp6.rightup.x = in2.rightup.x;
    if(in2.rightup.y<0) tp6.rightup.y = in2.rightup.y;
     
    printf("%lld\n",get_rect_area(tp5)+get_rect_area(tp6)-get_rect_area(get_overlap_rect(tp5,tp6)));

    Rect tp7 = {{0,in1.leftdown.y},{in1.rightup.x,0}};
    Rect tp8 = {{0,in2.leftdown.y},{in2.rightup.x,0}};
    if(tp7.leftdown.y > 0 || tp7.rightup.x < 0 )
    {
        tp7.leftdown.y =0;
        tp7.rightup.x =0;
    }
    if(in1.leftdown.x>0) tp7.leftdown.x = in1.leftdown.x;
    if(in1.rightup.y<0) tp7.rightup.y = in1.rightup.y;

    if( tp8.leftdown.y > 0 || tp8.rightup.x < 0)
    {
        tp8.leftdown.y =0;
        tp8.rightup.x =0;
    }
    if(in2.leftdown.x>0) tp8.leftdown.x = in2.leftdown.x;
    if(in2.rightup.y<0) tp8.rightup.y = in2.rightup.y;

    printf("%lld",get_rect_area(tp7)+get_rect_area(tp8)-get_rect_area(get_overlap_rect(tp7,tp8)));


    return 0;
};