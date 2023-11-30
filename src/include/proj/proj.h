#ifndef MATH_PROJ_H
#define MATH_PROJ_H 
#include "../linAlg/mat4x4.h"
#include "../trig/tan.h"
#include "../trig/types.h"
#include <error.h>


//utility functions

static inline ErrorCode mat4_translate(mat4x4_float* m, vec3float t) {
    m->val[0][3] += t.val[0];
    m->val[1][3] += t.val[1];
    m->val[2][3] += t.val[2];

    return NoError;
}

static inline ErrorCode mat4_scale(mat4x4_float* m, float s) {
    m->val[0][0] *= s;
    m->val[1][1] *= s;
    m->val[2][2] *= s;

    return NoError;
}

static inline ErrorCode mat4_rotate(mat4x4_float* m, vec3float axis, radians a) {
//Not supported at the moment
//Plan to implement rotors for efficient rotations in the future
    return NoError;
}




//rendering constructors


static inline ErrorCode mat4_PerspectiveMatrix(mat4x4_float* m, float near, float far, radians fov, float aspect){ 
    float tanfov = tan_r((radians){fov.val/2.0f});
    float nearfardiff = far-near;

    m->val[0][0] = 1.0f/(aspect * tanfov); 
    m->val[1][1] = 1.0f/tanfov;
    m->val[2][2] = -(far+near)/nearfardiff;
    m->val[3][2] = -1;
    m->val[2][3] = -(2*far*near)/nearfardiff;

    return NoError;
}

static inline ErrorCode mat4_OrthoMatrix() {
    return NoError;
}

static inline ErrorCode mat4_ViewMatrix() {
    return NoError;
}

static inline ErrorCode mat4_CameraMatrix() {
    return NoError;
}





#endif
