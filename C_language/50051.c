#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{


    int testcases;
    scanf("%d",&testcases);

    char type1[testcases][10];
    int type1Count = 0;
    char type2[testcases][10];
    int type2Count = 0;

    bool first = true;
    for(int i=0;i<testcases;i++)
    {
        char in[10];
        scanf("%s",in);
        int length = strlen(in);
        if(length != 7) continue;

        int nums = 0;
        bool alpha_or_digits = true;
        bool too_much_four = false;
        bool repetitive = false;
        int abc[52] = {0};
        int onetwothree[10] = {0};
        if(in[2]=='-')
        {
            //type 1
            for(int j=0;j<length;j++)
            {
                if(j==2) continue;

                if(!isalnum(in[j]))
                {
                    alpha_or_digits = false;
                    break;
                }


                if(j!=0 && in[j] == in[j-1] && in[j]== '4')
                {
                    too_much_four = true;
                    break;
                }

                if(isdigit(in[j]))
                {
                    nums+= in[j]-'0';
                    onetwothree[in[j]-'0']++;
                    if(onetwothree[in[j]-'0']>2)
                    {
                        repetitive = true;
                        break;
                    }
                }
                else
                {
                    if(in[j]<='z' && in[j]>='a')
                    {
                        abc[in[j]-'a']+=1;
                        if(abc[in[j]-'a'] >2)
                        {repetitive = true;break;}
                    }
                    else if(in[j]<='Z' && in[j]>='A')
                    {
                        abc[in[j]-'A'+26]+=1;
                        if(abc[in[j]-'A'+26]>2)
                        {repetitive = true;break;}
                    }
                }
            }


            if(too_much_four || !alpha_or_digits || nums%7==0 || repetitive)
            {
                continue;
            }
            else
            {
                strcpy(type1[type1Count],in);
                type1Count++;
            }
            



        }
        else if(in[3]=='-')
        {
            //type 2
            for(int j=0;j<length;j++)
            {
                if(j==3) continue;

                if(!isalnum(in[j]))
                {
                    alpha_or_digits = false;
                    break;
                }


                if(j!=0 && in[j] == in[j-1] && in[j]== '4')
                {
                    too_much_four = true;
                    break;
                }

                if(isdigit(in[j]))
                {
                    nums+= in[j]-'0';
                    onetwothree[in[j]-'0']++;
                    if(onetwothree[in[j]-'0']>2)
                    {
                        repetitive = true;
                        break;
                    }
                }
                else
                {
                    if(in[j]<='z' && in[j]>='a')
                    {
                        abc[in[j]-'a']+=1;
                        if(abc[in[j]-'a']>2)
                        {repetitive = true;break;}
                    }
                    else if(in[j]<='Z' && in[j]>='A')
                    {
                        abc[in[j]-'A'+26]+=1;
                        if(abc[in[j]-'A'+26] > 2)
                        {repetitive = true;break;}
                    }
                }
            }


            if(too_much_four || !alpha_or_digits || nums%7==0 || repetitive)
            {
                continue;
            }
            else
            {
                strcpy(type2[type2Count],in);
                type2Count++;
            }
            
        }

    }
    for(int i = 0 ; i< type1Count;i++)
    {
        for(int j= 1;j<type1Count;j++)
        {
            if(strcmp(type1[j],type1[j-1])<0)
            {
                char temp[10];
                strcpy(temp,type1[j]);

                strcpy(type1[j],type1[j-1]);
                strcpy(type1[j-1],temp);
            }
        }
    }
    for(int i = 0 ; i< type2Count;i++)
    {
        for(int j= 1;j<type2Count;j++)
        {
            if(strcmp(type2[j],type2[j-1])<0)
            {
                char temp[10];
                strcpy(temp,type2[j]);

                strcpy(type2[j],type2[j-1]);
                strcpy(type2[j-1],temp);
            }
        }
    }

    for(int i = 0 ; i< type1Count;i++)
    {
        if(first) first = false;
        else putchar('\n');

        printf("%s",type1[i]);
    }
    for(int i=0;i<type2Count;i++)
    {
        if(first) first = false;
        else putchar('\n');

        printf("%s",type2[i]);
    }


    return 0;
}