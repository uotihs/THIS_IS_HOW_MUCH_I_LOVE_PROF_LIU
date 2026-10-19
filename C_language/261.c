#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

int use[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

int Add1(int ABC[],int inABC[],int inCount)
{
    for(int i=0;i<inCount;i++)
    {
        if(ABC[inABC[i]] == 9)
        {
            ABC[inABC[i]] = 1;
            continue;
        }
        else
        {
            ABC[inABC[i]] ++;
            return 1;
        }
    }

    return 0;
}

bool solveIt(int ABC[],int inABC[],int inCount,char in1[],char in2[],char in3[],int len1,int len2,int len3,int* ans1,int* ans2,int* ans3)
{
    int a = 0;
    for(int i = 0 ; i < len1 ; i++)
    {
        int tp = 0;
        if(in1[i] >= 'A' && in1[i] <='Z')
        {
            tp = ABC[in1[i]-'A'];
        }
        else
        {
            tp = in1[i] - '0';
        }

        tp *= use[len1-1-i];
        a+=tp;
    }

    int b = 0;
    for(int i = 0 ; i < len2 ; i++)
    {
        int tp = 0;
        if(in2[i] >= 'A' && in2[i] <='Z')
        {
            tp = ABC[in2[i]-'A'];
        }
        else
        {
            tp = in2[i] - '0';
        }

        tp *= use[len2-1-i];
        b+=tp;
    }

    int c = 0;
    for(int i = 0 ; i < len3 ; i++)
    {
        int tp = 0;
        if(in3[i] >= 'A' && in3[i] <='Z')
        {
            tp = ABC[in3[i]-'A'];
        }
        else
        {
            tp = in3[i] - '0';
        }

        tp *= use[len3-1-i];
        c+=tp;
    }

    (*ans1) = a;(*ans2) = b;(*ans3) = c;

    if(a*b==c)
    return true;
    else
    return false;


}


// int resolve(int ABC[],bool inABC[],char in1[],char in2[],char in3[],int len1,int len2,int len3,char realNum1[],char realNum2[],char realNum3[])
// {
    
//     for(int i=0;i<len1;i++)
//     {
//         if(in1[i]>='A'&& in1[i]<='Z')
//         {
//             if(inABC[in1[i]-'A'])
//             {
//                 if(ABC[in1[i]-'A'] == realNum1[i]-'0')
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 inABC[in1[i]-'A'] = true;
//                 ABC[in1[i]-'A'] = realNum1[i]-'0';
//             }
            
//         }
//         else
//         {
//             if(ABC[in1[i]-'A']!= realNum1[i]-'0')
//             {
//                 return false;
//             }
//         }
//     }

//     for(int i=0;i<len2;i++)
//     {
//         if(in2[i]>='A'&& in2[i]<='Z')
//         {
//             if(inABC[in2[i]-'A'])
//             {
//                 if(ABC[in2[i]-'A'] == realNum2[i]-'0')
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 inABC[in2[i]-'A'] = true;
//                 ABC[in2[i]-'A'] = realNum2[i]-'0';
//             }
            
//         }
//         else
//         {
//             if(ABC[in2[i]-'A']!= realNum2[i]-'0')
//             {
//                 return false;
//             }
//         }
//     }

//     for(int i=0;i<len3;i++)
//     {
//         if(in3[i]>='A'&& in3[i]<='Z')
//         {
//             if(inABC[in3[i]-'A'])
//             {
//                 if(ABC[in3[i]-'A'] == realNum3[i]-'0')
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 inABC[in3[i]-'A'] = true;
//                 ABC[in3[i]-'A'] = realNum3[i]-'0';
//             }
            
//         }
//         else
//         {
//             if(ABC[in3[i]-'A'] != realNum3[i]-'0')
//             {
//                 return false;
//             }
//         }
//     }



//     return true;
// }

int main()
{
    int ABC[26] = {0};
    int inABC[26] = {0};
    int inABCcount = 0;
    char in1[10];
    char in2[10];
    char in3[20];

    scanf("%s%s%s",in1,in2,in3);
    int len1 = strlen(in1);
    int len2 = strlen(in2);
    int len3 = strlen(in3);

    for(int i=0;i<len1;i++)
    {
        if(in1[i] >= 'A' && in1[i] <= 'Z')
        {
            bool in = false;
            for(int j=0;j<inABCcount;j++)
            {
                if(inABC[j] == in1[i] -'A')
                {
                    in = true;
                    break;
                }
            }

            if(in)
            {
                continue;
            }
            else
            {
                inABC[inABCcount] = in1[i]-'A';
                inABCcount++;
            }
        }
    }

    for(int i=0;i<len2;i++)
    {
        if(in2[i] >= 'A' && in2[i] <= 'Z')
        {
            bool in = false;
            for(int j=0;j<inABCcount;j++)
            {
                if(inABC[j] == in2[i] -'A')
                {
                    in = true;
                    break;
                }
            }

            if(in)
            {
                continue;
            }
            else
            {
                inABC[inABCcount] = in2[i]-'A';
                inABCcount++;
            }
        }
    }

    for(int i=0;i<len3;i++)
    {
        if(in3[i] >= 'A' && in3[i] <= 'Z')
        {
            bool in = false;
            for(int j=0;j<inABCcount;j++)
            {
                if(inABC[j] == in3[i] -'A')
                {
                    in = true;
                    break;
                }
            }

            if(in)
            {
                continue;
            }
            else
            {
                inABC[inABCcount] = in3[i]-'A';
                inABCcount++;
            }
        }
    }

    for(int i=0;i<inABCcount;i++)
    {
        ABC[inABC[i]] = 1;
    }

    do
    {
        int ans1,ans2,ans3;
        if(solveIt(ABC,inABC,inABCcount,in1,in2,in3,len1,len2,len3,&ans1,&ans2,&ans3))
        {
            printf("%d x %d = %d\n",ans1,ans2,ans3);
            return 0;
        }


    } while (Add1(ABC,inABC,inABCcount));
    
    
    
    // int pow10len1 = 1;
    // for(int i=1;i<len1;i++)
    // {
    //     pow10len1*=10;
    // }

    // int pow10len2 = 1;
    // for(int i=1;i<len2;i++)
    // {
    //     pow10len2*=10;
    // }

    //         int i = 1234,j=4321;
    //         int ans = i*j;

    //         char realNum1[10]; 
    //         itoa(i,realNum1,10);
    //         char realNum2[10]; 
    //         itoa(j,realNum2,10);
    //         char realNum3[10]; 
    //         itoa(ans,realNum3,10);


    //         if(resolve(ABC,inABC,in1,in2,in3,len1,len2,len3,realNum1,realNum2,realNum3))
    //         {
    //             printf("%s x %s = %s",realNum1,realNum2,realNum3);
    //         }
    //         else
    //         {
    //             for(int k=0;k<26;k++)
    //             {
    //                 inABC[k]= 0;
    //             }
    //         }


    // // for(int i=pow10len1;i<pow10len1*10;i++)
    // // {
    // //     for(int j=pow10len2;j<pow10len2*10;j++)
    // //     {
    // //         int ans = i*j;

    // //         char realNum1[10]; 
    // //         itoa(i,realNum1,10);
    // //         char realNum2[10]; 
    // //         itoa(j,realNum2,10);
    // //         char realNum3[10]; 
    // //         itoa(ans,realNum3,10);


    // //         if(resolve(ABC,inABC,in1,in2,in3,len1,len2,len3,realNum1,realNum2,realNum3))
    // //         {
    // //             printf("%s x %s = %s",realNum1,realNum2,realNum3);
    // //         }
    // //         else
    // //         {
    // //             for(int k=0;k<26;k++)
    // //             {
    // //                 inABC[k]= 0;
    // //             }
    // //         }

    // //     }
    // // }
    // printf("no");








    return 0;
}