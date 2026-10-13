#include<stdio.h>
#include<assert.h>

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

int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}