#include "calRectArea.h"

typedef struct point{
    int  x;
    int  y;
}Point;

typedef struct rect
{
    Point leftdown;
    Point rightup;
}Rect;

int  get_rect_area(Rect r1)
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


int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[])
{
    Rect rects[M];
    for(int i=0;i<M;i++)
    {
        rects[i].leftdown.x = (ptrLeft[i] - ptrMat) > 0 ? (ptrLeft[i] - ptrMat)/N : ((ptrLeft[i] - ptrMat))/N;
        rects[i].leftdown.y = (ptrLeft[i] - ptrMat) > 0 ? (ptrLeft[i] - ptrMat)%N : ((-(ptrLeft[i] - ptrMat))%N);
        rects[i].rightup.x = (ptrRight[i] - ptrMat) > 0 ? (ptrRight[i] - ptrMat)/N : ((ptrRight[i] - ptrMat))/N;
        rects[i].rightup.y = (ptrRight[i] - ptrMat) > 0 ? (ptrRight[i] - ptrMat)%N : ((-(ptrRight[i] - ptrMat))%N);
        rects[i].rightup.x += 1;
        rects[i].rightup.y += 1;
        // printf("%d %d %d %d\n",rects[i].leftdown.x,rects[i].leftdown.y,rects[i].rightup.x,rects[i].rightup.y);
    }

    int sum = get_rect_area(rects[0]);
    for(int i=1;i<M;i++)
    {
        sum += get_rect_area(rects[i]);
        sum -= get_rect_area(get_overlap_rect(rects[i],rects[i-1]));
    }


    return sum;
}