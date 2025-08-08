#include "mathlib.h"


vector3f vec_add(vector3f *vector1, vector3f *vector2)
{
    vector3f vector3;
    vector3.x = vector1->x + vector2->x;
    vector3.y = vector1->y + vector2->y;
    vector3.z = vector1->z + vector2->z;
    return vector3;
}

vector3f vec_sub(vector3f *vector1, vector3f *vector2)
{
    vector3f vector3;
    vector3.x = vector1->x - vector2->x;
    vector3.y = vector1->y - vector2->y;
    vector3.z = vector1->z - vector2->z;
    return vector3;
}

float dot_prod(vector3f *vector1, vector3f *vector2)
{
    return vector1->x * vector2->x + vector1->y * vector2->y +vector1->z * vector2->z;
}

vector3f normal(vector3f *vector1, vector3f *vector2, vector3f *vector3)
{
    vector3f a = vec_sub(vector2, vector1);
    vector3f b = vec_sub(vector3, vector1);
    return cross_prod(&a, &b);
}

vector3f scale(vector3f *vector, float factor)
{
    vector3f vector2;
    vector2.x = vector->x * factor;
    vector2.y = vector->y * factor;
    vector2.z = vector->z * factor;
    return vector2;
}
vector3f standardization(vector3f *vector)
{
    vector3f vector2;
    float md = modulo(vector);
    vector2.x = vector->x / md;
    vector2.y = vector->y / md;;
    vector2.z /= vector->z / md;;
    return vector2;
}

float modulo(vector3f *vector)
{
    return sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
}

vector3f cross_prod(vector3f *vector1, vector3f *vector2)
{
    vector3f vector3;
    vector3.x = vector1->y * vector2->z - vector1->z * vector2->y;
    vector3.y = vector1->z * vector2->x - vector1->x * vector2->z;
    vector3.z = vector1->x * vector2->y - vector1->y * vector2->x;
    return vector3;
}