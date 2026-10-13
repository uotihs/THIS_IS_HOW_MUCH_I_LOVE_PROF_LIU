#include<stdio.h>

int main()
{
    int width,height;
    scanf("%d%d",&width,&height);

    char s1[2],s2[2];
    scanf("%s%s",s1,s2);
    char zero=s1[0];
    char one= s2[0];

    int count = ((width * height % 32) != 0 ) ? width * height / 32 + 1 : width * height / 32;
    unsigned int nums[count];
    for(int i=0;i<count;i++)
    {
        scanf("%u",&(nums[i]));
    }
    
    int nowIndex = 0;
    int index = 0;
    unsigned int dealwith = nums[index];

    for(int j=0;j<height;j++)
    {
        for(int i=0;i<width;i++)
        {
            if(nowIndex == 32)
            {
                index++;
                dealwith = nums[index];
                nowIndex = 0;
            }
            // printf("%d",dealwith & 2147483648U);
            if(dealwith & 2147483648U)
            {
                printf("%c",zero);
            }
            else
            {
                printf("%c",one);
            }
            dealwith <<=1;
            nowIndex ++;
        }
        putchar('\n');

        
    }

    

    return 0;
}