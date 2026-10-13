#include<stdio.h>

int main()
{
    int nums;
    scanf("%d",&nums);

    int in;
    int count3n = 0 ,count3n1 = 0 , count3n2 = 0;
    for(int index = 0 ;index <nums ; index++)
    {
        scanf("%d",&in);

        if(in % 3 == 0)
        {
            count3n ++;
        }
        else if(in % 3 == 1)
        {
            count3n1 ++;
        }
        else
        {
            count3n2 ++;
        }

    }


    printf("%d %d %d",count3n,count3n1,count3n2);



    return 0;
}