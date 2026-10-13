#include "fill_array.h"

void fill_array(int *ptr[], int n)
{
    int lastIndex = 0;
    lastIndex = (ptr[n-1]-ptr[0]);

    int Indexs[n];
    int Sorted[n];

    for(int i=0;i<n;i++)
    {
        Indexs[i] = ptr[i]-ptr[0];
        Sorted[i] = Indexs[i];
    }

    
    for(int i = 0 ;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(Sorted[j] < Sorted[j-1])
            {
                int temp = Sorted[j];
                Sorted[j] = Sorted[j-1];
                Sorted[j-1] = temp;
            }       
        }
    }





    int* start = ptr[0];

    for(int i=0;i<n;i++)
    {
        ptr[i] = start+Indexs[i];
    }

    int temp1[lastIndex+1];
    for(int i=0;i<lastIndex+1;i++)
    {
        temp1[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        temp1[Indexs[i]] = i;
    }


    int index=0;
    for(int i=1;i<lastIndex+1;i++)
    {
        if(i > Sorted[index])
        {
            index++;
        }
        if(temp1[i]==0)
        {
            temp1[i] = temp1[Sorted[index]]+temp1[Sorted[index-1]];
        }
    }

    for(int i=0;i<lastIndex+1;i++)
    {
        // printf("%d ",temp1[i]);
        *(start+i) = temp1[i];
    }

    
}