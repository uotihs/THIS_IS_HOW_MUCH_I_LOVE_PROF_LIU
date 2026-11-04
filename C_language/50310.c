#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int start;
    int end;
    int pplCount;
    int day;
} Course;

typedef struct{
    int cap;
} Classroom;


int cmp(const void* p1,const void* p2)
{
    const Course* c1 = (Course*)p1;
    const Course* c2 = (Course*)p2;

    if(c1->end > c2->end)
    {
        return 1;
    }
    else if(c1->end < c2->end)
    {
        return -1;
    }
    return 0;

}

void solve(int start,int n,int m,Classroom classR[n],Course courses[m],int nums,int* num,int count,int* TimeCount,int selected[m],int ans[m],int counts[n],int ansCounts[n],int remain)
{
    if(start == m)
    {
        if(count >= (*TimeCount) )
        {
            if(count == (*TimeCount))
            {
                int better = 0;
                for(int i=0;i<n;i++)
                {
                    if(ansCounts[i]!=counts[i])
                    {
                        better = ansCounts[i] < counts[i];
                        break;
                    }
                }


                if(!better) return;
            }
            

            for(int i=0;i<m;i++)
            {
                ans[i]=selected[i];
            }
            for(int i=0;i<n;i++)
            {
                ansCounts[i] = counts[i];
            }
            (*TimeCount) = count;

            (*num) = nums;


        }
        return;
    }

    if(count+remain < (*TimeCount)) return;

    for(int i=0;i<n;i++)
    {
        if(courses[start].pplCount > classR[i].cap)
        {continue;}

        int wrong = 0;

        for(int a=start-1;a>=0;a--)
        {
            if(selected[a] != i+100*courses[start].day)
            {continue;}

            if(courses[start].start <= courses[a].end)
            {
                wrong = 1;
                break;
            }
            break;
        }

        if(wrong)
        {
            continue;
        }

        selected[start] = i+100*courses[start].day;
        counts[i]++;
        solve(start+1,n,m,classR,courses,nums+1,num,count+1+(courses[start].end - courses[start].start),TimeCount,selected,ans,counts,ansCounts,remain-(1+(courses[start].end - courses[start].start)));
        selected[start] = -1;
        counts[i]--;
    }

    solve(start+1,n,m,classR,courses,nums,num,count,TimeCount,selected,ans,counts,ansCounts,remain-(1+(courses[start].end - courses[start].start)));
}



int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    Course courses[m];
    Classroom classR[n];
    
    int selected[m];
    int ans[m];
    int counts[n];
    int ansCounts[n];
    for(int i=0;i<n;i++)
    {
        counts[i]=0;
        ansCounts[i]=0;
        scanf("%d",&(classR[i].cap));
    }

    for(int i=0;i<m;i++)
    {
        selected[i]=-1;
        ans[i] = -1;
        int tp1,tp2,tp3,tp4;
        scanf("%d%d%d%d",&tp1,&tp2,&tp3,&tp4);

        courses[i].start = tp1*60+tp2;
        courses[i].end = tp3*60+tp4;
        scanf("%d%d",&(courses[i].pplCount),&(courses[i].day));
    }

    qsort(courses, m, sizeof(Course), cmp);

    int totalTime = 0;
    int totalNum = 0;
    int totalCounts[n];

    for(int i = 0; i < n; i++)
    {
        totalCounts[i] = 0;
    }

    for(int d = 0; d < m; d++)
    {
        int seen = 0;

        for(int j = 0; j < d; j++)
        {
            if(courses[j].day == courses[d].day)
            {
                seen = 1;
                break;
            }
        }

        if(seen) continue;

        Course today[m];
        int todayM = 0;
        int remain = 0;

        for(int j = 0; j < m; j++)
        {
            if(courses[j].day == courses[d].day)
            {
                today[todayM++] = courses[j];
                remain += courses[j].end - courses[j].start + 1;
            }
        }

        int TimeCount = 0;
        int num = 0;

        for(int i = 0; i < todayM; i++)
        {
            selected[i] = -1;
            ans[i] = -1;
        }

        for(int i = 0; i < n; i++)
        {
            counts[i] = 0;
            ansCounts[i] = 0;
        }

        solve(0,n,todayM,classR,today,0,&num,0,&TimeCount,selected, ans, counts, ansCounts, remain);

        totalTime += TimeCount;
        totalNum += num;

        for(int i = 0; i < n; i++)
        {
            totalCounts[i] += ansCounts[i];
        }
    }

    printf("%d\n%d\n", totalTime, totalNum);

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", totalCounts[i]);
    }

    return 0;
}
    // qsort(courses,m,sizeof(Course),cmp);

    // int TimeCount = 0;
    // int num = 0;
    
    // int remain = 0;
    // for(int i = 0 ; i<m;i++)
    // {
    //     remain += 1+(courses[i].end - courses[i].start);
    // }
    
    
    // solve(0,n,m,classR,courses,0,&num,0,&TimeCount,selected,ans,counts,ansCounts,remain);

    // printf("%d\n%d",TimeCount,num);

    // int countqs[n];
    // for(int i=0;i<n;i++)
    // {
    //     countqs[i]=0;
    //     // printf("%d",countqs[i]);
    // }

    // for(int i=0;i<m;i++)
    // {
    //     if(ans[i]!=-1) countqs[ans[i]%100]+=1;
    //     // printf("|%d|",ans[i]%100);
    //     // printf("%d ",ans[i]);   
    // }

    // for(int i=0;i<n;i++)
    // {
    //     printf("\n%d",ansCounts[i]);
    // }
    // return 0;
// }