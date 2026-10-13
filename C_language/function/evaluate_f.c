#include"evaluate_f.h"

int evaluate_f(int *iptr[], int n, int *index)
{
    int max = 4 * (iptr[0][0]) - 6 * (iptr[0][1]), Mindex = 0;
    

    for(int i = 1;i<n;i++)
    {
        int new = 4 * iptr[i][0] - 6 * iptr[i][1];
        if(new > max)
        {
            Mindex = i;
            max = new;
        }
    }

    *index = Mindex;
    return max;

}