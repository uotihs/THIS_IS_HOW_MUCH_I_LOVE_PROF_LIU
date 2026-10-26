
#include<stdio.h>
// #include"sort_list.h"

struct node{
    struct node *next_node;
};



struct node *swap(struct node *ND,int* haveChanged)
{
    if(ND->next_node == NULL)
    return ND;
    struct node noFunction;
    struct node* now ;
    struct node* nown ;

    noFunction.next_node = ND;
    now = &noFunction;
    nown = (noFunction.next_node);

    while (nown->next_node != NULL)
    {
        if(nown - nown->next_node > 0)
        {
            *haveChanged = 1;
            struct node* ndNext = nown->next_node;
            struct node* ndNextNext = nown->next_node->next_node;
            struct node* nd = nown;

            ndNext->next_node = nd;
            nown->next_node = ndNextNext;


            now->next_node = ndNext;

            nown = ndNext->next_node;
            now = ndNext;
        }
        else
        {
            nown = nown->next_node;
            now = now->next_node;
        }
    }
    return noFunction.next_node;
    
}


struct node *sort_list(struct node *ND)
{
    int changed = 0;

    struct node *head = swap(ND,&changed);
    while (changed==1)
    {
        changed = 0;
        head = swap(head,&changed);
    }
    return head;
}



// #include<stdio.h>
// #include <stdlib.h>
// #include <time.h>  
// // #include "sort_list.h"
 
 
// int main(){
//     struct node ptr_list[30000];
//     int n; scanf("%d",&n);
 
 
//     // below is just to randomized addresses
//     srand(time(NULL));
//     for(int i=0;i<30000;i++){
//         ptr_list[i].next_node = ptr_list+rand()%30000;
//     }
//     // 
 
 
//     int cur; scanf("%d",&cur);
//     int head = cur;
//     for(int i=1;i<n;i++){
//         int next; scanf("%d",&next);
//         ptr_list[cur].next_node = ptr_list+next;
//         cur = next;
//     }
//     ptr_list[cur].next_node = NULL;
//     struct node *cur_node = ptr_list+head;
//     struct node *new_head = sort_list(cur_node);
//     printf("%d",(int)(new_head-ptr_list));
//     for(int i=0;i<n-1;i++){
//         new_head = new_head->next_node;
//         printf(" %d",(int)(new_head-ptr_list));
//     }
//     printf("\n");
 
// }