#include<stdio.h>

typedef struct data
{
    int leftStart;
    int rightEnd;
    int count;
} Data;

int CheckData(Data last,Data new)
{
    if(last.count > new.count){return 0;}
    else{return 1;}
}

int ChectP(int array[],int left,int right)
{
    while (left < right){if(array[left++] != array[right--]){return 0;}}
    return 1;
}


int main()
{
    int array[100] = {1,1};
    int index = 0;

    while (scanf("%d",&array[index++]) != EOF){}
    index --;

    Data nowData = {-1,-1,0};
    
    for(int now=1;now<index;now++)
    {
        int left = 0, right = index -1;

        int leftEnd = now-1;
        int rightStart = now;

        while(!ChectP(array,rightStart,right) && rightStart <= right){right--;}
        while (!ChectP(array,left,leftEnd) && left <= leftEnd){left++;}
        
        Data newData = {left,right,right-left+1};
        if(CheckData(nowData,newData) && nowData.rightEnd <= newData.rightEnd)
        {
            nowData.leftStart = newData.leftStart;
            nowData.rightEnd = newData.rightEnd;
            nowData.count = newData.count;
        }
    }

    for(int i=nowData.leftStart;i<=nowData.rightEnd;i++)
    {
        printf("%d",array[i]);
        if(i!= nowData.rightEnd) putchar(' ');
    }

    return 0;
}