#include<stdio.h>
#include<stdbool.h>

bool IsInMatrix(int a, int b,int len)
{
    return ( (a>=0) && (b>=0) && (a<len) && (b<len) ) ;
}


int main()
{
    int len;
    scanf("%d",&len);

    int map[len][len];

    for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
    scanf("%d",&(map[i][j]));


    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    int types[4] ={0};
    
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            int count1 = 0;
            if(map[i][j] != 1) continue;

            for(int k=0;k<4;k++)
            {
                if(IsInMatrix(i+x[k],j+y[k],len))
                {
                    if(map[i+x[k]][j+y[k]] == 1) 
                        count1++;
                }
            }

            if(count1 == 4) 
            {types[0]++;}
            else if(count1 == 3) 
            {types[1]++;}
            else if(count1 == 2)
            {
                if( IsInMatrix(i+x[0],j+y[0],len) && IsInMatrix(i+x[1],j+y[1],len) && map[i+x[0]][j+y[0]]==1 && map[i+x[1]][j+y[1]]==1)
                    continue;
                if( IsInMatrix(i+x[2],j+y[2],len) && IsInMatrix(i+x[3],j+y[3],len) && map[i+x[2]][j+y[2]]==1 && map[i+x[3]][j+y[3]]==1)
                    continue;
                types[2]++;
            }
            else if(count1 == 1 )
            {types[3]++;}
        }
    }

    for(int i=0;i<4;i++)
    {
        printf("%d",types[i]);
        if(i!=3) putchar('\n');
    }


    return 0;
}