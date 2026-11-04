#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

const float epslion = 0.00000001;


typedef struct ppl
{
    char name[65];
    uint16_t height;
    uint16_t weight;
    float BMI;
}PPL;

int equal(PPL* p1,PPL* p2)
{
    if( p1->BMI - p2->BMI >= 0 && p1->BMI - p2->BMI <= epslion )
    {
        return 1;
    }
    if( p2->BMI - p1->BMI >= 0 && p2->BMI - p1->BMI <= epslion )
    {
        return 1;
    }
    return 0;
}

int cmp(const void* p1,const void* p2)
{
    PPL* peo1 = (const PPL*)p1;
    PPL* peo2 = (const PPL*)p2;

    if(peo1->BMI > peo2->BMI + epslion)
    {
        return 1;
    }
    else if(equal(peo1,peo2))
    {
        if(peo1->weight > peo2->weight)
        {
            return 1;
        }
        else if(peo1->weight == peo2->weight)
        {        
            if(peo1->height > peo2->height)
            {
                return 1;
            }
            else if(peo1->height == peo2->height)
            {
                if(strcmp(peo1->name,peo2->name) > 0)
                {
                    return 1;
                }
            }
        }
    }
    return -1;
}


int main()
{
    int pplNum;
    scanf("%d",&pplNum);

    PPL peoples[pplNum];

    for(int i=0;i<pplNum;i++)
    {
        scanf("%s",peoples[i].name);
        scanf("%hd",&(peoples[i].height));
        scanf("%hd",&(peoples[i].weight));

        peoples[i].BMI = (float)peoples[i].weight / (((float)peoples[i].height)/100) / (((float)peoples[i].height)/100); 
    }

    qsort(peoples,pplNum,sizeof(PPL),cmp);
    
    for(int i=0;i<pplNum;i++)
    {
        printf("%s",peoples[i].name);
        printf(" %hd %hd\n",peoples[i].height,peoples[i].weight);    
    }

    return 0;
}