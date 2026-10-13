#include<stdio.h>

int strlen(char s[])
{
    int index = 0;
    while (s[index]!= 0)
    {
        index++;
    }
    return index;
}

void concatenate(char ans[],char in[])
{
    int index = 0;
    int anslen = strlen(ans);
    int inlen = strlen(in);
    // printf("anslen = %d\n",anslen);
    // while (ans[anslen-index-1] == in[index])
    // {
    //     index++;
    // }

    for(int i=0;i<anslen;i++)
    {
        index = 0;
        while (ans[index+i] == in[index] && ans[index+i]!= 0)
        {
            index++;
        }
        
        if(index+i != anslen) 
        {
            // printf("index =%d %d\n",index,i);
            index =0;
            continue;
        }
        else break;

    }
    
    

    for(int i = 0 ;  i <= inlen ;i++)
    {
        // //i = anslen-index+2
        // printf("?");
        ans[i+anslen-index] = in[i];
        // printf("%d %d\n",i+anslen-index,i);
    }


}


int main()
{
    char ans[1000]={0};
    char in[1000]={0};
    // scanf("%s",ans);
    while (scanf("%s",in)!=EOF)
    {
        concatenate(ans,in);
        // printf("%s\n",ans);

        // for(int i=0;i<20;i++)
        // {
        //     printf("%c ",ans[i]);
        //     if(ans[i]==0) putchar('w');
        // }
    }

    printf("%s",ans);
    
    


    return 0;
}