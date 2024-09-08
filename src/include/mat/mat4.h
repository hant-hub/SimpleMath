#ifndef SIMPLE_MAT_4_H
#define SIMPLE_MAT_4_H
#include "stdio.h"
#include "common.h"
#include "angles.h"
#include "vec4.h"
#include "vec3.h"


/**
 * \defgroup sm_mat4
 * @brief 4x4 Matrix
 *
 * 4x4 Matrix stored in
 * column major format.
 * Array type -> works like pass by reference
 * @{
 */
typedef struct {
   sm_vec4i a; /** 4 component 32bit integer column**/  
   sm_vec4i b; /** 4 component 32bit integer column**/ 
   sm_vec4i c; /** 4 component 32bit integer column**/ 
   sm_vec4i d; /** 4 component 32bit integer column**/ 
} sm_mat4i;

typedef struct {
   sm_vec4l a; /** 4 component 64bit integer column**/ 
   sm_vec4l b; /** 4 component 64bit integer column**/ 
   sm_vec4l c; /** 4 component 64bit integer column**/ 
   sm_vec4l d; /** 4 component 64bit integer column**/ 
} sm_mat4l;

typedef struct {
   sm_vec4f a; /** 4 component 32bit float column**/ 
   sm_vec4f b; /** 4 component 32bit float column**/ 
   sm_vec4f c; /** 4 component 32bit float column**/ 
   sm_vec4f d; /** 4 component 32bit float column**/ 
} sm_mat4f;

typedef struct {
   sm_vec4d a; /** 4 component 64bit float column**/ 
   sm_vec4d b; /** 4 component 64bit float column**/
   sm_vec4d c; /** 4 component 64bit float column**/
   sm_vec4d d; /** 4 component 64bit float column**/
} sm_mat4d;
/** @} */


/**
 * \defgroup sm_mat4_print
 * @param stream FILE* to output stream. ex: stdout, stderr, etc.
 * @param m mat4 to be printed
 *
 * prints values of mat4 to
 * stream. Can be directed to file etc.
 *
 * @{
 */
SM_INLINE void sm_mat4_i32_print(FILE* stream, sm_mat4i* m) {
    fprintf(stream, "%d\t%d\t%d\t%d\n"
                    "%d\t%d\t%d\t%d\n"
                    "%d\t%d\t%d\t%d\n"
                    "%d\t%d\t%d\t%d\n",
                    m->a.x, m->b.x, m->c.x, m->d.x,
                    m->a.y, m->b.y, m->c.y, m->d.y,
                    m->a.z, m->b.z, m->c.z, m->d.z,
                    m->a.w, m->b.w, m->c.w, m->d.w);
}

SM_INLINE void sm_mat4_i64_print(FILE* stream, sm_mat4l* m) {
    fprintf(stream, "%ld\t%ld\t%ld\t%ld\n"
                    "%ld\t%ld\t%ld\t%ld\n"
                    "%ld\t%ld\t%ld\t%ld\n"
                    "%ld\t%ld\t%ld\t%ld\n",
                    m->a.x, m->b.x, m->c.x, m->d.x,
                    m->a.y, m->b.y, m->c.y, m->d.y,
                    m->a.z, m->b.z, m->c.z, m->d.z,
                    m->a.w, m->b.w, m->c.w, m->d.w);
}

SM_INLINE void sm_mat4_f32_print(FILE* stream, sm_mat4f* m) {
    fprintf(stream, "%f\t%f\t%f\t%f\n"
                    "%f\t%f\t%f\t%f\n"
                    "%f\t%f\t%f\t%f\n"
                    "%f\t%f\t%f\t%f\n",
                    m->a.x, m->b.x, m->c.x, m->d.x,
                    m->a.y, m->b.y, m->c.y, m->d.y,
                    m->a.z, m->b.z, m->c.z, m->d.z,
                    m->a.w, m->b.w, m->c.w, m->d.w);
}

SM_INLINE void sm_mat4_f64_print(FILE* stream, sm_mat4d* m) {
    fprintf(stream, "%f\t%f\t%f\t%f\n"
                    "%f\t%f\t%f\t%f\n"
                    "%f\t%f\t%f\t%f\n"
                    "%f\t%f\t%f\t%f\n",
                    m->a.x, m->b.x, m->c.x, m->d.x,
                    m->a.y, m->b.y, m->c.y, m->d.y,
                    m->a.z, m->b.z, m->c.z, m->d.z,
                    m->a.w, m->b.w, m->c.w, m->d.w);
}
/** @} **/






