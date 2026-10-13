#include<stdio.h>
#include<string.h>

typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
}Employee;

int main()
{
    int nums;
    int length=0;
    Employee company[32]={0};
    scanf("%d",&nums);

    for(int i=0;i<nums;i++)
    {
        scanf("%d",&(company[i].id));

        scanf("%s",(company[i].first_name));   

        scanf("%s",(company[i].last_name));   

        scanf("%d",&(company[i].boss_id));

    }

    int testcases;
    scanf("%d",&testcases);

    for(int i=0;i<testcases;i++)
    {
        if(i!=0) putchar('\n');
        char names[2][2][33];
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                scanf("%s",names[j][k]);
            }
        }
        int employee1Index;
        int employee2Index;

        for(int i=0;i<nums;i++)
        {
            if(strcmp(names[0][0],company[i].first_name)==0 && strcmp(names[0][1],company[i].last_name)==0)
            {
                employee1Index = i;
            }
            if(strcmp(names[1][0],company[i].first_name)==0 && strcmp(names[1][1],company[i].last_name)==0)
            {
                employee2Index = i;
            }
        }

        
        if(company[employee1Index].id == company[employee2Index].boss_id)
        {
            printf("supervisor");
        }
        else if(company[employee1Index].boss_id == company[employee2Index].id)
        {
            printf("subordinate");
        }
        else if(company[employee1Index].boss_id == company[employee2Index].boss_id)
        {
            printf("colleague");
        }
        else
        {   
            int found = 0;
            int nowSearching = company[employee1Index].boss_id;
            int nowSearchingBossID = -1;
            while (nowSearching != nowSearchingBossID)
            {
                int over = 0;
                for(int i=0;i<nums;i++)
                {
                    if(company[i].id == nowSearching)
                    {
                        nowSearchingBossID = company[i].boss_id;
                        if(company[i].id == company[i].boss_id)
                            over=1;
                        break;
                    }
                }
                nowSearching = nowSearchingBossID;

                if(nowSearchingBossID == company[employee2Index].id)
                {

                    printf("subordinate");
                    found = 1;
                    break;
                }
                if(over==1)
                    break;

                
                nowSearchingBossID = -1;
            }
            

            if(found) continue;
            
            int nowSearching2 = company[employee2Index].boss_id;
            int nowSearchingBossID2 = -1;
            while (nowSearching2 != nowSearchingBossID2)
            {
                int over = 0;
                for(int i=0;i<nums;i++)
                {
                    if(company[i].id == nowSearching2)
                    {
                        nowSearchingBossID2 = company[i].boss_id;
                        if(company[i].id == company[i].boss_id)
                            over=1;
                        break;
                    }
                }
                nowSearching2 = nowSearchingBossID2;

                if(nowSearchingBossID2 == company[employee1Index].id)
                {
                    printf("supervisor");
                    found = 1;
                    break;
                }
                if(over==1)
                    break;

                
                nowSearchingBossID2 = -1;
            }

            if(found) continue;

            if(nowSearching == nowSearching2)printf("colleague");
            else printf("unrelated");

        }
    }



}