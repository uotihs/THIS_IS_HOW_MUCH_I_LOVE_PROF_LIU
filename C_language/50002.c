#include<stdio.h>

int R[4] = {0,0,1,-1};
int C[4] = {1,-1,0,0};

int isInMap(int r,int c,int len)
{
    return r>=0 && c>=0 && r<len && c<len;
}


int Game(int len,int map1[len][len],int map2[len][len],int remember1s[len][len])
{

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            int count = 0;

            for(int a=-1;a<=1;a++)
            {
                for(int b=-1;b<=1;b++)
                {
                    if(!isInMap(i+a,j+b,len)) continue;
                    if(a==0&&b==0) continue;

                    if(map1[i+a][j+b]==1)
                    {
                        count++;
                    }
                }
            }

            if(map1[i][j]==1)
            {
                if(count<2)
                {
                    map2[i][j] = 0;

                    remember1s[i][j] =-1;
                }
                else if(count==2 || count == 3)
                {
                    map2[i][j] = 1;

                    remember1s[i][j] ++;

                }
                else if(count>3)
                {
                    map2[i][j] = 0;

                    remember1s[i][j] =-1;
                }
            }
            else
            {
                if(count == 3)
                {
                    map2[i][j] = 1;

                    remember1s[i][j] ++;
                }
                else
                {
                    map2[i][j] = 0;

                    remember1s[i][j] =-1;
                }
            }
        }
    }
/*

Any live cell with fewer than two live neighbors dies.
Any live cell with two or three live neighbors lives on to the next step.
Any live cell with more than three live neighbors dies.
Any dead cell with exactly three live neighbors becomes a live cell.

*/
}

int main()
{
    int len,times;
    scanf("%d%d",&len,&times);
    int map1[len][len];
    int map2[len][len];
    int remember1s[len][len];
    for(int i=0;i<len;i++)
    {
        for(int j= 0 ;j<len;j++)
        {
            scanf("%d",&map1[i][j]);
            remember1s[i][j]=-1;
            if(map1[i][j]==1)
            {
                remember1s[i][j] = 1;
            }
        }
    }

    
    for(int now = 1 ; now <= times ; now++)
    {
        if(now % 2 == 1)
        {
            Game(len,map1,map2,remember1s);
        }
        else
        {
            Game(len,map2,map1,remember1s);
        }

    }


    // for(int i=0;i<len;i++)
    // {
    //     for(int j=0;j<len;j++)
    //     {
    //         if(j!=0) putchar(' ');

    //         if(times%2==1)
    //         {
    //             printf("%d",remember1s[i][j]);
    //         }
    //         else
    //         {
    //             printf("%d",remember1s[i][j]);
    //         }
            
    //     }
    //     putchar('\n');
    // }


    int r=-1,c=-1;
    int max = 0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(j!=0) putchar(' ');


            if(remember1s[i][j] >= max)
            {
                max = remember1s[i][j];
                if(i>r || i==r && j>c)
                {
                    r=i;
                    c=j;
                }                
            }



            if(times%2==1)
            {
                printf("%d",map2[i][j]);
            }
            else
            {
                printf("%d",map1[i][j]);
            }
            
        }
        putchar('\n');
    }
    
    printf("%d %d",r+1,c+1);






    return 0;
}