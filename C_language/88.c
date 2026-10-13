#include<stdio.h>

int main()
{
    int in1,in2;
    scanf("%d%d",&in1,&in2);

    int map[10]={0};
    int a=0;
    for(int i=0;i<4;i++)
    {   
        if(in1%10 == in2%10) a++;
        map[in1%10]++;
        map[in2%10]++;

        in1/=10;
        in2/=10;
    }

    int b=0;
    for(int i=0;i<10;i++)
    {
        if(map[i]==2) b++;
    }

    printf("%dA%dB",a,b-a);

    

    


    return 0;
}