#include<stddef.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// // #include "splitAndMap.h"
// #define numPtrArray 4
// #define MAXLEN 400000

void splitAndMap(char*** ptr, char* str)
{
    int ptrLen = 0;
    while (ptr[ptrLen]!=NULL)
    {
        ptrLen++;
    }
    
    int checklen[ptrLen];
    int ptrsindex[ptrLen];
    for(int i=0;i<ptrLen;i++)
    {
        checklen[i] = 0;
        ptrsindex[i] = 0;
    }
    int strindex = 0;
    int smlIn = 0;
    while (str[strindex]!='\0')
    {
        if(str[strindex]=='*')
        {
            if(smlIn!=0)
            {
                int index = 0;int min = __INT32_MAX__;
                for(int i=0;i<ptrLen;i++)
                {
                    if(min > checklen[i])
                    {
                        min = checklen[i];
                        index = i;
                    }
                }
                ptr[index][ptrsindex[index]] = &(str[strindex])-smlIn;
                checklen[index] += smlIn;
                ptrsindex[index]++;
                str[strindex] = '\0';
                smlIn = 0;
            }
        }
        else
        {
            smlIn++;
        }
        strindex++;
    }
    int index = 0;int min = __INT32_MAX__;
    for(int i=0;i<ptrLen;i++)
    {
        if(min > checklen[i])
        {
            min = checklen[i];
            index = i;
        }
    }
    ptr[index][ptrsindex[index]] = &(str[strindex])-smlIn;
    checklen[index] += smlIn;
    ptrsindex[index]++;
    str[strindex] = '\0';
    smlIn = 0;


    for(int i=0;i<ptrLen;i++)
    {   
        ptr[i][ptrsindex[i]] = NULL; 
    }
}


// int main(){
//     char*** ptr = malloc((numPtrArray+1) * sizeof(char**));
//     for(int i=0; i<numPtrArray; i++){
//         ptr[i] = malloc(MAXLEN * sizeof(char**));
//     }
//     ptr[numPtrArray] = NULL;
 
//     char str[MAXLEN];
//     scanf("%s", str);
 
//     splitAndMap(ptr, str);
 
//     for(int i=0; i<numPtrArray; i++){
//         for(int j=0; ptr[i][j]!=NULL; j++)
//             printf("%s ", ptr[i][j]);
//         printf("\n");
//     }
 
//     for(int i=0; i<numPtrArray; i++) free(ptr[i]);
//     free(ptr);
//     return 0;
// }