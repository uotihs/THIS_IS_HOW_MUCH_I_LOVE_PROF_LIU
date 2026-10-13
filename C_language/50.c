#include<stdio.h>

typedef struct point{
    int x;
    int y;
}Point;


typedef struct rect{
    Point leftdown;
    Point rightup;
}Rect;

int get_rect_area(Rect r1)
{
    if(r1.rightup.x > r1.leftdown.x && r1.rightup.y > r1.leftdown.y)
    {
        return (r1.rightup.x - r1.leftdown.x)*(r1.rightup.y - r1.leftdown.y);
    }
    else
    {
        return 0;
    }
}

Rect get_overlap_btw_rects(Rect r1, Rect r2)
{
    Rect ans = {{0,0},{0,0}};


    ans.leftdown.x = r1.leftdown.x > r2.leftdown.x ? r1.leftdown.x : r2.leftdown.x;
    ans.leftdown.y = r1.leftdown.y > r2.leftdown.y ? r1.leftdown.y : r2.leftdown.y;
    ans.rightup.x = r1.rightup.x < r2.rightup.x ? r1.rightup.x : r2.rightup.x;
    ans.rightup.y = r1.rightup.y < r2.rightup.y ? r1.rightup.y : r2.rightup.y;


    

    if(ans.rightup.x > ans.leftdown.x && ans.rightup.y > ans.leftdown.y)
    {
        return ans;
    }
    else
    {
        ans.leftdown.x = 0;
        ans.leftdown.y = 0;
        ans.rightup.x = 0;
        ans.rightup.y = 0;
        return ans;
    }

}

int main()
{
    Rect r1,r2,r3;


    scanf("%d%d%d%d",&(r1.leftdown.x),&(r1.leftdown.y),&(r1.rightup.x),&(r1.rightup.y));
    scanf("%d%d%d%d",&(r2.leftdown.x),&(r2.leftdown.y),&(r2.rightup.x),&(r2.rightup.y));
    scanf("%d%d%d%d",&(r3.leftdown.x),&(r3.leftdown.y),&(r3.rightup.x),&(r3.rightup.y));

    // ans  =  A+B+C -AB -AC -BC +ABC
    int a = get_rect_area(r1);
    int b = get_rect_area(r2);
    int c = get_rect_area(r3);

    int ab = get_rect_area(get_overlap_btw_rects(r1,r2));
    int bc = get_rect_area(get_overlap_btw_rects(r2,r3));
    int ac = get_rect_area(get_overlap_btw_rects(r1,r3));

    int abc = get_rect_area(get_overlap_btw_rects(get_overlap_btw_rects(r2,r3),get_overlap_btw_rects(r1,r3)));

    printf("%d",a+b+c-ab-ac-bc+abc);
    return 0;
}