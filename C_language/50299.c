#include<stdio.h>


int abs(int x)
{
    return x>0 ? x : -x;
}

int getRow(int* ptr,int* first,int n)
{
    return (ptr-first)/n;
}

int getCol(int* ptr,int* first,int n)
{
    if(ptr - first > 0) return (ptr-first)%n;
    else return -((first-ptr)%n);
}

int canGo(int x,int y)
{
    if(x==0)
    return 1;
    if(y==0)
    return 1;
    if(x==y)
    return 1;
    if(x==-y)
    return 1;

    return 0;
}

void snake(int* first_element, int n, int* pointers[], int m)
{
    int pos[m][2];
    int stop = m;



    for(int i=0;i<m;i++)
    {
        if(pointers[i]==NULL)
        {
            stop = i;
            break;
        }

        pos[i][0] = getRow(pointers[i],first_element,n);
        pos[i][1] = getCol(pointers[i],first_element,n);
        // printf("pos %d %d\n",pos[i][0],pos[i][1]);
        if( pos[i][0]<0 || pos[i][0] >=n || pos[i][1]<0 || pos[i][1] >=n)
        {
            stop = i;
            break;
        }

        if(i>=1)
        {
            if(!canGo(pos[i][0]-pos[i-1][0],pos[i][1]-pos[i-1][1]))
            {
                stop = i;
                break;;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(first_element+i*n+j) = 0;
        }
    }
    

    for(int i=1;i<stop;i++)
    {
        int time = 0;

        int diffx = pos[i][0]-pos[i-1][0];
        int diffy = pos[i][1]-pos[i-1][1];

        time = abs(diffx);
        if(abs(diffy) > time) time = abs(diffy);

        if(diffx>0) diffx = 1;
        else if(diffx <0) diffx = -1;
        if(diffy > 0) diffy = 1;
        else if(diffy <0 )diffy = -1; 

        for(int j=0;j<=time;j++)
        {
            *(first_element + pos[i-1][0]*n + pos[i-1][1] + j*diffx*n + j*diffy) = 1;
        }
    }



}


 
// int main () {
//     int n, m;
//     scanf("%d%d", &n, &m);
 
//     int grid[n][n];
//     for (int x = 0; x < n; x++) {
//         for (int y = 0; y < n; y++) {
//             grid[x][y] = 0;
//         }
//     }
 
//     int* pointers[m];
 
//     for (int i = 0; i < m; i++) {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         if (x == -1 && y == -1) {
//             pointers[i] = &(grid[n - 1][n - 1]) + 1;
//         } else if (x == -2 && y == -2) {
//             pointers[i] = NULL;
//         } else {
//             pointers[i] = &(grid[x][y]);
//         }
//     }
 
//     snake(&(grid[0][0]), n, pointers, m);
 
//     for (int x = 0; x < n; x++) {
//         for (int y = 0; y < n; y++) {
//             printf("%d ", grid[x][y]);
//         }
//         printf("\n");
//     }
// }