/**
 * \defgroup sm_mat4_identity
 * @brief Matrix initialization
 * 
 * Macros for initializing Matricies
 *
 *
 * @{
 */
/** @brief 32 bit Integer**/

#define SM_MAT4_IDENTITY \
{ \
    {1, 0, 0, 0}, \
    {0, 1, 0, 0}, \
    {0, 0, 1, 0}, \
    {0, 0, 0, 1}, \
}

static const sm_mat4i sm_mat4i_identity = SM_MAT4_IDENTITY;
static const sm_mat4l sm_mat4l_identity = SM_MAT4_IDENTITY;
static const sm_mat4f sm_mat4f_identity = SM_MAT4_IDENTITY;
static const sm_mat4d sm_mat4d_identity = SM_MAT4_IDENTITY;

/** @} **/


/** 
 * \defgroup sm_mat4_diag
 * @brief Initializes diagonal matricies
 * @param s vec4
 * @retval mat4 with s along all diagonal entries
 * @{
 */

SM_INLINE sm_mat4i sm_mat4_i32_diag(const sm_vec4i s) {
    return (sm_mat4i) {
        {s.x, 0, 0, 0},
        {0, s.y, 0, 0},
        {0, 0, s.z, 0},
        {0, 0, 0, s.w},
    };
}
SM_INLINE sm_mat4l sm_mat4_i64_diag(const sm_vec4l s) {
    return (sm_mat4l) {
        {s.x, 0, 0, 0},
        {0, s.y, 0, 0},
        {0, 0, s.z, 0},
        {0, 0, 0, s.w},
    };
}
SM_INLINE sm_mat4f sm_mat4_f32_diag(const sm_vec4f s) {
    return (sm_mat4f) {
        {s.x, 0, 0, 0},
        {0, s.y, 0, 0},
        {0, 0, s.z, 0},
        {0, 0, 0, s.w},
    };
}
SM_INLINE sm_mat4d sm_mat4_f64_diag(const sm_vec4d s) {
    return (sm_mat4d) {
        {s.x, 0, 0, 0},
        {0, s.y, 0, 0},
        {0, 0, s.z, 0},
        {0, 0, 0, s.w},
    };
}

 
/** @} **/


/**
 * \defgroup sm_mat4_add
 * @brief Matrix Component Adds
 * @param a mat4
 * @param b mat4
 * @retval mat4 which is the component wise addition
 *
 * a and b must be distinct
 * if you want to add a matrix
 * to itself do not use this function
 *
 * @{
 */
/** @brief 32 Bit Integer **/
SM_INLINE sm_mat4i sm_mat4_i32_add(const sm_mat4i* restrict a, const sm_mat4i* restrict b) {
    return (sm_mat4i){
            sm_vec4_i32_add(a->a, b->a),
            sm_vec4_i32_add(a->b, b->b),
            sm_vec4_i32_add(a->c, b->c),
            sm_vec4_i32_add(a->d, b->d)
    };
}

/** @brief 64 Bit Integer **/
SM_INLINE sm_mat4l sm_mat4_i64_add(const sm_mat4l* restrict a, const sm_mat4l* restrict b) {
    return (sm_mat4l){
            sm_vec4_i64_add(a->a, b->a),
            sm_vec4_i64_add(a->b, b->b),
            sm_vec4_i64_add(a->c, b->c),
            sm_vec4_i64_add(a->d, b->d)
    };
}

/** @brief 32 Bit Float **/
SM_INLINE sm_mat4f sm_mat4_f32_add(const sm_mat4f* restrict a, const sm_mat4f* restrict b) {
    return (sm_mat4f){
            sm_vec4_f32_add(a->a, b->a),
            sm_vec4_f32_add(a->b, b->b),
            sm_vec4_f32_add(a->c, b->c),
            sm_vec4_f32_add(a->d, b->d)
    };
}

/** @brief 64 Bit Float **/
SM_INLINE sm_mat4d sm_mat4_f64_add(const sm_mat4d* restrict a, const sm_mat4d* restrict b) {
    return (sm_mat4d){
            sm_vec4_f64_add(a->a, b->a),
            sm_vec4_f64_add(a->b, b->b),
            sm_vec4_f64_add(a->c, b->c),
            sm_vec4_f64_add(a->d, b->d)
    };
}
/** @} */




