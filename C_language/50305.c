#include<stdio.h>
 
int main()
{
    int n;
    scanf("%d",&n);
    int colC=0,rowC=0,diaC=0,AdaC=0;
    int sum = 0;
 
    // int dia[64] = {0}; //64-n+1
    // int anti_dia[64] = {0}; //64-n+1
    int col[64] = {0}; //64-n+1
    int row[64] = {0};
    unsigned long long lastin[n];
    for (int i = 0; i < n; i++)
    lastin[i] = 0;
    
    int FourBefore[64] = {0};
    int rowIndex = 0;
    int diaInd = n-1;

    int diag[64] = {0};
    int anti_diag[64] = {0};

    unsigned long long in;
    while (scanf("%llu",&in)!=EOF)
    {


        lastin[0] = in;
        int colIndex = 0;
 
        for(int i=63;i>=0;i--)
        {
 
            for(int j=0;j<n;j++)
            {
                if(colIndex-j>=0 && colIndex-j <64-n+1)
                    col[colIndex-j] += (in>>i & 1);
            }

 
            colIndex++;
 
            // col Index
 
            row[63-i] += (in>>i & 1);
            diag[63-i] += (in>>i & 1);
            anti_diag[63-i] += (in>>i & 1);
 
            // row
 
        }
        rowIndex++;
 
        for(int i=0;i<64-n+1;i++)
        {
            // printf("%d\n",col[i]);
            if(col[i]==n)
            {
                colC++;
            }
 
            col[i]=0;
        }  
 
 
        for(int i=0;i<64;i++)
        {
            if(row[i]==n)
            {
                rowC++;
            }
 
            if(rowIndex>=n)
                row[i] -= (lastin[n-1] >> (63-i)) & 1;
        }
 
 

         if(rowIndex>=n)
        {

            for (int c = n - 1; c < 64; c++)
            {
                if (diag[c] == n)
                    diaC++;
            }

            for (int c = 0; c <= 64 - n; c++)
            {
                if (anti_diag[c] == n)
                    AdaC++;
            }



            for(int j=63;j>=0;j--)
            {
                int nowbit =( lastin[n-1] >> (63-j) )&1;

                if (j + n - 1 < 64)
                diag[j + n - 1] -= nowbit;

                if (j - n + 1 >= 0)
                anti_diag[j - n + 1] -= nowbit;
            }
 

        }
 
 
        for(int i=n-1;i>=1;i--)
        {
            lastin[i] = lastin[i-1];
        }
        for(int i=63;i>=1;i--)
        {
            diag[i] = diag[i-1];
        }
        diag[0] = 0;
        for(int i=0;i<63;i++)
        {
            anti_diag[i] = anti_diag[i+1];
        }
        anti_diag[63] = 0;
        
 

    }
 
 
    printf("%d\n%d\n%d\n%d",colC,rowC,diaC,AdaC);
 
 
    return 0;
}