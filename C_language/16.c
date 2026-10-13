#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int n;
    scanf("%d",&n);

    int* array = (int *)malloc(sizeof(int)* (size_t)n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &(array[i]));
    }

    bool first = true;
    for(int i=0;i<n;i++)
    {
        if(array[i] % 2 == 1)
        { 
            if(!first) putchar(' ');
            first = false;
            printf("%d", array[i]);
        }
    }
    putchar('\n');

    first = true;
    for(int i=0;i<n;i++)
    {
        if(array[i] % 2 == 0) 
        {
            if(!first) putchar(' ');
            first = false;
            printf("%d", array[i]);
        } 
    }
    
    free(array);

    return 0;
}