/**
 * \defgroup sm_mat4_sub
 * @brief Matrix Component Subs
 * @param a mat4
 * @param b mat4
 * @retval mat4 output from a Component wise subtraction
 * @{
 */
/** @brief 32 Bit Integer **/
SM_INLINE sm_mat4i sm_mat4_i32_sub(const sm_mat4i* restrict a, const sm_mat4i* restrict b) {
    return (sm_mat4i){
            sm_vec4_i32_sub(a->a, b->a),
            sm_vec4_i32_sub(a->b, b->b),
            sm_vec4_i32_sub(a->c, b->c),
            sm_vec4_i32_sub(a->d, b->d)
    };
}

/** @brief 64 Bit Integer **/
SM_INLINE sm_mat4l sm_mat4_i64_sub(const sm_mat4l* restrict a, const sm_mat4l* restrict b) {
    return (sm_mat4l){
            sm_vec4_i64_sub(a->a, b->a),
            sm_vec4_i64_sub(a->b, b->b),
            sm_vec4_i64_sub(a->c, b->c),
            sm_vec4_i64_sub(a->d, b->d)
    };
}

/** @brief 32 Bit Float **/
SM_INLINE sm_mat4f sm_mat4_f32_sub(const sm_mat4f* restrict a, const sm_mat4f* restrict b) {
    return (sm_mat4f){
            sm_vec4_f32_sub(a->a, b->a),
            sm_vec4_f32_sub(a->b, b->b),
            sm_vec4_f32_sub(a->c, b->c),
            sm_vec4_f32_sub(a->d, b->d)
    };
}

/** @brief 64 Bit Float **/
SM_INLINE sm_mat4d sm_mat4_f64_sub(const sm_mat4d* restrict a, const sm_mat4d* restrict b) {
    return (sm_mat4d){
            sm_vec4_f64_sub(a->a, b->a),
            sm_vec4_f64_sub(a->b, b->b),
            sm_vec4_f64_sub(a->c, b->c),
            sm_vec4_f64_sub(a->d, b->d)
    };
}
/** @} **/


/**
 * \defgroup sm_mat4_transpose
 * @brief Matrix Component transposes
 * @param a mat4
 * @retval Transpose of the matrix
 * @{
 */
/** @brief 32 bit Integer **/
SM_INLINE sm_mat4i sm_mat4_i32_transpose(const sm_mat4i* a) {
    return (sm_mat4i){
            { a->a.x, a->b.x, a->c.x, a->d.x },
            { a->a.y, a->b.y, a->c.y, a->d.y },
            { a->a.z, a->b.z, a->c.z, a->d.z },
            { a->a.w, a->b.w, a->c.w, a->d.w }
    };
}

/** @brief 64 bit Integer **/
SM_INLINE sm_mat4l sm_mat4_i64_transpose(const sm_mat4l* a) {
    return (sm_mat4l){
            { a->a.x, a->b.x, a->c.x, a->d.x },
            { a->a.y, a->b.y, a->c.y, a->d.y },
            { a->a.z, a->b.z, a->c.z, a->d.z },
            { a->a.w, a->b.w, a->c.w, a->d.w },
    };
}

/** @brief 32 bit float **/
SM_INLINE sm_mat4f sm_mat4_f32_transpose(const sm_mat4f* a) {
    return (sm_mat4f){
            { a->a.x, a->b.x, a->c.x, a->d.x },
            { a->a.y, a->b.y, a->c.y, a->d.y },
            { a->a.z, a->b.z, a->c.z, a->d.z },
            { a->a.w, a->b.w, a->c.w, a->d.w }
    };
}

/** @brief 64 bit float **/
SM_INLINE sm_mat4d sm_mat4_f64_transpose(const sm_mat4d* a) {
    return (sm_mat4d){
            { a->a.x, a->b.x, a->c.x, a->d.x },
            { a->a.y, a->b.y, a->c.y, a->d.y },
            { a->a.z, a->b.z, a->c.z, a->d.z },
            { a->a.w, a->b.w, a->c.w, a->d.w },
    };
}
/** @} **/


