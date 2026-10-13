#include<stdio.h>
#include<stdbool.h>
#include<time.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    char names[n][65] ;
    

    int playersMap[n][m][m];
    int in2mapIndex[n][m*m+1];
    
    for(int i=0;i<n;i++)
    {
        scanf("%s",names[i]);

        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                scanf("%d",&(playersMap[i][j][k]));
                in2mapIndex[i][playersMap[i][j][k]] = ((j)*m+(k)) ;
            }
        }
    }

    int HowManyInARow[n][m];
    int HowManyInACol[n][m];
    int HowManyInXie[n][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            HowManyInARow[i][j] = 0;
            HowManyInACol[i][j] = 0;
        }
        HowManyInXie[i][0] = 0;
        HowManyInXie[i][1] = 0;
    }

    
    bool playersWin[n] ;
    for(int i=0;i<n;i++)
        playersWin[i] = false;

    bool SomeOneWined = false;

    for(int i=0;i<m*m;i++)
    {
        int in;

        scanf("%d",&in);

        for(int j=0;j<n;j++)
        {
            // for(int k=0;k<m;k++)
            // {
            //     for(int l=0;l<m;l++)
            //     {
            //         if(playersMap[j][k][l] == in)
            //         {
            //             playersMap[j][k][l] = 0;
            //         }
            //     }       
            // }
            playersMap[j][in2mapIndex[j][in] / m ][in2mapIndex[j][in] % m ] = 0;

            

            HowManyInARow[j][in2mapIndex[j][in] / m] +=1;
            if(HowManyInARow[j][in2mapIndex[j][in] / m] == m) 
            {
                playersWin[j] = true;
                SomeOneWined = true;
                continue;
            }

            HowManyInACol[j][in2mapIndex[j][in] % m] +=1;
            if(HowManyInACol[j][in2mapIndex[j][in] % m] == m)
            {
                playersWin[j] = true;
                SomeOneWined = true;
                continue;
            }

            if( ( in2mapIndex[j][in] % m ) == (in2mapIndex[j][in] / m ))
            {
                HowManyInXie[j][0] ++;
                if(HowManyInXie[j][0] == m)
                {
                    playersWin[j] = true;
                    SomeOneWined = true;
                    continue;
                }
            }

            if( ( in2mapIndex[j][in] % m ) + (in2mapIndex[j][in] / m ) == m-1)
            {
                HowManyInXie[j][1] ++;
                if(HowManyInXie[j][1] == m)
                {
                    playersWin[j] = true;
                    SomeOneWined = true;
                    continue;
                }
            }
            // bool isRowWin = true;
            // for(int  k=0;k<m;k++)
            // {
            //     isRowWin = true;
            //     for(int l=1;l<m;l++)
            //     {
            //         if(playersMap[j][k][l] != playersMap[j][k][l-1])
            //         {
            //             isRowWin = false;
            //         }
            //     }
            //     if(isRowWin) break;
            // }
            // if(isRowWin) 
            // {
            //     playersWin[j] = true;
            //     SomeOneWined = true;
            //     continue;
            // }

            // bool isColWin = true;
            // for(int  k=0;k<m;k++)
            // {
            //     isColWin = true;
            //     for(int l=1;l<m;l++)
            //     {
            //         if(playersMap[j][l][k] != playersMap[j][l-1][k])
            //         {
            //             isColWin = false;
            //         }
            //     }
            //     if(isColWin) break;
            // }
            // if(isColWin) 
            // {
            //     playersWin[j] = true;
            //     SomeOneWined = true;
            //     continue;
            // }

            // bool isXieWin = true;
            // for(int  k=1;k<m;k++)
            // {
            //     if(playersMap[j][k][k] != playersMap[j][k-1][k-1])
            //     {
            //         isXieWin = false;
            //     }
            // }
            // if(isXieWin) 
            // {
            //     playersWin[j] = true;
            //     SomeOneWined = true;
            //     continue;
            // }

            // bool isXie2Win = true;
            // for(int  k=1;k<m;k++)
            // {
            //     if(playersMap[j][k][m-1-k] != playersMap[j][k-1][m-k])
            //     {
            //         isXie2Win = false;
            //     }
            // }
            // if(isXie2Win) 
            // {
            //     playersWin[j] = true;
            //     SomeOneWined = true;
            //     continue;
            // }


            // if(isColWin || isRowWin || isXie2Win || isXieWin)
            // {
            //     playersWin[j] = true;
            //     SomeOneWined = true;
            // }



            
        }


        if(SomeOneWined)
        {

            printf("%d",in);
            for(int j=0;j<n;j++)
            {
                if(playersWin[j])
                    printf(" %s",names[j]);
            }


            return 0;
        }
        // if(in ==10)
        // {
        //     for(int a=0;a<n;a++)
        //     {
        //         printf("\n%s ",names[a]);

        //         for(int b=0;b<m;b++)
        //         {
        //             for(int c=0;c<m;c++)
        //             {
        //                 printf("%d ",(playersMap[a][b][c]));
        //             }
        //             putchar('\n');
        //         }
        //     }
        //     printf("row =%d",HowManyInACol[1][1]);
        // }
        

    }


    return 0;
}