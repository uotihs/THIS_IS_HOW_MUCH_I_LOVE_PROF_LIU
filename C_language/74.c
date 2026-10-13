#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    scanf("%d",&n);

    int* array = (int *)malloc(sizeof(int) * (size_t)n);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &(array[i]));
    }

    scanf("%d",&m);

    int* ansArray = (int *)malloc(sizeof(int) * (size_t)m);
    for(int i=0;i<m;i++) ansArray[i] = 0;

    for(int i=0;i<n;i++) {ansArray[ array[i] % m ] += 1;}

    for(int i=0;i<m;i++) 
    {
        printf("%d", ansArray[i]);
        if(i != m-1) putchar('\n');
    }


    free(array);
    free(ansArray);
    return 0;
}