/**
 * \defgroup sm_mat4_comp
 * @brief Matrix composition
 * @param a mat4
 * @param b mat4
 * @retval Composition of the matrix
 * @{
 */

/** @brief 32 Bit Integer **/
SM_INLINE sm_mat4i sm_mat4_i32_comp(const sm_mat4i* restrict a, const sm_mat4i* restrict b) {
    sm_mat4i transpose = sm_mat4_i32_transpose(a);
    return (sm_mat4i){
            { sm_vec4_i32_dot(transpose.a, b->a), sm_vec4_i32_dot(transpose.b, b->a), sm_vec4_i32_dot(transpose.c, b->a), sm_vec4_i32_dot(transpose.d, b->a) },
            { sm_vec4_i32_dot(transpose.a, b->b), sm_vec4_i32_dot(transpose.b, b->b), sm_vec4_i32_dot(transpose.c, b->b), sm_vec4_i32_dot(transpose.d, b->b) },
            { sm_vec4_i32_dot(transpose.a, b->c), sm_vec4_i32_dot(transpose.b, b->c), sm_vec4_i32_dot(transpose.c, b->c), sm_vec4_i32_dot(transpose.d, b->c) },
            { sm_vec4_i32_dot(transpose.a, b->d), sm_vec4_i32_dot(transpose.b, b->d), sm_vec4_i32_dot(transpose.c, b->d), sm_vec4_i32_dot(transpose.d, b->d) },
    };

}

/** @brief 64 Bit Integer **/
SM_INLINE sm_mat4l sm_mat4_i64_comp(const sm_mat4l* restrict a, const sm_mat4l* restrict b) {
    sm_mat4l transpose = sm_mat4_i64_transpose(a);
    return (sm_mat4l){
            { sm_vec4_i64_dot(transpose.a, b->a), sm_vec4_i64_dot(transpose.b, b->a), sm_vec4_i64_dot(transpose.c, b->a), sm_vec4_i64_dot(transpose.d, b->a) },
            { sm_vec4_i64_dot(transpose.a, b->b), sm_vec4_i64_dot(transpose.b, b->b), sm_vec4_i64_dot(transpose.c, b->b), sm_vec4_i64_dot(transpose.d, b->b) },
            { sm_vec4_i64_dot(transpose.a, b->c), sm_vec4_i64_dot(transpose.b, b->c), sm_vec4_i64_dot(transpose.c, b->c), sm_vec4_i64_dot(transpose.d, b->c) },
            { sm_vec4_i64_dot(transpose.a, b->d), sm_vec4_i64_dot(transpose.b, b->d), sm_vec4_i64_dot(transpose.c, b->d), sm_vec4_i64_dot(transpose.d, b->d) },
    };

}

/** @brief 32 Bit Float **/
SM_INLINE sm_mat4f sm_mat4_f32_comp(const sm_mat4f* restrict a, const sm_mat4f* restrict b) {
    sm_mat4f transpose = sm_mat4_f32_transpose(a);
    return (sm_mat4f){
            { sm_vec4_f32_dot(transpose.a, b->a), sm_vec4_f32_dot(transpose.b, b->a), sm_vec4_f32_dot(transpose.c, b->a), sm_vec4_f32_dot(transpose.d, b->a) },
            { sm_vec4_f32_dot(transpose.a, b->b), sm_vec4_f32_dot(transpose.b, b->b), sm_vec4_f32_dot(transpose.c, b->b), sm_vec4_f32_dot(transpose.d, b->b) },
            { sm_vec4_f32_dot(transpose.a, b->c), sm_vec4_f32_dot(transpose.b, b->c), sm_vec4_f32_dot(transpose.c, b->c), sm_vec4_f32_dot(transpose.d, b->c) },
            { sm_vec4_f32_dot(transpose.a, b->d), sm_vec4_f32_dot(transpose.b, b->d), sm_vec4_f32_dot(transpose.c, b->d), sm_vec4_f32_dot(transpose.d, b->d) },
    };

}

