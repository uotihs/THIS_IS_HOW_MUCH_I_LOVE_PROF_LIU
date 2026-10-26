#include<stdio.h>


typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;


int main()
{
    char inputFile[81];
    char outputFile[81];

    scanf("%s",inputFile);
    scanf("%s",outputFile);

    FILE* readF = fopen(inputFile,"rb");
    FILE* writef = fopen(outputFile,"w");

    fprintf(writef,"<table border=\"1\">\n<tbody>\n");

    Student s;

    while (fread(&s,sizeof(s),1,readF)!=0)
    {
        fprintf(writef,"<tr>\n");
        fprintf(writef,"<td>%s</td>\n",s.name);
        fprintf(writef,"<td>%d</td>\n",s.id);
        fprintf(writef,"<td>%s</td>\n",s.phone);
        fprintf(writef,"<td>%f, %f, %f, %f</td>\n",s.grade[0],s.grade[1],s.grade[2],s.grade[3]);
        fprintf(writef,"<td>%d, %d, %d</td>\n",s.birth_year,s.birth_month,s.birth_day);
        fprintf(writef,"</tr>\n");
    }
    fprintf(writef,"</tbody>\n</table>");

    fclose(readF);
    fclose(writef);

    return 0;
}