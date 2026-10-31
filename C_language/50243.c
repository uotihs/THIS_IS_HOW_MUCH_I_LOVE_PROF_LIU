#include<stdio.h>
#include<stdbool.h>

bool isFirst(bool a[],bool b[],int n)
{
    for(int i=0;i<n;i++)
    {
        bool A = a[i];
        bool B = b[i];

        if(A!=B)
        {
            return A>B;
        }
    }
    return false;
}


bool solve(int start,int count,bool nowSet[],int m,int n,int pairs[m][2],int *min,bool ans[])
{
    if(count>(*min)) return false;
    if(start==m) return false;

    int i = start;
    while (i<m)
    {
        if(nowSet[pairs[i][0]]==0 && nowSet[pairs[i][1]]==0)
        {
            break;
        }
        i++;
    }
    
    if(i==m)
    {
        if(count < (*min))
        {
            for(int i=0;i<n;i++)
                ans[i] = nowSet[i];
            (*min) = count;
            return true;
        }
        else if(count == (*min) && isFirst(nowSet,ans,n))
        {
            for(int i=0;i<n;i++)
                ans[i] = nowSet[i];
            (*min) = count;
            return true;
        }
        else
        {
            return false;
        }

    }


    nowSet[pairs[i][0]] = 1;
    solve(i,count+1,nowSet,m,n,pairs,min,ans);
    nowSet[pairs[i][0]] = 0;   

    nowSet[pairs[i][1]] = 1;
    solve(i,count+1,nowSet,m,n,pairs,min,ans);
    nowSet[pairs[i][1]] = 0;   

    return false;
}




int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    bool first = 1;
    int pairs[m][2];

    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&pairs[i][0],&pairs[i][1]);
    }
    int min = __INT32_MAX__;
    bool nowSet[n];
    bool ans[n];
    for(int i=0;i<n;i++)
    {
        nowSet[i] = 0;
        ans[i] = 0;
    }
    
    solve(0,0,nowSet,m,n,pairs,&min,ans);

    for(int i=0;i<n;i++)
    {
        if(ans[i])
        {
            if(first) first = 0;
            else putchar('\n');

            printf("%d",i);
        }
    }




    return 0;
}