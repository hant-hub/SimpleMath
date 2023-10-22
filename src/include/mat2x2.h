#ifndef MATH_MAT2_H
#define MATH_MAT2_H
#include "types.h"
#include "error.h"
#include "vec2.h"

def_mat(float, 2, 2);

/** 
 *
 * @brief Tests if two mat2x2 are equivalent
 * @param a A 2x2 matrix with floating point entries
 * @param b A 2x2 matrix with floating point entries
 *
 * @return Boolean representing whether the two matricies are equivalent.
 * */
static inline int mat2x2_float_eq(mat2x2_float* a, mat2x2_float* b) {
    return (a->val[0][0] == b->val[0][0]) &&
           (a->val[1][0] == b->val[1][0]) &&
           (a->val[0][1] == b->val[0][1]) &&
           (a->val[1][1] == b->val[1][1]);
}

/** 
 *
 * @brief Sums two matricies
 * @param a A 2x2 matrix with floating point entries
 * @param b A 2x2 matrix with floating point entries
 *
 * @return 2x2 matrix with final matrix
 * */
static inline mat2x2_float mat2x2add(mat2x2_float* a, mat2x2_float* b) {
    return (mat2x2_float){{ 
        {a->val[0][0] + b->val[0][0], a->val[0][1] + b->val[0][1]},
        {a->val[1][0] + b->val[1][0], a->val[1][1] + b->val[1][1]}
    }};
}


/** 
 * @brief Calculates the Determinant of a Matrix
 *
 * @param a A 2x2 matrix with floating point entries
 * @return Returns a float with the determinant
 * */
static inline float mat2x2det(mat2x2_float* m) {
    return (m->val[0][0] * m->val[1][1]) -
        (m->val[1][0] * m->val[0][1]);
}

/** 
 *
 * @brief Applies Matrix A to B
 * @param a A 2x2 matrix with floating point entries
 * @param b A 2x2 matrix with floating point entries
 *
 * @return Returns the composition of A and B
 *
 * */
static inline mat2x2_float mat2x2comp(mat2x2_float* a, mat2x2_float* b) {
    return (mat2x2_float){{
        {a->val[0][0] * b->val[0][0] + a->val[0][1] * b->val[1][0],
        a->val[0][0] * b->val[0][1] + a->val[0][1] * b->val[1][1]},
        {a->val[1][0] * b->val[0][0] + a->val[1][1] * b->val[1][0],
        a->val[1][0] * b->val[0][1] + a->val[1][1] * b->val[1][1]}
    }};
}


/** 
 *
 * @brief Applies Matrix A to vector
 *
 * @param m A 2x2 Matrix
 * @param v A 2 component Vector
 *
 * @return A 2 component Vector with A applied.
 * */
static inline vec2float mat2x2app(mat2x2_float* m, vec2float* v) {
    return (vec2float){
    {
    (v->val[0] * m->val[0][0]) + (v->val[1] * m->val[0][1]),
    (v->val[0] * m->val[1][0]) + (v->val[1] * m->val[1][1])
    }};
}






#endif
