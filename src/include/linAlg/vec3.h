#ifndef MATH_VEC3_H
#define MATH_VEC3_H
#include "types.h"

def_vector(float, 3);


/** 
 *
 * @brief Determine Whether two vec3float are equivalent.
 *
 * @param{vec3float} a Three component Floating point vector.
 * @param{vec3float} b Three component Floating point vector.
 *
 * @return Returns a boolean which evaluates whether two vectors are equivalent.
 * */
static inline int vec3float_eq(vec3float a, vec3float b) {
    return ((a.val[0] == b.val[0]) && 
            (a.val[1] == b.val[1]) &&
            (a.val[2] == b.val[2]));
}



/**
 * 
 * @brief Take the dot product of three vectors.
 * @param{vec3float} a Three component Floating point vector.
 * @param{vec3float} b Three component Floating point vector.
 *
 *
 * @return Returns the float result of dot product.
 *
 */
static inline const float vec3dot(vec3float a, vec3float b) {
    return a.val[0] * b.val[0] + 
           a.val[1] * b.val[1] +
           a.val[2] * b.val[2];
}

/**
 * @brief Do a Component-wise multiplication.
 * @param{vec3float} a Three component Floating point vector.
 * @param{vec3float} b Three component Floating point vector.
 *
 * @return Returns a vector containing the component wise multiplication.
 * */
static inline const vec3float vec3mult(vec3float a, vec3float b) {
    return (vec3float){a.val[0]*b.val[0], 
                       a.val[1]*b.val[1],
                       a.val[2]*b.val[2]};
}

/**
 *
 * @brief Add vectors component wise.
 *
 * @param a Three component Floating point vector.
 * @param b Three component Floating point vector.
 *
 * @return Returns a vector containing the component wise addition.
 * */
static inline const vec3float vec3add(vec3float a, vec3float b) {
    return (vec3float){a.val[0]+b.val[0],
                       a.val[1]+b.val[1],
                       a.val[2]+b.val[2]};
}

/**
 *
 * @brief Right Handed Cross Product
 *
 * @param a Three component Floating point vector.
 * @param b Three component Floating point vector.
 *
 * @return Returns a vector which is the right handed cross product of a and b.
 *
 *
 * */
static inline const vec3float vec3cross(vec3float a, vec3float b) {
    float first = (a.val[1] * b.val[2]) - (a.val[2] * b.val[1]);
    float second = (a.val[0] * b.val[2]) - (a.val[2] * b.val[0]);
    float third = (a.val[0] * b.val[1]) - (a.val[1] * b.val[0]);
    
    return (vec3float){first, -second, third};
}


#endif