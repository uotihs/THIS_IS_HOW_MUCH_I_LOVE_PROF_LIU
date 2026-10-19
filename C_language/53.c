#include<stdio.h>

void Permutation(int array[],int now[],int used[],int depth,int n)
{
    if(depth == n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",now[i]);
        }
        putchar('\n');

        return;
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(used[i])
        {
            continue;
        }

        used[i] = 1;
        now[depth] = array[i];

        Permutation(array,now,used,depth+1,n);

        used[i] = 0;

    }
    

}


int main()
{
    int n;
    scanf("%d",&n);

    int array[n];
    int now[n];
    int used[n];
    for(int i=0;i<n;i++)
    {scanf("%d",&array[i]);used[i]=0;}

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(array[j]<array[j-1])
            {
                int tp = array[j-1];
                array[j-1] = array[j];
                array[j]=tp;
            }
        }
    }

    Permutation(array,now,used,0,n);

    return 0;
}