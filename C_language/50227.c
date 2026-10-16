#include<stdio.h>

int main()
{
    // recursion? for future me
    int one,two,three,four;
    scanf("%d%d%d%d",&one,&two,&three,&four);

    int yes = 0;
    for(int i=one-1;i>=1;i--)
    {
        int i2 = i*i;
        int i4 = i2*i2;
        if(i4 < four)
        {
            int secondFour = four - i4;
            for(int j = i-1;j>=1;j--)
            {
                int j2 = j*j;
                int j4 = j2*j2;
                if(j4 < secondFour)
                {
                    int thirdFour = secondFour - j4;
                    for(int k = j-1 ; k >= 1; k--)
                    {
                        int k2 = k*k;
                        int k4 = k2*k2;
                        if( k4 < thirdFour)
                        {
                            int fourthFour = thirdFour - k4;
                            for(int l = k-1 ; l>=1;l--)
                            {
                                int l2 = l*l;
                                int l4 = l2*l2;
                                if(l4 == fourthFour)
                                {
                                    if(i2*i+j2*j+k2*k+l2*l == three)
                                    {
                                        if(i2+j2+k2+l2 == two)
                                        {
                                            if(i+j+k+l == one)
                                            {
                                                printf("%d\n%d\n%d\n%d",i,j,k,l);
                                                return 0;
                                            }
                                        }
                                    }
                                }
                                if(l4 < fourthFour)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("-1");


    return 0;
}