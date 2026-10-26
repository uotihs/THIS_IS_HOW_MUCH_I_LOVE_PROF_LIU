#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct  
{
    char lastname[81];
    char firstname[81];
    char ID[81];
    int salary;
    int age;
}ZhiLiau;

enum {DAYU,DAYUDENYU,DENYU,XIAOYU,XIAOYUDENYU,BUDENYU};
enum {LASTNAME,FIRSTNAME,IDENTITY,SALARY,AGE};
typedef struct 
{
    int search[10];
    int len;

    bool findLastName;
    bool findFirstname;
    bool findID;
    bool findSalary;
    bool findAge;

    int condition;
    int num;
    char str[81];
}YauChuo;


void getData(ZhiLiau *data) 
{
    scanf("%s",data->lastname);
    scanf("%s",data->firstname);
    scanf("%s",data->ID);
    scanf("%d",&(data->salary));
    scanf("%d",&(data->age));
}

void getRequest(YauChuo *request)
{
    request->len = 0;
    char in[81];
    scanf("%s",in);//select

    while (scanf("%s",in)!=EOF)
    {
        if(strcmp(in,"where")==0)
            break;

        if(strcmp(in,"lastname")==0)
        {
            request->search[request->len] = LASTNAME;
            request->len++;
        }
        else if(strcmp(in,"firstname")==0)
        {
            request->search[request->len] = FIRSTNAME;
            request->len++;
        }
        else if(strcmp(in,"ID")==0)
        {
            request->search[request->len] = IDENTITY;
            request->len++;
        }
        else if(strcmp(in,"salary")==0)
        {
            request->search[request->len] = SALARY;
            request->len++;
        }
        else if(strcmp(in,"age")==0)
        {
            request->search[request->len] = AGE;
            request->len++;
        }
        
    }

    scanf("%s",in);
    if(strcmp(in,"lastname")==0)
    {
        request->findLastName = true;
        scanf("%s",in);
        if(strcmp(in,"==")==0)
        {
            request->condition =DENYU;
        }
        else if(strcmp(in,"!=")==0)
        {
            request->condition =BUDENYU;
        }
        scanf("%s",request->str);
    }
    else if(strcmp(in,"firstname")==0)
    {
        request->findFirstname = true;
        scanf("%s",in);
        if(strcmp(in,"==")==0)
        {
            request->condition =DENYU;
        }
        else if(strcmp(in,"!=")==0)
        {
            request->condition =BUDENYU;
        }
        scanf("%s",request->str);
    }
    else if(strcmp(in,"ID")==0)
    {
        request->findID = true;        
        scanf("%s",in);
        if(strcmp(in,"==")==0)
        {
            request->condition =DENYU;
        }
        else if(strcmp(in,"!=")==0)
        {
            request->condition =BUDENYU;
        }
        scanf("%s",request->str);

    }
    else if(strcmp(in,"salary")==0)
    {
        request->findSalary = true;
        scanf("%s",in);
        if(strcmp(in,">")==0)
        {
            request->condition =DAYU;
        }
        else if(strcmp(in,">=")==0)
        {
            request->condition =DAYUDENYU;
        }
        else if(strcmp(in,"==")==0)
        {
            request->condition =DENYU;
        }
        else if(strcmp(in,"<")==0)
        {
            request->condition =XIAOYU;
        }
        else if(strcmp(in,"<=")==0)
        {
            request->condition =XIAOYUDENYU;
        }
        scanf("%d",&(request->num));
    }
    else if(strcmp(in,"age")==0)
    {
        request->findAge = true;
        scanf("%s",in);
        if(strcmp(in,">")==0)
        {
            request->condition =DAYU;
        }
        else if(strcmp(in,">=")==0)
        {
            request->condition =DAYUDENYU;
        }
        else if(strcmp(in,"==")==0)
        {
            request->condition =DENYU;
        }
        else if(strcmp(in,"<")==0)
        {
            request->condition =XIAOYU;
        }
        else if(strcmp(in,"<=")==0)
        {
            request->condition =XIAOYUDENYU;
        }
        scanf("%d",&(request->num));
    }
}

void dealRequest(ZhiLiau data[],int dataLength,YauChuo request)
{
    bool isQualified[dataLength];

    for(int i=0;i<dataLength;i++)
    {
        if(request.findLastName)
        {
            if(request.condition == DENYU)
            {
                if(strcmp(data[i].lastname,request.str)==0)
                    isQualified[i]=true;
                else
                    isQualified[i]=false;
            }
            else if(request.condition == BUDENYU)
            {
                if(strcmp(data[i].lastname,request.str)!=0)
                    isQualified[i]=true;
                else 
                    isQualified[i]=false;
            }   
        }
        else if(request.findFirstname)
        {
            if(request.condition == DENYU)
            {
                if(strcmp(data[i].firstname,request.str)==0)
                    isQualified[i]=true;
                else
                    isQualified[i]=false;
            }
            else if(request.condition == BUDENYU)
            {
                if(strcmp(data[i].firstname,request.str)!=0)
                    isQualified[i]=true;
                else 
                    isQualified[i]=false;
            }   
        }
        else if(request.findID)
        {
            if(request.condition == DENYU)
            {
                if(strcmp(data[i].ID,request.str)==0)
                    isQualified[i]=true;
                else
                    isQualified[i]=false;
            }
            else if(request.condition == BUDENYU)
            {
                if(strcmp(data[i].ID,request.str)!=0)
                    isQualified[i]=true;
                else 
                    isQualified[i]=false;
            }   
        }
        else if(request.findSalary)
        {
            switch (request.condition)
            {
            case DAYU:
                if(data[i].salary > request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case DAYUDENYU:
                if(data[i].salary >= request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case DENYU:
                if(data[i].salary == request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case XIAOYU:
                if(data[i].salary < request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case XIAOYUDENYU:
                if(data[i].salary <= request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            }
        
        }
        else if(request.findAge)
        {
            switch (request.condition)
            {
            case DAYU:
                if(data[i].age > request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case DAYUDENYU:
                if(data[i].age >= request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case DENYU:
                if(data[i].age == request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case XIAOYU:
                if(data[i].age < request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            case XIAOYUDENYU:
                if(data[i].age <= request.num) isQualified[i]=true;
                else isQualified[i]=false;
                break;
            }
        }
    }

    for(int i=0;i<dataLength;i++)
    {
        if(isQualified[i]==false) continue;
        for(int currentRequest = 0 ; currentRequest < request.len ; currentRequest++)
        {
            if(currentRequest!=0) putchar(' ');

            if(request.search[currentRequest]==LASTNAME)
            {
                printf("%s",data[i].lastname);
            }
            else if(request.search[currentRequest]== FIRSTNAME)
            {
                printf("%s",data[i].firstname);
            }
            else if(request.search[currentRequest]== IDENTITY)
            {
                printf("%s",data[i].ID);
            }
            else if(request.search[currentRequest]== AGE)
            {
                printf("%d",data[i].age);
            }
            else if(request.search[currentRequest]== SALARY)
            {
                printf("%d",data[i].salary);
            }
        }
        putchar('\n');
    }

}


int main()
{
    int datalength;
    scanf("%d",&datalength);
    ZhiLiau datas[datalength];

    for(int i = 0 ; i< datalength;i++)
    {
        getData(&(datas[i]));
    }

    int requestlength;
    scanf("%d",&requestlength);

    for(int i=0;i<requestlength;i++)
    {
        YauChuo request = {0};
        getRequest(&request);
        dealRequest(datas,datalength,request);
    }

}
