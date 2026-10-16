#include<stdio.h>
#include<string.h>
#include<stdlib.h>





int main()
{
    int size,number,queries;
    scanf("%d%d%d",&size,&number,&queries);
    int hashTable[size];
    // char strs[size][10001][21];

    char*** strs = (char ***)malloc(sizeof(char**)*size);

    int strsIndex[size];
    for(int i=0;i<size;i++)
    {
        hashTable[i] = 0;
        strsIndex[i] = 0;
        strs[i] = NULL;
    }

    for(int i=0;i<number;i++)
    {
        char str[100];
        scanf("%s",str);

        int len = strlen(str);
        int value = 0;
        for(int j=0;j<len;j++)
        {
            if(str[j] >= '0' && str[j] <= '9') value += str[j] - '0';
            else value += str[j];
        }
        value = value % size;
        hashTable[value] +=1 ;

        char **temp = realloc(strs[value],(strsIndex[value] + 1) * sizeof(char *));
        if (temp == NULL)
            return 1;
        strs[value] = temp;
        strs[value][strsIndex[value]] = malloc((len + 1) * sizeof(char));
        if (strs[value][strsIndex[value]] == NULL)
            return 1;

        strcpy(strs[value][strsIndex[value]],str);
        strsIndex[value] ++;

    }

    for(int i=0;i<queries;i++)
    {
        if(i!=0) putchar('\n');

        char str[100];
        scanf("%s",str);
        
        
        int len = strlen(str);
        int value = 0;
        for(int j=0;j<len;j++)
        {
            if(str[j] >= '0' && str[j] <= '9') value += str[j] - '0';
            else value += str[j];
        }
        value = value % size;

        if(hashTable[value] != 0)
        {
            int yes = 0;
            for(int k=0;k<strsIndex[value];k++)
            {
                if(strcmp(str,strs[value][k]) == 0)
                {
                    yes = 1;
                    break;
                }
            }    
            if(yes)
                printf("%d",value);
            else
                printf("-1");
        }

        else printf("-1");
    }

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<strsIndex[i];j++)
        {
            free(strs[i][j]);
        }
        free(strs[i]);
    }
    free(strs);




    return 0;
}