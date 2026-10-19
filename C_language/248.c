#include<stdio.h>
#include<stdbool.h>
#define LEN 9

bool isInMap(int r,int c)
{
    return r<LEN && r>=0 && c<LEN && c>=0;
}

bool MineMap(int ans[LEN][LEN],int map[LEN][LEN],int r,int c)
{
    if(c==LEN) 
    {
        c=0;r+=1;
    }
    if(r==LEN)
    {
        for(int i=0;i<LEN;i++)
        {
            for(int j=0;j<LEN;j++)
            {
                if(map[i][j]!=0)
                {
                    return false;
                }
            }
        }
        return true;

    } 

    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]!=0)
            {
                return false;
            }
        }
    }

    bool canPut = true;
    for(int i=r-1;i<=r+1;i++)
    {
        for(int j=c-1;j<=c+1;j++)
        {
            if( isInMap(i,j) && map[i][j] == 0)
            {
                canPut = false;
                break;
            }
        }
    }

    if(canPut)
    {
        for(int i=r-1;i<=r+1;i++)
        {
            for(int j=c-1;j<=c+1;j++)
            {
                if(isInMap(i,j))
                map[i][j] -=1;
            }
        }


        ans[r][c]+=1;

        if(!MineMap(ans,map,r,c+1))
        {
            for(int i=r-1;i<=r+1;i++)
            {
                for(int j=c-1;j<=c+1;j++)
                {
                    if(isInMap(i,j))
                        map[i][j] +=1;
                }
            }

            ans[r][c]-=1;

            return MineMap(ans,map,r,c+1);
        }
        else
        {
            return true;
        }

    } 
    return MineMap(ans,map,r,c+1);

}


int main()
{   
    int map[LEN][LEN];
    for(int i=0;i<LEN;i++)
        for(int j=0;j<LEN;j++)
            scanf("%d",&map[i][j]);

    int ans[LEN][LEN] = {0};

    MineMap(ans,map,0,0);

    for(int i=0;i<LEN;i++)
    {
        for(int j=0;j<LEN;j++)
        {
            if(map[i][j]!=0)
            {
                printf("no solution\n");
                return 0;
            }
        }
    }

    for(int i=0;i<LEN;i++)
    {
        if(i!=0) putchar('\n');
        for(int j=0;j<LEN;j++)
        {
            if(j!=0)putchar(' ');
            printf("%d",ans[i][j]);

        }
    }
    



    return 0;
}