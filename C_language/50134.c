#include<stdio.h>
#include<stdint.h>
#include<string.h>

int main()
{
    uint64_t twos[64];
    uint64_t temp = 1;
    for(int i=0;i<64;i++)
    {
        twos[i] = temp;
        temp*=2;
    }

    int reverse;
    scanf("%d",&reverse);

    char type[10];


    int first = 1;

    if(!reverse)
    {    
        uint32_t bit32;
        uint16_t bit16;
        char bit8s[10];
        while (scanf("%s",type)!=EOF)
        {
            scanf("%u",&bit32);
            scanf("%hu",&bit16);
            scanf("%s",bit8s);

            uint64_t ans = 0;
            int nowRemain = 64;
            int nowChar = 0;
            for(int a=0;a<4;a++)
            {
                if(type[a]=='L')
                {
                    for(int i = 0 ; i < 32;i++)
                    {
                        if( (bit32>>i ) & 1 )
                        {
                            ans |= twos[i+nowRemain-32];
                        }
                    }
                    nowRemain-=32;   
                }
                else if(type[a]=='S')
                {
                    for(int i = 0 ; i < 16;i++)
                    {
                        if( (bit16>>i ) & 1 )
                        {
                            ans |= twos[i+nowRemain-16];
                        }
                    }
                    nowRemain-=16;
                }
                else if(type[a]=='C')
                {
                    for(int i = 0 ; i < 8;i++)
                    {
                        if( (bit8s[nowChar]>>i ) & 1 )
                        {
                            ans |= twos[i+nowRemain-8];
                        }
                    }
                    nowChar++;
                    nowRemain-=8;
                }
            }

            if(first) first = 0;
            else putchar('\n');
            printf("%llu",ans);
        }
    }
    else
    {
        while (scanf("%s",type)!=EOF)
        {
            uint64_t in;
            scanf("%llu",&in);
            int nowRemain = 64;
            uint32_t bit32=0;
            uint16_t bit16=0;
            char bit8s[3]={0};
            int nowChar =0;
            for(int a=0;a<4;a++)
            {
                if(type[a]=='L')
                {
                    for(int i = 0 ; i < 32;i++)
                    {
                        if( (in >> (i+nowRemain-32)) & 1 )
                        {
                            bit32 |= twos[i];
                        }
                    }
                    nowRemain-=32;   
                }
                else if(type[a]=='S')
                {
                    for(int i = 0 ; i < 16;i++)
                    {
                        if( (in >> (i+nowRemain-16) ) & 1 )
                        {
                            bit16 |= twos[i];
                        }
                    }
                    nowRemain-=16;
                }
                else if(type[a]=='C')
                {
                    for(int i = 0 ; i < 8;i++)
                    {
                        if( (in>>(i+nowRemain-8) ) & 1 )
                        {
                            bit8s[nowChar] |= twos[i];
                        }
                    }
                    nowChar++;
                    nowRemain-=8;
                }
            }

            if(first) first = 0;
            else putchar('\n');
            printf("%u %hu %s",bit32,bit16,bit8s);
        }
    }




    return 0;
}