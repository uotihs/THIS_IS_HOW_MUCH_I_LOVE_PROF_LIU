#include<stdio.h>

int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy;

    scanf("%d%d",&ax,&ay);
    scanf("%d%d",&bx,&by);
    scanf("%d%d",&cx,&cy);
    scanf("%d%d",&dx,&dy);

    printf("%d\n",2*(cx-ax+cy-ay));
    printf("%d",(cx-ax)*(cy-ay) - (cx-bx)*(by-ay) - (cy-dy)*(dx-ax));

    return 0;
}