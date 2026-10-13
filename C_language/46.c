#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct listnode{
    char value;
    struct listnode* right;
    struct listnode* left;
}ListNode;


ListNode* make_Head(char value,int* length)
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->value = value;
    head->left = NULL;
    head->right = NULL;

    (*length)++;

    return head;
}

void add_Node_After(ListNode* last,char value,int* length)
{
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    last->right = new;
    new->left = last;
    new->right = NULL;
    new->value = value;

    (*length)++;
}

ListNode* add_Node_Before(ListNode* head,char value,int* length)
{
    ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
    head->left = newhead;
    newhead->right = head;
    newhead->value = value;
    newhead->left = NULL;

    (*length)++;

    return newhead;
}

void add_Node_Middle(ListNode* head,char value,int* length)
{
    ListNode* newmid = (ListNode*)malloc(sizeof(ListNode));
    ListNode* after = head->right;
    newmid->right = after;
    newmid->value = value;
    newmid->left = head;
    head->right = newmid;
    after->left = newmid;

    (*length)++;
}


ListNode* get_Last(ListNode* head)
{
    if(head->right == NULL)
    {
        return head;
    }
    else
    {
        return get_Last(head->right);
    }
}


ListNode* delete_First(ListNode* head, int* length)
{
    if (head == NULL)
        return NULL;

    ListNode* newhead = head->right;

    if (newhead != NULL)
        newhead->left = NULL;

    free(head);
    (*length)--;

    return newhead;
}

void delete_After(ListNode* last,int* length)
{
    ListNode* after = last->right;
    last->right = NULL;
    free(after);

    (*length)--;
}

void delete_middle(ListNode* node,int* length)
{
    ListNode* temp ;
    temp = node->right->right;
    
    free(node->right);
    node->right = temp;
    temp->left = node;
    (*length) --;
}

void delete_whole_list(ListNode* head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        delete_whole_list(head->right);
    }
    free(head);
}





ListNode* Read_Insert(char line[],ListNode* list,int* length)
{
    char* insertW;
    char* direct;
    char* numberS;
    int index = 0;
    char* fraction;
    fraction = strtok(line," \r\n\t");
    while (fraction != NULL && index < 3)
    {
        if(index == 0)
        {
            insertW = fraction;
        }
        else if(index == 1)
        {
            direct = fraction;
        }
        else if(index == 2)
        {
            numberS = fraction;
        }

        index++;
        fraction = strtok(NULL," \r\n\t");
    }
    
    if(strcmp("right",direct)==0) //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        // add right numberS[0];
        if(*length == 0)
        {
            list = make_Head(numberS[0],length);
        }
        else
        {
            ListNode* last = get_Last(list);
            // printf("%p",last);
            add_Node_After(last,numberS[0],length);
        }

    }
    else if(strcmp("left",direct)==0) 
    {
        // add left numberS[0];
        if(*length == 0)
        {
            list = make_Head(numberS[0],length);
        }
        else
        {
            list = add_Node_Before(list,numberS[0],length);
        }

    }
    else
    {
        int position = atoi(direct);

        if (*length == 0)
        {
            list = make_Head(numberS[0],length);
        }
        else if (position == 1)
        {
            list = add_Node_Before(list,numberS[0],length);
        }
        else
        {
            ListNode* previous = list;

            for (int i = 1;i<position-1;i++)
            {
                previous = previous->right;
            }

            if (previous->right == NULL)
            {
                add_Node_After(previous, numberS[0], length);
            }
            else
            {
                add_Node_Middle(previous, numberS[0], length);
            }
        }
    }


    return list;
}

ListNode* Read_Delete(char line[],ListNode* list,int* length)
{
    char* insertW;
    char* direct;
    int index = 0;
    char* fraction;
    fraction = strtok(line," \r\n\t");
    while (fraction != NULL && index < 2)
    {
        if(index == 0)
        {
            insertW = fraction;
        }
        else if(index == 1)
        {
            direct = fraction;
        }

        index++;
        fraction = strtok(NULL," \r\n\t");
    }
    
    if(strcmp("right",direct)==0) 
    {
        //delete right
        if(*length == 1)
        {
            list = delete_First(list,length);
        }
        else
        {
            ListNode* last = get_Last(list);
            delete_After(last->left,length);
        }
    }
    else if(strcmp("left",direct)==0)
    {
        //delete left
        if(*length == 1)
        {
            list = delete_First(list,length);
        }
        else
        {
            list = delete_First(list,length);
        }
    }
    else
    {
        //delete atoi(direct);
        int index = atoi(direct);
        // printf("index%d",index);
        ListNode* kill;
        if(index != 1)
        {
           kill = list->right;//2
            for(int i=2;i<index;i++)
            {
                kill = kill->right;
            }
            if(index == *length)
            {
                delete_After(kill->left,length);
            }
            else
            {
                delete_middle(kill->left,length);
            } 
        }
        else
        {
            list = delete_First(list,length);
        }
    }

    return list;
}

int main()
{
    char line[100]={0};
    ListNode* list = NULL;
    int length = 0;
    while (fgets(line,100,stdin)!=NULL)
    {
        if(strncmp("insert",line,6)==0)
        {
            list = Read_Insert(line,list,&length);
        }
        else if(strncmp("delete",line,6)==0)
        {
            list = Read_Delete(line,list,&length);
        }

        // ListNode* now  = list;
        // while (now!=NULL)
        // {
        //     printf(":%c: ",now->value);
        //     now=now->right;
        // }
        // printf("%d\n",length);
    }

    
    
    

    ListNode* now  = list;
    ListNode* ans = NULL;
    int max = 0;
    int nowMax = 0;
    int len = 0;
    if(length==1 || length == 0)
    {
        if(length==1) printf("%c ",now->value);
        printf("%d",length);
        return 0;
    }

    for(int i=1;i<=length;i++)
    {
        if(i!=1 && now->value == now->left->value)
        {
            nowMax++;
        }
        else if(i==1)
        {
            nowMax = 1;
        }
        else
        {
            if(max < nowMax)
            {
                if(ans != NULL) delete_whole_list(ans);
                len = 0;
                ans = make_Head(now->left->value,&len);
                max = nowMax;
                nowMax = 1;

                // printf("%d",i);
            }
            else if(max == nowMax)
            {
                ListNode* last = get_Last(ans);
                add_Node_After(last,now->left->value,&len);
                nowMax = 1;
            }
            else
            {
                nowMax = 1;
            }
        }

        if(i!= length)
        now=now->right;
    }
    if(max < nowMax)
    {
        delete_whole_list(ans);
        len = 0;
        ans = make_Head(now->value,&len);
        max = nowMax;
    }
    else if(max == nowMax)
    {
        ListNode* last = get_Last(ans);
        add_Node_After(last,now->value,&len);
        nowMax = 1;
    }
    else
    {
        nowMax = 0;
    }

    ListNode* yeah = ans;
    while (yeah!=NULL)
    {

        printf("%c ",yeah->value);
        yeah=yeah->right;
    }
    printf("%d",max);


    delete_whole_list(ans);
    delete_whole_list(list);
    return 0;
}