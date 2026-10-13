#include<stdio.h>




int main()
{
    

    int nums;
    scanf("%d",&nums);

    for(int i=0;i<nums;i++)
    {
        if(i!=0) putchar('\n');

        char in1[81]={0};
        char in2[81]={0};

        scanf("%s",in1);
        scanf("%s",in2);

        int index = 0;
        int change = 0,changeCount = 0;
        while (in1[index] != 0 || in2[index] != 0)
        {
            if(in1[index]!=in2[index])
            {
                changeCount ++;
                if(in1[index+1] == in2[index] && in1[index]== in2[index+1])
                {
                    change ++;
                }
            }
            if(changeCount>2)
            {
                break;
            }

            index++;
        }
        

        index = 0;
        int tmp = 0;
        int no = 0;
        while (in1[index+tmp] != 0 || in2[index] != 0)
        {
            if(tmp==1 && in1[index+tmp]==0 && in2[index]!=0)
            {
                if(in2[index+1] != 0)
                {no = 1; break;}
                else
                {break;}
            }
            else if(tmp==-1 && in1[index+tmp]!=0 && in2[index]==0)
            {
                if(in2[index+tmp+1] != 0)
                {no = 1; break;}
                else
                {break;}
            }


            if(in1[index+tmp]!=in2[index])
            {
                if(tmp != 0 )
                { 
                    no=1;
                    break;
                }

                if(in1[index+1]==in2[index])
                {
                    tmp =1;
                }
                else if(in1[index]==in2[index+1])
                {
                    tmp=-1;
                }
                else
                {
                    no = 1;
                    break;
                }
            }
            index++;
        }
        
        
        if(changeCount==2 && change == 1 || changeCount == 0 && change==0 || no == 0)
        {
            printf("yes");
        }
        else
        {
            printf("no");
        }


    }


    return 0;
}