#include"set.h"
#include<stdio.h>

void init(Set *set)
{
    *set = 0;
}

void add(Set *set, int i)
{
    unsigned long long index = 1;
    for(int j=0;j<i;j++)
    {index*=2;}

    (*set) |= index;
}

void has(Set set, int i)
{
    unsigned long long index = 1;
    for(int j=0;j<i;j++)
    {index*=2;}
    if(set & index)
    printf("set has %d\n",i);
    else
    printf("set does not have %d\n",i);

}

Set setUnion(Set a, Set b)
{
    Set ans = 0;
    unsigned long long index = 1;
    for(int i=0;i<64;i++)
    {
        if( (a>>i & 1 )== 1 ||( b>>i & 1) == 1)
        {
            ans |= index;
        }
        index*=2;
    }
    return ans;
}

Set setIntersect(Set a, Set b)
{
    Set ans = 0;
    unsigned long long index = 1;
    for(int i=0;i<64;i++)
    {
        if( ((a>>i & 1) == 1) && ( (b>>i & 1) == 1) )
        {
            ans |= index;
        }
        index*=2;
    }
    return ans;
}

Set setDifference(Set a, Set b)
{
    Set ans = 0;
    unsigned long long index = 1;
    for(int i=0;i<64;i++)
    {
        if( (a>>i & 1) == 1 && (b>>i & 1) == 0)
        {
            ans |= index;
        }
        
        if( (a>>i & 1) == 0 && (b>>i & 1) == 1)
        {
            ans |= index;
        }
        index*=2;
    }
    return ans;
}



 
// int main()
// {
//   Set a, b, c;
 
//   init(&a);
//   add(&a, 3);
//   add(&a, 5);
//   add(&a, 2);
 
//   init(&b);
//   add(&b, 3);
//   add(&b, 7);
//   add(&b, 9);
 
//   c = setUnion(a, b);
//   has(c, 2);
//   has(c, 3);
//   has(c, 5);
//   has(c, 7);
//   has(c, 9);
 
//   c = setIntersect(a, b);
//   has(c, 2);
//   has(c, 3);
//   has(c, 5);
//   has(c, 7);
//   has(c, 9);
 
//   c = setDifference(a, b);
//   has(c, 2);
//   has(c, 3);
//   has(c, 5);
//   has(c, 7);
//   has(c, 9);
 
//   return 0;
// }