#include<stdlib.h>
#include <stdio.h>
#include "activity.h"


#ifndef _ACTIVITY_H
#define _ACTIVITY_H 
 
typedef struct activity {
    int start;
    int end;
} Activity;
 
int select(Activity activities[], int n);
 
#endif



int cmp(const void* p1,const void* p2)
{
    const Activity* a1 = (Activity*)p1;
    const Activity* a2 = (Activity*)p2;

    if(a1->end > a2->end){
        return 1;
    }
    else{
        return -1;
    }
}


void recurison(int now,Activity activities[],int n,int count,int lastput,int* max,int nowGet[],int ngIndex,int ans[])
{
    if( n - now + count <= (*max) ) return;

    if(now==n)
    {
        if(count>(*max))
        {
            (*max) = count;

            for(int i=0;i<count;i++)
            {
                ans[i] = nowGet[i];
            }
        }
        return ;
    }


    
    if( lastput != -1 && activities[lastput].end > activities[now].start)
    {
        recurison(now+1,activities,n,count,lastput,max,nowGet,ngIndex,ans);
        return;
    }
    else
    {
        nowGet[ngIndex] = now;
        recurison(now+1,activities,n,count+1,now,max,nowGet,ngIndex+1,ans);
        
        if( now!=n-1 && activities[now+1].start > activities[now].end)
            return;


        // recurison(now+1,activities,n,count,lastput,max,nowGet,ngIndex,ans);
        return;
    }
}



int select(Activity activities[], int n)
{
    qsort(activities,n,sizeof(Activity),cmp);


    int max = 0;
    int nowGet[n];
    int ans[n];
    recurison(0,activities,n,0,-1,&max,nowGet,0,ans);

    // #define PRINT
    #ifdef PRINT

    for(int i=0;i<max;i++)
    {
        printf("%d %d\n",activities[ans[i]].start,activities[ans[i]].end);
    }

    #endif
    return max;

}



 
// #define MAXN 262144
// Activity A[MAXN];
// int main() {
//     int n, cases = 0;
//     while (scanf("%d", &n) == 1) {
//         for (int i = 0; i < n; i++)
//             scanf("%d %d", &A[i].start, &A[i].end);
//         int ret = select(A, n);
//         printf("%d\n", ret);
//     }
//     return 0;
// }