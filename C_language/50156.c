#include<stdio.h>=

int main()
{
    int a,b,v,w,x,y,z;
    scanf("%d%d%d%d%d%d%d",&a,&b,&v,&w,&x,&y,&z);


    int maxIndex = 0;
    double maxValue = -1.0;

    for(int i=1;i<=b+6;i++)
    {
        double tp = 0;

        if(i>=a && i<b)
        {
            if(i%2==0)tp = w;
            else tp = v;
        }
        else if(i>=b)
        {
            if(i%3 == 0) tp =x;
            else if(i%3 == 1) tp = y;
            else tp =z;
        }

        tp =tp / i;

        if(maxValue<tp)
        {
            maxIndex = i;
            maxValue = tp;
        }

    }
    printf("%d",maxIndex);
    // int ans = 0;
    
    // if(v==w && w==x && x==y && y==z)
    // {
    //     printf("%d",1);
    // }
    // else if(v>=w&&v>=x&&v>=y&&v>=z)
    // {
    //     if(a%2 == 1)printf("%d",a);
    //     else printf("%d",a+1);
    // }

    // else if(w>=x&&w>=v&&w>=y&&w>=z)
    // {
    //     if(a%2 == 0) printf("%d",a);
    //     else printf("%d",a+1);
    // }

    // else if(x>=v && x>=y && x>=w && x>=z)
    // {
    //     if(b%3==0) printf("%d",b);
    //     else if(b%3==1) printf("%d",b+2);
    //     else printf("%d",b+1);
    // }

    // if(y>=x && y>=z && y>=v && y>=w)
    // {
    //     if(b%3==1) printf("%d",b);
    //     else if(b%3==0) printf("%d",b+1);
    //     else printf("%d",b+2);
    // }
    
    
    // if(z>=x && z>=v && z>=a && z>=w)
    // {
    //     if(b%3==2) printf("%d",b);
    //     else if(b%3==1) printf("%d",b+1);
    //     else printf("%d",b+2);
    // }
    




    return 0;
}