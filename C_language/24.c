#include<stdio.h>

int main()
{
    int digits=0, letters=0, vowels=0,  consonants=0;

    char in;
    while (scanf("%c",&in)!=EOF)
    {
        if(in >='0' && in<='9')
        {
            digits++;
        }
        else if(in>='a' && in<='z')
        {
            if(in =='a'||in=='e'||in=='i'||in=='o'||in=='u')
            {
                vowels ++;
            }
            else
            {
                consonants++;
            }
            letters++;
        }
        else if(in>='A' && in<='Z')
        {
            if(in =='A'||in=='E'||in=='I'||in=='O'||in=='U')
            {
                vowels ++;
            }
            else
            {
                consonants++;
            }
            letters++;
        }
    }
    printf("%d %d %d %d",digits,letters,vowels,consonants);

    return 0;
}