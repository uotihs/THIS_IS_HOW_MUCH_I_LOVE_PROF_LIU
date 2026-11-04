#include<stdio.h>
#include<string.h>

char tentwenty[10][10] = {"onety","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char elevens[10][10] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char onetwothree[10][6] ={"one","two","three","four","five","six","seven","eight","nine","ten"};
char millions[6][15] = {"thousand","million","billion","trillion","quadrillion","quintillion"};

int Print(int i)
{
    int haveFirst = 0;
    if(i==0)
    {
        return 0;
    }


    if(i/100)
    {
        printf("%s hundred",onetwothree[i/100 - 1]);
        i%=100;
        haveFirst = 1;
    }
    
    if(i>=11 && i<=19)
    {
        if(haveFirst) putchar(' ');
        printf("%s",elevens[i-11]);
        return 1;
    }


    if(i/10)
    {
        if(haveFirst) putchar(' ');
        printf("%s",tentwenty[i/10 - 1]);
        i%=10;    
        if(i)
        {
            printf("-%s",onetwothree[i-1]);
        }
        return 1;
    }

    if(i)
    {
        if(haveFirst) putchar(' ');
        printf("%s",onetwothree[i-1]);
    }

}


int main()
{
    char num[30] = {0};
    scanf("%s",num);
    int len = strlen(num);


    int times = len/3+1;

    for(int i=0;i<times;i++)
    {
        int n = 0;
        if(i==0)
        {
            if(len%3==0) continue;
            for(int a =0;a<len%3;a++)
            {
                n*=10;
                n+= num[3*i+a]-'0';
            }
        }
        else
        {
            for(int a =0;a<3;a++)
            {
                n*=10;

                int ind = 3*(i-1)+len%3+a;
                n+= num[ind]-'0';
            }
        }

        // printf("%d ",n);
        Print(n);
        
        if(i!=times-1)
        {
            printf(" %s ",millions[times - i - 2]);
        }
    }

    return 0;
}

