#ifndef SIMPLE_ANGLES_H
#define SIMPLE_ANGLES_H
#include "common.h"
#include <math.h>

typedef float Radian;
typedef double Radian_d;
typedef float Degree;
typedef double Degree_d;



SM_INLINE Degree RadianToDegree(Radian r) {
    return (r/SM_2_PI) * 360.0f;
}

SM_INLINE Degree RadianToDegree_d(Radian_d r) {
    return (r/SM_2_PI) * 360.0;
}

SM_INLINE Radian DegreeToRadian(Degree d) {
    return (d/360.0f) * SM_2_PI;
}

SM_INLINE Radian DegreeToRadian_d(Degree_d d) {
    return (d/360.0) * SM_2_PI;
}





#endif
