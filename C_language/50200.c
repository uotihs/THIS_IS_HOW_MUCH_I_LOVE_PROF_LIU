#include<stdio.h>

int main()
{
    int height,width;
    scanf("%d%d",&height,&width);
    int Map[height][width];
    
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            Map[i][j]=0;
        }
    }


    int type,r,c;
    while (scanf("%d%d%d",&type,&c,&r)!=EOF)
    {
        int up = r+1;
        int left = c+1;
        int down = height-r;
        int right = width-c;
        Map[r][c] = 1;
        // printf("%d %d %d %d\n",up,left,down,right);

        switch (type)
        {

            case 0: //stones
                Map[r][c] = 1;
                break;



            case 1: //queens


                for(int i=1;i<up && i<left;i++)
                {
                    if(Map[r-i][c-i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r-i][c-i]=1;
                    }
                }

                for(int i=1;i<up && i<right;i++)
                {
                    if(Map[r-i][c+i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r-i][c+i]=1;
                    }
                }

                for(int i=1;i<down && i<right;i++)
                {
                    if(Map[r+i][c+i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r+i][c+i]=1;
                    }
                }

                for(int i=1;i<down && i<left;i++)
                {
                    if(Map[r+i][c-i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r+i][c-i]=1;
                    }
                }



                for(int i=r+1;i<height;i++)
                {
                    if(Map[i][c]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[i][c] = 1;
                    }
                }

                for(int i=r-1;i>=0;i--)
                {
                    if(Map[i][c]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[i][c] = 1;
                    }
                }

                for(int i=c-1;i>=0;i--)
                {
                    if(Map[r][i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r][i] = 1;
                    }
                }

                for(int i=c+1;i<width;i++)
                {
                    if(Map[r][i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r][i] = 1;
                    }
                }




                break;




            case 2: //bishops
                
                for(int i=1;i<up && i<left;i++)
                {
                    if(Map[r-i][c-i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r-i][c-i]=1;
                    }
                }

                for(int i=1;i<up && i<right;i++)
                {
                    if(Map[r-i][c+i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r-i][c+i]=1;
                    }
                }

                for(int i=1;i<down && i<right;i++)
                {
                    if(Map[r+i][c+i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r+i][c+i]=1;
                    }
                }

                for(int i=1;i<down && i<left;i++)
                {
                    if(Map[r+i][c-i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r+i][c-i]=1;
                    }
                }



                break;




            case 3: //rooks
                
                for(int i=r+1;i<height;i++)
                {
                    if(Map[i][c]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[i][c] = 1;
                    }
                }

                for(int i=r-1;i>=0;i--)
                {
                    if(Map[i][c]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[i][c] = 1;
                    }
                }

                for(int i=c-1;i>=0;i--)
                {
                    if(Map[r][i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r][i] = 1;
                    }
                }

                for(int i=c+1;i<width;i++)
                {
                    if(Map[r][i]==1)
                    {
                        break;
                    }
                    else
                    {
                        Map[r][i] = 1;
                    }
                }

                break;
        }
    }
    
    for(int i=0;i<height;i++)
    {
        if(i!=0)putchar('\n');

        for(int j=0;j<width;j++)
        {
            if(j!=0)putchar(' ');

            printf("%d",Map[i][j]);
        }
    }

}