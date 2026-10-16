#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
 
#define mxn 1010

int morseToType(char code)
{
    if(code == '.')
    {
        return 1;
    }
    if(code == '-')
    {
        return 2;
    }
    
}
/*
Each signal is represented by two bits:
00 for a dot, 01 for a dash, 10 for a space, and 11 for the EOF signal.
The Morse code for a string should be stored in an array of unsigned 64-bit integers,
arranged from the first to the last entry,
and from the most significant bit to the least significant bit within each entry.
*/

void MorseEncode(int* n, char str[], uint64_t* encoded_content)
{
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int index = 0;
    int smallindex = 0;
    int now = 0;
    while (str[now] != 0)
    {
        int len = strlen(MorseCodes[(str[now]-'A')]);
        for(int i = 0;i<len;i++)
        {
            if(morseToType(MorseCodes[(str[now]-'A')][i]) == 1)
            {
                encoded_content[index] <<=1;
                encoded_content[index] &= UINT64_MAX-1;

                smallindex++;
                encoded_content[index] <<=1;
                encoded_content[index] &= UINT64_MAX-1;
                
                smallindex++;
                
                if(smallindex == 64)
                {
                    smallindex = 0;
                    index++;
                } 
            }
            else if(morseToType(MorseCodes[(str[now]-'A')][i]) == 2)
            {
                encoded_content[index] <<=1;
                encoded_content[index] &= UINT64_MAX-1;
                
                smallindex++;
                encoded_content[index] <<=1;
                encoded_content[index] |= 1;
                
                smallindex++;
                
                if(smallindex == 64)
                {
                    smallindex = 0;
                    index++;
                } 
            }
        }
        // space 

        if(str[now+1] != 0)
        {
            encoded_content[index] <<=1;
            encoded_content[index] |= 1;

            smallindex++;

            encoded_content[index] <<=1;
            encoded_content[index] &= UINT64_MAX-1;
            
            smallindex++;

            if(smallindex == 64)
            {
                smallindex = 0;
                index++;
            } 
        }


        now ++;
    }
    encoded_content[index] <<=1;
    encoded_content[index] |= 1;
    smallindex++;

    encoded_content[index] <<=1;
    encoded_content[index] |= 1;

    smallindex++;

    while(smallindex < 64)
    {
        encoded_content[index] <<=1;
        encoded_content[index] |= 1;
        
        smallindex++;
    } 
    (*n) = index+1;

}

 
// int main(){
//     char str[mxn];
//     scanf("%s", str);
 
//     int n = 0;
//     uint64_t encoded_content[mxn];
//     MorseEncode(&n, str, encoded_content);
 
//     for(int i = 0; i < n; i++)
//         printf("%llu ", encoded_content[i]);

//     printf("\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int bit = 63; bit >= 0; bit--)
//         {
//             printf("%d", (int)((encoded_content[i] >> bit) & 1u));
//         }
//         putchar('\n');
//     }
    


//     return 0;
// }