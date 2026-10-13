#include<stdio.h>

int main()
{
    unsigned long long a,b,c,d,e,f;
    scanf("%llu%llu%llu%llu%llu%llu",&a,&b,&c,&d,&e,&f);

    printf("%llu\n%llu",2*(a+b+c+d+e+f),(a+c+e)*(b+d+f)-(b+d)*e -b*c);
    // int sum = 0;
    // int area = 0;
    // int jochung = 0;
    // int up=1;
    // int in;
    // int last = 0;
    // while(scanf("%d",&in)!=EOF)
    // {
    //     jochung += in;

    //     if(up)
    //     {
    //         last = in;
    //     }
    //     else
    //     {
    //         sum += in;
    //         area += sum * last ;
    //     }

    //     up =!up;
    // }
    // printf("%d\n%d",2*jochung,area);



    return 0;
}