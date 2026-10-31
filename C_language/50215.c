#include<stdio.h>



void solve(int nowSet,int nowCost,int testCases,int nowtestcase,unsigned int sets[],int costs[],int* min)
{
    if(nowSet==67108863)
    {
        if((*min)>nowCost)
            *min = nowCost;
        return;
    }


    if(nowtestcase==testCases)
    {
        return;
    }

    solve(nowSet|sets[nowtestcase],nowCost+costs[nowtestcase],testCases,nowtestcase+1,sets,costs,min);
    solve(nowSet,nowCost,testCases,nowtestcase+1,sets,costs,min);
}



int main()
{
    unsigned int twos[32]={0};
    unsigned int tp=1;
    for(int i=0;i<32;i++)
    {
        twos[i]=tp;
        tp*=2;
    }






    int first = 1;
    int testCaseCounts = 0;

    while (scanf("%d",&testCaseCounts)!=EOF)
    {
        unsigned int sets[testCaseCounts];
        int costs[testCaseCounts];
        for(int i=0;i<testCaseCounts;i++)
        {
            char in[50];
            scanf("%s",in);
            sets[i]=0;
            costs[i]=0;

            int index = 0;
            while (in[index]!='\0')
            {
                costs[i]+=in[index]-'a'+1;
                // printf("%c ",in[index]);
                sets[i] |= twos[in[index]-'a'];
                index++;
            }
        }

        int ans = __INT32_MAX__;
        solve(0,0,testCaseCounts,0,sets,costs,&ans);
        
        if(first==1)first=0;
        else putchar('\n');
        printf("%d",ans);




    }



    return 0;
}