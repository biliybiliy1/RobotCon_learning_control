#include "../inc/stack.h"

#define STACK_SIZE 40

int main(void)
{
    Stack stack = NULL;
    stack = stack_init(stack, STACK_SIZE);
    printf("push value into stack\n");
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            float in = (float) i;
            push(stack, &in, sizeof(float));
        }
        else push(stack, &i, sizeof(int));
    }
    printf("pop value from stack\n");
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0) // 最后一个压入的是整数9，故先取出整数，别搞反了（就因为搞反了卡我好久，我一直以为代码错了）
        {
            int value = 0; pop(stack, &value, sizeof(int));
            printf("out: %i\n", value);
        }
        else 
        {
            float value = 0; 
            pop(stack, &value, sizeof(float));
            printf("out: %f\n", value);
        }
    }
    free_stack(&stack);
}