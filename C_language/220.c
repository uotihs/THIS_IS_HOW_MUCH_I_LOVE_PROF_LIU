#include<stdio.h>

int main()
{
    int isEnd = 0;
    int endCount = 0;
    char in;

    int spaceCount = 0;
    int newlineCount = 0;
    while (scanf("%c",&in)!= EOF)
    {
        switch (in)
        {
            case '.':
                isEnd = 1;
                spaceCount = 0;
                newlineCount = 0;
                break;
            case ' ': 
                if(isEnd==1||spaceCount>0)
                {
                    spaceCount++;
                }
                if(spaceCount==2)
                {
                    endCount ++;
                    spaceCount = 0;
                }

                newlineCount = 0;
                isEnd = 0;
                break;
            case '\n':
                if(newlineCount || spaceCount) newlineCount++;

                if(isEnd)
                {
                    newlineCount = 0;
                    endCount ++;
                }

                spaceCount = 0;
                isEnd = 0;
                break;
            default:
                isEnd = 0;
                spaceCount = 0;
                newlineCount = 0;
                break;
        }
    }
    if(newlineCount || spaceCount || isEnd)
    {
        endCount ++;
    }
    



    printf("%d",endCount);


    return 0;
}