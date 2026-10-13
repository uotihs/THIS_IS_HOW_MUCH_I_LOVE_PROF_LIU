#include<stdio.h>

int strLen(char s[])
{
    int index = 0;

    while (s[index] != '\0')
    {
        index++;
    }
    // printf("%d\n",index);
    return index;
}



int main()
{
    char cmp[100] = {0};

    scanf("%s",cmp);

    int cmpLEN = strLen(cmp);
    int count = 0;
    
    char c;
    int index=0;
    
    int isS = 0;
    if(cmp[0] == cmp[1])
    {
        isS =1;
    }

    while (scanf("%c",&c)!=EOF)
    {
        if(c == cmp[index])
        {
            if(index == cmpLEN-1)
            {
                if(isS)index=1;
                else index = 0;
                count++;
            }
            else
            {
                index++;
            }
        }
        else
        {
            index = 0;
        }
    }
    
    
    // for(int i=0;i<inLEN;i++)
    // {
    //     if(i+cmpLEN-1 >= inLEN) break;

    //     for(int j=0;j<cmpLEN;j++)
    //     {
    //         if(cmp[j] != in[i+j])
    //         {
    //             break;
    //         }

            
    //         if(j==1)
    //         {
    //             count++;
    //         }
    //     }
    // }
    printf("%d",count);




    return 0;
}