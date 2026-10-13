#include"value.h"

int gcd(int n1,int n2)
{
    if(n1 ==0 && n2==0) return -1;
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;


    if(n1<n2)
    {
        int tp = n1;
        n1 = n2;
        n2 = tp;
    }

    while (n2!=0)
    {
        int temp = n2;
        n2 = n1 % n2 ;
        n1 = temp ;
    }

    return n1;
    
}

int value(int type, int width, int height, int length){
    int price = 0;

    switch (type)
    {
        case 79:
        price = 30;
            break;
        case 47:
        price = 10;
            break;
        case 29:
        price = 4;
            break;
        case 82:
        price = 5;
            break;
        case 26:
        price = 3;
            break;
        case 22:
        price = 9;
            break;
    }
    if(price == 0) return -1;

    if( width<=0|| height<=0|| length<=0) return -2;
    // 30,10,4,5,3,9
// The type parameter indicates the type of the metal block. If the type is 79
// , then the metal is gold. The rest are 47,29,82,26,22
// , for silver, copper, lead, iron, and titanium. 

    int fac;
    fac = gcd(width,height);
    fac = gcd(fac,length);
    int sum = fac*fac*fac;
    
    sum = sum*sum;
    sum *= width/fac;
    sum *= height/fac;
    sum *= length/fac;

    return sum*price;
    
}