/** @brief 64 Bit Float **/
SM_INLINE sm_mat4d sm_mat4_f64_comp(const sm_mat4d* restrict a, const sm_mat4d* restrict b) {
    sm_mat4d transpose = sm_mat4_f64_transpose(a);
    return (sm_mat4d){
            { sm_vec4_f64_dot(transpose.a, b->a), sm_vec4_f64_dot(transpose.b, b->a), sm_vec4_f64_dot(transpose.c, b->a), sm_vec4_f64_dot(transpose.d, b->a) },
            { sm_vec4_f64_dot(transpose.a, b->b), sm_vec4_f64_dot(transpose.b, b->b), sm_vec4_f64_dot(transpose.c, b->b), sm_vec4_f64_dot(transpose.d, b->b) },
            { sm_vec4_f64_dot(transpose.a, b->c), sm_vec4_f64_dot(transpose.b, b->c), sm_vec4_f64_dot(transpose.c, b->c), sm_vec4_f64_dot(transpose.d, b->c) },
            { sm_vec4_f64_dot(transpose.a, b->d), sm_vec4_f64_dot(transpose.b, b->d), sm_vec4_f64_dot(transpose.c, b->d), sm_vec4_f64_dot(transpose.d, b->d) },
    };
}
/** @} **/




// Rendering Functions -----------------------


/**
 * \defgroup sm_mat4_translate
 * @brief Matrix translation
 * @param m mat4
 * @param delta translation in 3d space  
 * @retval matrix with translation multiplied on the left
 * @{
 */
/** @brief 32 Bit Integer **/
SM_INLINE sm_mat4i sm_mat4_i32_translate(const sm_mat4i* m, const sm_vec3i delta) {
    sm_mat4i transform = SM_MAT4_IDENTITY;
    transform.d = (sm_vec4i){delta.x, delta.y, delta.z, 1};
    return sm_mat4_i32_comp(&transform, m);
}

/** @brief 64 Bit Integer **/
SM_INLINE sm_mat4l sm_mat4_i64_translate(const sm_mat4l* m, const sm_vec3l delta) {
    sm_mat4l transform = SM_MAT4_IDENTITY;
    transform.d = (sm_vec4l){delta.x, delta.y, delta.z, 1};
    return sm_mat4_i64_comp(&transform, m);
}

/** @brief 32 Bit Float **/
SM_INLINE sm_mat4f sm_mat4_f32_translate(const sm_mat4f* m, const sm_vec3f delta) {
    sm_mat4f transform = SM_MAT4_IDENTITY;
    transform.d = (sm_vec4f){delta.x, delta.y, delta.z, 1};
    return sm_mat4_f32_comp(&transform, m);
}

/** @brief 64 Bit Float **/
SM_INLINE sm_mat4d sm_mat4_f64_translate(const sm_mat4d* m, const sm_vec3d delta) {
    sm_mat4d transform = SM_MAT4_IDENTITY;
    transform.d = (sm_vec4d){delta.x, delta.y, delta.z, 1};
    return sm_mat4_f64_comp(&transform, m);
}
/** @} **/



/**
 * \defgroup sm_mat4_scale
 * @brief Matrix scale
 * @param m mat4
 * @param scale vec3
 * @retval mat4 applies scaling in 3d space and returns the result
 * @{
 */
/* 32-bit Integer */
SM_INLINE sm_mat4i sm_mat4_i32_scale(const sm_mat4i* m, const sm_vec4i scale) {
    sm_mat4i transform = {
        { scale.x, 0, 0, 0 },
        { 0, scale.y, 0, 0 },
        { 0, 0, scale.z, 0 },
        { 0, 0, 0, scale.w}
    };
    return sm_mat4_i32_comp(&transform, m);
}

/* 64-bit Integer */
SM_INLINE sm_mat4l sm_mat4_i64_scale(const sm_mat4l* m, const sm_vec4l scale) {
    sm_mat4l transform = {
        { scale.x, 0, 0, 0 },
        { 0, scale.y, 0, 0 },
        { 0, 0, scale.z, 0 },
        { 0, 0, 0, scale.w }
    };
    return sm_mat4_i64_comp(&transform, m);
}

/* 32-bit Float */
SM_INLINE sm_mat4f sm_mat4_f32_scale(const sm_mat4f* m, const sm_vec4f scale) {
    sm_mat4f transform = {
        { scale.x, 0, 0, 0 },
        { 0, scale.y, 0, 0 },
        { 0, 0, scale.z, 0 },
        { 0, 0, 0, scale.w }
    };
    return sm_mat4_f32_comp(&transform, m);
}

