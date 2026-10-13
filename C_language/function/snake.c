#include"snake.h"

void snake(const int *ptr_array[100][100], int m){
    int sortedA[m*m][3];

    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         printf("%d ",ptr_array[i][j]);
    //     }
    // }


    for(int i = 0 ;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            sortedA[i*m+j][0] = *(ptr_array[i][j]);
            sortedA[i*m+j][1] = i;
            sortedA[i*m+j][2] = j;
        }
    }
    
    for(int i=0;i<m*m;i++)
    {
        for(int j=1;j<m*m;j++)
        {
            if(sortedA[j][0] < sortedA[j-1][0])
            {
                int temp=sortedA[j][0],temp1=sortedA[j][1],temp2=sortedA[j][2];
                sortedA[j][0] = sortedA[j-1][0];
                sortedA[j][1] = sortedA[j-1][1];
                sortedA[j][2] = sortedA[j-1][2];

                sortedA[j-1][0] = temp;
                sortedA[j-1][1] = temp1;
                sortedA[j-1][2] = temp2;
            }
        }
    }
    const int* start = ptr_array[0][0];

    // for(int i=0;i<m*m;i++)
    // {
    //     printf("%d %d %d\n",sortedA[i][0],sortedA[i][1],sortedA[i][2]);
    // }

    for(int i=0;i<m;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<m;j++)
            {   
                ptr_array[i][j] = (start+100*sortedA[i*m+j][1]+sortedA[i*m+j][2]);
                // printf("%d\n",start+100*sortedA[i*m+j][1]+sortedA[i*m+j][2]);
                // printf("%d\n",*(start+100*sortedA[i*m+j][1]+sortedA[i*m+j][2]));
            }
        }
        else
        {
            for(int j=0;j<m;j++)
            {   
                ptr_array[i][m-j-1] = (start+100*sortedA[i*m+j][1]+sortedA[i*m+j][2]);
                // printf("%d\n",start+100*sortedA[i*m+j][1]+sortedA[i*m+j][2]);
                // printf("%d\n",*(start+100*sortedA[i*m+j][1]+sortedA[i*m+j][2]));
            }
        }
    }
}