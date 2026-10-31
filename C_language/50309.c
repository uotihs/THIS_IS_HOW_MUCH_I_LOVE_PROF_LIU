#include<stdio.h>


void solve(int start,int n,int k,int nums[],int groups[k][n],int gLens[k],int sum[k],int *min)
{    
    for(int i=0;i<k;i++)
    {
        if(sum[i]>(*min)) return;
    }


    if(start==n)
    {
        int max = 0;
        for(int i=0;i<k;i++)
        {
            if(sum[i]>max)
            {
                max = sum[i];
            }
        }
        if(max<(*min))
        {
            (*min) = max;
        }
        return;
    }



    

    for(int i=0;i<k;i++)
    {
        groups[i][gLens[i]] = nums[start];
        sum[i]+=nums[start];
        gLens[i]++;
        
        solve(start+1,n,k,nums,groups,gLens,sum,min);

        sum[i]-=nums[start];
        gLens[i]--;
    }
}






int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int nums[n];
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);

    int groups[k][n];
    int gLens[k];
    int sum[k];
    for(int i=0;i<k;i++) {gLens[i] = 0;sum[i]=0;}

    int min = __INT32_MAX__;
    solve(0,n,k,nums,groups,gLens,sum,&min);

    printf("%d",min);



}