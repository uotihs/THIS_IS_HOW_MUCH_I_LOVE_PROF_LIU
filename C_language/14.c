#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);


    int* array = (int *)malloc(sizeof(int)*(size_t)n);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &(array[i]));
    }

    for(int i=n-1;i>0;i--)
    {
        printf("%d ",array[i]);
    }
    printf("%d",array[0]);


    free(array);

    return 0;
}