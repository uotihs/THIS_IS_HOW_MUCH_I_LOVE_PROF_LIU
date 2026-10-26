#include<stdio.h>
#include<string.h>

int main()
{
    char suffixes[20][5] = {"able","ary","ed","ence","ful","hood","ical","ing","ish","ism","ist","ive","ize","less","ly","ment","ness","ous","ship","tion"};
    int suffixesLen[20] = {4,3,2,4,3,4,4,3,3,3,3,3,3,4,2,4,4,3,4,4};
    int counts[20] = {0};

    char sen[100001] = {0};
    while (fgets(sen,100001,stdin)!=NULL)
    {
        char* token = strtok(sen," .,?!;:\r\n");
        while (token!=NULL)
        {
            int len = strlen(token);

            for(int i=0;i<20;i++)
            {
                //int sufLen = strlen(suffixes[i]);

                if(strcmp(token+len-suffixesLen[i],suffixes[i])==0)
                {
                    counts[i]++;
                    break;
                }
            }
            token = strtok(NULL," .,?!;:\r\n");
        }
    }

    int first = 1;

    for(int i = 0 ; i<20;i++)
    {
        if(counts[i]>0)
        {
            if(first) first = 0;
            else putchar('\n');

            printf("%s:\n",suffixes[i]);
            printf("Frequency: %d",counts[i]);
        }
    }
    







}