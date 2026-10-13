#include<stdio.h>

int isCom(char s[])
{
    int index = 0,isCo = 0;
    while (s[index]!=0)
    {
        if(s[index]=='.') isCo = 1;
        index++;
    }

    return isCo;
}

int strCmp(char cmp[],char s[])
{
    int index = 0;
    int same = 1;

    while (cmp[index] != 0)
    {
        if(cmp[index]!=s[index])
        {
            same = 0;
            break;
        }
        index++;
    }

    if(s[index]!= 0 && s[index]!= '.') same = 0;


    return same;
}

int noprint(char s[])
{
    char cmp[4][5] = {"of","the","at","and"};
    int  is = 0;
    for(int i=0;i<4;i++)
    {
        if(strCmp(cmp[i],s))
        {
            is = 1;
            break;
        }
    }
    return is;

}


int main()
{
    char sin[1000] = {0};

    char buf[1000] = {0};
    int index = 0;
    int first = 1;
    while (scanf("%s",sin)!=EOF)
    {
        if(!noprint(sin))
        {
            buf[index] = sin[0]+'A'-'a';
            index++;
        } 

        if(isCom(sin))
        {
            if(first)
            {
                first = 0;
            }
            else
            {
                putchar('\n');
            }
            for(int i=0;i<index;i++)
            {
                putchar(buf[i]);
                buf[i] = 0;
            }
            index = 0;
        }
        
    }
    




    return 0;
}