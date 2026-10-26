#include<stdio.h>
#include<stdio.h>
#include <string.h>
#include<stdbool.h>
#include "eval.h"
 
int eval(int exp[]) {
    bool isNum = 1;
    int index = exp[0];
//1 for + |  2 for - |  3 for *  | 4 for /
    int n1=0 , n2=0;
    int lastjiajian = 1;

    for(int i=1;i<index+1;i++)
    {
        if(isNum)
        {
            n2 = exp[i];
            isNum=!isNum;
            continue;
        }

        switch (exp[i])
        {
        case 1:
            while (!(exp[i]==1 && isNum == false || exp[i]==2 && isNum == false))
            {
                if(isNum)
                {
                    n2 = exp[i];
                }
                else
                {
                    if(exp[i]==3)
                    {
                        i++;
                        isNum=!isNum;
                        n2 = n2*exp[i];
                    }
                    else if(exp[i]==4)
                    {
                        i++;
                        isNum=!isNum;
                        if(exp[i]==0) return -2147483647;
                        n2 = n2/exp[i];
                    }
                }
                i++;
                isNum=!isNum;
            }
            if(lastjiajian== 1)
            {
                n1 = n1+n2;
            }
            else if(lastjiajian == 2)
            {
                n1 = n1-n2;
            }
            else
            {
                return -2147483646;
            }

            lastjiajian = exp[i];

            break;
        
        case 2:
            while (!(exp[i]==1 && isNum == false || exp[i]==2 && isNum == false))
            {
                if(isNum)
                {
                    n2 = exp[i];
                }
                else
                {
                    if(exp[i]==3)
                    {
                        i++;
                        isNum=!isNum;
                        n2 = n2*exp[i];
                    }
                    else if(exp[i]==4)
                    {
                        i++;
                        isNum=!isNum;
                        if(exp[i]==0) return -2147483647;
                        n2 = n2/exp[i];
                    }
                    else
                    {
                        return -2147483646;
                    }
                }
                i++;
                isNum=!isNum;
            }
            if(lastjiajian== 1)
            {
                n1 = n1+n2;
            }
            else if(lastjiajian == 2)
            {
                n1 = n1-n2;
            }

            lastjiajian = exp[i];
            


            break;

        case 3: // *
            i++;
            isNum=!isNum;
            n2 = n2*exp[i];
            break;

        case 4:
            i++;
            isNum=!isNum;
            if(exp[i]==0) return -2147483647;
            n2 = n2/exp[i];
            break;
            
        default:
            return -2147483646;

            break;
        }
        
        isNum=!isNum;
    }
    if(lastjiajian==1)
    {
        n1 = n1 + n2;
    }
    else if(lastjiajian==2)
    {
        n1 = n1 - n2;
    }



    return n1;




}



// // #include "eval.h"
 
// int main() {
//     int exp[1024];
//     memset(exp, -1, sizeof(exp));
//     scanf("%d", &exp[0]);
//     for (int i = 1; i <= exp[0]; i++)
//         scanf("%d", &exp[i]);
//     int ret = eval(exp);
//     printf("%d\n", ret);
//     return 0;
// }