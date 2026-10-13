#include<stdio.h>


char map[10][7]=
{{1,1,1,0,1,1,1},
{0,0,1,0,0,1,0},
{1,0,1,1,1,0,1},
{1,0,1,1,0,1,1},
{0,1,1,1,0,1,0},
{1,1,0,1,0,1,1},
{1,1,0,1,1,1,1},
{1,1,1,0,0,1,0},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,0}};



void printASCII(int intarray[],int n,int width,int height)
{
    int Wsml = width-3;
    int Hsml = (height-3) /2;


    //print 1
    for(int i=0;i<n;i++)
    {
        int isLast = 1;
        for(int k=i+1;k<n;k++)
        {
            if(map[intarray[k]][0] == 1)
            {
                isLast = 0;
                break;
            }
        }

        if(!isLast || map[intarray[i]][0] == 1) putchar(' ');
        if(map[intarray[i]][0] == 1)
        {
            for(int j=0;j<Wsml;j++)
            {
                putchar('0'+intarray[i]);
            }
        }
        else
        {
            if(!isLast)
            {
                for(int j=0;j<Wsml;j++)
                {
                    putchar(' ');
                }
            }
        }
        if(!isLast) putchar(' ');

        //checkkkkkkk
        if(!isLast) putchar(' ');
    }
    putchar('\n');


    //print sml
    for(int i=0;i<Hsml;i++)
    {

        for(int j=0;j<n;j++)
        {
            int isLast = 1;
            for(int k=j+1;k<n;k++)
            {
                if(map[intarray[k]][1] == 1|| map[intarray[k]][2] == 1)
                {
                    isLast = 0;
                    break;
                }
            }

            int sp = 0;
            if(map[intarray[j]][2] == 1)sp = 1;

            if(map[intarray[j]][1] == 1)
            {
                putchar('0'+intarray[j]);
            }
            else
            {
                if(!isLast||sp) putchar(' ');
            }
            
            for(int k=0;k<Wsml;k++)
            {
                if(!isLast || sp) putchar(' ');
            }

            if(map[intarray[j]][2] == 1)
            {
                putchar('0'+intarray[j]);
            }
            else 
            {
                if(!isLast)putchar(' ');     
            }
            if(!isLast) putchar(' ');
        }
        putchar('\n');
    }

        //print 1
    for(int i=0;i<n;i++)
    {
        int isLast = 1;
        for(int k=i+1;k<n;k++)
        {
            if(map[intarray[k]][3] == 1)
            {
                isLast = 0;
                break;
            }
        }

        if(!isLast || map[intarray[i]][3] == 1) putchar(' ');
        if(map[intarray[i]][3] == 1)
        {
            for(int j=0;j<Wsml;j++)
            {
                putchar('0'+intarray[i]);
            }
        }
        else
        {
            if(!isLast)
            {
                for(int j=0;j<Wsml;j++)
                {
                    putchar(' ');
                }
            }
        }
        if(!isLast) putchar(' ');

        //checkkkkkkk
        if(!isLast) putchar(' ');
    }
    putchar('\n');

    //print sml
    for(int i=0;i<Hsml;i++)
    {

        for(int j=0;j<n;j++)
        {
            int isLast = 1;
            for(int k=j+1;k<n;k++)
            {
                if(map[intarray[k]][5] == 1 || map[intarray[k]][4] == 1)
                {
                    isLast = 0;
                    break;
                }
            }

            int sp = 0;
            if(map[intarray[j]][5] == 1)sp = 1;

            if(map[intarray[j]][4] == 1)
            {
                putchar('0'+intarray[j]);
            }
            else
            {
                if(!isLast||sp) putchar(' ');
            }
            
            for(int k=0;k<Wsml;k++)
            {
                if(!isLast||sp) putchar(' ');
            }

            if(map[intarray[j]][5] == 1)
            {
                putchar('0'+intarray[j]);
            }
            else 
            {
                if(!isLast)putchar(' ');     
            }
            if(!isLast) putchar(' ');
        }
        putchar('\n');
    }



        //print 1
    for(int i=0;i<n;i++)
    {
        int isLast = 1;
        for(int k=i+1;k<n;k++)
        {
            if(map[intarray[k]][6] == 1)
            {
                isLast = 0;
                break;
            }
        }
        

        if(!isLast || map[intarray[i]][6] == 1) putchar(' ');
        if(map[intarray[i]][6] == 1)
        {
            for(int j=0;j<Wsml;j++)
            {
                putchar('0'+intarray[i]);
            }
        }
        else
        {
            if(!isLast)
            {
                for(int j=0;j<Wsml;j++)
                {
                    putchar(' ');
                }
            }
        }
        if(!isLast) putchar(' ');

        //checkkkkkkk
        if(!isLast) putchar(' ');
        
    }

    putchar('\n');
}

int main()
{
    int array[100] = {0};
    char string[100] = {0};
    while (scanf("%s",string)!=EOF)
    {
        int indexEnd = 0;
        while (string[indexEnd] != 0)
        {
            array[indexEnd] = string[indexEnd]-'0';
            indexEnd++;
        }
        
        int width,height;
        scanf("%d%d",&width,&height);

        printASCII(array,indexEnd,width,height);
        
    }
    return 0;
}