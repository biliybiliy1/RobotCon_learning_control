#include "../inc/queue.h"

Queue queue_init(Queue queue, int size)
{
    queue = (queue == NULL) ? malloc(sizeof(struct My_queue)) : queue;
    if (queue == NULL) {printf("the memory has been full\n"); return NULL;}
    queue->size = size;
    queue->memory = malloc(size);
    if (queue->memory == NULL) {free(queue); printf("the memory has been full\n"); return NULL;}
    queue->front = queue->rear = queue->memory;
    queue->store = 0;
    return queue;
}
void enqueue(Queue queue, char value)
{
    if (is_full(queue)) return;
    queue->rear = (queue->rear - queue->memory + 1) % queue->size + queue->memory;
    *queue->rear = value;
    queue->store++;
}
char dequeue(Queue queue)
{
    if (is_empty(queue)) return '\0';
    queue->front = (queue->front - queue->memory + 1) % queue->size + queue->memory;
    char value = *queue->front;
    queue->store--;
    return value;
}

int is_empty(Queue queue)
{
    return (queue->store == 0);
}
int is_full(Queue queue)
{
    return (queue->store == queue->size);
}

void free_queue(Queue *queue)
{
    if (queue == NULL || *queue == NULL) return;
    if ((*queue)->memory != NULL)
    {
        free((*queue)->memory);
        (*queue)->memory = NULL;
    }
    free(*queue);
    *queue = NULL;
}