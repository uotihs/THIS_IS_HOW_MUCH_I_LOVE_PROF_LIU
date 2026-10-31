#include "grading.h"
#include<string.h>
#include<stdio.h>

// #define maxL 1000
// typedef struct Submission
// {
//     int subID;
//     int studentID;
//     char outputs[10][maxL];    
// }Submission;

void grading(char answer[10][maxL], Submission* sub, int num_of_submission)
{
    int subMits[num_of_submission][3];
    int grades[num_of_submission];
    int students[num_of_submission];
    int peopleNums=0;
    


    int totalGrade = 0;
    for(int a=0;a<num_of_submission;a++)
    {
        grades[a] = 0;


        int grade = 0;
        for(int i=0;i<10;i++)
        {
            if(strcmp(answer[i],(sub+a)->outputs[i])==0)
            {
                grade+=10;
            }
        }

        subMits[a][0] = (sub+a)->studentID;
        subMits[a][1] = grade;
        subMits[a][2] = (sub+a)->subID;

        int newStudent = 1;
        int index = -1;
        for(int i=0;i<peopleNums;i++)
        {
            if(students[i]==(sub+a)->studentID)
            {
                index = i;
                newStudent=0;
                break;
            }
        }

        if(newStudent)
        {
            students[peopleNums] = (sub+a)->studentID;
            grades[peopleNums] = grade; 
            peopleNums++;
        }
        else
        {
            if(grades[index]<grade) grades[index]=grade;
        }

    }

    for(int i=0;i<peopleNums;i++)
    {
        for(int j=1;j<peopleNums;j++)
        {
            if(students[j]<students[j-1])
            {
                int tps = students[j];
                students[j]=students[j-1];
                students[j-1] = tps;

                int tpg = grades[j];
                grades[j]=grades[j-1];
                grades[j-1] = tpg;
            }
        }
    }

    for(int i=0;i<num_of_submission;i++)
    {
        for(int j=1;j<num_of_submission;j++)
        {
            if(subMits[j][0] < subMits[j-1][0])
            {
                int tp1 = subMits[j][0];
                int tp2 = subMits[j][1];
                int tp3 = subMits[j][2];

                subMits[j][0]=subMits[j-1][0];
                subMits[j][1]=subMits[j-1][1];
                subMits[j][2]=subMits[j-1][2];

                subMits[j-1][0]=tp1;
                subMits[j-1][1]=tp2;
                subMits[j-1][2]=tp3;
            }
            if(subMits[j][0] == subMits[j-1][0] && subMits[j][2] < subMits[j-1][2])
            {
                int tp1 = subMits[j][0];
                int tp2 = subMits[j][1];
                int tp3 = subMits[j][2];

                subMits[j][0]=subMits[j-1][0];
                subMits[j][1]=subMits[j-1][1];
                subMits[j][2]=subMits[j-1][2];

                subMits[j-1][0]=tp1;
                subMits[j-1][1]=tp2;
                subMits[j-1][2]=tp3;
            }
        }
    }

    int nowStudent = -1;
    int stuIndex = -1;
    for(int a=0;a<num_of_submission;a++)
    {    
        if(nowStudent==-1)
        {
            nowStudent = subMits[a][0];
            stuIndex++;
        }

        if(subMits[a][0]!=nowStudent)
        {
            printf("Student %d gets %d in this exam.\n",students[stuIndex],grades[stuIndex]);
            nowStudent = subMits[a][0];
            stuIndex++;
        }
        printf("Student %d gets %d with Submission %d.\n",subMits[a][0],subMits[a][1],subMits[a][2]);
    }
    printf("Student %d gets %d in this exam.",students[stuIndex],grades[stuIndex]);


}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

 
// #define maxL 1000
 
// int main(){
//     char answer[10][maxL];
//     int  num_of_submission;
//     Submission* sub;
 
//     for(int i=0;i<10;i++){
//         scanf("%s",answer[i]);
//     }
 
//     scanf("%d",&num_of_submission);
 
//     sub=(Submission*)malloc(num_of_submission*sizeof(Submission)); 
//     for(int i=0;i<num_of_submission;i++){
//         scanf("%d %d",&sub[i].subID,&sub[i].studentID);
//         for(int j=0;j<10;j++){
//             scanf("%s",sub[i].outputs[j]);
//         }
//     }
//     grading(answer,sub,num_of_submission);
// }