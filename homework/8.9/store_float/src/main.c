#include "../inc/store_float.h"
#include <stdio.h>

int main(void)
{
    char array[4];
    float num1 = 59.622f; float num2 = 92.6327f;
    store_float(array, &num1, &num2);
    float new_num1 = 0; float new_num2 = 0;
    read_float(array, &new_num1, &new_num2);
    printf("before, num1: %f, num2: %f\n", num1, num2);
    printf("after, new_num1: %f, new_num2: %f\n", new_num1, new_num2);
}