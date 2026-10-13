#include<stdio.h>
#include<stdbool.h>

// void reloadBookshelf(int bookshelf[8],bool is_full[8])
// {
//     for(int i=0;i<7;i++)
//     {
//         if(is_full[i] == 0)
//         {
//             bookshelf[i] = bookshelf[i+1];
//             is_full[i] = is_full[i+1];
//             bookshelf[i+1] = 0;
//             is_full[i+1] = 0;
//         }
//     }
//     bookshelf[7] = 0;
//     is_full[7] = 0;
// }

void reloadBookshelf(int bookshelf[8],int pos,bool is_full[8])
{
    int temp = 0;
    for(int j=pos;j<=6;j++)
    {
        bookshelf[j] = bookshelf[j+1];
        is_full[j] = is_full[j+1];
    }
    
    bookshelf[7] = 0;
    is_full[7] = 0;
}


int main()
{
    int bookshelf[8] = {0};
    bool is_full[8] = {0};
    int in;
    int nums = 0;
    while (scanf("%d",&in)!=EOF)
    {
        int pos = -1;
        bool isIn = 0;
        for(int i=0;i<8;i++)
        {
            if(bookshelf[i] == in)
            {
                bookshelf[i] =0;
                is_full[i] = 0;
                pos = i;
                isIn = 1;
                nums-=1;
                break;
            }
        
        }

        if(!isIn || isIn)
        {
            if (is_full[7] == 0)
            {
                is_full[7] =1;
                bookshelf[7] = in;
                nums+=1;
            }
            else
            {
                if(nums == 8)
                {
                    is_full[0]= 0;
                    bookshelf[0] = 0;
                    reloadBookshelf(bookshelf,0,is_full);
                }
                else
                {
                    nums++;
                    reloadBookshelf(bookshelf,pos,is_full);
                }
            
                
                is_full[7] = 1;
                bookshelf[7] = in;
            }
        }
            // for(int i=0;i<8;i++)
            // {
            //     if(is_full[i] == 0)
            //     {
            //         bookshelf[i] = in;
            //         is_full[i] = 1;
            //         break;
            //     }

            //     if(i==7)
            //     {
            //         bookshelf[0] = 0;
            //         is_full[0] = 0;
            //         reloadBookshelf(bookshelf,is_full);
            //         bookshelf[7] = in;
            //         is_full[7] = 1;
            //     }
            // }

    // for(int j=0;j<8;j++)
    // {
    //     if(j != 0) putchar(' ');
    //     printf("%d",bookshelf[j]);
    // }
    // putchar('\n');

        

    }
    
    for(int j=0;j<8;j++)
    {
        if(j != 0) putchar(' ');
        printf("%d",bookshelf[j]);
    }




    return 0;
}