#include<stdio.h>
#include<stdint.h>

void solve(int now,int n,int nums[],int k,uint64_t sums[],uint64_t *min)
{
    uint64_t max=0;
    for(int i=0;i<k;i++)
    {
        max += sums[i]*sums[i];
    }
    if(max >= (*min))
    { return; }

    if(now == n)
    {
        if(max < (*min)) 
        {
            (*min) = max;
        }
        return;
    }

    for(int i=0;i<k;i++)
    {
        int same = 0;
        for(int j=0;j<i;j++)
        {
            if(sums[i]==sums[j])
            {
                same= 1;
                break;      
            }
        }
        if(same) break;


        sums[i] += nums[now];
        solve(now+1,n,nums,k,sums,min);
        sums[i] -= nums[now];

        
    }
}



int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    int nums[n];
    for(int i=0;i<n;i++)scanf("%d",&nums[i]);

    uint64_t sums[k];
    for(int i=0;i<k;i++) 
    {
        sums[i] = 0;
    }
    uint64_t min = UINT64_MAX;
    
    solve(0,n,nums,k,sums,&min);

    printf("%llu",min);

}