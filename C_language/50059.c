#include<stdio.h>
#include<stdbool.h>


int main()
{
    long long twos[64];
    long long temp = 1;
    for(int i=0;i<64;i++)
    {
        twos[i] = temp;
        // printf("%lld ",twos[i]);
        temp*=2;
    } 


    char text[33] = {0};
    int testCases = 0;
    scanf("%s",text);
    scanf("%d",&testCases);

    int nums[testCases];
    for(int i=0;i<testCases;i++)
    {scanf("%d",&(nums[i]));}

    int readPtr = 0;
    int readBit = 31;
    int five = 5;
    int indexToPrint = 0;
    while (readPtr<testCases)
    {


        if((nums[readPtr] >> readBit) & 1 == 1)
        {
            indexToPrint |= twos[five-1]; 
            
        }
        // printf("%d %d %d\n",(nums[readPtr] >> readBit) & 1,readPtr,readBit);



        five--;
        readBit--;        
        
        if(five == 0)
        {
            five = 5;
            // printf("%d",indexToPrint);
            printf("%c",text[indexToPrint]);
            indexToPrint = 0;
        }
        if(readBit == -1)
        {
            readPtr++;
            readBit = 31;
        }
    }
    

    return 0;
}