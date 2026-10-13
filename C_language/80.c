#include<stdio.h>

typedef struct point{
    int x;
    int y;
}Point;


int distanceBtwPoints(Point p1,Point p2)
{
    int x = (p1.x - p2.x)*(p1.x - p2.x);
    int y = (p1.y - p2.y)*(p1.y - p2.y);

    return x + y;
}

int checkIfIsosceles(int a,int b,int c)
{
    if(a == b || b==c || c==a) return 1;
    else return 0;
}

int Print_If_Acute_OR_Obtuse_OR_Right(int a, int b, int c)
{
    if(a + b == c || b+c == a || c+a == b)
    {
        printf("right");
    }
    else if(a+b < c || b+c < a || a+c < b )
    {
        printf("obtuse");
    }
    else
    {
        printf("acute");
    }
}


int main()
{
    int nums;
    scanf("%d",&nums);

    

    for(int index = 0 ; index < nums ; index ++)
    {
        Point p1,p2,p3;

        scanf("%d%d%d%d%d%d",&(p1.x),&(p1.y),&(p2.x),&(p2.y),&(p3.x),&(p3.y));


        int len1,len2,len3;

        len1 = distanceBtwPoints(p1,p2);
        len2 = distanceBtwPoints(p2,p3);
        len3 = distanceBtwPoints(p3,p1);

        if(index != 0) putchar('\n');

        if(checkIfIsosceles(len1,len2,len3))
        {
            printf("isosceles");
        }
        else
        {
            Print_If_Acute_OR_Obtuse_OR_Right(len1,len2,len3);
        }

    
    }




    return 0;
}