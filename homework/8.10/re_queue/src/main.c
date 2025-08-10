#include "../inc/queue.h"

#define QUEUE_SIZE 5

int main(void)
{
    Queue queue = NULL; queue = queue_init(queue, QUEUE_SIZE);
    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    enqueue(queue, 'd');
    enqueue(queue, 'e');
    enqueue(queue, 'f');
    enqueue(queue, 'j');
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    enqueue(queue, 'k');
    enqueue(queue, 'l');
    enqueue(queue, 'm');
    enqueue(queue, 'n');
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    printf("dequeue: %c\n", dequeue(queue));
    free(queue);
}