#include<stdio.h>

typedef struct point
{
    int x;
    int y;
} Point ;


int CrossTwoPoints(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    Point points[4] = {0};
    Point zero = {0};

    for(int i=0;i<4;i++)
    {
        scanf("%d%d",&(points[i].x), &(points[i].y));
    }

    int a = CrossTwoPoints(points[0],points[1]);
    int b = CrossTwoPoints(points[1],points[2]);
    int c = CrossTwoPoints(points[2],points[3]);
    int d = CrossTwoPoints(points[3],points[0]);
    if(a>0 && b>0 && c>0 && d>0)
    {
        printf("1");
        return 0 ;
    }
    printf("0");
    return 0;

}