#include<stdio.h>

int twos[8]={1,2,4,8,16,32,64,128};

int main()
{
    int validcodeNum,intsforvalidcode,testcases;
    scanf("%d%d%d",&validcodeNum,&intsforvalidcode,&testcases);

    unsigned long long codes[intsforvalidcode];
    for(int i=0;i<intsforvalidcode;i++)
    {
        scanf("%llu",&codes[i]);
    }
    int first = 1;

    for(int i = 0 ; i < testcases ; i++)
    {
        unsigned char in;
        scanf("%hhu",&in);
        
        

        int nowCheck = 0;
        int inIndex = 8-1;
        int checkedHowMuch = 0;
        int whichIndexWrong;

        int haveMayBeRight = 0;
        unsigned char maybeRight=-1;

        for(int a=0;a<intsforvalidcode;a++)
        {
            if(nowCheck>=validcodeNum) break;

            for(int b=63;b>=0;b--)
            {
                if( ((in>>inIndex) & 1 ) == ((codes[a]>>b) & 1 ))
                {
                    checkedHowMuch ++;
                }
                else
                {
                    whichIndexWrong = inIndex;
                }
                inIndex-=1;

                if(inIndex < 0)
                {
                    nowCheck+=1;
                    if(checkedHowMuch == 8)
                    {
                        if(first) first=0;
                        else printf("\n");
                        

                        printf("%hhu",in);
                        break;
                    }
                    else if(checkedHowMuch == 7)
                    {
                        if((in>>whichIndexWrong) & 1)
                        {
                            in &= ~(twos[whichIndexWrong]);
                        }
                        else
                        {
                            in |= (twos[whichIndexWrong]);
                        }

                        maybeRight = in;
                        haveMayBeRight = 1;
                    }

                    inIndex=8-1;
                    checkedHowMuch = 0;
                }
                if(nowCheck>=validcodeNum) break;
            }

            if(checkedHowMuch==8) break;
        }

        if(haveMayBeRight && checkedHowMuch!=8)
        {
            if(first) first=0;
            else printf("\n");
            

            printf("%d",maybeRight);
            continue;
        }

    }


    return 0;
}