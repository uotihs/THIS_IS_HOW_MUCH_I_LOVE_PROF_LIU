#include<stdio.h>
#include<string.h>

void try_minimal_sets(int depth,int Nowvalue,unsigned long long nowSet,unsigned long long sets[],int values[],int testcases,int* min)
{
    
    {
        int isAns = 1;
        for(int i=0;i<26;i++)
        {
            if(((nowSet >> i)&1)!=1)
            {
                isAns = 0;
                break;
            }
        }

        if(isAns)
        {
            if(Nowvalue < *min)
            {
                *min = Nowvalue;
            }
            return;
        }
        
    }
    if(depth>=testcases) return;

    try_minimal_sets(depth+1,Nowvalue,nowSet,sets,values,testcases,min);

    try_minimal_sets(depth+1,Nowvalue+values[depth],nowSet|sets[depth],sets,values,testcases,min);

}


int main()
{
    unsigned long long twos[26];
    int assign = 1;
    for(int i=0;i<26;i++)
    {
        twos[i] = assign;
        assign*=2;
    }


    int testCases;
    scanf("%d",&testCases);

    unsigned long long sets[testCases];
    int values[testCases];

    for(int now=0;now<testCases;now++)
    {
        char in[51];
        scanf("%s",in);

        int len = strlen(in);

        sets[now] = 0;
        for(int i=0;i<len;i++)
        {
            sets[now] |= twos[(in[i]-'a')]; 
        }

        scanf("%d",&values[now]);
    }



    int min = __INT32_MAX__;
    try_minimal_sets(0,0,0,sets,values,testCases,&min);

    printf("%d",min);

    return 0;
}
