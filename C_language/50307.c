#include<stdio.h>
#include<math.h>

const double Epslion = 0.000000001;
#include "scholarship.h"
// struct Class {
//     int credit, type, score;
//     // type = 0 : compulsory, 1 : elective, 2 : others
// };

// struct Student {
//     char id[4];
//     int k;
//     struct Class classes[10];
 
//     // calculate values below by yourself
//     double gpa_avg, comp_avg, elec_avg;
//     int major, total;
// };



double getGPA(int n)
{
    if(n>=90)return 4.3;
    if(n>=85)   return 4.0;
    if(n>=80)   return 3.7;
    if(n>=77)   return 3.3;
    if(n>=73)   return 3.0;
    if(n>=70)   return 2.7;
    if(n>=67)   return 2.3;
    if(n>=63)   return 2.0;
    if(n>=60)   return 1.7;
    return 0;
}


int equals(double a,double b)
{
    if( a-b <= Epslion && a-b >= 0 )
    {
        return 1;
    }    
    if( b-a <= Epslion && b-a >= 0 )
    {
        return 1;
    }
    return 0;
}


void scholarship(int n, struct Student students[])
{
    

    // double GPAAverages[n];
    for(int i=0;i<n;i++)
    {
        double sumGPA=0;
        double sumElec = 0;
        double sumComP = 0;

        int credits=0;
        int creditsElec = 0;
        int creditsComP = 0;
        for(int j=0;j<students[i].k;j++)
        {
            sumGPA += students[i].classes[j].credit * getGPA(students[i].classes[j].score);
            // sum += students[i].classes[j].credit * students[i].classes[j].score;
            credits += students[i].classes[j].credit;

            if(students[i].classes[j].type == 0)
            {
                sumComP += students[i].classes[j].score*students[i].classes[j].credit;
                creditsComP += students[i].classes[j].credit;
            }
            if(students[i].classes[j].type == 1)
            {
                sumElec += students[i].classes[j].score*students[i].classes[j].credit;
                creditsElec += students[i].classes[j].credit;
            }
        }
        students[i].gpa_avg = sumGPA/credits;
        students[i].elec_avg = sumElec/creditsElec; 
        students[i].comp_avg = sumComP/creditsComP;
        students[i].major = creditsComP+creditsElec;
        students[i].total = credits;
    }
    int awards = (int)(ceil(n * 0.05)); 

    int lists[n];
    for(int i = 0;i<n;i++)
    {
        lists[i]=i;
        // printf("%lf %lf %lf %d %d\n",students[i].gpa_avg,students[i].comp_avg,students[i].elec_avg,students[i].major,students[i].total);
    
    
    }

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            int change = 0;

                if(students[lists[j]].gpa_avg > students[lists[j-1]].gpa_avg+Epslion)
                {
                    change = 1;
                }
                else if(equals(students[lists[j]].gpa_avg,students[lists[j-1]].gpa_avg))
                {
                    if(students[lists[j]].comp_avg > students[lists[j-1]].comp_avg+Epslion)
                    {
                        change = 1;
                    }
                    else if(equals(students[lists[j]].comp_avg ,students[lists[j-1]].comp_avg))
                    {
                        if(students[lists[j]].elec_avg > students[lists[j-1]].elec_avg+Epslion)
                        {
                            change = 1;
                        }
                        else if(equals(students[lists[j]].elec_avg , students[lists[j-1]].elec_avg))
                        {
                            if(students[lists[j]].major > students[lists[j-1]].major)
                            {
                                change = 1;
                            }
                            else if(students[lists[j]].major == students[lists[j-1]].major)
                            {
                                if(students[lists[j]].total > students[lists[j-1]].total)
                                {
                                    change = 1;
                                }
                            }
                        }
                    }
                }

            if(change)
            {
                
                int tp = lists[j];
                lists[j] = lists[j-1];
                lists[j-1] = tp;
            }

        }
    }

    printf("%d",awards);
    for(int i=0;i<awards;i++)
    {
        printf("\n%s",students[lists[i]].id);
    }
/*
The weighted average GPA.
The weighted average SCORE in compulsory classes.
The weighted average SCORE in elective classes.
The number of credits in compulsory and elective classes.
The number of total credits.
90~100	4.3
85~89	4.0
80~84	3.7
77~79	3.3
73~76	3.0
70~72	2.7
67~69	2.3
63~66	2.0
60~62	1.7
0~59	0

*/
}



// #include <stdio.h>
// // #include "scholarship.h"
 
// int main() {


//     int n;
//     scanf("%d", &n);
 
//     struct Student students[505];
//     for (int i = 0; i < n; i++) {
//         scanf("%s", students[i].id);
//         scanf("%d", &students[i].k);
 
//         for (int j = 0; j < students[i].k; j++) {
//             scanf("%d %d %d", &students[i].classes[j].credit, &students[i].classes[j].type, &students[i].classes[j].score);
//         }
//     }
 
//     scholarship(n, students);
// }