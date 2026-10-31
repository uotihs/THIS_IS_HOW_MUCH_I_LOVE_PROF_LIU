#include"heap.h"

#ifndef HEAP_H
#define HEAP_H
#define MAXHEAP 100
 
struct Heap{
    int ary[MAXHEAP];
    int num;
};
 

#endif


void initialize(struct Heap *heap)
{
    heap->num = 0;
}

int removeMin(struct Heap *heap)
{
    int ans = heap->ary[0];
    heap->ary[0] = heap->ary[heap->num-1];
    heap->ary[heap->num-1] = 0;
    heap->num-=1;
    int index = 0;

    while (index<heap->num)
    {
        int right=(index+1)*2;
        int left=(index+1)*2-1;
        int rightValue = __INT32_MAX__;
        int leftValue = __INT32_MAX__;

        if(right < heap->num)
        {
            rightValue = heap->ary[right];
        }

        if(left < heap->num)
        {
            leftValue = heap->ary[left];
        }

        if(leftValue==__INT32_MAX__ && rightValue==__INT32_MAX__)
        {
            break;
        }
        if(heap->ary[index] < leftValue && heap->ary[index] < rightValue)
        {
            break;
        }

        if(rightValue<=leftValue)
        {
            int tp = heap->ary[right];
            heap->ary[right] = heap->ary[index];
            heap->ary[index] = tp;
            index = right;
        }
        else if(leftValue < rightValue)
        {
            int tp = heap->ary[left];
            heap->ary[left] = heap->ary[index];
            heap->ary[index] = tp;
            index = left;
        }

    }
    return ans;
}

void add(struct Heap *heap, int i)
{
    heap->ary[heap->num] = i;
    heap->num++;
    int index = heap->num-1;
    while (index != 0)
    {
        if(heap->ary[(index-1)/2] > heap->ary[index])
        {
            int tp = heap->ary[(index-1)/2];
            heap->ary[(index-1)/2] = heap->ary[index];
            heap->ary[index] = tp;
        }
        else
        {
            break;
        }
        index = (index-1)/2;
    }    

}


int isFull(struct Heap *heap)
{
    return(heap->num==MAXHEAP);
}

int isEmpty(struct Heap *heap)
{
    return heap->num==0 ;
}


