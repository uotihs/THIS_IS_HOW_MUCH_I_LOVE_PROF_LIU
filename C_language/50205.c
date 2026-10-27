#include<stdio.h>
#include<stdbool.h>

// char map={)!@#$%^&*(};
int char2num(char in)
{
    switch (in)
    {
    case ')':
        return 0;
        break;
    case '!':
        return 1;
        break;
    case '@':
        return 2;
        break;
    case '#':
        return 3;
        break;
    case '$':
        return 4;
        break;
    case '%':
        return 5;
        break;
    case '^':
        return 6;
        break;
    case '&':
        return 7;
        break;
    case '(':
        return 9;
        break;

    default:
        return -1;
    }
}
int main()
{
    int n1=0,n2=0,tp=1;
    char in;

    
    while (scanf("%c",&in)!=EOF)
    {
        int num = char2num(in);

        if(num!=-1)
        {
            n2*=10;
            n2+=num;
        }
        else
        {
            if(in=='*')
            {
                tp *= n2;
                n2 = 0;
            }
            else if(in=='+')
            {
                n1 += tp*n2;
                tp=1;
                n2=0;
            }
        }
    }
    n1 += tp*n2;


    printf("%d",n1);

    return 0;   
}