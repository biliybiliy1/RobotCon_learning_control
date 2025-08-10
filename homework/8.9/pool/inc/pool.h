#pragma once

#define ALIGN_SIZE 8
#define BlOCK_SIZE 64

typedef struct 
{
    void *start;
    int total_size;
    int block_size;
    int block_count;
    char *bitmap;
} MemoryPool;

MemoryPool* pool_create(int total_size);
int align(int used);