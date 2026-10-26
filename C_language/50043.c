#include<stdio.h>

int cross(int point1[],int point2[],int x,int y)
{
    return (point2[0]-point1[0])*(y-point1[1])-(point2[1]-point1[1])*(x-point1[0]);
}


int main()
{
    int points[3][2];

    int Xmax = __INT32_MAX__+1;
    int Xmin = __INT32_MAX__;
    int Ymax = __INT32_MAX__+1;
    int Ymin = __INT32_MAX__;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&points[i][j]);
            if(j==0)
            {
                if(points[i][j]>Xmax) Xmax = points[i][j];
                if(points[i][j]<Xmin) Xmin = points[i][j];
            }
            else
            {
                if(points[i][j]>Ymax) Ymax = points[i][j];
                if(points[i][j]<Ymin) Ymin = points[i][j];
            }
        }
    }   
    int x[4] ={0,0,1,1};
    int y[4] ={0,1,0,1};
    int count = 0;
    for(int i=Xmin;i<=Xmax;i++)
    {
        for(int j=Ymin;j<=Ymax;j++)
        {   
            int good = 1;

            for(int a=0;a<4;a++)
            {
                int c1 = cross(points[2],points[0],i+x[a],j+y[a]);
                int c2 = cross(points[0],points[1],i+x[a],j+y[a]);
                int c3 = cross(points[1],points[2],i+x[a],j+y[a]);
                if(c1>=0&&c2>=0&&c3>=0)
                {
                    continue;
                }
                if(c1<=0&&c2<=0&&c3<=0)
                {
                    continue;
                }   
                good = 0;
                break;
            }
            if(good) count++;


        }

    }

    printf("%d",count);
    




    // int areaSum = (Xmax - Xmin)*( Ymax - Ymin);
    // printf("%d ",areaSum);
    
    // {
    // for(int i=1;i<3;i++)
    // {
    //     int xDistance = points[i][0]-points[i-1][0];
    //     int yDistance = points[i][1]-points[i-1][1];

    //     if(xDistance<0) xDistance = -xDistance;
    //     if(yDistance<0) yDistance = -yDistance;     

    //     int areaTp = xDistance*yDistance;
    //     if(xDistance>yDistance)
    //     {
    //         areaSum -= xDistance;
    //         if((areaTp - xDistance)/2 > 0)
    //         areaSum -= (areaTp - xDistance)/2;
    //         printf("%d ",areaSum);
    //     }
    //     else
    //     {
    //         areaSum -= yDistance;
    //         if((areaTp - yDistance)/2 > 0)
    //         areaSum -= (areaTp - yDistance)/2;
    //         printf("%d ",areaSum);
    //     }
    // }
    // int xDistance = points[0][0]-points[2][0];
    // int yDistance = points[0][1]-points[2][1];

    // if(xDistance<0) xDistance = -xDistance;
    // if(yDistance<0) yDistance = -yDistance; 

    // int areaTp = xDistance*yDistance;
    // if(xDistance>yDistance)
    // {
    //     areaSum -= xDistance;
    //     if((areaTp - xDistance)/2 > 0)
    //     areaSum -= (areaTp - xDistance)/2;
    // }
    // else
    // {
    //     areaSum -= yDistance;
    //     if((areaTp - yDistance)/2 > 0)
    //     areaSum -= (areaTp - yDistance)/2;
    // }

    // }

    // // for


    // printf("%d",areaSum);
    return 0;
}