#include<stdio.h>

int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int in;
    int rem[3] = {0};
    for(int i=0;i<row;i++)
    {
        int max1=0,max2=0,max1Index = 0,max2Index = 0;
        for(int j=0;j<col;j++)
        {
            scanf("%d",&in);

            if(in >= max1)
            {
                max2 = max1;
                max2Index = max1Index;
                max1 = in;
                max1Index = j;
            }
            else if(in >= max2)
            {
                max2 = in;
                max2Index = j;
            }
        }
        if(max1 >= rem[2])
        {
            rem[0] = i;
            rem[1] = max1Index;
            rem[2] = max1;
        }


        printf("%d %d\n",max1Index + 1,max2Index+1);


    }
    printf("%d %d",rem[0]+1,rem[1]+1);



    return 0;
}