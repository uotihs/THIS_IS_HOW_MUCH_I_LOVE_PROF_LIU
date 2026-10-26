#include<stdio.h>
#include<string.h>

int getDistance(const char* s1,const char* s2 )
{
    if(s1[0] == '\0') return strlen(s2);
    if(s2[0] == '\0') return strlen(s1);
    
    
    if(s1[0] == s2[0])
    {return getDistance(s1+1,s2+1);}
    else
    {
        int i1 = getDistance(s1+1,s2);
        int i2 = getDistance(s1,s2+1);

        if(i1 > i2) return 1+i2;
        else return 1+i1;
    }
    
}


int main()
{
    char lines[100][11];
    int index = 0;
    while (scanf("%s",lines[index])!=EOF)
    {
        index++;
    }

    int minIndex1,minIndex2,min=__INT32_MAX__;
    for(int i=1;i<=index;i++)
    {
        for(int j=i+1;j<=index;j++)
        {
            int tp =getDistance(lines[i-1],lines[j-1]);
            if(tp<min)
            {
                minIndex1 = i;
                minIndex2 = j;
                min = tp;
            }
            else if(tp==min && i*1000+j < minIndex1*1000+j)
            {
                minIndex1 = i;
                minIndex2 = j;
                min = tp;
            }
        }
    }

    printf("%d %d %d",min,minIndex1,minIndex2);
    








    return 0;
}