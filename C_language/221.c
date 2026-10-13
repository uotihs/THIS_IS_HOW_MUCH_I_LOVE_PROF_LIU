#include<stdio.h>


int strprint(char s[])
{
    int index=0;
    while (s[index]!=0)
    {
        printf("%c",s[index]);
        index++;
    }
    return 1;
}

int strcpy(char src[],char dst[])
{
    int index = 0;

    while (src[index]!=0)
    {
        dst[index] = src[index];
        index++;
    }
    dst[index]=src[index];
    //for the \0 at the end

    return index;
    //return length
}

int strlen(char s[])
{
    int index = 0;
    while (s[index]!=0)
    {
        index++;
    }


    return index;
}


int printTheArray(int bufIndex,char buffer[257][257],int now_word_len,int maxprint)
{
    int spaces = (maxprint - now_word_len) / (bufIndex-1);
    int moreSpaces = (maxprint - now_word_len) % (bufIndex-1);



    //printf("\n%d %d %d %d %d\n",maxprint,now_word_len,spaces,moreSpaces,bufIndex);

    for(int i=0;i<bufIndex;i++)
    {
        strprint(buffer[i]);

        if(i != bufIndex-1)
        {
            for(int i=0;i<spaces;i++)
            {
                putchar(' ');
            }

            if(moreSpaces > 0)
            {
                putchar(' ');
                moreSpaces--;
            }
        }

    }
    
}



int main()
{
    int sentenceMax;
    scanf("%d",&sentenceMax);

    char word[257]={0};

    char buf[257][257] = {0};
    int buf_index = 0;
    int now_word_len = 0;
    int now_space_len = 0;
    while (scanf("%s",word)!= EOF)
    {
        

        if(now_word_len+buf_index+strlen(word) > sentenceMax)
        {
            if(buf_index == 1)
            {
                printf("%s",buf[0]);
                for(int i=0;i<sentenceMax-now_word_len;i++)
                {
                    putchar(' ');
                }
            }
            else
            {
                printTheArray(buf_index,buf,now_word_len,sentenceMax);
            }
            
            putchar('\n');

            buf_index = 0;
            now_word_len = 0;

            now_word_len += strcpy(word,buf[buf_index]);
        }
        else
        {
            now_word_len += strcpy(word,buf[buf_index]);
        }


        buf_index+=1;
    }
    if(buf_index == 1)
    {
        printf("%s",buf[0]); 
        for(int i=0;i<sentenceMax-now_word_len;i++)
        {
            putchar(' ');
        }
    }
    else
    {
        printTheArray(buf_index,buf,now_word_len,sentenceMax);
    }
    putchar('\n');




    return 0;
}