#include<stdio.h>
#include<stdbool.h>


int main()
{

    int len = 0;
    scanf("%d",&len);

    int ans = 0;

    int diag[len*2-1];
    int row[len];
    int col[len];

    bool contiRow[len];
    bool contiCol[len];
    bool contiDia[len*2-1];

    for(int i=0;i<len;i++)
    {
        row[i] = 0;
        col[i] = 0;
        contiCol[i] = 1;
        contiRow[i] = 1;
    }
    for(int i=0;i<len*2-1;i++)
    {
        contiDia[i] = 1;
        diag[i] = 0;
    }

    int in;

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            scanf("%d",&in);

            int ansTp = 0;
            if(in == 1)
            {
                col[j]++;
                row[i]++;

                if(contiCol[j])
                {
                    if(ansTp < col[j])
                    ansTp = col[j];
                }
                if(contiRow[i])
                {
                    if(ansTp < row[i])
                    ansTp = row[i];
                }

                int diaNum = i-j;
                if(diaNum<0) diaNum = -diaNum+len-1;

                diag[diaNum]++;
                if(contiDia[diaNum])
                {
                    if(ansTp<diag[diaNum])
                    ansTp = diag[diaNum];
                }

                contiDia[diaNum] =1;
                contiCol[j] = 1;
                contiRow[i] = 1;
            }
            else
            {
                int diaNum = i-j;
                if(diaNum<0) diaNum = -diaNum+len-1;

                diag[diaNum]=0;
                col[j] = 0;
                row[i] = 0;

                contiDia[diaNum] =0;
                contiCol[j] = 0;
                contiRow[i] = 0;
            }

            if(ansTp > ans) ans = ansTp;

        }
    }

    printf("%d",ans);

    return 0;
}