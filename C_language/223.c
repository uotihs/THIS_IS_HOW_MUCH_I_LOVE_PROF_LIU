#include<stdio.h>
#include<stdbool.h>
#define RIGHTUP 1
#define LEFTUP 2
#define LEFTDOWN 3
#define RIGHTDOWN 4

void fill(int x,int y,int l,int m,int corner)
{
    if(l==m) return;

    
    printf("%d %d %d\n",corner,l/2+x,l/2+y);
    

    if(corner == 1)
    {
        fill( x , y ,  l/2 , 1 , 1 );
        fill( x+l/2 , y , l/2 , 1 , 2 );
        fill( x , y+l/2 ,  l/2 , 1 , 4 );   

        fill(x+l/2,y+l/2,l/2,m,1);
    }
    else if(corner == 2)
    {
        fill( x , y ,  l/2 , 1 , 1 );
        fill( x+l/2 , y , l/2 , 1 , 2 );
        fill( l/2+x , l/2+y ,  l/2 , 1 , 3 );   

        fill(x,y+l/2 ,l/2,m,2);
    }
    else if(corner == 3)
    {
        fill( x+l/2 , y , l/2 , 1 , 2 );
        fill( l/2+x , l/2+y ,  l/2 , 1 , 3 );  
        fill( x , y+l/2 ,  l/2 , 1 , 4 );   

        fill(x,y,l/2,m,3);
    }
    else if(corner ==4)
    {
        fill( x , y ,  l/2 , 1 , 1 );
        fill( l/2+x , l/2+y ,  l/2 , 1 , 3 );  
        fill( x , y+l/2 ,  l/2 , 1 , 4 );     
        
        fill(x+l/2,y,l/2,m,4);
    }



}


int main()
{
    int l,m;
    scanf("%d%d",&l,&m);

    fill(0,0,l,m,1);
    // int map[l][l];
    // for(int i=0;i<l;i++)
    // {
    //     for(int j=0;j<l;j++)
    //     {
    //         if(i<m&&j>=l-m)
    //         {
    //             map[i][j]=0;
    //         }
    //         else
    //         {
    //             map[i][j]=1;
    //         }
    //     }
    // }
    // int ans[(l*l-m*m) / 3];

    // for(int i=0;i<l;i++)
    // {
    //     for(int j=0;j<l;j++)
    //     {
    //         printf("%d ",map[i][j]);
    //     }
    //     putchar('\n');
    // }

    return 0;
}