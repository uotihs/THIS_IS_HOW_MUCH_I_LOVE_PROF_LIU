#include<stdio.h>

int distance(int x1,int y1,int x2,int y2)
{
    int sum = 0;

    if(x2>x1) sum += x2-x1;
    else sum += x1-x2;

    if(y2>y1) sum += y2-y1;
    else sum += y1-y2;

    return sum;
}


int main()
{

    int parkingLotNums;
    scanf("%d",&parkingLotNums);

    int pl[parkingLotNums][4];

    for(int i=0;i<parkingLotNums;i++)
    {
        scanf("%d%d%d",&pl[i][0],&pl[i][1],&pl[i][2]);
    }

    int bicycleNums;
    scanf("%d",&bicycleNums);

    for(int i=0;i<parkingLotNums;i++)
    {
        pl[i][3] = 0 ;
    }


    for(int i=0;i<bicycleNums;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);


        int LastSmlDis,lastSmlIndex=-1;
        for(int j = 0 ;j<parkingLotNums;j++)
        {
            if(pl[j][3] == pl[j][2]) continue;

            if(lastSmlIndex != -1)
            {
                int nowDis = distance(x,y,pl[j][0],pl[j][1]);
                if( nowDis < LastSmlDis)
                {
                    lastSmlIndex = j;
                    LastSmlDis = distance(x,y,pl[j][0],pl[j][1]);
                }
                else if(nowDis == LastSmlDis)
                {
                    if(pl[lastSmlIndex][0] > pl[j][0])
                    {
                        lastSmlIndex = j;
                        LastSmlDis = distance(x,y,pl[j][0],pl[j][1]);
                    }
                    else if(pl[lastSmlIndex][0] == pl[j][0])
                    {
                        if(pl[lastSmlIndex][1] > pl[j][1])
                        {
                            lastSmlIndex = j;
                            LastSmlDis = distance(x,y,pl[j][0],pl[j][1]);   
                        }
                    }
                }

            }
            else
            {
                lastSmlIndex = j;
                LastSmlDis = distance(x,y,pl[j][0],pl[j][1]);
            }
        }

        pl[lastSmlIndex][3]++;
    }

    for(int i=0;i<parkingLotNums;i++)
    {
        if(i!=0)putchar('\n');
        printf("%d",pl[i][3]);
    }



    return 0;
}