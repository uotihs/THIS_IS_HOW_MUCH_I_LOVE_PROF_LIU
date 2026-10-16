#include<stdio.h>

int main()
{
    int A[2],B[2],C[2],D[2];
    int first = 1;
    while (scanf("%d%d",&(A[0]),&(A[1]))!=EOF)
    {
        if(first == 1)
        {
            first = 0;
        }
        else
        {
            putchar(' ');
        }
        scanf("%d%d",&(B[0]),&(B[1]));
        scanf("%d%d",&(C[0]),&(C[1]));
        scanf("%d%d",&(D[0]),&(D[1]));

        int Ad = (A[0] - D[0])*(A[0] - D[0])+(A[1] - D[1])*(A[1] - D[1]);
        int Bd = (B[0] - D[0])*(B[0] - D[0])+(B[1] - D[1])*(B[1] - D[1]);
        int Cd = (C[0] - D[0])*(C[0] - D[0])+(C[1] - D[1])*(C[1] - D[1]);

        if(Ad == Bd && Bd == Cd)
        {
            printf("0");
        }
        else if(Ad < Bd  && Ad < Cd)
        {
            printf("1");
        }
        else if(Bd < Ad  && Bd < Cd)
        {
            printf("2");
        }
        else if(Cd < Bd  && Cd < Ad)
        {
            printf("3");
        }
        else if(Ad == Bd  && Ad < Cd)
        {
            printf("4");
        }
        else if(Ad == Cd  && Ad < Bd)
        {
            printf("5");
        }
        else if(Cd == Bd  && Cd < Ad)
        {
            printf("6");
        }

    }
    

    



    return 0;
}