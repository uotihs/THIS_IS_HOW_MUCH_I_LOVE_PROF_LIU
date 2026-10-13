#include"prepare_array.h"

void prepare_array(int buffer[], int *array[], int row, int column[]){

    //buffer length = 10000;
    int now = 0;
    for(int i = 0 ; i < row ; i++)
    {
        array[i] = &(buffer[now]);

        now += column[i];
    }
}