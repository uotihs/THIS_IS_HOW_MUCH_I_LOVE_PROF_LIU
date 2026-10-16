#include<stdio.h>

int sumyes(int nowsum,int sum,int index,int array[],int n,int* count)
{
    if(nowsum == sum) 
    {(*count)++;return 1;}
    if(index>=n) return 0;

    
    if(sumyes( nowsum + array[index] , sum , index+1 , array , n ,count))
    {
        // (*count) ++;
    }
    if(sumyes( nowsum , sum , index+1 , array , n ,count))
    {
        // (*count) ++;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&(array[i]));
    }

    int in;
    int first = 1;
    while (scanf("%d",&in)!=EOF)
    {
        if(first)
        {
            first = !first;
        }
        else
        {
            putchar('\n');
        }
        //dealing in
        int count = 0;
        sumyes(0,in,0,array,n,&count);

        printf("%d",count);
    }
    


    

    return 0;
}