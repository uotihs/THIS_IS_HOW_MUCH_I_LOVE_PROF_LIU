#include<stdio.h>

#if !defined(HUNDRED) && !defined(APLUS)
#define HUNDRED
#endif


#ifdef HUNDRED
int main()
{
    int score;
    double sum=0;
    int nums=0;
    int first=1;
    while (scanf("%d",&score)!= EOF)
    {
        sum+=score;
        nums++;

        printf("%d ",score);
    }

    printf("%.1f",sum/nums);
}




#endif

#ifdef APLUS

int main()
{
    int score;
    double sum=0;
    double rankSum = 0;
    int nums=0;
    while (scanf("%d",&score)!= EOF)
    {
        
        nums++;

        if(score <=100 && score >=90)
        {
            printf("A+");
            sum+=95;
            rankSum += 4.3;
        }
        else if(score >=85 && score<=89)
        {
            printf("A");
            sum+=87;
            rankSum += 4.0;
        }
        else if(score >=80 && score <=84)
        {
            printf("A-");
            sum+=82;
            rankSum += 3.7;
        }
        else if(score >=77 && score <=79)
        {
            printf("B+");
            sum+=78;
            rankSum += 3.3;
        }
        else if(score >=73 && score <=76)
        {
            printf("B");
            sum+=75;
            rankSum += 3.0;
        }
        else if(score >=70 && score <=72)
        {
            printf("B-");
            sum+=70;
            rankSum += 2.7;
        }
        else if(score >=67 && score <=69)
        {
            printf("C+");
            sum+=68;
            rankSum += 2.3;
        }
        else if(score >=63 && score <=66)
        {
            printf("C");
            sum+=65;
            rankSum += 2.0;
        }
        else if(score >=60 && score <=62)
        {
            printf("C-");
            sum+=60;
            rankSum += 1.7;
        }
        else if(score >=0 && score <=59)
        {
            printf("F");
            sum+=50;
            rankSum += 0.0;
        }
        printf(" ");

    }
    rankSum /= nums;
    printf("%.1f ",rankSum);
    printf("%.1f",sum/nums);
}



#endif