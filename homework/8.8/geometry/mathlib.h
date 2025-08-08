#pragma once

#include <math.h>

typedef struct
{
    float x;
    float y;
    float z;
} vector3f;

vector3f vec_add(vector3f *vector1, vector3f *vector2);
vector3f vec_sub(vector3f *vector1, vector3f *vector2);
float dot_prod(vector3f *vector1, vector3f *vector2);
vector3f standardization(vector3f *vector);
float modulo(vector3f *vector);
vector3f cross_prod(vector3f *vector1, vector3f *vector2);
vector3f scale(vector3f *vector, float factor);
vector3f normal(vector3f *vector1, vector3f *vector2, vector3f *vector3);