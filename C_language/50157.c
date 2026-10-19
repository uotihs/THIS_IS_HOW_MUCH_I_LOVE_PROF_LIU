#include<stdio.h>

int main()
{
    int mod[3]={0};
    int Big[3]={0};

    int sum = 0;
    int in;

    int n;
    scanf("%d",&n);

    while (scanf("%d",&in)!=EOF)
    {
        int type = in%3;
        
        mod[type] += 1;

        if(Big[0] <= in)
        {
            Big[1] = Big[0];
            Big[0] = in;
        }
        else if(Big[1] < in)
        {
            Big[1] = in;
        }

        int allGet = 1;
        for(int i=0;i<3;i++)
        {
            if(mod[i]<n)
            {
                allGet = 0;
                break;
            }
        }

        if(allGet)
        {
            sum += Big[1];

            for(int i=0;i<3;i++)
            {
                Big[i] = 0;
                mod[i] = 0;
            }
            
            
        }
    }
    sum += Big[1];
    
    printf("%d",sum);

    return 0;
}