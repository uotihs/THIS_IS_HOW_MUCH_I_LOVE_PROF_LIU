#include <stdio.h>

int main()
{
    int isEnd = 0;
    int endCount = 0;
    char in;

    int spaceCount = 0;
    int pending = 0;

    while (scanf("%c", &in) != EOF)
    {
        switch (in)
        {
            case '.':
                isEnd = 1;
                pending = 1;
                spaceCount = 0;
                break;

            case ' ':
                if (isEnd || spaceCount > 0)
                {
                    spaceCount++;
                }

                if (spaceCount == 2)
                {
                    endCount++;
                    spaceCount = 0;
                    pending = 0;  // 已經算過
                }

                isEnd = 0;
                break;

            case '\n':
                if (isEnd)
                {
                    endCount++;
                    pending = 0;  // 已經算過
                }

                // pending 保留，供 EOF 時判斷
                spaceCount = 0;
                isEnd = 0;
                break;

            default:
                isEnd = 0;
                spaceCount = 0;
                pending = 0;  // 句點後出現其他字元
                break;
        }
    }

    if (pending)
    {
        endCount++;
    }

    printf("%d", endCount);
    return 0;
}