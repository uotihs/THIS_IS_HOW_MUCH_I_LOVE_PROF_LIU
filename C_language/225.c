#include<stdio.h>
#include<string.h>

struct person {
    unsigned int id;
    char name[32];
};

struct friends {
    unsigned id1;
    unsigned id2;
};

int returnIndexFromName(const char* str,struct person Humans[],int length)
{
    for(int i=0;i<length;i++)
    {
        if(strcmp(Humans[i].name,str)==0)
        {
            return Humans[i].id;
        }
    }
    return -1;
}

int main()
{
    FILE* readF = fopen("friends","rb");
    if(readF==NULL)printf("Sdasd");

    int peoplecount;
    fread(&peoplecount,sizeof(peoplecount),1,readF);

    struct person humans[peoplecount];
    for(int i=0;i<peoplecount;i++)
    {
        fread(&(humans[i]),sizeof(struct person),1,readF);
    }

    int friendsCount;
    fread(&friendsCount,sizeof(friendsCount),1,readF);

    struct friends Fs[friendsCount];
    for(int i=0;i<friendsCount;i++)
    {
        fread(&(Fs[i]),sizeof(struct friends),1,readF);
    }

    fclose(readF);

    char in1[101];
    int first =1;
    while (scanf("%s",in1)!=EOF)
    {
        if(strcmp(in1,"end")==0) return 0;
        if(first == 1 ) first=0;
        else putchar('\n');


        char in2[101];
        scanf("%s",in2);

        int id1 = returnIndexFromName(in1,humans,peoplecount);
        int id2 = returnIndexFromName(in2,humans,peoplecount);

        int success = 0;
        for(int i=0;i<friendsCount;i++)
        {
            if(Fs[i].id1 == id1 && Fs[i].id2 == id2)
            {
                printf("yes");
                success = 1;
                break;
            }
            else if(Fs[i].id1 == id2 && Fs[i].id2 == id1)
            {
                printf("yes");
                success = 1;
                break;
            }
        }
        if(!success) printf("no");
    }


    


    return 0;
}