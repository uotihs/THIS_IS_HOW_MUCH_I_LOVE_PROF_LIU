#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>




void Print()
{

    printf("$\n");
}

void Insert(char* arrayC,int* arrayN,bool dire,int pos,char c,int n)
{
    if(dire)
    {
        if(pos == 1)
        {
            
            //right
        }
        if(pos == -1)
        {
            //left
        }
    } 
    else
    {
        //insert at pos
    }
}




int main()
{
    char* string = (char *)malloc(sizeof(char)*1);
    int* number = (char *)malloc(sizeof(int)*1);


    char sentence[100];
    while (fgets(sentence,100,stdin) != NULL)
    {
        char *fractions = strtok(sentence," \r\n\t");
        int index = 0;
        bool is_print = 0;
        bool is_direction = 0;

        char* pos;
        char c;
        char* num;

        while (fractions != NULL && index < 4)
        {
            if(index == 0)
            {
                if(strcmp(fractions,"print")==0)
                {
                    is_print = 1;
                    break;
                }
                else if(strcmp(fractions,"insert")==0)
                {
                    is_print = 0;
                }
            }
            else if(index == 1)
            {
                if(isdigit(fractions[0]))
                {
                    pos = fractions;
                    is_direction = 0;
                }
                else
                {
                    pos = fractions;
                    is_direction = 1;
                }
            }
            else if(index == 2)
            {
                c = fractions[0];
            }
            else if(index == 3)
            {
                num = fractions;
            }

            fractions = strtok(NULL," \r\n\t");
            index ++;
        }

        if(is_print)
        {
            Print();
            //print function
        }
        else
        {
            if(is_direction)
            {
                if(strcmp("left",pos) == 0)
                {
                    Insert(1,-1,c,atoi(num));
                    //insert left
                }
                else if(strcmp("right",pos) == 0)
                {
                    Insert(1,1,c,atoi(num));
                    //insert right
                }
            }
            else
            {
                Insert(0,atoi(pos),c,atoi(num));
                //regular insert
            }
        }
        



    }
    





    return 0;
}