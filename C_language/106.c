#include<stdio.h>

int main()
{
    char num[1001] = {0};
    int first = 1;
    while (scanf("%s",num))
    {
        if(num[0] == '-')break;
        if(first==0)putchar('\n');
        else
        {
            first = 0;
        }

        int d2=0,d3=0,d5=0,d11=0;

        int index = 0;
        int sumD2 = 0;
        int sumD1 = 0;
        while (num[index] != 0)
        {
            
            if(index % 2 == 0) sumD1 += num[index]-'0';
            else sumD2 += num[index]-'0';
            index++;
        }
        if((num[index-1]-'0') % 2 == 0) d2 =1;
        if((num[index-1]-'0') % 5 == 0) d5 =1;

        int tp = sumD1 - sumD2;
        if(tp < 0 ) tp = - tp;

        if(tp % 11 == 0) d11 = 1;

        if((sumD1+sumD2) % 3 == 0) d3 = 1;
        
        
        if(d2) printf("yes");
        else printf("no");

        putchar(' ');

        if(d3) printf("yes");
        else printf("no");

        putchar(' ');

        if(d5) printf("yes");
        else printf("no");

        putchar(' ');

        if(d11) printf("yes");
        else printf("no");

    }
    





    return 0;
}