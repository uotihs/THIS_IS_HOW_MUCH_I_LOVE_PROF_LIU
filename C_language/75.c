#include<stdio.h>



int main()
{
    int ABCtable[26] = {0};
    char in = 0;
    while (scanf("%c",&in) != EOF)
    {
        if(  'A' <= in && in <= 'Z' )
            ABCtable[ (in-'A') ] += 1;
        else if('a' <= in && in <= 'z')
            ABCtable[ (in-'a') ] += 1;
    }
    
    for(int i=0;i<26;i++)
    {
        printf("%d",ABCtable[i]);
        if(i != 25) putchar('\n');
    }


    return 0;
}