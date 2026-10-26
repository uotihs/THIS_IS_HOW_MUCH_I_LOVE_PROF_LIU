#include<stdio.h>

int main()
{
    unsigned long long array[1000] = {0};
    int importance[1000] = {0};
    int index;

    while (scanf("%llu",&array[index])!=EOF)
    {
        int ones = 0;
        for(int i=63;i>=0;i--)
        {
            if(((array[index] >> i)& 1ULL) == 1)
            {
                ones++;
            }
        }
        importance[index]=ones;

        index++;
    }

    for(int i=0;i<index;i++)
    {
        for(int j=1;j<index;j++)
        {
            if(importance[j]<importance[j-1])
            {
                int tempIm = importance[j];
                unsigned long long tempLn = array[j];

                array[j] = array[j-1];
                importance[j] = importance[j-1];

                array[j-1] = tempLn;
                importance[j-1] = tempIm;
            }
            else if(importance[j]==importance[j-1] && array[j] < array[j-1])
            {
                int tempIm = importance[j];
                unsigned long long tempLn = array[j];

                array[j] = array[j-1];
                importance[j] = importance[j-1];

                array[j-1] = tempLn;
                importance[j-1] = tempIm;
            }
        }
    }

    for(int i=0;i<index;i++)
    {
        if(i!=0) putchar('\n');
        printf("%llu",array[i]);
    }
    


    return 0;
}