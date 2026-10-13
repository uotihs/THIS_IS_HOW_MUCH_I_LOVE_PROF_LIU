#include"card.h"

void shuffle(int *deck[])
{
    int endIndex;
    for(int i=0;i<10000;i++)
    {
        if((deck[i])==NULL)
        {
            endIndex = i;
            break;
        }
    }
    // ps: endIndex == the length of cards

    int leftEnd = endIndex/2;
    int leftStart  = 0;
    int rightEnd = endIndex-1;
    if(endIndex % 2 == 0) leftEnd-=1;
    int rightStart = leftEnd+1;

    int* temp[endIndex];
    for(int i=0;i<endIndex;i++)
    {
        temp[i] = deck[i];
    }

    for(int i=leftStart;i<=leftEnd;i++)
    {
        deck[2*i] = temp[i];
    }
    for(int i=rightStart;i<=rightEnd;i++)
    {
        deck[2*(i-rightStart)+1] = temp[i];
    }



}

void print(int *deck[])
{
    for(int i=0;i<10000;i++)
    {
        if(deck[i] == NULL) break;;
        if(i!=0) putchar(' '); 
        printf("%d",*(deck[i]));
    }

}