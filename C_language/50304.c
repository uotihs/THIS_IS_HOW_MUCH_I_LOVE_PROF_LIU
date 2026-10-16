#include <stdio.h>
#include <string.h>
#include <stdint.h>

 
#define mxn 1010

char DOT_DASH_TO_CHAR(char *str)
{
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    for(int i= 0 ; i<26;i++)
    {
        if(strcmp(MorseCodes[i],str)==0)
        {
            return i+'A';
        }
    }
    return '?';

}

void MorseDecode(int n, const uint64_t encoded_content[] ,char ans[])
{
    
    int index = 0;
    char str[30] = {0};
    int strIndex = 0;

    for(int now = 0 ; now < n ; now++)
    {
        
        for(int bit = 63; bit >= 0 ; bit -= 2)
        {
            int first = (encoded_content[now] >> bit) & 1;
            int second = (encoded_content[now] >> (bit-1)) & 1;
            if(first == 1 && second == 1)
            {
                //eof
                ans[index] = DOT_DASH_TO_CHAR(str);
                index++;
                ans[index] = '\0';
                for(int i=0;i<30;i++)
                {
                    str[i] = 0;
                }
                strIndex = 0;
                return ;
                
            }
            else if(first == 0 && second == 0)
            {
                // dot
                str[strIndex] = '.';
                strIndex ++;
            }
            else if(first == 0 && second == 1)
            {
                //dash
                str[strIndex] = '-';
                strIndex ++;
            }
            else if(first == 1 && second == 0)
            {
                //space
                ans[index] =  DOT_DASH_TO_CHAR(str);
                index++;
                for(int i=0;i<30;i++)
                {
                    str[i] = 0;
                }
                strIndex = 0;
            }



        }







    }




}

// int main() {
//     int n;
//     scanf("%d", &n);
 
//     uint64_t encoded_content[mxn];
//     for (int i = 0; i < n; i++)
//         scanf("%llu", &encoded_content[i]);
 
//     char ans[mxn];
//     MorseDecode(n, encoded_content, ans);
 
//     printf("%s\n", ans);
//     return 0;
// }