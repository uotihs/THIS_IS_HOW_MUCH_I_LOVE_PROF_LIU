#include<stdio.h>
#include<stdbool.h>


void solve(int i,int n,int m,int classRoom[n],int timesC[m][4],bool isSelected[n][m],int nowSum,int* max)
{
    if(i==m)
    {
        if((*max) < nowSum)
        {
            (*max) = nowSum;
        }
        return;
    }

    int test = nowSum;
    for(int a=i;a<m;a++)
    {
        test+= timesC[a][1]-timesC[a][0]+1;
    }
    if(test <(*max))
    return;

    for(int nowclassRooms = 0 ; nowclassRooms < n ; nowclassRooms++)
    {
        if(timesC[i][2] > classRoom[nowclassRooms])
        {
            continue;
        }

        bool canIuse = 1;
        for(int past = 0 ; past < i ; past++)
        {
            if(!(isSelected[nowclassRooms][past]))
            continue;
            
            if(timesC[past][3]!=timesC[i][3])
            {
                continue;
            }

            int startTimeNow = timesC[i][0];
            int endTimeNow = timesC[i][1];

            int startTimePast =timesC[past][0];
            int endTimePast = timesC[past][1];

            if(startTimeNow <= endTimePast && endTimeNow >= startTimePast)
            {
                canIuse = 0;
                break;
            }
        }

        if(canIuse)
        {
            isSelected[nowclassRooms][i] = 1;
            solve(i+1,n,m,classRoom,timesC,isSelected,nowSum+timesC[i][1]-timesC[i][0]+1,max);
            isSelected[nowclassRooms][i] = 0;
        }
    }
    solve(i+1,n,m,classRoom,timesC,isSelected,nowSum,max);

}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int classRoom[n];
    char names[100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",names);
        scanf("%d",&classRoom[i]);
    }
    bool isSelected[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            isSelected[i][j]=0;
        }
    }
    int timesC[m][4];
    for(int i=0;i<m;i++)
    {
        scanf("%s",names);

        int tp0 ,tp1,tp2,tp3,tp4,tp5;
        scanf("%d",&tp0);
        scanf("%d",&tp1);
        scanf("%d",&tp2);
        scanf("%d",&tp3);
        scanf("%d",&tp4);
        scanf("%d",&tp5);

        timesC[i][0] =tp0*60+tp1;
        timesC[i][1] =tp2*60+tp3;
        timesC[i][2] =tp4;
        timesC[i][3] =tp5;
    }


    int max = 0;
    solve(0,n,m,classRoom,timesC,isSelected,0,&max);

    printf("%d",max);




    return 0;
}