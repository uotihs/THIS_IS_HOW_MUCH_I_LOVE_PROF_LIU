#include<stdio.h>
#include<stdbool.h>

bool paintIt(int countryNum,int colors,int pairs,int p[pairs][2],int ans[],int depth)
{   
    for(int i=0;i<pairs;i++)
    {
        if(p[i][0] < depth && p[i][1] < depth)
        {
            if(ans[p[i][0]] == ans[p[i][1]])
            {
                return false;
            }
        }
    }

    if(depth == countryNum) return true;


    for(int i=1;i<=colors;i++)
    {
        ans[depth] = i;
        if(paintIt(countryNum,colors,pairs,p,ans,depth+1))
        {
            return true;
        }    
    }

    return false;


}

int main()
{
    int countryNum,colors,pairs;
    scanf("%d%d%d",&countryNum,&colors,&pairs);
    int p[pairs][2];
    int ans[countryNum];
    for(int i=0;i<pairs;i++)
    {
        scanf("%d%d",&p[i][0],&p[i][1]);
    }

    if(paintIt(countryNum,colors,pairs,p,ans,0))
    {
        for(int i=0;i<countryNum;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    else
    {
        printf("no solution.\n");
    }


}