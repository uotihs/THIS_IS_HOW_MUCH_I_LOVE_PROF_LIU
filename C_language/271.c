#include<stdio.h>


int main()
{
    int n1;
    scanf("%d",&n1);
    int nums1[n1];
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&(nums1[i]));
    }

    int n2;
    scanf("%d",&n2);
    int nums2[n2];
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&(nums2[i]));
    }


    int ans[n1+n2];

    for(int i = 0 ;i<n1+n2;i++)
    {
        ans[i] = 0;
    }

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            ans[i+j] += nums1[i] * nums2[j];         
        }
    }

    for(int i=0;i<n1+n2-1;i++)
    {
        if(i==0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
}