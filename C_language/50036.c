#include<stdio.h>

void pickNum(int at_least,int now,int index,int nums[],int num,int nowSum,int sum,int* count,int isadded)
{
    if(nowSum > sum) return;
    if(index > num) return;

    if( now >= at_least && nowSum <= sum && isadded)
    {
        (*count) ++;    
    }
    if(index==num) return;



    pickNum(at_least,now+1,index+1,nums,num,nowSum+nums[index],sum,count,1);
    pickNum(at_least,now,index+1,nums,num,nowSum,sum,count,0);
    
}


int main()
{
    int at_least,num,sum;
    scanf("%d%d%d",&at_least,&num,&sum);

    int nums[num];
    for(int i=0;i<num;i++)
    {
        scanf("%d",&nums[i]);
    }

    int count = 0;

    pickNum(at_least,0,0,nums,num,0,sum,&count,0);
    printf("%d",count);

    return 0;
}