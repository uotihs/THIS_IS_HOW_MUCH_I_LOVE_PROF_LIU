#include<stdio.h>

int main()
{
    int ax,ay,bx,by,cx,cy;
    scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);

    printf("%d\n",cx-ax+bx);
    printf("%d\n",cy-ay+by);

    printf("%d\n",cx+ax-bx);
    printf("%d\n",cy+ay-by);

    printf("%d\n",ax+bx-cx);
    printf("%d\n",ay+by-cy);

    return 0;
}