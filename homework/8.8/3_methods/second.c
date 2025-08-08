#include <stdio.h>

int main(void)
{
    char array[8];
    float *f1 = (float *) array;
    float *f2 = (float *) (array + sizeof(float));
    *f1 = 7.2;
    *f2 = 8.4;
    printf("*f1, *f2, f1: %f, f2: %f\n", *f1, *f2);
    printf("*array, *(array + sizeof(float)), f1: %f, f2: %f\n", 
        *array, *(array + sizeof(float)));
    printf("*((float *) (array + sizeof(float))), f1: %f, f2: %f\n", 
        *((float *) array), *((float *) (array + sizeof(float))));
    return 0;
    
}