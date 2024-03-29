
#ifndef MATH_MAT4_H
#define MATH_MAT4_H
#include "types.h"
#include "vec4.h"
#include "mat3x3.h"

def_mat(float, 4, 4);


const static mat4x4_float mat4x4_float_identity = {{ 
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
}};


/** 
 *
 * @brief Tests if two mat4x4 are equivalent
 * @param a A 4x4 matrix with floating point entries
 * @param b A 4x4 matrix with floating point entries
 *
 * @return Boolean representing whether the two matricies are equivalent.
 * */
static inline const int mat4x4_float_eq(mat4x4_float* a, mat4x4_float* b) {
    return (a->val[0][0] == b->val[0][0]) &&
           (a->val[1][0] == b->val[1][0]) &&
           (a->val[2][0] == b->val[2][0]) &&
           (a->val[3][0] == b->val[3][0]) &&
           (a->val[0][1] == b->val[0][1]) &&
           (a->val[1][1] == b->val[1][1]) &&
           (a->val[2][1] == b->val[2][1]) &&
           (a->val[3][1] == b->val[3][1]) &&
           (a->val[0][2] == b->val[0][2]) &&
           (a->val[1][2] == b->val[1][2]) &&
           (a->val[2][2] == b->val[2][2]) &&
           (a->val[3][2] == b->val[3][2]) &&
           (a->val[0][3] == b->val[0][3]) &&
           (a->val[1][3] == b->val[1][3]) &&
           (a->val[2][3] == b->val[2][3]) &&
           (a->val[3][3] == b->val[3][3]);
}

/** 
 *
 * @brief Sums two matricies
 * @param a A 4x4 matrix with floating point entries
 * @param b A 4x4 matrix with floating point entries
 *
 * @return 4x4 matrix with final matrix
 * */
static inline const mat4x4_float mat4x4add(mat4x4_float* a, mat4x4_float* b) {
    return (mat4x4_float){{ 
        {a->val[0][0] + b->val[0][0], a->val[0][1] + b->val[0][1], a->val[0][2] + b->val[0][2], a->val[0][3] + b->val[0][3]},
        {a->val[1][0] + b->val[1][0], a->val[1][1] + b->val[1][1], a->val[1][2] + b->val[1][2], a->val[1][3] + b->val[1][3]},
        {a->val[2][0] + b->val[2][0], a->val[2][1] + b->val[2][1], a->val[2][2] + b->val[2][2], a->val[2][3] + b->val[2][3]},
        {a->val[3][0] + b->val[3][0], a->val[3][1] + b->val[3][1], a->val[3][2] + b->val[3][2], a->val[3][3] + b->val[3][3]}
    }};
}


/** 
 * @brief Calculates the Determinant of a Matrix
 *
 * @param a A 4x4 matrix with floating point entries
 * @return Returns a float with the determinant
 * */
static inline const float mat4x4det(mat4x4_float* m) {
    mat3x3_float a = {{
        {m->val[1][1], m->val[1][2], m->val[1][3]},
        {m->val[2][1], m->val[2][2], m->val[2][3]},
        {m->val[3][1], m->val[3][2], m->val[3][3]}
    }};
    mat3x3_float b = {{
        {m->val[1][0], m->val[1][2], m->val[1][3]},
        {m->val[2][0], m->val[2][2], m->val[2][3]},
        {m->val[3][0], m->val[3][2], m->val[3][3]}
    }};
    mat3x3_float c = {{
        {m->val[1][0], m->val[1][1], m->val[1][3]},
        {m->val[2][0], m->val[2][1], m->val[2][3]},
        {m->val[3][0], m->val[3][1], m->val[3][3]}
    }};
    mat3x3_float d = {{
        {m->val[1][0], m->val[1][1], m->val[1][2]},
        {m->val[2][0], m->val[2][1], m->val[2][2]},
        {m->val[3][0], m->val[3][1], m->val[3][2]}
    }};

    return (m->val[0][0]*mat3x3det(&a)) - (m->val[0][1]*mat3x3det(&b)) + (m->val[0][2]*mat3x3det(&c)) - (m->val[0][3]*mat3x3det(&d));
}


