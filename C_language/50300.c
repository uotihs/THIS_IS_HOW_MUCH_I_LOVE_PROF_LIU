#include<stdio.h>

void getLWH(int *p , int *start , int L , int W , int H, int *a,int *b ,int *c)
{
    (*a) = (p - start)/ (W*H);
    (*b) = ((p - start)%(W*H)) /(H);
    (*c) = ((p - start)%(H));
}

void paintSurface(int *start, int *p1, int *p2, int L, int W, int H)
{

    int startpos[3];
    getLWH(p1,start,L,W,H,&(startpos[0]),&(startpos[1]),&(startpos[2]));
    int endpos[3];
    getLWH(p2,start,L,W,H,&(endpos[0]),&(endpos[1]),&(endpos[2]));



    for(int i=0;i<3;i++)
    {
        if(startpos[i] > endpos[i])
        {
            int temp = endpos[i];
            endpos[i] = startpos[i];
            startpos[i] = temp;
        }
    }


    // for(int i=0;i<3;i++)
    // {
    //     printf("%d ",startpos[i]);
    // }
    
    // for(int i=0;i<3;i++)
    // {
    //     printf("%d ",endpos[i]);
    // }

    // for(int i=startpos[0] ;i<=endpos[0] ;i++)
    // {
    //     for(int j= startpos[1] ; j <= endpos[1]  ; j++)
    //     {
    //         for(int k = startpos[2] ; k <= endpos[2] ; k++)
    //         {
    //             *(start + i*W*H + j*H + k) = 1;
    //             printf("%d %d %d \n",i,j,k);
    //         }
    //     }
    // }

    
    for(int i=startpos[0] ;i<=endpos[0] ;i++)
    {
        for(int j= startpos[1] ; j <= endpos[1]  ; j++)
        {
            int k = startpos[2];
            *(start + i*W*H + j*H + k) = 1;
            // printf("%d %d %d \n",i,j,k);
            k = endpos[2];
            *(start + i*W*H + j*H + k) = 1;
            // printf("%d %d %d \n",i,j,k);
        }
    }

    for(int i=startpos[0] ;i<=endpos[0] ;i++)
    {
        for(int j= startpos[2] ; j <= endpos[2]  ; j++)
        {
            int k = startpos[1];
            *(start + i*W*H + k*H + j) = 1;
            // printf("%d %d %d \n",i,k,j);
            k = endpos[1];
            *(start + i*W*H + k*H + j) = 1;
            // printf("%d %d %d \n",i,k,j);
        }
    }

    for(int i=startpos[1] ;i<=endpos[1] ;i++)
    {
        for(int j= startpos[2] ; j <= endpos[2]  ; j++)
        {
            int k = startpos[0];
            *(start + k*W*H + i*H + j) = 1;
            // printf("%d %d %d \n",i,j,k);
            k = endpos[0];
            *(start + k*W*H + i*H + j) = 1;
            // printf("%d %d %d \n",k,i,j);
        }
    }



}

// int main() {
//     int L, W, H;
//     scanf("%d%d%d", &L, &W, &H);
 
//     int cuboid[L][W][H];
//     for (int i = 0; i < L; i++) {
//         for (int j = 0; j < W; j++) {
//             for (int k = 0; k < H; k++) {
//                 cuboid[i][j][k] = 0;
//             }
//         }
//     }
 
//     int n;
//     scanf("%d", &n);
 
//     while (n--) {
//         int x1, x2, y1, y2, z1, z2;
//         scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
//         paintSurface(&cuboid[0][0][0], &cuboid[x1][y1][z1], &cuboid[x2][y2][z2], L, W, H);
//     }
 
//     for (int i = 0; i < L; i++) {
//         for (int j = 0; j < W; j++) {
//             for (int k = 0; k < H; k++) {
//                 printf("%d", cuboid[i][j][k]);
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
 
//     return 0;
// }