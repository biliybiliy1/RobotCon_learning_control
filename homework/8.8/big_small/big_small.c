#include "big_small.h"

void local_order(unsigned int number)
{
    char array[4];
    unsigned int *num = &number;
    for (int i = 0; i < 4; i++)
    {
        array[i] = ((char *) num)[i];
    }
    printf("the signed number in local order is : %i\n", *((int *) array));
}

void small(unsigned int number)
{
    char array[4];
    unsigned int tmp = 0x000000FF; // 别写成0x00000011了，这个是16进制不是二进制
    for (int i = 0; i < 4; i++)
    {
        array[i] = (char) ((number & tmp) >> (8 * i));
        tmp <<= 8;
    }
    printf("the signed number in small end is :   %i\n", *((int *) array));
}

void big(unsigned int number)
{
    char array[4];
    unsigned int tmp = 0xff000000;
    for (int i = 0; i < 4; i++)
    {
        array[i] = (char) ((number & tmp) >> (8 * (3 - i)));
        tmp >>= 8;
    }
    printf("the signed number in big end is :     %i\n", *((int *) array));
}