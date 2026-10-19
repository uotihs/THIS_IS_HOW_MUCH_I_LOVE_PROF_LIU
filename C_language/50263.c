#include"image2column.h"


void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH])
{
    int row = h-k+1;
    int col = w-k+1;
    for(int i=0;i<row;i++)
    {

        for(int j=0;j<col;j++)
        {

            for(int a=0;a<k;a++)
            {
                for(int b=0;b<k;b++)
                {
                    colMatrix[a*k+b][(i)*(col)+j] = imgMatrix[i+a][j+b]; 
                }
            }

        }

    }


}


 
// int main() {
//     int imgHeight, imgWidth;
//     int colHeight, colWidth;
//     int windowSize;
//     int imgMat[MAXH][MAXW];
//     int colMat[MAXK * MAXK][MAXW * MAXH];
 
//     scanf("%d%d", &imgHeight, &imgWidth);
//     scanf("%d", &windowSize);
 
//     colHeight = windowSize * windowSize;
//     colWidth = (imgWidth - windowSize + 1) * (imgHeight - windowSize + 1);
 
//     for (int i = 0; i < imgHeight; i++) 
//         for (int j = 0; j < imgWidth; j++) 
//             scanf("%d", &imgMat[i][j]);
 
//     img2col(imgHeight, imgWidth, windowSize, imgMat, colMat);
 
//     for (int i = 0; i < colHeight; i++) {
//         for (int j = 0; j < colWidth; j++) 
//             printf("%d ", colMat[i][j]);
//         printf("\n");
//     }
// }