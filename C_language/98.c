#include<stdio.h>
#include<string.h>

int strCmp(char in1[],char in2[])
{
    int index = 0;
    while (in1[index] == in2[index] && in1[index]!=0)
    {
        index++;
    }
    
    if(in1[index]==0 && in2[index]==0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void strcpy1(char src[],char dst[])
{
    int index = 0;
    while (src[index]!= 0)
    {
        dst[index]=src[index];
        index++;
    }
    dst[index] = 0;
    
    
}


int str2index(char c[100][65],char s[65],int num)
{
    int ans=0;
    for(int i=0;i<num;i++)
    {
        int index = 0;
        int isSame = 1;
        while (c[i][index] == s[index] && c[i][index]!= 0)
        {
            // printf("%c",c[i][index]);
            // printf("|%c ",s[index]);
            index++;
            
        }

        if(c[i][index] == 0 && s[index] == 0)
        {
            // printf("Ddd");
            ans = i;
            return ans;
        }
        else
        {
            // printf("fgg%d\n",i);
            isSame = 0;
            continue;
        }
    }
}

void strcmpfirst(char s1[],char s2[])
{
    int index =0;
    while (s1[index]!=0 && s2[index] !=0)
    {
        /* code */
    }
    
}

void str_array_sorted(char* s[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(strcmp(s[j],s[j-1])<0)
            {
                char buf2[65] = {0};
                strcpy1(s[j],buf2);
                strcpy1(s[j-1],s[j]);
                strcpy1(buf2,s[j-1]);
            }
        }
    }


}





int main()
{
    int num;
    scanf("%d",&num);
    char foods[100][65] = {0};
    int foodINums[100] = {0};
    char ingredient[100][10][65] = {0};

    //putchar('t'); it means the memory is sufficient

    for(int i=0;i<num;i++)
    {
        scanf("%s",foods[i]);

        scanf("%d",&(foodINums[i]));

        for(int j=0;j<foodINums[i];j++)
        {
            scanf("%s",ingredient[i][j]);
        }
    }

    int testCount;
    scanf("%d",&testCount);
    char in1[65],in2[65];
    for(int i=0;i<testCount;i++)
    {
        if(i!=0) putchar('\n');
        
        scanf("%s",in1);
        scanf("%s",in2);

        int in1Index = str2index(foods,in1,num);
        int in2Index = str2index(foods,in2,num);
        // printf("index %d %d\n",in1Index,in2Index);

        char buf[10][65] = {0};
        int bufInd = 0;

        for(int i = 0;i < foodINums[in1Index]; i++)
        {
            for(int j=0;j<foodINums[in2Index];j++)
            {
                if(strCmp(ingredient[in1Index][i],ingredient[in2Index][j]))
                {
                    strcpy1(ingredient[in1Index][i],buf[bufInd]);
                    bufInd++;
                }
            }
        }
        char* b[bufInd];

        for(int i=0;i<bufInd;i++)
        {
            b[i] =buf[i];
        }

        str_array_sorted(b,bufInd);

        if(bufInd==0)
        {
            printf("nothing");
        }
        else
        {
            for(int i=0;i<bufInd;i++)
            {
                if(i!=0) putchar(' ');
                printf("%s",buf[i]);
            }
        }
    }



    return 0;
}