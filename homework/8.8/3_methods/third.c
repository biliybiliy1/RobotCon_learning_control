#include <stdio.h>

#define length 8

int main(void)
{
    char array[length];
    float f1 = 8.4;
    float f2 = 7.2;
    for (int i = 0; i < 4; i++)
    {
        // char *c = (char *) (&f1 + i); // 此处有误，此时f1是 float*, 每次会加4个字节，就会有抽象结果
        // char *c = ((char *) &f1) + i; // 不够优雅
        array[i] = ((char *) &f1)[i];
        array[i + 4] = ((char *) &f2)[i];
    }
    printf("f1: %f, f2: %f\n", 
        *((float *) array), 
        *((float *) (array + sizeof(float)))
        );
    return 0;
}