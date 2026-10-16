#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*
一：yi1
二：er4
三：san1
四：sz4
五：wu3
六：lyou4
七：chi1
八：ba1
九：jyou3
十：shr2
百：bai3
千：chyan1
萬：wan4
億：yi4
*/

int strToType(char *str)
{
    if(strcmp("yi1",str)==0)
    {
        return 1;
    }
    else if(strcmp("er4",str)==0)
    {
        return 2;
    }
    else if(strcmp("san1",str)==0)
    {
        return 3;
    }

    else if(strcmp("sz4",str)==0)
    {
        return 4;
    }

    else if(strcmp("wu3",str)==0)
    {
        return 5;
    }

    else if(strcmp("lyou4",str)==0)
    {
        return 6;
    }

    else if(strcmp("chi1",str)==0)
    {
        return 7;
    }

    else if(strcmp("ba1",str)==0)
    {
        return 8;
    }
    else if(strcmp("jyou3",str)==0)
    {
        return 9;
    }

    else if(strcmp("shr2",str)==0)
    {
        return 10;
    }
    else if(strcmp("bai3",str)==0)
    {
        return 100;
    }
    else if(strcmp("chyan1",str)==0)
    {
        return 1000;
    }
    else if(strcmp("wan4",str)==0)
    {
        return 10000;
    }
    else if(strcmp("yi4",str)==0)
    {
        return 100000000;
    }

}




int main()
{
    char in[100];

    fgets(in,100,stdin);

    int sum[3] = {0};
    int sumtemp =0;
    int temp = 0;
    char *start = strtok(in," \r\n\t");
    while (start != NULL)
    {
        //deal with start;

        int type = strToType(start);

        if( type > 0 && type <= 9)
        {
            temp = type;
        }
        else if(type == 10)
        {
            temp *= 10;
            sumtemp += temp;
            temp = 0;
        }
        else if(type == 100)
        {
            temp *= 100;
            sumtemp += temp;
            temp = 0;
        }
        else if(type == 1000)
        {
            temp *= 1000;
            sumtemp += temp;
            temp = 0;
        }
        else if(type == 10000)
        {
            sumtemp += temp;
            sum[1] = sumtemp;
            // sum[index] *= 10000;
            temp = 0;
            sumtemp = 0;
        }
        else if(type == 100000000)
        {
            sumtemp += temp;
            sum[0] = sumtemp;
            // sum *= 10000;
            temp = 0;
            sumtemp = 0;
        }
        


        start = strtok(NULL," \r\n\t");
    }
    sum[2] += sumtemp+temp;

    printf("%d\n",sum[0]*100000000 + sum[1]*10000 + sum[2]);
    

    


    return 0;
}