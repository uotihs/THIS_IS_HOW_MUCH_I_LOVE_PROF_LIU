#include"node.h"
#include<stddef.h>

#ifndef _NODE_H
#define _NODE_H
 
struct node {
       struct node *next;
};
 
#endif

unsigned int countLength(struct node* head)
{
    if(head==NULL) return 0;
    if(head->next == NULL) return 1U;
    return countLength(head->next)+1U;
}

struct node *reallyGet(struct node* head,unsigned int i)
{
    if(head == NULL) return NULL;
    if(i==0) return head;
    return reallyGet(head->next,i-1);
}

struct node *getNode(struct node *head, unsigned int i)
{
    int length = countLength(head);
    if(length <= i) return NULL;
    return reallyGet(head,length-i-1);
}