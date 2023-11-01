#ifndef MATH_TRIG_TYPES_H
#define MATH_TRIG_TYPES_H
#include "../complex/cfloat.h"

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


static inline radians DegreestoRadians(degrees theta) {
    static const float ratio = 1.0f/360.0f;
    float x = theta.val;
    x *= ratio;
    x *= 2*pi;
    return (radians){x};
}

static inline degrees RadianstoDegrees(radians theta) {
    static const float ratio = 1.0f/(2*pi);
    float x = theta.val;
    x *= ratio;
    x *= 360;
    return (degrees){x};
}


// Precomputed powers of i
static const cfloat ipowerTable[] = {
    {1, 0},
    {0.707106781, 0.707106781},    // 1/2
    {0.9238795325, 0.3826834324},  // 1/4
    {0.9807852804, 0.1950903220},  // 1/8
    {0.9951847267, 0.0980171403},  // 1/16
    {0.9987954562, 0.0490676743},  // 1/32
    {0.9996988187, 0.0245412285},  // 1/64
    {0.9999247018, 0.0122715383},  // 1/128
    {0.9999811753, 0.0061358846},  // 1/256
    {0.9999952938, 0.0030679568},  // 1/512
    {0.9999988235, 0.0015339802}   // 1/1024
};


#endif
