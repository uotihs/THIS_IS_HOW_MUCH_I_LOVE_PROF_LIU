#include<stdio.h>
#include<stdbool.h>

int position[20] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};



void solve(int now,int ppl,int pairs,char pair[][2],char currentAns[],char ans[],int nowMax,int* maximum)
{
    if(nowMax >= *maximum) return;

    if(now == ppl)
    {
        if(nowMax >= (*maximum)) return;

        *maximum = nowMax;
        for(int i=0;i<ppl;i++)
        {
            ans[i] = currentAns[i];
        }

        return;
    }

    {
        int remaining[20] = {0};

        for(int i = 0; i < pairs; i++)
        {
            int a = pair[i][0] - 'A';
            int b = pair[i][1] - 'A';

            if(position[a] != -1 && position[b] == -1)
                remaining[a]++;

            if(position[b] != -1 && position[a] == -1)
                remaining[b]++;
        }

        for(int i = 0; i < ppl; i++)
        {
            if(position[i] == -1 || remaining[i] == 0)
                continue;

            if(now + remaining[i] - 1 - position[i] >= *maximum)
                return;
        }
    }


    for(int i=0;i<ppl;i++)
    {
        if(position[i] != -1) continue;

        currentAns[now] = i+'A';
        position[i] = now;

        int NOWmaxTP = nowMax;

        for(int p=0;p<pairs;p++)
        {
            if(pair[p][0]==i+'A')
            {
                int f = position[pair[p][1]-'A'];

                if(f==-1) continue;

                int distance = now - f;

                if(NOWmaxTP < distance)
                {
                    NOWmaxTP = distance;
                }
                
                if(NOWmaxTP >= *maximum) break;
            }
            else if(pair[p][1]==i+'A')
            {
                int f = position[pair[p][0]-'A'];

                if(f==-1) continue;
                
                int distance = now - f;

                if(NOWmaxTP < distance)
                {
                    NOWmaxTP = distance;
                }

                if(NOWmaxTP >= *maximum) break;
            }
        }

        if(NOWmaxTP >= (*maximum))
        {
            position[i] = -1;
            continue;
        }

        solve(now+1,ppl,pairs,pair,currentAns,ans,NOWmaxTP,maximum);

        position[i] = -1;
    }




}


int main()
{
    int ppl,pairs;
    scanf("%d%d",&ppl,&pairs);
    char ans[ppl];
    char pair[pairs][2];
    char newLine[4];
    for(int i = 0 ; i < pairs ; i++)
    {
        scanf("%s",newLine);
        pair[i][0] = newLine[0];
        scanf("%s",newLine);
        pair[i][1] = newLine[0];
    }

    char currentAns[ppl];
    int max = __INT32_MAX__;
    solve(0,ppl,pairs,pair,currentAns,ans,0,&max);

    printf("%d\n",max);
    for(int i=0;i<ppl;i++)
    {
        if(i!=0)putchar(' ');
        printf("%c",ans[i]);
    }


    return 0;
}