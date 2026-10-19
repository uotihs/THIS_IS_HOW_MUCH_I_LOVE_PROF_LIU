#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>

int HashFuction(char* str)
{
    int len = strlen(str);
    int index = 0;
    bool first = 1;
    bool isVaild = false;

    for(int i=0;i<len;i++)
    {
        if(isdigit(str[i]))
        {
            if(first) break;
            index += str[i] ;
        }
        else if(str[i] >='a' && str[i] <= 'z'|| str[i] >= 'A' && str[i]<='Z' || str[i]== '_' )
        {
            first = false;
            isVaild = true;
            index += str[i];
        }
        else
        {
            isVaild = false;
            break;
        }
    }
    if(isVaild) return index;
    else return -1;
}

int HashFuction2(char* str)
{
    int len = strlen(str);
    int ans = 93563;
    for(int i=0;i<len;i++)
    {
        ans ^= str[i];
        ans *= 14851;
    }
    return ans;
}

int main()
{
    char in[100];
    int buckets[1000][3] = {0};
    int indexs[1000] = {0};
    int bucketsTimes[1000][3] = {0};
    bool first = 1;
    while (scanf("%s",in) != EOF)
    {
        int value = HashFuction(in);
        value%=1000;
        if(value != -1)
        {
            if(first) {first = false;}
            else {putchar('\n');}


            printf("%s ",in);
            bool isIn = false;
            int value2 = HashFuction2(in);

            for(int i=0;i<indexs[value];i++)
            {
                if(value2 == buckets[value][i])
                {
                    isIn = true;
                    bucketsTimes[value][i]++;
                    printf("%d",bucketsTimes[value][i]);
                    break;
                }
            }
            if(!isIn)
            {
                buckets[value][indexs[value]] = value2;
                bucketsTimes[value][indexs[value]]++;

                printf("%d",bucketsTimes[value][indexs[value]]);
                indexs[value]++;
            }
        }
    }
    



    return 0;
}