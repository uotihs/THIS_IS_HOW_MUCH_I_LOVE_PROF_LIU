#include<stdio.h>
#include<stdbool.h>

int main()
{
    int k,in,len = 0,len_past = 0,through_x_rounds = 0,now = 0;
    bool pos_or_neg = true;
    scanf("%d",&k);
    while(scanf("%d",&in))
    {
        if(in == 0)
            break;

        if(pos_or_neg)
        {
            if(in > 0)
                now ++;
            else
            {
                pos_or_neg = true;
                now = 0;
                through_x_rounds = 0;
                if(len > len_past) len_past = len;
            }
        }
        else
        {
            if(in < 0)
                now ++;
            else
            {
                pos_or_neg = true;
                now = k;
                through_x_rounds = 0;
                if(len > len_past) len_past = len;
            }
        }

        if(now == k)
        {
            through_x_rounds ++;
            //printf("through!!!!!!!!!\n");
            if(through_x_rounds%2 == 1 && through_x_rounds !=1)
            {
                len = through_x_rounds * k;
            }
                
            now=0;
            pos_or_neg = !pos_or_neg;
        }

    // printf("len = %d \n" , len);
    // printf("through = %d \n" , through_x_rounds);
    // printf("pos = %d \n" , pos_or_neg);
    // printf("len_past = %d \n" , len_past);
    // printf("now = %d \n---------------\n" , now);
    }
    // printf("%d\n",len_past);
    // printf("%d\n",len);
    (len < len_past) ? printf("%d",len_past) : printf("%d",len);
    return 0;
}