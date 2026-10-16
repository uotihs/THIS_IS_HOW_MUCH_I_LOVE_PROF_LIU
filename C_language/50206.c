#include<stdio.h>

int hashfunction(char a)
{
    return (a-'a');
}

int char_to_index(char* s)
{
    return hashfunction(s[0])*26*26 + hashfunction(s[1])*26 + hashfunction(s[2]);
}

char index_to_char(int a)
{
    return (a+'a');
}

int check_fractions(int tables[],char* s)
{
    for(int i=0;i<3;i++)
        if(!(s[i] >= 'a' && s[i] <= 'z'))
            return 0;
    
    tables[char_to_index(s)] ++;
}       


int main()
{
    // printf("%d",char_to_index("can"));
    int dict[17576] = {0};

    char line[100001] = {0};

    fgets(line,100001,stdin);

    for(int i=0;i<99999;i++)
    {
        check_fractions(dict,&(line[i]));
    }

    int firstIndex = -1;
    int secondIndex = -1;
    int thirdIndex = -1;
    int max = 0;
    for(int i=0;i<17576;i++)
    {
        if(dict[i] > max)
        {
            max = dict[i];
            firstIndex = i;
        }
    }

    max = 0;
    for(int i=0;i<17576;i++)
    {
        if(i == firstIndex) continue;

        if(dict[i] > max)
        {
            max = dict[i];
            secondIndex = i;
        }
    }

    max = 0;
    for(int i=0;i<17576;i++)
    {
        if(i == firstIndex || i == secondIndex) continue;

        if(dict[i] > max)
        {
            max = dict[i];
            thirdIndex = i;
        }

    }
    // printf("%d %d %d",firstIndex,secondIndex,thirdIndex);

    printf("%c%c%c\n",firstIndex/676 + 'a', (firstIndex%676)/26 + 'a' , firstIndex%26 + 'a');
    printf("%c%c%c\n",secondIndex/676 + 'a', (secondIndex%676)/26 + 'a' , secondIndex%26 + 'a');
    printf("%c%c%c",thirdIndex/676 + 'a', (thirdIndex%676)/26 + 'a' , thirdIndex%26 + 'a');

    return 0;
}