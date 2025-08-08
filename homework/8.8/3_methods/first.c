#include <stdio.h>
#include <string.h>

int main(void)
{
    float f1 = 8.4;
    float f2 = 7.2;
    char array[8];
    memcpy(array, &f1, sizeof(float));
    memcpy(array + sizeof(float), &f2, sizeof(float));
    float c1;
    float c2;
    memcpy(&c1, array, sizeof(float));
    memcpy(&c2, array + sizeof(float), sizeof(float));
    printf("before, f1: %f, f2: %f\n", f1, f2);
    printf("after, c1: %f, c2: %f\n", c1, c2);
    return 0;
}