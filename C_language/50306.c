#include<stdio.h>

#include "classroom_arrangement.h"


// struct Classroom{
//     char name[20];
//     int capacity;
// };

// struct Time{
//   int hour;
//   int minute;
// };

// struct Course{
//     char id[10];
//     struct Time start;
//     struct Time end;
//     int number_of_students;
//     int day; // 1: Monday, 2: Tuesday, 3: Wednesday, 4: Thursday, 5: Friday
// };

void class_arrangement(int classnum, int coursenum, struct Classroom classrooms[], struct Course courses[])
{
    // how to keep times?
    int classRoomToIndex[classnum][coursenum];
    int classRTI_index[classnum];
    for(int i=0;i<classnum;i++)
    {
        classRTI_index[i] = 0;
    }

    for(int i=0;i<coursenum;i++)
    {
        for(int j=0;j<classnum;j++)
        {
            if(classrooms[j].capacity >= courses[i].number_of_students)
            {
                // cap ok
                int ok = 1;
                if(classRTI_index[j] > 0)
                {
                    for(int k=0;k<classRTI_index[j];k++)
                    {
                        int StartTatClass = courses[classRoomToIndex[j][k]].start.hour*60 + courses[classRoomToIndex[j][k]].start.minute;
                        int EndTatClass = courses[classRoomToIndex[j][k]].end.hour*60 + courses[classRoomToIndex[j][k]].end.minute;

                        if(courses[i].start.hour*60+courses[i].start.minute <= EndTatClass && courses[i].end.hour*60 + courses[i].end.minute >= StartTatClass )
                        {
                            if(courses[i].day == courses[classRoomToIndex[j][k]].day)
                            {
                                ok = 0;
                                break;
                            }

                        }
                    }
                }

                if(ok)
                {
                    classRoomToIndex[j][classRTI_index[j]] = i;
                    classRTI_index[j]++;
                    break;
                }

            }
        }
    }

    for(int i=0;i<classnum;i++)
    {
        if(classRTI_index[i]>0)
        {
            for(int k=0;k<classRTI_index[i];k++)
            {

                for(int j=1;j<classRTI_index[i];j++)
                {
                    if(courses[classRoomToIndex[i][j]].day < courses[classRoomToIndex[i][j-1]].day)
                    {
                        int tp = classRoomToIndex[i][j];
                        classRoomToIndex[i][j] = classRoomToIndex[i][j-1];
                        classRoomToIndex[i][j-1] = tp;
                    }
                    else if(courses[classRoomToIndex[i][j]].day == courses[classRoomToIndex[i][j-1]].day)
                    {
                        if(courses[classRoomToIndex[i][j]].start.hour*60 + courses[classRoomToIndex[i][j]].start.minute < courses[classRoomToIndex[i][j-1]].start.hour*60 + courses[classRoomToIndex[i][j-1]].start.minute )
                        {
                            int tp = classRoomToIndex[i][j];
                            classRoomToIndex[i][j] = classRoomToIndex[i][j-1];
                            classRoomToIndex[i][j-1] = tp;
                        }
                    }
                }

            }

        }
    }


    for(int i=0;i<classnum;i++)
    {
        
        printf("%s :",classrooms[i].name);
        if(classRTI_index[i]>0)
        {
            for(int j=0;j<classRTI_index[i];j++)
            {
                printf(" %s",courses[classRoomToIndex[i][j]].id);
            }
        }
        putchar('\n');
    }


}

// #include <stdio.h>
// // #include <stdio.h>
// // #include "classroom_arrangement.h"
 
// int main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
 
//     struct Classroom classrooms[n];
//     for(int i = 0; i < n; i++){
//         scanf("%s %d", classrooms[i].name, &classrooms[i].capacity);
//     }
 
//     struct Course courses[m];
//     for(int i = 0; i < m; i++){
//         scanf("%s %d:%d %d:%d %d %d", courses[i].id, &courses[i].start.hour, &courses[i].start.minute, &courses[i].end.hour, &courses[i].end.minute, &courses[i].number_of_students, &courses[i].day);
//     }
 
//     class_arrangement(n, m, classrooms, courses);
 
//     return 0;
// }