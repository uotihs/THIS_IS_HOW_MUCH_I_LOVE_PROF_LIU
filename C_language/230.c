#include<stdio.h>

void putInBag(int index,int n,int backPack[][2],int nowWeight,int limit,int nowValue,int* max)
{
    if(nowWeight > limit) return;
    if(index > n) return;
    
    if(nowValue > (*max)) (*max) = nowValue;


    putInBag(index+1,n,backPack,nowWeight,limit,nowValue,max);
    putInBag(index+1,n,backPack,nowWeight+backPack[index][0],limit,nowValue+backPack[index][1],max);

}

int main()
{
    int n,limit;
    scanf("%d%d",&n,&limit);

    int backPack[n][2];

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&backPack[i][0],&backPack[i][1]);
    }
    int max = 0;
    putInBag(0,n,backPack,0,limit,0,&max);

    printf("%d",max);

    return 0;
}