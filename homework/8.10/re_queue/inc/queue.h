#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct My_queue
{
    int size;
    int store;
    char *front;
    char *rear;
    char *memory;
} *Queue;

Queue queue_init(Queue queue, int size);
void enqueue(Queue queue, char value);
char dequeue(Queue queue);
int is_empty(Queue queue);
int is_full(Queue queue);
void free_queue(Queue *queue);