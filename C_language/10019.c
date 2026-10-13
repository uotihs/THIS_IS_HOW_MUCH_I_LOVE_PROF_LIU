#include<stdio.h>
#include<ctype.h>

int strLen(char s[],int start)
{
    int len = start;
    while (s[len]!='\n')
    {
        len++;
    }
    return len;
}

int strBack(char s[],int len)
{
    int last = len;
    while (isspace(s[last]))
    {
        last-=1;
    }
    return last;
}

int main()
{
    char string[1000] = {0};
    int first = 1;

    while(fgets(string,1000,stdin)!=NULL){
        if(first==0) putchar('\n');
        else
        {
            first = 0;
        }

        int indexS = 0;
        while(isspace(string[indexS]))
        {
            indexS++;
        }
        
        int len = strLen(string,indexS);
        int last = strBack(string,len);
        
        for(int i=indexS;i<=last;i++)
        {
            printf("%c",string[i]);
        }

    }

    
}