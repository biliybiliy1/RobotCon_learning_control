#include "../inc/qsort.h"

void store(Node **node, float value)
{
    Node *tmp = malloc(sizeof(Node));
    if (tmp == NULL)
    {
        printf("failed to allocate memory\n");
        return;
    }
    tmp->value = value;
    tmp->next = *node;
    *node = tmp;
}
int sum(Node *node)
{
    int sum = 0;
    while (node != NULL)
    {
        node = node->next;
        sum++;
    }
    return sum;
}
int compare_ase(const void *a1, const void *a2)
{
    const float *f1 = (const float *) a1;
    const float *f2 = (const float *) a2;

    if (*f1 > *f2) return 1;
    else if (*f1 < *f2) return -1;
    else return 0;
}