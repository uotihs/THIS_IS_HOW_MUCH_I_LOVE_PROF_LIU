#include<stdio.h>
#include<string.h>
#include<stdbool.h>


enum {ADD,MINUS};

void Concatenate(char* n1,char* n2)
{
    int len = strlen(n1);
    strcpy(n1+len,n2);
}

void Truncation(char* n1,char* n2)
{
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    if(len2>len1) return;

    for(int i = len1-len2;i<len1;i++)
    {
        if(n1[i]!=n2[i-len1+len2])
        {
            return;
        }
    }

    n1[len1-len2] = '\0';
}


void Duplication(char* n1,int i)
{
    char tp[5001] = {0};
    int len = strlen(n1);
    int index = 0;
    for(int k=0;k<len;k++)
    {
        for(int j=0;j<i;j++)
        {
            tp[index] = n1[k];
            index++;
        }
    }
    strcpy(n1,tp);
}

void Stride(char* n1,int i)
{
    int index = 0;
    int len = strlen(n1);

    for(int k=0;k<len;k++)
    {
        if(k%i==0)
        {
            n1[index] = n1[k];
            index++;
        }
    }

    n1[index] = '\0';
}


int main()
{
    int testcases;
    scanf("%d",&testcases);
    char n1[5001] = {0};
    char n2[5001] = {0};

    char in[5001] = {0};
    int lastdo = ADD;
    scanf("%s",n2);

    for(int i=1;i<testcases;i++)
    {
        scanf("%s",in);
        if(in[0]=='+')
        {
            if(lastdo == ADD)
            {
                Concatenate(n1,n2);
                scanf("%s",n2);
            }
            else if(lastdo == MINUS)
            {
                Truncation(n1,n2);
                scanf("%s",n2);
            }
            
            
            lastdo = ADD;
        }
        else if(in[0]=='-')
        {
            if(lastdo == ADD)
            {
                Concatenate(n1,n2);
                scanf("%s",n2);
            }
            else if(lastdo == MINUS)
            {
                Truncation(n1,n2);
                scanf("%s",n2);
            }
            
            lastdo = MINUS;
        }
        else if(in[0]=='*')
        {
            int times;
            scanf("%d",&times);
            Duplication(n2,times);
        }
        else if(in[0]=='/')
        {
            int times;
            scanf("%d",&times);
            Stride(n2,times);
        }
        else
        {
            printf("s");
        }
    }

    if(lastdo == ADD)
    {
        Concatenate(n1,n2);
    }
    else if(lastdo == MINUS)
    {
        Truncation(n1,n2);
    }
    printf("%s",n1);

    return 0;
}