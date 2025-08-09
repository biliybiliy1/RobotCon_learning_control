#include "../inc/qsort.h"
#include <stdio.h>

int main(void)
{
    Node *node = NULL;
    float value = 0;
    int flag = 0;
    do 
    {
        printf("input any other than float will stop input\n");
        flag = scanf("%f", &value); 
        if (flag == 1)
        {
            store(&node, value);
        }
    } while(flag);

    float array[sum(node)];
    int i = 0; Node *read = node;
    while (read != NULL)
    {
        array[i] = read->value;
        read = read->next;
        i++;
    }

    qsort(array, sum(node), sizeof(float), compare_ase);
    for (int j = 0; j < sum(node); j++)
    {
        printf("%f ", array[j]);
    }
}