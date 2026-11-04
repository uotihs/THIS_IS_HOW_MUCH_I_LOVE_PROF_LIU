#include<stdio.h>
#include<math.h>

typedef struct 
{
    double a;
    double b;
    double c;
}Line;



double getPoints(Line l1,Line l2,double* x,double*y)
{
    *y = ( l2.c * l1.a - l1.c * l2.a ) / ( l1.b * l2.a - l2.b * l1.a );
    // printf("y = %.3lf\n",*y);
    *x = ( l2.c * l1.b - l1.c * l2.b ) / ( l1.a * l2.b - l2.a * l1.b );
    // printf("x = %.3lf\n",*x);
}

int main()
{
    int sides;
    scanf("%d",&sides);

    double ans = 0;
    Line lines[sides];

    for(int now = 0 ; now < sides ; now++ )
    {
        scanf("%lf%lf%lf",&(lines[now].a),&(lines[now].b),&(lines[now].c));
    }

    double points[sides][2];

    for(int i=1;i<sides;i++)
    {
        getPoints(lines[i],lines[i-1],&points[i][0],&points[i][1]);
    }
    getPoints(lines[sides-1],lines[0],&points[0][0],&points[0][1]);

    for(int i=1;i<sides;i++)
    {
        ans += sqrt(( points[i][0] - points[i-1][0] )* ( points[i][0] - points[i-1][0] ) +  ( points[i][1] - points[i-1][1] ) * ( points[i][1] - points[i-1][1] ) );
        // printf("%.3lf ",ans);
    }
    ans += sqrt(( points[0][0] - points[sides-1][0] )* ( points[0][0] - points[sides-1][0] ) +  ( points[0][1] - points[sides-1][1] ) * ( points[0][1] - points[sides-1][1] ) );


    printf("%.3lf ",ans);


    return 0;
}