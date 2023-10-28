#ifndef MATH_TAN_H
#define MATH_TAN_H
#include "types.h"
#include "cos.h"
#include "sin.h"

static inline float tan_r(radians theta) {
    return sin_r(theta)/cos_r(theta);
}


static inline float tan_d(degrees theta) {
    return sin_d(theta)/cos_d(theta);
}


#endif
