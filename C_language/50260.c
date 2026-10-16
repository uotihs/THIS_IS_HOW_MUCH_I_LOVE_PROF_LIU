#include<stdio.h>

int isInMap(int r,int c,int len)
{
    return r>=0 && r<len && c>=0 && c<len;
}


int main()
{
    int len;
    scanf("%d",&len);

    int map[len][len];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    
    int testCases;
    scanf("%d",&testCases);
    int ans[testCases][5];
    
    int up[len] ;
    int down[len] ;
    int left[len] ;
    int right[len] ;
    for(int i = 1 ; i <= len ; i++)
    {
        up[i-1] = -i;
        down[i-1] = i;
        left[i-1] = -i;
        right[i-1] = i;
    }


    for(int now= 0 ; now < testCases ; now ++)
    {
        int row,col;
        scanf("%d%d",&row,&col);
        ans[now][3] = row ; ans[now][4] = col;

        int upCount = 0 ,downCount = 0 , leftCount = 0 , rightCount = 0,type = -1;
        for(int i=0;i<len;i++)
        {
            if(isInMap(row+up[i],col,len) && map[row+up[i]][col] == 1)
            {
                upCount++;
            }
            else
            {
                break;
            }
        }

        for(int i=0;i<len;i++)
        {
            if(isInMap(row+down[i],col,len) && map[row+down[i]][col] == 1)
            {
                downCount++;
            }
            else
            {
                break;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(isInMap(row,col+left[i],len) && map[row][col+left[i]] == 1)
            {
                leftCount++;
            }
            else
            {
                break;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(isInMap(row,col+right[i],len) && map[row][col+right[i]] == 1)
            {
                rightCount++;
            }
            else
            {
                break;
            }
        }

        if(rightCount && upCount)
        {
            type = 0;
            ans[now][0] = type;
            ans[now][1] = upCount;
            ans[now][2] = rightCount;
        }
        else if(leftCount && upCount)
        {
            type = 1;
            ans[now][0] = type;
            ans[now][1] = upCount;
            ans[now][2] = leftCount;
        }
        else if(leftCount && downCount)
        {
            type = 2;
            ans[now][0] = type;
            ans[now][1] = downCount;
            ans[now][2] = leftCount;
        }
        else if(rightCount && downCount)
        {
            type = 3;
            ans[now][0] = type;
            ans[now][1] = downCount;
            ans[now][2] = rightCount;
        }

    }
    
    for(int i=0;i<testCases;i++)
    {
        for(int j = 1 ;j<testCases ;j++)
        {
            if(ans[j][3] < ans[j-1][3])
            {
                int temprow,tempcol,temptype,tempver,temphor;
                
                temptype = ans[j][0];
                tempver = ans[j][1];
                temphor = ans[j][2];
                temprow = ans[j][3];
                tempcol = ans[j][4];

                for(int k=0;k<5;k++)
                {
                    ans[j][k] = ans[j-1][k];
                }
                ans[j-1][0] = temptype;
                ans[j-1][1] = tempver;
                ans[j-1][2] = temphor;
                ans[j-1][3] = temprow;
                ans[j-1][4] = tempcol;
            }
            else if(ans[j][3] == ans[j-1][3])
            {
                if(ans[j][4] < ans[j-1][4])
                {
                    int temprow,tempcol,temptype,tempver,temphor;
                
                    temptype = ans[j][0];
                    tempver = ans[j][1];
                    temphor = ans[j][2];
                    temprow = ans[j][3];
                    tempcol = ans[j][4];

                    for(int k=0;k<5;k++)
                    {
                        ans[j][k] = ans[j-1][k];
                    }
                    ans[j-1][0] = temptype;
                    ans[j-1][1] = tempver;
                    ans[j-1][2] = temphor;
                    ans[j-1][3] = temprow;
                    ans[j-1][4] = tempcol;
                }
            }
            
        }
    }

    for(int i=0;i<testCases;i++)
    {
        if(i!=0) putchar('\n');
        printf("%d %d %d",ans[i][0],ans[i][1]+1,ans[i][2]+1);
    }
    


    return 0;
}