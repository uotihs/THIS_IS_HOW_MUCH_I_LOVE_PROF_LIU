#include<stdio.h>



int main()
{
    int n;
    scanf("%d",&n);


    
    int in,last;

    scanf("%d",&in);
    last = in;

    int maxCount = in,maxlen = 1,maxstart = in,diff = 0;

    int len=1,count=in,start=in;
    int reset = 0;
    for(int index = 1 ; index < n ;index ++)
    {
        scanf("%d", &in);

        if(index ==1) diff = in - last;
        

        if( diff == in - last)
        {
            len ++;
            count += in;
        }
        else
        {
            reset = 1;
        }


        if(reset)
        {
            start = last;
            count = last+in;
            len = 2;
            reset = 0;
        }
        

        if(count > maxCount)
        {
            maxCount = count;
            maxlen = len;
            maxstart = start;
        }
        else if(count == maxCount && len > maxlen)
        {
            maxCount = count;
            maxlen = len;
            maxstart = start;
        }
        else if(len == maxlen && count == maxCount && start > maxstart)
        {
            maxCount = count;
            maxlen = len;
            maxstart = start;
        }

        diff = in -last;
        last = in ;
    }

    printf("%d %d %d",maxCount,maxlen,maxstart);


    // long long array[n];

    
    // for(int i=0;i<n;i++)
    // {
    //     scanf("%lld",&array[i]);
    // }

    // long long maxCount = 0,maxlen = 0,maxstart = 0;
    // for(int start = 0; start < n  ; start++)
    // {
    //     long long len=1,count = array[start];
    //     long long diff = array[start+1] - array[start];
    
    //     for(int end = start + 1 ; end < n ; end++)
    //     {
    //         if(array[end] - array[end-1] != diff)
    //         {
    //             break;
    //         }

    //         len ++;
    //         count += array[end];
    //     }

    
        

    //     if(len > maxlen)
    //     {
    //         maxCount = count;
    //         maxlen = len;
    //         maxstart = start;
    //     }
    // }

    // printf("%lld %lld %lld",maxCount,maxlen,array[maxstart]);

    return 0;
}