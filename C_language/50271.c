#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

int varCount[30] = {0};
char variables[30][31] = {0};
int index = 0;

char conserved[12][10] = {"if","else","while","for","switch","case","break","return","void","int","float","char"};


int isFunction_or_Variables(char* string)
{
    for(int i=0;i<12;i++)
    {
        if(strcmp(conserved[i],string)==0)
        {
            return 0;
        }
    }

    for(int i=0;i<index;i++)
    {
        if(strncmp(string,variables[i],24)==0)
        {
            varCount[i] ++;
            return 1;
        }
    }

    if( !isalpha(string[0]) && string[0] != '_' ) return 0;
    strcpy(variables[index],string);
    varCount[index]=1;
    variables[index][24] = '\0';
    index++;
    
    return 2;
}



int main()
{
    char lines[201] = {0};

    while (scanf("%s",lines)!=EOF)
    {
        char* start = strtok(lines," \n\r\t=(){};+-*/,![]~^&.><");
        while (start != NULL)
        {
            isFunction_or_Variables(start);


            start = strtok(NULL," \n\r\t=(){};+-*/,![]~^&.><");
        }
    }
    

    for(int i=0;i<index;i++)
    {
        if(i!=0) putchar('\n');

        printf("%s %d",variables[i],varCount[i]);
    }




    return 0;
}