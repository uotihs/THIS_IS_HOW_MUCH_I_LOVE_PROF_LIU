#include<stdio.h>
#include<stdint.h>


int main()
{
    int n;
    scanf("%d",&n);

    for(int now=0;now<n;now++)
    {
        uint64_t in;
        scanf("%llu",&in);

        int ifFive = 0;
        char s = 0;
        for(int i=0;i<60;i++)
        {
            char tp = ((in>>(i)) & 1);
        
            for(int j=0;j<ifFive;j++)
            {
                tp*=2;
            }

            s+=tp;
            ifFive++;
            if(ifFive == 5)
            {
                putchar(s+'a');
        
                s = 0;
                ifFive = 0;
            }
        }
        



    }


    return 0;
}