/** 
 * @brief Calculates vector Matrix multiply
 * @param m Matrix to be Multiplied
 * @param v Vector to be Multiplied
 * @return Vector which has been transformed.
 * */
static inline const vec4float mat4x4app(mat4x4_float* m, vec4float* v) {
    return (vec4float){{
        v->val[0] * m->val[0][0] + v->val[1] * m->val[0][1] + v->val[2] * m->val[0][2] + v->val[3] * m->val[0][3],
        v->val[0] * m->val[1][0] + v->val[1] * m->val[1][1] + v->val[2] * m->val[1][2] + v->val[3] * m->val[1][3],
        v->val[0] * m->val[2][0] + v->val[1] * m->val[2][1] + v->val[2] * m->val[2][2] + v->val[3] * m->val[2][3],
        v->val[0] * m->val[3][0] + v->val[1] * m->val[3][1] + v->val[2] * m->val[3][2] + v->val[3] * m->val[3][3]
    }};
}


/** 
 *
 * @brief Applies Matrix A to B
 * @param a A 4x4 matrix with floating point entries
 * @param b A 4x4 matrix with floating point entries
 *
 * @return Returns the composition of A and B
 *
 * */
static inline const mat4x4_float mat4x4comp(mat4x4_float* a, mat4x4_float* b) {
    vec4float col1 = (vec4float){b->val[0][0], b->val[1][0], b->val[2][0], b->val[3][0]};    
    vec4float col2 = (vec4float){b->val[0][1], b->val[1][1], b->val[2][1], b->val[3][1]};    
    vec4float col3 = (vec4float){b->val[0][2], b->val[1][2], b->val[2][2], b->val[3][2]};    
    vec4float col4 = (vec4float){b->val[0][3], b->val[1][3], b->val[2][3], b->val[3][3]};    

    vec4float t1 = mat4x4app(a, &col1); 
    vec4float t2 = mat4x4app(a, &col2); 
    vec4float t3 = mat4x4app(a, &col3); 
    vec4float t4 = mat4x4app(a, &col4); 

    return (mat4x4_float) {{
        {t1.val[0], t2.val[0], t3.val[0], t4.val[0]},
        {t1.val[1], t2.val[1], t3.val[1], t4.val[1]},
        {t1.val[2], t2.val[2], t3.val[2], t4.val[2]},
        {t1.val[3], t2.val[3], t3.val[3], t4.val[3]}
    }};

}


// Elementary Row Operations

/** 
 * @brief Scales a matrix Row
 * @param m Matrix to be modified
 * @param s floating point scalar
 * @param row Index of row to be scaled
 *
 * */
static inline void mat4x4RowMult(mat4x4_float* m, float s, int row) {
    m->val[row][0] *= s;  
    m->val[row][1] *= s;
    m->val[row][2] *= s;
    m->val[row][3] *= s;
}

/** 
 * @brief Swap two rows in a matrix
 * @param m Matrix to be modified
 * @param row1 First Index of matrix
 * @param row2 Second Index of matrix
 *
 * */
static inline void mat4x4RowSwap(mat4x4_float* m, int row1, int row2) {
    float temp[4] = {m->val[row1][0], m->val[row1][1], m->val[row1][2], m->val[row1][3]};

    m->val[row1][0] = m->val[row2][0];
    m->val[row1][1] = m->val[row2][1];
    m->val[row1][2] = m->val[row2][2];
    m->val[row1][3] = m->val[row2][3];

    m->val[row2][0] = temp[0];
    m->val[row2][1] = temp[1];
    m->val[row2][2] = temp[2];
    m->val[row2][3] = temp[3];
}

/** 
 * @brief Replace Row with sum of Itself and another row
 * @param m Matrix to be modified
 * @param src Row that won't be modified
 * @param dest Row to be modified
 * @param s Scalar which is multiplied with src row before addition
 * */
static inline void mat4x4RowAdd(mat4x4_float* m, int src, int dest, float s) {
    m->val[dest][0] += m->val[src][0] * s;
    m->val[dest][1] += m->val[src][1] * s;
    m->val[dest][2] += m->val[src][2] * s;
    m->val[dest][3] += m->val[src][3] * s;
}



#endif
