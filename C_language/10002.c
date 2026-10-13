#include<stdio.h>


int main()
{
    int h,w,a;
    scanf("%d%d%d",&h,&w,&a);

    int area = h*w - (h-2*a)*(w-a);
    area += h*w - (h-3*a)*(w-a);
    area += h*a;
    area += h*w - (h-3*a)*(w-a);
    int len = 2*(h+w)*3+2*a+2*h+10*(w-a);
    printf("%d\n%d",area,len);

    return 0;
}