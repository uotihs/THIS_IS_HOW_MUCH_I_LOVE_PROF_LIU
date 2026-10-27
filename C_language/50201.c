#include<stdio.h>


enum FOLDTYPES{BLANK,ROW,COL,DIAGONAL};


int main()
{
    int row,col;
    scanf("%d%d",&row,&col);

    int paper[row][col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            scanf("%d",&paper[i][j]);

    int rowStart = 0;

    int foldType,size;
    while (scanf("%d%d",&foldType,&size)!=EOF)
    {
        switch (foldType)
        {
        case ROW:
            
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<col;j++)
                {    
                    paper[rowStart + 2*size - i -1 ][j] += paper[rowStart + i][j];
                    paper[rowStart + i][j] = 0;
                }
            }
            rowStart += size;


            break;
        
        case COL:
        
            for(int i=col-1;i>=col-size;i--)
            {
                for(int j=rowStart;j<row;j++)
                {    
                    paper[j][col-i+col-2*size-1] += paper[j][i];
                    paper[j][i] = 0;
                }
            }
            col -= size;

            break;
        
        case DIAGONAL:
            
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(i-j>0)
                    {
                        paper[i+rowStart][col-size+j] += paper[j+rowStart][col-size+i];
                    }
                }
            }
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(i-j<0)
                    {
                        paper[i+rowStart][col-size+j]=0;
                    }
                }
            }



            break;
        
        }

    }
    
    for(int i=rowStart;i<row;i++)
    {
        if(i!=rowStart) putchar('\n');
        for(int j=0;j<col;j++)
        {
            if(j!=0) putchar(' ');
            printf("%d",paper[i][j]);
        }
    }


    return 0;
}