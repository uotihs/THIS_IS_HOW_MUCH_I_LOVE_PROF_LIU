#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define MAX 65536
int main()
{
    char fileName[257];
    scanf("%s",fileName);

    FILE* writeF;
    FILE* readF;

    readF = fopen(fileName,"rb");
    if (readF==NULL)
    {
        printf("ssds");
    }
    

    int16_t in[1];
    int nums[1];

    fread(nums,sizeof(nums),1,readF);


    int count[65536]={0};

    
    for(int i=0;i<nums[0];i++)
    {
        fread(in,sizeof(in),1,readF);
        count[in[0]+32768]++;
    }

    int max = -1, maxIndex = -1;
    for(int i=0;i<65536;i++)
    {
        if(count[i] >= max)
        {
            max = count[i];
            maxIndex = i;
        }
    }

    
    printf("%d",(maxIndex-32768));

    putchar('\n');

    printf("%d",max);

    fclose(readF);
    return 0;

}