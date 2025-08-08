#include "big_small.h"

int main(void)
{
    int number = 0x12253647;
    local_order(number);
    small(number);
    big(number);
}