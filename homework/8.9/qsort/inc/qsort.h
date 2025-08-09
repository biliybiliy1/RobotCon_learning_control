#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    float value;
    struct node *next;
} Node;

void store(Node **node, float value);
int sum(Node *node);
int compare_ase(const void *a1, const void *a2);