#include<stdio.h>

int main()
{
    int mini=__INT32_MAX__;
    int hour,min,sec;
    scanf("%2d",&hour);
    scanf("%2d",&min);
    scanf("%2d",&sec);

    int h2,m2,s2;
    while (scanf("%2d%2d%2d",&h2,&m2,&s2)!=EOF)
    {
        int newmin = (h2-hour)*3600+(m2-min)*60+s2-sec;
        if(newmin < 0) newmin = -newmin;
        if(newmin < mini) mini = newmin;
        
        hour=h2;min=m2;sec =s2;
    }

    printf("%d",mini);
    
    


    return 0;
}