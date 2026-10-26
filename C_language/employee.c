// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

// #ifndef EMPLOYEE_H
// #define EMPLOYEE_H
 
// typedef struct employee {
//   char first_name[32];
//   char last_name[32];
//   struct employee *boss;
// } Employee;
 
// int relation(Employee *employee1, Employee *employee2);
// #endif

#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
    
    Employee *boss1;
    boss1 = employee1->boss;
    while (boss1->boss != boss1 && boss1 != employee2)
    {
        boss1 = boss1->boss;
    }

    if(employee2 == boss1)
    {return 1;}

    Employee *boss2;
    boss2 = employee2->boss;
    while (boss2->boss != boss2 && boss2 != employee1)
    {
        boss2 = boss2->boss;
    }
    
    if(employee1 == boss2)
    {return 2;}

    if(boss1 == boss2) 
    {return 3;}


    return 4;

}



// // #include "employee.h"
 
// typedef struct me {
//     int id;
//     char first_name[32];
//     char last_name[32];
//     int boss_id;
// } employee;
 
// void readName(employee *e) {
//     scanf("%s %s", e->first_name, e->last_name);
// }
 
// int nameToIndex(employee *e, employee A[], int n) {
//     for (int i = 0; i < n; i++) {
//         if (!strcmp(A[i].first_name, e->first_name) &&
//             !strcmp(A[i].last_name, e->last_name))
//             return i;
//     }
//     return -1;
// }


// int main() {
//     int n, m;
//     employee A[32];
//     Employee B[32];
//     const char out[4][32] = {"subordinate", "supervisor", "colleague", "unrelated"};
//     while (scanf("%d", &n) == 1) {
//         for (int i = 0; i < n; i++) {
//             scanf("%d", &A[i].id);
//             readName(&A[i]);
//             scanf("%d", &A[i].boss_id);
//         }
 
//         for (int i = 0; i < n; i++) {
//             strcpy(B[i].first_name, A[i].first_name);
//             strcpy(B[i].last_name, A[i].last_name);
//             B[i].boss = NULL;
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (A[i].boss_id == A[j].id)
//                     B[i].boss = &B[j];
//             }
//         }
//         scanf("%d", &m);
//         employee x, y;
//         for (int i = 0; i < m; i++) {
//             readName(&x);
//             readName(&y);
//             int ix = nameToIndex(&x, A, n), iy = nameToIndex(&y, A, n);
//             assert(ix != -1);
//             assert(iy != -1);
//             printf("%d\n", relation(&B[ix], &B[iy]));
//         }
//     }
//     return 0;
// }















// #include<stdio.h>
// #include<string.h>

// typedef struct employee {
//   int id;
//   char first_name[32];
//   char last_name[32];
//   int boss_id;
// }Employee;

// int main()
// {
//     int nums;
//     int length=0;
//     Employee company[32]={0};
//     scanf("%d",&nums);

//     for(int i=0;i<nums;i++)
//     {
//         scanf("%d",&(company[i].id));

//         scanf("%s",(company[i].first_name));   

//         scanf("%s",(company[i].last_name));   

//         scanf("%d",&(company[i].boss_id));

//     }

//     int testcases;
//     scanf("%d",&testcases);

//     for(int i=0;i<testcases;i++)
//     {
//         if(i!=0) putchar('\n');
//         char names[2][2][33];
//         for(int j=0;j<2;j++)
//         {
//             for(int k=0;k<2;k++)
//             {
//                 scanf("%s",names[j][k]);
//             }
//         }
//         int employee1Index;
//         int employee2Index;

//         for(int i=0;i<nums;i++)
//         {
//             if(strcmp(names[0][0],company[i].first_name)==0 && strcmp(names[0][1],company[i].last_name)==0)
//             {
//                 employee1Index = i;
//             }
//             if(strcmp(names[1][0],company[i].first_name)==0 && strcmp(names[1][1],company[i].last_name)==0)
//             {
//                 employee2Index = i;
//             }
//         }

        
//         if(company[employee1Index].id == company[employee2Index].boss_id)
//         {
//             printf("supervisor");
//         }
//         else if(company[employee1Index].boss_id == company[employee2Index].id)
//         {
//             printf("subordinate");
//         }
//         else if(company[employee1Index].boss_id == company[employee2Index].boss_id)
//         {
//             printf("colleague");
//         }
//         else
//         {   
//             int found = 0;
//             int nowSearching = company[employee1Index].boss_id;
//             int nowSearchingBossID = -1;
//             while (nowSearching != nowSearchingBossID)
//             {
//                 int over = 0;
//                 for(int i=0;i<nums;i++)
//                 {
//                     if(company[i].id == nowSearching)
//                     {
//                         nowSearchingBossID = company[i].boss_id;
//                         if(company[i].id == company[i].boss_id)
//                             over=1;
//                         break;
//                     }
//                 }
//                 nowSearching = nowSearchingBossID;

//                 if(nowSearchingBossID == company[employee2Index].id)
//                 {

//                     printf("subordinate");
//                     found = 1;
//                     break;
//                 }
//                 if(over==1)
//                     break;

                
//                 nowSearchingBossID = -1;
//             }
            

//             if(found) continue;
            
//             int nowSearching2 = company[employee2Index].boss_id;
//             int nowSearchingBossID2 = -1;
//             while (nowSearching2 != nowSearchingBossID2)
//             {
//                 int over = 0;
//                 for(int i=0;i<nums;i++)
//                 {
//                     if(company[i].id == nowSearching2)
//                     {
//                         nowSearchingBossID2 = company[i].boss_id;
//                         if(company[i].id == company[i].boss_id)
//                             over=1;
//                         break;
//                     }
//                 }
//                 nowSearching2 = nowSearchingBossID2;

//                 if(nowSearchingBossID2 == company[employee1Index].id)
//                 {
//                     printf("supervisor");
//                     found = 1;
//                     break;
//                 }
//                 if(over==1)
//                     break;

                
//                 nowSearchingBossID2 = -1;
//             }

//             if(found) continue;

//             if(nowSearching == nowSearching2)printf("colleague");
//             else printf("unrelated");

//         }
//     }



// }

// #define max(x,y) ((x>y)?x:y;)