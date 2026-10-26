#include<stdio.h>
#include<stdbool.h>


int snake(int *ptr, int *row, int *column)
{
    int index = 1;
    int colLen = 0;
    int nowShouldBe = 0;
    int nowRow = 0;
    bool first = true;

    while (ptr[index]!=0)
    {
        if(first)
        {
            int smlIndex = 0;
            while (ptr[index+smlIndex]!=0 && first && ptr[index+smlIndex]==ptr[index+smlIndex-1]+1)
            {
                colLen++;
                smlIndex++;
            }
            colLen+=1;
            index+=smlIndex-1;
            printf("c%d\n",colLen);
            first = false;
            nowRow++;
            continue;
            
        }
        else
        {
            if(nowRow%2 == 1)
            {

                int smlIndex = 1;
                while(ptr[index+smlIndex]!=0 && ptr[index+smlIndex]==ptr[index+smlIndex-1]-1)
                {
                    if(index+colLen-smlIndex!=ptr[index+smlIndex])
                    {
                        printf("num%d",ptr[index+smlIndex]);
                        printf("c%d",colLen);
                        printf("i%d",index);
                        printf("s%d",index+colLen-smlIndex);
                        *row = smlIndex;
                        *column = nowRow-1; 
                        return 0;
                    }

                    smlIndex++;
                }
                if(index+colLen-smlIndex!=ptr[index+smlIndex] && ptr[index+smlIndex]!=0)
                {
                    printf("num%d",ptr[index+smlIndex]);
                    printf("c%d",colLen);
                    printf("i%d",index);
                    printf("s%d",index+colLen-smlIndex);
                    *row = smlIndex;
                    *column = nowRow-1; 
                    return 0;
                }

                index+=smlIndex;
                if(ptr[index] == 0) break;
                //printf("si=%d\n",smlIndex);
                
                nowRow++;
                printf("\\index%d\n",index);
                printf("p%d",ptr[index]);
                printf("row%d",nowRow);
                
            }
            else
            {
                int smlIndex = 1;
                while(ptr[index+smlIndex]!=0 && ptr[index+smlIndex]==ptr[index+smlIndex-1]+1)
                {
                    if(index+smlIndex!=ptr[index+smlIndex])
                    {
                        *row = smlIndex;
                        *column = nowRow-1; 
                        return 0;
                    }

                    smlIndex++;
                }
                if(index+smlIndex!=ptr[index+smlIndex] && ptr[index+smlIndex]!=0)
                {
                    *row = smlIndex;
                    *column = nowRow-1; 
                    return 0;
                }
                index+=smlIndex;
                if(ptr[index] == 0) break;

                //printf("si=%d\n",smlIndex);
                
                nowRow++;
                printf("\\index%d\n",index);
                printf("p%d",ptr[index]);
                printf("row%d",nowRow);
            }
        }    
       
        index++;
    }
    nowRow-=1;

    if(colLen==index-1)
    {
        nowRow = colLen;
        colLen = 1;
    }

    *row = colLen;
    *column = nowRow;
    return 1;


    // int rowNow = 0;
    // int colNow = 0;
    // int index = 1;
    // bool first = 1;
    // bool right = true;
    // while (ptr[index]!=0)
    // {
    //     printf("%d\n",ptr[index]);
    //     if(right && ptr[index]!=ptr[index-1]+1)
    //     {
    //         if(first)
    //         {
    //             first = false;
    //             colNow = index+1;
    //         }

    //         rowNow+=1;
    //         right=!right;
    //     }
    //     else if(!right && ptr[index]!=ptr[index-1]-1)
    //     {
    //         if(first)
    //         {
    //             first = false;
    //             colNow = index+1;
    //         }

    //         rowNow+=1;
    //         right = !right;
    //     }

    //     index++;
    // }
    // printf("rn%dcn%did%d",rowNow,colNow,index);
    // (*row) = rowNow;
    // (*column) = colNow;
    // return 1;
    





}

int main(void)
{
    int trav[1024] = {0}, row = 0, column = 0, res = 0;
    scanf("%d %d", &trav[0], &trav[1]);
    for(int i = 1; trav[i]; i++)
      scanf("%d", &trav[i + 1]);
    res = snake(trav, &row, &column);
    if(res) printf("%d %d\n", row, column);
    else printf("err %d %d\n", row, column);
    return 0;
}