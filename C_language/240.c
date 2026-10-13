#include<stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

typedef struct vector{
    int x;
    int y;
}Vector;


long long get_len(Vector v)
{
    return v.x * v.x + v.y * v.y ;
}

long long dot(Vector v1,Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}


int main()
{
    int testDataCount ;
    scanf("%d",&testDataCount);


    for(int index=0;index<testDataCount;index++)
    {
        if(index != 0 ) putchar('\n');

        Point p[4];
        for(int i=0;i<4;i++)
        {
            scanf("%d%d",&(p[i].x),&(p[i].y));
        }

        Point centre={0};
        for(int i=0;i<4;i++)
        {
            p[i].x *=4;
            p[i].y *=4;
            centre.x += p[i].x;
            centre.y += p[i].y;
        }
        centre.x /= 4;
        centre.y /= 4;

        Vector v[4] ={0};

        for(int i=0;i<4;i++)
        {
            v[i].x = p[i].x - centre.x;
            v[i].y = p[i].y - centre.y;
        }

        
        
        long long lens[4] ;
        for(int i=0;i<4;i++)
        {
            lens[i] = get_len(v[i]);
        }

        int sameLen = 1;
        for(int i = 1 ;i<4;i++)
        {
            if(lens[i] != lens[i-1])
            {
                sameLen = 0;
                break;
            }
        }
        

        int rightAngle = 0;
        int count = 0;
        for(int i=0;i<4;i++)
        {
            for(int j=i;j<4;j++)
            {
                if(dot(v[i],v[j]) == 0)
                {
                    count ++;
                }
            }
        }
        
        if(count == 4)
        {
            rightAngle = 1;
        }



        if(sameLen)
        {
            if(rightAngle)
            {
                printf("square");
            }
            else
            {
                printf("rectangle");
            }
        }
        else if(rightAngle)
        {
            printf("diamond");
        }
        else
        {
            printf("other");
        }

    }




    return 0;
}