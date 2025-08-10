#include "../inc/pool.h"

MemoryPool* pool_create(int total_size)
{
    
}
int align(int used)
{
    return (used % ALIGN_SIZE == 0) ? used : used + ALIGN_SIZE;
}