#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct var{
    char name[8];
    int value;
}Var;


int strcmp1(char* str1,char* str2)
{
    int index = 0;
    while (str1[index]!=0)
    {
        if(str1[index]>str2[index])
        {
            return 1;
        }
        else if (str1[index]<str2[index])
        {
            return -1;
        }
        index++;
    }

    return 0;
}

int strcpy1(char* src,char* dst)
{
    int index=0;
    while (src[index]!=0)
    {
        dst[index]=src[index];
        index++;
    }
    dst[index]=src[index];
    return 1;
}

int findVar(char* name ,Var variables[],int varlength)
{
    for(int i=0;i<varlength;i++)
    {
        if(strcmp1(name,variables[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}

int read_N_EQUAL_A_OP_B(char line[],Var variables[],int varLength)
{
    char linetp[50];
    strcpy1(line,linetp);
    //read n = n + 1;
    int line_small_index = 0;
    char IN[8];
    char equal[2];
    char IN2[8];
    char IN3[8];    
    char op[2];

    char* fractions = strtok(linetp," \n\r\t");
    while (fractions !=NULL && line_small_index < 5)
    {
        // printf("%s",fractions);
        if(line_small_index == 0)
        {
            strcpy1(fractions,IN);
        }
        else if(line_small_index == 1)
        {
            strcpy1(fractions,equal);
        }
        else if(line_small_index == 2)
        {
            strcpy1(fractions,IN2);
        }
        else if(line_small_index == 3)
        {
            strcpy1(fractions,op);
        }
        else if(line_small_index == 4)
        {
            strcpy1(fractions,IN3);
        }
        


        fractions = strtok(NULL," \n\r\t");
        line_small_index++;
    }

    switch (op[0])
    {
    case '+':
        variables[findVar(IN,variables,varLength)].value=
        variables[findVar(IN2,variables,varLength)].value+
        variables[findVar(IN3,variables,varLength)].value;
        break;
    case '-':
        variables[findVar(IN,variables,varLength)].value=
        variables[findVar(IN2,variables,varLength)].value-
        variables[findVar(IN3,variables,varLength)].value;
        break;
    case '*':
        variables[findVar(IN,variables,varLength)].value=
        variables[findVar(IN2,variables,varLength)].value*
        variables[findVar(IN3,variables,varLength)].value;
        break;
    case '/':
        variables[findVar(IN,variables,varLength)].value=
        variables[findVar(IN2,variables,varLength)].value/
        variables[findVar(IN3,variables,varLength)].value;
        break;
    case '%':
        variables[findVar(IN,variables,varLength)].value=
        variables[findVar(IN2,variables,varLength)].value%
        variables[findVar(IN3,variables,varLength)].value;
        break;
    }
    //==============================================
}

void print(char line[],Var variables[],int varLength)
{
    //print
    char linetp[50];
    strcpy1(line,linetp);
    int line_small_index = 0;
    char PRINT[8];
    char IN[8];
    char* fractions = strtok(linetp," \n\r\t");
    while (fractions !=NULL && line_small_index < 2)
    {
        // printf("%s",fractions);
        if(line_small_index == 0)
        {
            strcpy1(fractions,PRINT);
        }
        else if(line_small_index == 1)
        {
            strcpy1(fractions,IN);
        }
        fractions = strtok(NULL," \n\r\t");
        line_small_index++;
    }
    printf("%d\n",variables[findVar(IN,variables,varLength)].value);
}

int Read_GOTO(char line[],Var variables[],int varLength)
{
    int isTrue;
    char linetp[50];
    strcpy1(line,linetp);
    int line_small_index = 0;
    char GOTO[8];
    char LINE[5];

    char* fractions = strtok(linetp," \n\r\t");
    while (fractions !=NULL && line_small_index < 2)
    {
        // printf("%s",fractions);
        if(line_small_index == 0)
        {
            strcpy1(fractions,GOTO);
        }
        else if(line_small_index == 1)
        {
            strcpy1(fractions,LINE);
        }
        fractions = strtok(NULL," \n\r\t");
        line_small_index++;
    }
    
    return atoi(LINE);
}


int Read_IF(char line[],Var variables[],int varLength)
{
    int isTrue;
    char linetp[50];
    strcpy1(line,linetp);
    int line_small_index = 0;
    char IF[3];
    char IN[8];
    char OP[3];
    char IN2[8];    
    char GOTO[8];
    char LINE[5];

    char* fractions = strtok(linetp," \n\r\t");
    while (fractions !=NULL && line_small_index < 6)
    {
        // printf("%s",fractions);
        if(line_small_index == 0)
        {
            strcpy1(fractions,IF);
        }
        else if(line_small_index == 1)
        {
            strcpy1(fractions,IN);
        }
        else if(line_small_index == 2)
        {
            strcpy1(fractions,OP);
        }
        else if(line_small_index == 3)
        {
            strcpy1(fractions,IN2);
        }
        else if(line_small_index == 4)
        {
            strcpy1(fractions,GOTO);
        }
        else if(line_small_index == 5)
        {
            strcpy1(fractions,LINE);
        }

        fractions = strtok(NULL," \n\r\t");
        line_small_index++;
    }

    if(strcmp1("==",OP)==0)
    {
        if(
            variables[findVar(IN,variables,varLength)].value
            ==
            variables[findVar(IN2,variables,varLength)].value
        )
        isTrue = 1;
        else
        isTrue = 0;
    }
    else if(strcmp1(">=",OP)==0)
    {
        if(
            variables[findVar(IN,variables,varLength)].value
            >=
            variables[findVar(IN2,variables,varLength)].value
        )
        isTrue = 1;
        else
        isTrue = 0;
    }
    else if(strcmp1("<=",OP)==0)
    {
        if(
            variables[findVar(IN,variables,varLength)].value
            <=
            variables[findVar(IN2,variables,varLength)].value
        )
        isTrue = 1;
        else
        isTrue = 0;
    }
    else if(strcmp1("!=",OP)==0)
    {
        if(
            variables[findVar(IN,variables,varLength)].value
            !=
            variables[findVar(IN2,variables,varLength)].value
        )
        isTrue = 1;
        else
        isTrue = 0;
    }
    else if(strcmp1(">",OP)==0)
    {
        if(
            variables[findVar(IN,variables,varLength)].value
            >
            variables[findVar(IN2,variables,varLength)].value
        )
        isTrue = 1;
        else
        isTrue = 0;
    }
    else if(strcmp1("<",OP)==0)
    {
        if(
            variables[findVar(IN,variables,varLength)].value
            <
            variables[findVar(IN2,variables,varLength)].value
        )
        isTrue = 1;
        else
        isTrue = 0;
    }
    //==============================================


    if(isTrue)
    {
        return atoi(LINE);
    }
    else
    {
        return -1;
    }
}


int main()
{
    char var_name[100];
    char equal[10];
    char newline;
    int value;

    Var variables[100]={0};
    int varLength = 0;


    while (scanf("%s",var_name)!=EOF)
    {
        if(strcmp1("END",var_name)==0)
        {
            break;
        }
        else
        {
            scanf("%s",equal);
            scanf("%d",&value);
            
            strcpy1(var_name,variables[varLength].name); 
            variables[varLength].value = value;

            varLength ++;
        }

    }
    scanf("%c",&newline);

    char lines[1000][50]={0};
    int linesIndex=1;

    while (fgets(lines[linesIndex],50,stdin)!=NULL)
    {
        linesIndex++;
    }
    
    int nowlineIndex = 1;
    while (nowlineIndex < linesIndex)
    {
        char temp[50] = {0}; 
        strcpy1(lines[nowlineIndex],temp);

        char* define;
        define = strtok(temp," \n\r\t");

        int goline = 0;int golineline = 0;
        if(strcmp1("IF",define)==0)
        {
            golineline = Read_IF(lines[nowlineIndex],variables,varLength);
            if(golineline!= -1)
            {
                goline = 1;
            }
        }
        else if(strcmp1("GOTO",define)==0)
        {
            golineline = Read_GOTO(lines[nowlineIndex],variables,varLength);
            goline = 1;
        }   
        else if(strcmp1("PRINT",define)==0)
        {
            print(lines[nowlineIndex],variables,varLength);
        }
        else if(strcmp1("STOP",define)==0)
        {
            break;
        }
        else
        {
            read_N_EQUAL_A_OP_B(lines[nowlineIndex],variables,varLength);
        }

        nowlineIndex++;
        if(goline == 1)
        {
            nowlineIndex = golineline;
            goline=0;
        }
    }
    


    return 0;
}