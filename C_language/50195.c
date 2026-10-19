#include<stdio.h>

int main()
{
    int oneMax[3] = {__INT32_MAX__+1,-1,0},oneMax2[3] = {__INT32_MAX__+1,-1,0};
    int twoMax[3] = {__INT32_MAX__+1,-1,0},twoMax2[3] = {__INT32_MAX__+1,-1,0};
    int threeMax[3] = {__INT32_MAX__+1,-1,0},threeMax2[3] = {__INT32_MAX__+1,-1,0};

    int lastone = -1,lasttwo = -1, lastthree = -1;
    int one_not_ready = 3,two_not_ready = 3,three_not_ready = 3;

    int in;
    int index = 0;
    while(scanf("%d",&in)!=EOF)
    {
        int newdis;
        switch (in)
        {
            case 1:
                /* code */
                newdis = index - lastone;
                
                if(newdis > oneMax[0] && lastone!=-1)
                {
                    for(int i =0;i<3;i++)
                    {
                        oneMax2[i] = oneMax[i];
                    }

                    oneMax[0] = newdis;
                    oneMax[1] = lastone;
                    oneMax[2] = index;

                    one_not_ready --;
                }
                else
                {
                    if(newdis < oneMax[0] && newdis >= oneMax2[0] && lastone!=-1)
                    {
                        oneMax2[0] = newdis;
                        oneMax2[1] = lastone;
                        oneMax2[2] = index;
                    }
                }


                lastone = index;

                break;


            case 2:


                newdis = index - lasttwo;
                
                if(newdis > twoMax[0]  && lasttwo!=-1)
                {
                    for(int i =0;i<3;i++)
                    {
                        twoMax2[i] = twoMax[i];
                    }

                    twoMax[0] = newdis;
                    twoMax[1] = lasttwo;
                    twoMax[2] = index;

                    two_not_ready--;
                }
                else
                {
                    if(newdis < twoMax[0] && newdis >= twoMax2[0]  && lasttwo!=-1)
                    {
                        twoMax2[0] = newdis;
                        twoMax2[1] = lasttwo;
                        twoMax2[2] = index;
                    }
                }


                lasttwo = index;


                /* code */
                break;


            case 3:


                newdis = index - lastthree;
                
                if(newdis > threeMax[0] && lastthree!=-1)
                {
                    for(int i =0;i<3;i++)
                    {
                        threeMax2[i] = threeMax[i];
                    }

                    threeMax[0] = newdis;
                    threeMax[1] = lastthree;
                    threeMax[2] = index;
                }
                else 
                {
                    if(newdis < threeMax[0] && newdis >= threeMax2[0] && lastthree!=-1)
                    {
                        threeMax2[0] = newdis;
                        threeMax2[1] = lastthree;
                        threeMax2[2] = index;
                    }
                }


                lastthree = index;



                /* code */
                break;
        }



        index++;
    }

    // if(oneMax[0] == oneMax2[0])
    // printf("%d %d %d\n",oneMax[0],oneMax[1],oneMax[2]);
    // else
    printf("%d %d %d\n",oneMax2[0],oneMax2[1],oneMax2[2]);

    // if(twoMax[0] == twoMax2[0])
    // printf("%d %d %d\n",twoMax[0],twoMax[1],twoMax[2]);
    // else
    printf("%d %d %d\n",twoMax2[0],twoMax2[1],twoMax2[2]);

    // if(threeMax[0] == threeMax2[0])
    // printf("%d %d %d\n",threeMax[0],threeMax[1],threeMax[2]);
    // else
    printf("%d %d %d\n",threeMax2[0],threeMax2[1],threeMax2[2]);



    return 0;
}