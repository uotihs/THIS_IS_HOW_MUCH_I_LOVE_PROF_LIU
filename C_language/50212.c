#include<stdio.h>

typedef unsigned int uot;

int bitNums(uot u1,int start,int end)
{
    int bits = 0;
    for(int i=start;i<end;i++)
    {
        if((u1 >> i) & 1)
        {
            bits++;
        }
    }
    return bits;
}

void printbits(uot u1)
{
    for(int i=31;i>=0;i--)
    {
        if((u1>>i) & 1)
            printf("1 ");
        else
            printf("0 ");
    }
    putchar('\n');
}

uot foo(uot* u1,int start,int len,uot twos[])
{
    // printbits(*u1);

    if(len == 1)
    {
        return 1;
    }

    if(bitNums(*u1,start,start+len) % 2 == 0)
    {
        foo(u1,start,len/2,twos);
        foo(u1,start+len/2,len/2,twos);
    }
    else
    {
        // printf("dsds\n");
        uot temp = 0;
        for(int i=start;i<start+len/2;i++)
        {
            if(((*u1) >> i) & 1) temp |= twos[i];

            if(((*u1) >> (i+len/2)) & 1)
            (*u1) |= twos[i];
            else
            (*u1) &= ~(twos[i]);
        }
        for(int i=start;i<start+len/2;i++)
        {
            if((temp >> i) & 1)
            (*u1) |= twos[i+len/2];
            else
            (*u1) &= ~(twos[i+len/2]);
        }

        foo(u1,start,len/2,twos);
        foo(u1,start+len/2,len/2,twos);
    }


}


int main()
{
    uot twos[32];
    uot index = 1;
    for(int i=0;i<32;i++)
    {
        twos[i]=index;
        index*=2;
    }


    uot in;
    scanf("%u",&in);

    

    foo(&in,0,32,twos);
    printf("%u",in);

    return 0;
}