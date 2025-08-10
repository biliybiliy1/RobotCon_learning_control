#include "../inc/stack.h"

Stack stack_init(Stack stack, uint8_t size)
{
    stack = (stack == NULL) ? malloc(sizeof(struct My_stack)) : stack;
    if (stack == NULL) {printf("fail to allocate memory\n"); return NULL;}
    stack->size = size;
    stack->start = malloc(size);
    stack->bottom = stack->top = stack->start + size;
    return stack;
}

void push(Stack stack, void *value, uint8_t size)
{
    if (is_full(stack)) {printf("the stack has been full\n");}
    if (stack->bottom - stack->top + size > stack->size) {printf("the stack can't store %i bytes\n", (int) size); return;}
    stack->top -= size;
    memcpy(stack->top, value, size);
}

void pop(Stack stack, void *value, uint8_t size)
{
    if (is_empty(stack)) {printf("the stack is empty\n"); return;}
    if (stack->top + size > stack->bottom) {printf("the stack can't read %i bytes\n", (int) size); return;}
    memcpy(value, stack->top, size);
    stack->top += size;
}

bool is_full(Stack stack)
{
    return (stack->top + stack->size <= stack->bottom);
}
bool is_empty(Stack stack)
{
    return (stack->bottom == stack->top);
}
void free_stack(Stack *stack)
{
    if (stack == NULL || *stack == NULL) return; // 如果啥都没有就释放
    if ((*stack)->start != NULL) // 先释放*stack所指结构体指向的栈内存
    {
        free((*stack)->start);
        (*stack)->start = NULL; // 把*stack所指结构体内部start设NULL，防止悬空
    }
    free(*stack); // 释放结构体
    *stack = NULL; // 防止悬空
}