/* 64-bit Float */
SM_INLINE sm_mat4d sm_mat4_f64_scale(const sm_mat4d* m, const sm_vec4d scale) {
    sm_mat4d transform = {
        { scale.x, 0, 0, 0 },
        { 0, scale.y, 0, 0 },
        { 0, 0, scale.z, 0 },
        { 0, 0, 0, scale.w }
    };
    return sm_mat4_f64_comp(&transform, m);
}
/** @} **/

/**
 * \defgroup sm_mat4_r
 * @brief Matrix rotate
 * @param m mat4
 * @param a angle in Radians
 * @retval rotates matrix and returns it
 * 
 * Specifies Euler rotation.
 * Can be combined like monads
 *
 * Not supported for integer matricies
 * (precision issues)
 *
 * @{
 */

SM_INLINE sm_mat4f sm_mat4_f32_rx(const sm_mat4f* m, const Radian a) {
    sm_mat4f transform = {
        { 1.0f, 0,       0,       0    },
        { 0,    cosf(a), sinf(a), 0    },
        { 0,   -sinf(a), cosf(a), 0    },
        { 0,    0,       0,       1.0f },
    };
    return sm_mat4_f32_comp(&transform, m);
}

SM_INLINE sm_mat4f sm_mat4_f32_ry(const sm_mat4f* m, const Radian a) {
    sm_mat4f transform = {
        { cosf(a), 0, -sinf(a), 0 },
        { 0, 1.0f, 0, 0 },
        { sinf(a), 0, cosf(a), 0 },
        { 0, 0, 0, 1.0f },
    };
    return sm_mat4_f32_comp(&transform, m);
}

SM_INLINE sm_mat4f sm_mat4_f32_rz(const sm_mat4f* m, const Radian a) {
    sm_mat4f transform = {
        { cosf(a), sinf(a), 0, 0 },
        { -sinf(a), cosf(a), 0, 0 },
        { 0, 0, 1.0f, 0 },
        { 0, 0, 0, 1.0f },
    };
    return sm_mat4_f32_comp(&transform, m);
}

SM_INLINE sm_mat4d sm_mat4_f64_rx(const sm_mat4d* m, const Radian a) {
    sm_mat4d transform = {
        { 1.0, 0, 0, 0 },
        { 0, cos(a), sin(a), 0 },
        { 0, -sin(a), cos(a), 0 },
        { 0, 0, 0, 1.0 },
    };
    return sm_mat4_f64_comp(&transform, m);
}

SM_INLINE sm_mat4d sm_mat4_f64_ry(const sm_mat4d* m, const Radian a) {
    sm_mat4d transform = {
        { cos(a), 0, -sin(a), 0 },
        { 0, 1.0, 0, 0 },
        { -sin(a), 0, cos(a), 0 },
        { 0, 0, 0, 1.0 },
    };
    return sm_mat4_f64_comp(&transform, m);
}

SM_INLINE sm_mat4d sm_mat4_f64_rz(const sm_mat4d* m, const Radian a) {
    sm_mat4d transform = {
        { cos(a), sin(a), 0, 0 },
        { -sin(a), cos(a), 0, 0 },
        { 0, 0, 1.0, 0 },
        { 0, 0, 0, 1.0 },
    };
    return sm_mat4_f64_comp(&transform, m);
}
/** @} **/


/**
 * \defgroup sm_mat4_perspective
 * @brief Perspective Projection Matrix
 * @param n near clipping plane along the z+ direction
 * @param f far clipping plane along the z+ direction
 * @param vfov angular size along the vertical axis
 * @param hfov angular size along the horizontal axis
 * @retval returns a projection matrix from camera space to clip space
 *
 * @{
 */
SM_INLINE sm_mat4i sm_mat4_i32_perspective(i32 n, i32 f, Radian vfov, Radian hfov){
    i32 hoffset = n*tanf(hfov)/2;
    i32 voffset = n*tanf(vfov)/2; 
    i32 dDiff = f - n;
    return (sm_mat4i){ 
            { 2*n, 0, 0, 0 },
            { 0, n/voffset, 0, 0 },
            { 0, 0, f/(dDiff), 1 },
            { 0, 0, -(n*f)/dDiff, 0 },
    };
}

