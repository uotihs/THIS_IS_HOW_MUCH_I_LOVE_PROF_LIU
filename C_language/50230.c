#include<stdio.h>
#include<stdbool.h>

int main()
{
    int S,B;
    scanf("%d%d",&S,&B);

    int map[S][B];
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<B;j++)
        {
            map[i][j]=0;
        }
    }
    
    int in;
    bool first = 1;
    while (scanf("%d",&in)!=EOF)
    {
        //hashFun
        int hashID =(77*in+2222)%S;

        int index = -1;
        bool hasIn = false;

        for(int i=0;i<B;i++)
        {
            if( index == -1 && map[hashID][i] == 0)
            {
                index = i;
            }
            if( map[hashID][i] == in )
            {
                hasIn = true;
                index = i;
                break;
            }
        }

        // for(int i = 0 ; i<S;i++)
        // {
        //     for(int j=0;j<B;j++)
        //     {
        //         printf("%d ",map[i][j]);
        //     }
        //     printf("\n");
        // }


        if(!hasIn)
        map[hashID][index] = in;
        else
        {
            if(first) first = false;
            else putchar('\n');


            printf("%d %d",in,hashID);
            map[hashID][index] = 0;
        }
        
    }
    






    return 0;
}