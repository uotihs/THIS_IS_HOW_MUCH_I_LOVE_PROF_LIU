#include <stdio.h>
/*

Current state	Tape value	Write tape	Move head	Next state
s0 0 0 R s2
s0 1 1 R s1
s0 2 2 R s2
s0 3 3 R s1
s1 0 1 L s2
s1 1 2 R s0
s1 2 3 L s2
s1 3 0 R s0
s2 0 2 N s1
s2 1 3 L s0
s2 2 0 R s1
s2 3 1 N s0
*/



void Turing_Machine(int *head, int K)
{
    int state = 0;
    int go;
    int now = 0;
    // printf("state 0");
    for(int i=0;i<K;i++)
    {
        switch (state)
        {
        case 0:

            head[now] = head[now];
            if(head[now]%2 == 0) state = 2;
            else state = 1;
            go = 1;

            break;

        case 1:


            if(head[now]!=3) head[now] += 1;
            else head[now] = 0;
            if(head[now]%2 == 1) {state = 2; go = -1;}
            else {state = 0;go=1;}


            break;

        case 2:

            if(head[now]==2) {head[now] = 0;go=1;}
            else if(head[now]==3) {head[now] = 1;go=0;}
            else if(head[now]==0) {head[now] = 2;go=0;}
            else if(head[now]==1) {head[now] = 3;go=-1;}
            if(head[now]%2 == 0) state = 1;
            else state = 0;

            break;
        }
        // printf(" now at %d , %d go %d\nstate %d,go %d",now,head[now],go,state,head[now+go]);
        now+=go;
    }
    // printf("\n\n");

}


// // #include "Turing_Machine.h"
 
// int main()
// {
//     int n, p, K;
//     scanf("%d%d%d", &n, &p, &K);
//     int tape[n];
//     for(int i = 0; i < n; i++) scanf("%d", &tape[i]);
 
//     int *head = &tape[p];
//     Turing_Machine(head, K);
 
//     for(int i = 0; i < n; i++) printf("%d ", tape[i]);
 
//     return 0;
// }