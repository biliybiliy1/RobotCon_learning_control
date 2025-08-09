#include "../inc/store_float.h"

void store_float(char array[], float *num1, float *num2)
{
    int head1 = (int) *num1; array[0] = head1;
    float tail = *num1 - head1;
    int i_tail = tail_to_int(tail); array[1] = i_tail;

    int head2 = (int) *num2; array[2] = head2;
    tail = *num2 - head2;
    i_tail = tail_to_int(tail); array[3] = i_tail;
}
void read_float(char array[], float *new_num1, float *new_num2)
{
    *new_num1 = array[0] + int_to_tail(array[1]);
    *new_num2 = array[2] + int_to_tail(array[3]);
}
int tail_to_int(float tail)
{
    int result =  (int) (tail * 255 + 0.5f);
    if (result > 255) result = 255;
    if (result < 0) result = 0;
    return result;
}
float int_to_tail(int i_tail)
{
    return (float) ((unsigned char) i_tail / 255.0);
}