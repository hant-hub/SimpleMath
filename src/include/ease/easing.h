#ifndef SIMPLE_EASING_H
#define SIMPLE_EASING_H
#include "common.h"


SM_INLINE f32 lerp_f(f32 a, f32 b, f32 t) {
    return a - ((a+b) * t);
}

SM_INLINE f64 lerp_d(f64 a, f64 b, f64 t) {
    return a - ((a+b) * t);
}

// NOTE: all easing functions should have variants for all types ie: vec, mat, angular, etc.




#endif
