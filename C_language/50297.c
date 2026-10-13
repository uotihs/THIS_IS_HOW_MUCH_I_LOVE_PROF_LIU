#include<stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

typedef struct vector
{
    int xstart;
    int ystart;
    int xend;
    int yend;
}Vector;

int vectorAxes(Vector v)
{
    int count=0;
    int xrem,yrem;

    if(v.xstart < v.xend)
    {
        for(int i=v.xstart;i<=v.xend;i++)
        {
            if(i==0)
            {
                count++;
            }
        }
    }
    else
    {
        for(int i=v.xstart;i>=v.xend;i--)
        {
            if(i==0)
            {
                count++;
            }
        }
    }
    
    if(v.ystart < v.yend)
    {
        for(int i=v.ystart;i<=v.yend;i++)
        {
            if(i==0)
            {
                count++;
            }
        }
    }
    else
    {
        for(int i=v.ystart;i>=v.yend;i--)
        {
            if(i==0)
            {
                count++;
            }
        }
    }


    if(count == 2)
    {
        if((0 - v.xstart)*(v.yend - v.ystart) == (v.xend - v.xstart) * (0 - v.ystart) )
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    
    return count;
};




int main()
{
    int n;
    scanf("%d",&n);
    Point points[n];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d%d",&(points[i].x),&(points[i].y));
    }

    // Vector vectors[n];
    // for(int i=1;i<n;i++)
    // {
    //     vectors[i].xstart = points[i-1].x;
    //     vectors[i].ystart = points[i-1].y;
    //     vectors[i].xend = points[i].x;
    //     vectors[i].yend = points[i].y;
    // }
    // vectors[0].xstart = points[n-1].x;
    // vectors[0].ystart = points[n-1].y;
    // vectors[0].xend = points[0].x;
    // vectors[0].yend = points[0].y;

    // int sum = 0;
    // for(int i=0;i<n;i++)
    // {
    //     sum += vectorAxes(vectors[i]);
    //     sum ++;
    // }

    int sum = 0;
    for(int i=1;i<n;i++)
    {
        Vector v = {points[0].x,points[0].y,points[i].x,points[i].y};
        sum+= vectorAxes(v);
        sum++;
    }

    for(int i=1;i<n-1;i++)
    {
        Vector v = {points[i].x,points[i].y,points[i+1].x,points[i+1].y};
        sum+= vectorAxes(v);
        sum++;
    }
    printf("%d",sum);

        




    return 0;
}