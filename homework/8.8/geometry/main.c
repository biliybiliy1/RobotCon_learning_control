#include "mathlib.h"
#include <stdio.h>

int main(void)
{
    
    vector3f AB; AB.x = 0; AB.y = 1; AB.z = 0;
    vector3f A; A.x = 1; A.y = 0; A.z = 1;
    vector3f E; E.x = 1; E.y = 0.5; E.z = 0;
    vector3f C1; C1.x = 0; C1.y = 1; C1.z = 0;   
    vector3f AC1; AC1.x = -1; AC1.y = 1; AC1.z = -1;

    vector3f tmp = cross_prod(&AC1, &AB);
    float distance1 = fabs(modulo(&tmp)) / modulo(&AC1);
    printf("distance from point B to line AC1 is: %f\n", distance1);

    vector3f normal_AEC1 = normal(&A, &E, &C1);
    vector3f AF = scale(&AB, 0.5);
    float distance2 = fabs(dot_prod(&AF, &normal_AEC1)) / modulo(&normal_AEC1);
    printf("distance from line FC to surface AEC1 is: %f\n", distance2);

}