#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct My_stack
{
    uint8_t size;
    void *top;
    void *bottom;
    void *start;
} *Stack;

Stack stack_init(Stack stack, uint8_t size);
void push(Stack stack, void *value, uint8_t size);
void pop(Stack stack, void *value, uint8_t size);
bool is_full(Stack stack);
bool is_empty(Stack stack);
void free_stack(Stack *stack);