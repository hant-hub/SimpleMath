#ifndef MATH_TRIG_TYPES_H
#define MATH_TRIG_TYPES_H

typedef struct radians { float val; } radians;
typedef struct degrees { float val; } degrees;

const static float pi = 3.141592;


static inline radians normalize_r(radians theta) {
    float x = theta.val;

    float sub = x/(2*pi);

    float whole = (long int)sub;
    float frac = sub - whole;

    return (radians){frac*2*pi};
}

static inline degrees normalize_d(degrees theta) {
    return (degrees){0};
}



#endif
