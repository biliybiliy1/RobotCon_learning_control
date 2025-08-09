#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


typedef struct MParam
{
    uint8_t row;
    uint8_t column;
    float **data;
} *Matrix;
Matrix nm_init(Matrix matrix);
Matrix memory_init(Matrix matrix);
Matrix init_matrix(Matrix matrix);
void assign_matrix(Matrix matrix);
void print_matrix(Matrix matrix);
Matrix transposed(Matrix matrix);
Matrix product(Matrix left, Matrix right);
void free_matrix(Matrix matrix);