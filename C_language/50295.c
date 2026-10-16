#include<stdio.h>
#include<stdbool.h>

int main()
{
    int m,c;
    scanf("%d%d",&m,&c);

    int items[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&(items[i]));
    }


    int remainindex = 0;
    int remainCap[m];
    for(int i=0;i<m;i++)
    {
        remainCap[i] = c;
    }

    int remainIndex2 = 0;
    int remainCap2[m];
    for(int i=0;i<m;i++)
    {
        remainCap2[i] = c;
    }
    
    int remainindex3 = 0;
    int remainCap3[m];
    for(int i=0;i<m;i++)
    {
        remainCap3[i] = c;
    }





    for(int now = 0 ; now < m ;now ++)
    {

        int smallest = __INT32_MAX__;
        int smallestIndex = -1;
        bool found = 0;
        for(int i=0;i<remainindex;i++)
        {
            if(remainCap[i] - items[now] >= 0 && remainCap[i]- items[now] < smallest)
            {
                // printf("now = %d item[now]=%d smallestindex = %d smallest = %d\n",now,items[now],i,remainCap[i] - items[now]);
                smallest = remainCap[i] - items[now];
                smallestIndex = i;
                found = 1;

            }
        }
        if(found)
        {
            remainCap[smallestIndex] -= items[now];
        }
        else
        {
            remainCap[remainindex] -= items[now];
            remainindex ++;
        }

        //----------------------------------------------------//
        bool found2 = 0;
        int canfitIndex = -1;
        for(int i=0;i<remainIndex2;i++)
        {
            if(remainCap2[i] - items[now] >= 0 )
            {
                // printf("now = %d item[now]=%d canfit = %d\n",now,items[now],i,canfitIndex);
                canfitIndex = i;
                found2 = 1;
                break;
            }
        }
        if(found2)
        {
            remainCap2[canfitIndex] -= items[now];
        }
        else
        {
            remainCap2[remainIndex2] -= items[now];
            remainIndex2 ++;
        }
        //----------------------------------------------------//
        
        int biggest = __INT32_MAX__+1;
        int biggestIndex = -1;
        bool found3 = 0;
        for(int i=0;i<remainindex3;i++)
        {
            if(remainCap3[i] - items[now] >= 0 && remainCap3[i]- items[now] > biggest)
            {
                // printf("now = %d item[now]=%d biggestindex = %d biggest = %d\n",now,items[now],i,remainCap[i] - items[now]);
                biggest = remainCap3[i] - items[now];
                biggestIndex = i;
                found3 = 1;
            }
        }
        if(found3)
        {
            remainCap3[biggestIndex] -= items[now];
        }
        else
        {
            remainCap3[remainindex3] -= items[now];
            remainindex3 ++;
        }
    }

    printf("%d %d %d",remainindex ,remainIndex2,remainindex3);

    




    return 0;
}