SM_INLINE sm_mat4l sm_mat4_i64_perspective(i64 n, i64 f, Radian vfov, Radian hfov){
    i64 hoffset = n*tanf(hfov)/2;
    i64 voffset = n*tanf(vfov)/2; 
    i64 dDiff = f - n;
    
    return (sm_mat4l) {
            { 2*n, 0, 0, 0 },
            { 0, n/voffset, 0, 0 },
            { 0, 0, f/(dDiff), 1 },
            { 0, 0, -(n*f)/dDiff, 0 },
    };
}

SM_INLINE sm_mat4f sm_mat4_f32_perspective(f32 n, f32 f, Radian vfov, Radian hfov){
    f32 hoffset = n*tanf(hfov)/2;
    f32 voffset = n*tanf(vfov)/2; 
    f32 dDiff = f - n;
    return (sm_mat4f){
            { 2*n, 0, 0, 0 },
            { 0, n/voffset, 0, 0 },
            { 0, 0, f/(dDiff), 1 },
            { 0, 0, -(n*f)/dDiff, 0 },
    };
}

SM_INLINE sm_mat4d sm_mat4_f64_perspective(f64 n, f64 f, Radian_d vfov, Radian_d hfov){
    f64 hoffset = n*tan(hfov)/2;
    f64 voffset = n*tan(vfov)/2; 
    f64 dDiff = f - n;
    return (sm_mat4d){ 
            { 2*n, 0, 0, 0 },
            { 0, n/voffset, 0, 0 },
            { 0, 0, f/(dDiff), 1 },
            { 0, 0, -(n*f)/dDiff, 0 },
    };
}

/** @} **/

/**
 * \defgroup sm_mat4_ortho
 * @brief Orthographic Projection Matrix
 * @param n near clipping plane z+ direction
 * @param f far clipping plane z+ direction
 * @param l left clipping plane x- direction
 * @param r right clipping plane x+ direction
 * @param t top clipping plane y- direction
 * @param b bottom clipping plane y+ direction
 * @retval returns a projection matrix from camera to clip space
 *
 *
 * @{
 */

SM_INLINE sm_mat4i sm_mat4_i32_ortho(i32 n, i32 f, i32 l, i32 r, i32 t, i32 b) {
    i32 horizontal_span = r - l;
    i32 vertical_span = b - t;
    i32 depth_span = f - n;

    return (sm_mat4i){
            { 2.0/horizontal_span, 0, 0, 0 },
            { 0, 2/vertical_span, 0, 0 },
            { 0, 0, 1/depth_span, 0 },
            { -(r+l)/horizontal_span, -(b+t)/vertical_span, -(n)/depth_span, 1 },
    };
}

SM_INLINE sm_mat4l sm_mat4_i64_ortho(i64 n, i64 f, i64 l, i64 r, i64 t, i64 b) {
    i64 horizontal_span = r - l;
    i64 vertical_span = b - t;
    i64 depth_span = f - n;

    return (sm_mat4l){
            { 2.0/horizontal_span, 0, 0, 0 },
            { 0, 2/vertical_span, 0, 0 },
            { 0, 0, 1/depth_span, 0 },
            { -(r+l)/horizontal_span, -(b+t)/vertical_span, -(n)/depth_span, 1 },
    };
}

SM_INLINE sm_mat4f sm_mat4_f32_ortho(f32 n, f32 f, f32 l, f32 r, f32 t, f32 b) {
    f32 horizontal_span = r - l;
    f32 vertical_span = b - t;
    f32 depth_span = f - n;

    return (sm_mat4f){
            { 2.0f/horizontal_span, 0.0f, 0.0f, 0.0f },
            { 0.0f, 2.0f/vertical_span, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f/depth_span, 0.0f },
            { -(r+l)/horizontal_span, -(b+t)/vertical_span, -(n)/depth_span, 1.0f },
    };
}

SM_INLINE sm_mat4d sm_mat4_f64_ortho(f64 n, f64 f, f64 l, f64 r, f64 t, f64 b) {
    f64 horizontal_span = r - l;
    f64 vertical_span = b - t;
    f64 depth_span = f - n;

    return (sm_mat4d){
            { 2.0/horizontal_span, 0.0, 0.0, 0.0 },
            { 0.0, 2.0/vertical_span, 0.0, 0.0 },
            { 0.0, 0.0, 1.0/depth_span, 0.0 },
            { -(r+l)/horizontal_span, -(b+t)/vertical_span, -(n)/depth_span, 1.0 },
    };
}

/** @} **/

#endif
