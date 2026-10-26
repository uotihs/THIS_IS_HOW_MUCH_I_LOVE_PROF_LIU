#include<string.h>
#include <stdio.h>

typedef struct {
    char journalName[64];
    int numCitedPaper;
    int citedPaperIndex[1024];
} paper;



void compute(paper P[], int N)
{
    int array[N][2];
    char authorities[N][65];
    int authIndex = 0;
    
    int authForEachPaper[N];

    for(int i=0;i<N;i++)
    {
        array[i][0]=0; array[i][1] = 0;

        int isIn = 0;
        for(int j=0;j<authIndex;j++)
        {
            if(strcmp(P[i].journalName,authorities[j])==0)
            {
                isIn = 1;
                authForEachPaper[i] = j;
                break;
            }
        }

        if(!isIn)
        {
            strcpy(authorities[authIndex],P[i].journalName);
            authForEachPaper[i] = authIndex;
            authIndex++;
        }
    }



    for(int i=0;i<N;i++)
    {
        for(int j=0;j<P[i].numCitedPaper;j++)
        {
            array[authForEachPaper[P[i].citedPaperIndex[j]]][0]++;
        }
        array[authForEachPaper[i]][1]++;
    }


    for(int j = 0 ; j<authIndex;j++)
    {
        for(int i = 1 ; i<authIndex;i++)
        {
            if(strcmp(authorities[i],authorities[i-1])<0)
            {
                int tmpA0 = array[i][0],tmpA1 = array[i][1];
                char temp[64]; 
                strcpy(temp,authorities[i]);

                strcpy(authorities[i],authorities[i-1]);
                array[i][0] =array[i-1][0];
                array[i][1] =array[i-1][1];

                array[i-1][0] = tmpA0;
                array[i-1][1] = tmpA1;
                strcpy(authorities[i-1],temp);
            }
        }
    }
    
    for(int i=0;i<authIndex;i++)
    {
        if(i!=0)putchar('\n');
        printf("%s %d/%d",authorities[i],array[i][0],array[i][1]);
    }
    

}




// #define MAXP 6
// // #include "compute.h"
// int main() {
//     int N;
//     paper P[MAXP] = {};
//     scanf("%d", &N);
//     for (int i = 0; i < N; i++) {
//         scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
//         for (int j = 0; j < P[i].numCitedPaper; j++)
//             scanf("%d", &P[i].citedPaperIndex[j]);
//     }
//     compute(P, N);
//     return 0;
// }
