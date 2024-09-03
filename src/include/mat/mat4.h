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
 * @param m mat4
 * @{
 */
/** @brief 32 bit Integer**/
SM_INLINE void sm_mat4_i32_identity(sm_mat4i* m) {
    *m = (sm_mat4i){
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
}

/** @brief 64 bit Integer**/
SM_INLINE void sm_mat4_i64_identity(sm_mat4l* m) {
    *m = (sm_mat4l){
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
}

/** @brief 32 bit Float**/
SM_INLINE void sm_mat4_f32_identity(sm_mat4f* m) {
    *m = (sm_mat4f){
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
}

/** @brief 64 bit Float**/
SM_INLINE void sm_mat4_f64_identity(sm_mat4d* m) {
    *m = (sm_mat4d){
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
}
/** @} **/


/**
 * \defgroup sm_mat4_add
 * @brief Matrix Component Adds
 * @param out mat4
 * @param a mat4
 * @param b mat4
 * @retval Component wise addition
 * @{
 */
/** @brief 32 Bit Integer **/
SM_INLINE void sm_mat4_i32_add(sm_mat4i* out, sm_mat4i* a, sm_mat4i* b) {
    out->a = sm_vec4_i32_add(a->a, b->a);
    out->b = sm_vec4_i32_add(a->b, b->b);
    out->c = sm_vec4_i32_add(a->c, b->c);
    out->d = sm_vec4_i32_add(a->d, b->d);
}

/** @brief 64 Bit Integer **/
SM_INLINE void sm_mat4_i64_add(sm_mat4l* out, sm_mat4l* a, sm_mat4l* b) {
    out->a = sm_vec4_i64_add(a->a, b->a);
    out->b = sm_vec4_i64_add(a->b, b->b);
    out->c = sm_vec4_i64_add(a->c, b->c);
    out->d = sm_vec4_i64_add(a->d, b->d);
}

/** @brief 32 Bit Float **/
SM_INLINE void sm_mat4_f32_add(sm_mat4f* out, sm_mat4f* a, sm_mat4f* b) {
    out->a = sm_vec4_f32_add(a->a, b->a);
    out->b = sm_vec4_f32_add(a->b, b->b);
    out->c = sm_vec4_f32_add(a->c, b->c);
    out->d = sm_vec4_f32_add(a->d, b->d);
}

/** @brief 64 Bit Float **/
SM_INLINE void sm_mat4_f64_add(sm_mat4d* out, sm_mat4d* a, sm_mat4d* b) {
    out->a = sm_vec4_f64_add(a->a, b->a);
    out->b = sm_vec4_f64_add(a->b, b->b);
    out->c = sm_vec4_f64_add(a->c, b->c);
    out->d = sm_vec4_f64_add(a->d, b->d);
}
/** @} */




/**
 * \defgroup sm_mat4_sub
 * @brief Matrix Component Subs
 * @param out mat4
 * @param a mat4
 * @param b mat4
 * @retval Component wise subtraction
 * @{
 */
/** @brief 32 Bit Integer **/
SM_INLINE void sm_mat4_i32_sub(sm_mat4i* out, sm_mat4i* a, sm_mat4i* b) {
    out->a = sm_vec4_i32_sub(a->a, b->a);
    out->b = sm_vec4_i32_sub(a->b, b->b);
    out->c = sm_vec4_i32_sub(a->c, b->c);
    out->d = sm_vec4_i32_sub(a->d, b->d);
}

/** @brief 64 Bit Integer **/
SM_INLINE void sm_mat4_i64_sub(sm_mat4l* out, sm_mat4l* a, sm_mat4l* b) {
    out->a = sm_vec4_i64_sub(a->a, b->a);
    out->b = sm_vec4_i64_sub(a->b, b->b);
    out->c = sm_vec4_i64_sub(a->c, b->c);
    out->d = sm_vec4_i64_sub(a->d, b->d);
}

/** @brief 32 Bit Float **/
SM_INLINE void sm_mat4_f32_sub(sm_mat4f* out, sm_mat4f* a, sm_mat4f* b) {
    out->a = sm_vec4_f32_sub(a->a, b->a);
    out->b = sm_vec4_f32_sub(a->b, b->b);
    out->c = sm_vec4_f32_sub(a->c, b->c);
    out->d = sm_vec4_f32_sub(a->d, b->d);
}

/** @brief 64 Bit Float **/
SM_INLINE void sm_mat4_f64_sub(sm_mat4d* out, sm_mat4d* a, sm_mat4d* b) {
    out->a = sm_vec4_f64_sub(a->a, b->a);
    out->b = sm_vec4_f64_sub(a->b, b->b);
    out->c = sm_vec4_f64_sub(a->c, b->c);
    out->d = sm_vec4_f64_sub(a->d, b->d);
}
/** @} **/


/**
 * \defgroup sm_mat4_transpose
 * @brief Matrix Component transposes
 * @param out mat4
 * @param a mat4
 * @retval Transpose of the matrix
 * @{
 */
/** @brief 32 bit Integer **/
SM_INLINE void sm_mat4_i32_transpose(sm_mat4i* out, sm_mat4i* a) {
    out->a = (sm_vec4i) {
        a->a.x,
        a->b.x,
        a->c.x,
        a->d.x
    };
    out->b = (sm_vec4i) {
        a->a.y,
        a->b.y,
        a->c.y,
        a->d.y
    };
    out->c = (sm_vec4i) {
        a->a.z,
        a->b.z,
        a->c.z,
        a->d.z
    };
    out->d = (sm_vec4i) {
        a->a.w,
        a->b.w,
        a->c.w,
        a->d.w
    };
}

/** @brief 64 bit Integer **/
SM_INLINE void sm_mat4_i64_transpose(sm_mat4l* out, sm_mat4l* a) {
    out->a = (sm_vec4l) {
        a->a.x,
        a->b.x,
        a->c.x,
        a->d.x
    };
    out->b = (sm_vec4l) {
        a->a.y,
        a->b.y,
        a->c.y,
        a->d.y
    };
    out->c = (sm_vec4l) {
        a->a.z,
        a->b.z,
        a->c.z,
        a->d.z
    };
    out->d = (sm_vec4l) {
        a->a.w,
        a->b.w,
        a->c.w,
        a->d.w
    };
}

/** @brief 32 bit float **/
SM_INLINE void sm_mat4_f32_transpose(sm_mat4f* out, sm_mat4f* a) {
    out->a = (sm_vec4f) {
        a->a.x,
        a->b.x,
        a->c.x,
        a->d.x
    };
    out->b = (sm_vec4f) {
        a->a.y,
        a->b.y,
        a->c.y,
        a->d.y
    };
    out->c = (sm_vec4f) {
        a->a.z,
        a->b.z,
        a->c.z,
        a->d.z
    };
    out->d = (sm_vec4f) {
        a->a.w,
        a->b.w,
        a->c.w,
        a->d.w
    };
}

/** @brief 64 bit float **/
SM_INLINE void sm_mat4_f64_transpose(sm_mat4d* out, sm_mat4d* a) {
    out->a = (sm_vec4d) {
        a->a.x,
        a->b.x,
        a->c.x,
        a->d.x
    };
    out->b = (sm_vec4d) {
        a->a.y,
        a->b.y,
        a->c.y,
        a->d.y
    };
    out->c = (sm_vec4d) {
        a->a.z,
        a->b.z,
        a->c.z,
        a->d.z
    };
    out->d = (sm_vec4d) {
        a->a.w,
        a->b.w,
        a->c.w,
        a->d.w
    };
}
/** @} **/


/**
 * \defgroup sm_mat4_comp
 * @brief Matrix composition
 * @param out mat4
 * @param a mat4
 * @param b mat4
 * @retval Composition of the matrix
 * @{
 */

/** @brief 32 Bit Integer **/
SM_INLINE void sm_mat4_i32_comp(sm_mat4i* out, sm_mat4i* a, sm_mat4i* b) {
    sm_mat4i transpose = {0};
    sm_mat4_i32_transpose(&transpose, a);
    out->a = (sm_vec4i) {
        sm_vec4_i32_dot(transpose.a, b->a),
        sm_vec4_i32_dot(transpose.b, b->a),
        sm_vec4_i32_dot(transpose.c, b->a),
        sm_vec4_i32_dot(transpose.d, b->a)
    };
    out->b = (sm_vec4i) {
        sm_vec4_i32_dot(transpose.a, b->b),
        sm_vec4_i32_dot(transpose.b, b->b),
        sm_vec4_i32_dot(transpose.c, b->b),
        sm_vec4_i32_dot(transpose.d, b->b)
    };
    out->c = (sm_vec4i) {
        sm_vec4_i32_dot(transpose.a, b->c),
        sm_vec4_i32_dot(transpose.b, b->c),
        sm_vec4_i32_dot(transpose.c, b->c),
        sm_vec4_i32_dot(transpose.d, b->c)
    };
    out->d = (sm_vec4i) {
        sm_vec4_i32_dot(transpose.a, b->d),
        sm_vec4_i32_dot(transpose.b, b->d),
        sm_vec4_i32_dot(transpose.c, b->d),
        sm_vec4_i32_dot(transpose.d, b->d)
    };

}

/** @brief 64 Bit Integer **/
SM_INLINE void sm_mat4_i64_comp(sm_mat4l* out, sm_mat4l* a, sm_mat4l* b) {
    sm_mat4l transpose = {0};
    sm_mat4_i64_transpose(&transpose, a);
    out->a = (sm_vec4l) {
        sm_vec4_i64_dot(transpose.a, b->a),
        sm_vec4_i64_dot(transpose.b, b->a),
        sm_vec4_i64_dot(transpose.c, b->a),
        sm_vec4_i64_dot(transpose.d, b->a)
    };
    out->b = (sm_vec4l) {
        sm_vec4_i64_dot(transpose.a, b->b),
        sm_vec4_i64_dot(transpose.b, b->b),
        sm_vec4_i64_dot(transpose.c, b->b),
        sm_vec4_i64_dot(transpose.d, b->b)
    };
    out->c = (sm_vec4l) {
        sm_vec4_i64_dot(transpose.a, b->c),
        sm_vec4_i64_dot(transpose.b, b->c),
        sm_vec4_i64_dot(transpose.c, b->c),
        sm_vec4_i64_dot(transpose.d, b->c)
    };
    out->d = (sm_vec4l) {
        sm_vec4_i64_dot(transpose.a, b->d),
        sm_vec4_i64_dot(transpose.b, b->d),
        sm_vec4_i64_dot(transpose.c, b->d),
        sm_vec4_i64_dot(transpose.d, b->d)
    };

}

/** @brief 32 Bit Float **/
SM_INLINE void sm_mat4_f32_comp(sm_mat4f* out, sm_mat4f* a, sm_mat4f* b) {
    sm_mat4f transpose = {0};
    sm_mat4_f32_transpose(&transpose, a);
    out->a = (sm_vec4f) {
        sm_vec4_f32_dot(transpose.a, b->a),
        sm_vec4_f32_dot(transpose.b, b->a),
        sm_vec4_f32_dot(transpose.c, b->a),
        sm_vec4_f32_dot(transpose.d, b->a)
    };
    out->b = (sm_vec4f) {
        sm_vec4_f32_dot(transpose.a, b->b),
        sm_vec4_f32_dot(transpose.b, b->b),
        sm_vec4_f32_dot(transpose.c, b->b),
        sm_vec4_f32_dot(transpose.d, b->b)
    };
    out->c = (sm_vec4f) {
        sm_vec4_f32_dot(transpose.a, b->c),
        sm_vec4_f32_dot(transpose.b, b->c),
        sm_vec4_f32_dot(transpose.c, b->c),
        sm_vec4_f32_dot(transpose.d, b->c)
    };
    out->d = (sm_vec4f) {
        sm_vec4_f32_dot(transpose.a, b->d),
        sm_vec4_f32_dot(transpose.b, b->d),
        sm_vec4_f32_dot(transpose.c, b->d),
        sm_vec4_f32_dot(transpose.d, b->d)
    };

}

/** @brief 64 Bit Float **/
SM_INLINE void sm_mat4_f64_comp(sm_mat4d* out, sm_mat4d* a, sm_mat4d* b) {
    sm_mat4d transpose = {0};
    sm_mat4_f64_transpose(&transpose, a);
    out->a = (sm_vec4d) {
        sm_vec4_f64_dot(transpose.a, b->a),
        sm_vec4_f64_dot(transpose.b, b->a),
        sm_vec4_f64_dot(transpose.c, b->a),
        sm_vec4_f64_dot(transpose.d, b->a)
    };
    out->b = (sm_vec4d) {
        sm_vec4_f64_dot(transpose.a, b->b),
        sm_vec4_f64_dot(transpose.b, b->b),
        sm_vec4_f64_dot(transpose.c, b->b),
        sm_vec4_f64_dot(transpose.d, b->b)
    };
    out->c = (sm_vec4d) {
        sm_vec4_f64_dot(transpose.a, b->c),
        sm_vec4_f64_dot(transpose.b, b->c),
        sm_vec4_f64_dot(transpose.c, b->c),
        sm_vec4_f64_dot(transpose.d, b->c)
    };
    out->d = (sm_vec4d) {
        sm_vec4_f64_dot(transpose.a, b->d),
        sm_vec4_f64_dot(transpose.b, b->d),
        sm_vec4_f64_dot(transpose.c, b->d),
        sm_vec4_f64_dot(transpose.d, b->d)
    };
}
/** @} **/




// Rendering Functions -----------------------


/**
 * \defgroup sm_mat4_translate
 * @brief Matrix translation
 * @param out mat4
 * @param a mat4
 * @param b mat4
 * @retval specifies translation in 3d space
 * @{
 */
/** @brief 32 Bit Integer **/
SM_INLINE void sm_mat4_i32_translate(sm_mat4i* out, sm_vec3i delta) {
    sm_vec3i pos = sm_vec3_i32_add((sm_vec3i){out->d.x, out->d.y, out->d.z}, delta);
    out->d = (sm_vec4i) {
        pos.x,
        pos.y,
        pos.z,
        1
    };
}

/** @brief 64 Bit Integer **/
SM_INLINE void sm_mat4_i64_translate(sm_mat4l* out, sm_vec3l delta) {
    sm_vec3l pos = sm_vec3_i64_add((sm_vec3l){out->d.x, out->d.y, out->d.z}, delta);
    out->d = (sm_vec4l) {
        pos.x,
        pos.y,
        pos.z,
        1
    };
}

/** @brief 32 Bit Float **/
SM_INLINE void sm_mat4_f32_translate(sm_mat4f* out, sm_vec3f delta) {
    sm_vec3f pos = sm_vec3_f32_add((sm_vec3f){out->d.x, out->d.y, out->d.z}, delta);
    out->d = (sm_vec4f) {
        pos.x,
        pos.y,
        pos.z,
        1
    };
}

/** @brief 64 Bit Float **/
SM_INLINE void sm_mat4_f64_translate(sm_mat4d* out, sm_vec3d delta) {
    sm_vec3d pos = sm_vec3_f64_add((sm_vec3d){out->d.x, out->d.y, out->d.z}, delta);
    out->d = (sm_vec4d) {
        pos.x,
        pos.y,
        pos.z,
        1
    };
}
/** @} **/



/**
 * \defgroup sm_mat4_scale
 * @brief Matrix scale
 * @param out mat4
 * @param a mat4
 * @param b mat4
 * @retval specifies scaling in 3d space
 * @{
 */
/* 32-bit Integer */
SM_INLINE void sm_mat4_i32_scale(sm_mat4i* out, i32 scale) {
    out->a = (sm_vec4i) {
        scale,
        0,
        0,
        0
    };
    out->b = (sm_vec4i) {
        0,
        scale,
        0,
        0
    };
    out->c = (sm_vec4i) {
        0,
        0,
        scale,
        0
    };
    out->d = (sm_vec4i) {
        0,
        0,
        0,
        scale,
    };
}

/* 64-bit Integer */
SM_INLINE void sm_mat4_i64_scale(sm_mat4l* out, i64 scale) {
    out->a = (sm_vec4l) {
        scale,
        0,
        0,
        0
    };
    out->b = (sm_vec4l) {
        0,
        scale,
        0,
        0
    };
    out->c = (sm_vec4l) {
        0,
        0,
        scale,
        0
    };
    out->d = (sm_vec4l) {
        0,
        0,
        0,
        scale,
    };
}

/* 32-bit Float */
SM_INLINE void sm_mat4_f32_scale(sm_mat4f* out, f32 scale) {
    out->a = (sm_vec4f) {
        scale,
        0,
        0,
        0
    };
    out->b = (sm_vec4f) {
        0,
        scale,
        0,
        0
    };
    out->c = (sm_vec4f) {
        0,
        0,
        scale,
        0
    };
    out->d = (sm_vec4f) {
        0,
        0,
        0,
        scale,
    };
}

/* 64-bit Float */
SM_INLINE void sm_mat4_f64_scale(sm_mat4d* out, f64 scale) {
    out->a = (sm_vec4d) {
        scale,
        0,
        0,
        0
    };
    out->b = (sm_vec4d) {
        0,
        scale,
        0,
        0
    };
    out->c = (sm_vec4d) {
        0,
        0,
        scale,
        0
    };
    out->d = (sm_vec4d) {
        0,
        0,
        0,
        scale,
    };
}
/** @} **/

/**
 * \defgroup sm_mat4_r
 * @brief Matrix rotate
 * @param m mat4
 * @param a angle in Radians
 * @retval specifies rotation in 3d space
 * 
 * Specifies Euler rotation.
 * Can be combined using the
 * sm_mat4_comp functions.
 *
 * Not supported for integer matricies
 * (precision issues)
 *
 * @{
 */

SM_INLINE void sm_mat4_f32_rx(sm_mat4f* m, Radian a) {
    m->a = (sm_vec4f) {
        1.0f,
        0,
        0,
        0
    };
    m->b = (sm_vec4f) {
        0,
        cosf(a),
        sinf(a),
        0
    };
    m->c = (sm_vec4f) {
        0,
        -sinf(a),
        cosf(a),
        0
    };
    m->d = (sm_vec4f) {
        0,
        0,
        0,
        1.0f
    };
}

SM_INLINE void sm_mat4_f32_ry(sm_mat4f* m, Radian a) {
    m->a = (sm_vec4f){
        cosf(a),
        0,
        -sinf(a),
        0
    };
    m->b = (sm_vec4f){
        0,
        1.0f,
        0,
        0
    };
    m->c = (sm_vec4f){
        sinf(a),
        0,
        cosf(a),
        0
    };
    m->d = (sm_vec4f){
        0,
        0,
        0,
        1.0f
    };
}

SM_INLINE void sm_mat4_f32_rz(sm_mat4f* m, Radian a) {
    m->a = (sm_vec4f){
        cosf(a),
        sinf(a),
        0,
        0
    };
    m->b = (sm_vec4f){
        -sinf(a),
        cosf(a),
        0,
        0
    };
    m->c = (sm_vec4f){
        0,
        0,
        1.0f,
        0
    };
    m->d = (sm_vec4f){
        0,
        0,
        0,
        1.0f
    };
}

SM_INLINE void sm_mat4_f64_rx(sm_mat4d* m, Radian a) {
    m->a = (sm_vec4d) {
        1.0,
        0,
        0,
        0
    };
    m->b = (sm_vec4d) {
        0,
        cos(a),
        sin(a),
        0
    };
    m->c = (sm_vec4d) {
        0,
        -sin(a),
        cos(a),
        0
    };
    m->d = (sm_vec4d) {
        0,
        0,
        0,
        1.0
    };
}

SM_INLINE void sm_mat4_f64_ry(sm_mat4d* m, Radian a) {
    m->a = (sm_vec4d){
        cos(a),
        0,
        -sin(a),
        0
    };
    m->b = (sm_vec4d){
        0,
        1.0,
        0,
        0
    };
    m->c = (sm_vec4d){
        -sin(a),
        0,
        cos(a),
        0
    };
    m->d = (sm_vec4d){
        0,
        0,
        0,
        1.0
    };
}

SM_INLINE void sm_mat4_f64_rz(sm_mat4d* m, Radian a) {
    m->a = (sm_vec4d){
        cos(a),
        sin(a),
        0,
        0
    };
    m->b = (sm_vec4d){
        -sin(a),
        cos(a),
        0,
        0
    };
    m->c = (sm_vec4d){
        0,
        0,
        1.0,
        0
    };
    m->d = (sm_vec4d){
        0,
        0,
        0,
        1.0
    };
}
/** @} **/


/**
 * \defgroup sm_mat4_perspective
 * @brief Perspective Projection Matrix
 * @param out mat4
 * @param n near clipping plane along the z+ direction
 * @param f far clipping plane along the z+ direction
 * @param vfov angular size along the vertical axis
 * @param hfov angular size along the horizontal axis
 * @retval returns a projection matrix from camera space to clip space
 *
 * @{
 */

SM_INLINE void sm_mat4_i32_perspective(sm_mat4i* out, i32 n, i32 f, Radian vfov, Radian hfov){
    i32 hoffset = n*tanf(hfov)/2;
    i32 voffset = n*tanf(vfov)/2; 
    i32 dDiff = f - n;
    
    out->a = (sm_vec4i){
        2*n,
        0,
        0,
        0
    };
    out->b = (sm_vec4i){
        0,
        n/voffset,
        0,
        0
    };
    out->c = (sm_vec4i){
        0,
        0,
        f/(dDiff),
        1
    };
    out->d = (sm_vec4i){
        0,
        0,
        (n*f)/dDiff,
        0
    };
}

SM_INLINE void sm_mat4_i64_perspective(sm_mat4l* out, i64 n, i64 f, Radian vfov, Radian hfov){
    i64 hoffset = n*tanf(hfov)/2;
    i64 voffset = n*tanf(vfov)/2; 
    i64 dDiff = f - n;
    
    out->a = (sm_vec4l){
        2*n,
        0,
        0,
        0
    };
    out->b = (sm_vec4l){
        0,
        n/voffset,
        0,
        0
    };
    out->c = (sm_vec4l){
        0,
        0,
        f/(dDiff),
        1
    };
    out->d = (sm_vec4l){
        0,
        0,
        (n*f)/dDiff,
        0
    };
}

SM_INLINE void sm_mat4_f32_perspective(sm_mat4f* out, f32 n, f32 f, Radian vfov, Radian hfov){
    f32 hoffset = n*tanf(hfov)/2;
    f32 voffset = n*tanf(vfov)/2; 
    f32 dDiff = f - n;
    
    out->a = (sm_vec4f){
        2*n,
        0,
        0,
        0
    };
    out->b = (sm_vec4f){
        0,
        n/voffset,
        0,
        0
    };
    out->c = (sm_vec4f){
        0,
        0,
        f/(dDiff),
        1
    };
    out->d = (sm_vec4f){
        0,
        0,
        (n*f)/dDiff,
        0
    };
}

SM_INLINE void sm_mat4_f64_perspective(sm_mat4d* out, f64 n, f64 f, Radian_d vfov, Radian_d hfov){
    f64 hoffset = n*tan(hfov)/2;
    f64 voffset = n*tan(vfov)/2; 
    f64 dDiff = f - n;
    
    out->a = (sm_vec4d){
        2*n,
        0,
        0,
        0
    };
    out->b = (sm_vec4d){
        0,
        n/voffset,
        0,
        0
    };
    out->c = (sm_vec4d){
        0,
        0,
        f/(dDiff),
        1
    };
    out->d = (sm_vec4d){
        0,
        0,
        (n*f)/dDiff,
        0
    };
}

/** @} **/

/**
 * \defgroup sm_mat4_ortho
 * @brief Orthographic Projection Matrix
 * @param out mat4
 * @param n near clipping plane z+ direction
 * @param f far clipping plane z+ direction
 * @param l left clipping plane x- direction
 * @param r right clipping plane x+ direction
 * @param t top clipping plane y- direction
 * @param b bottom clipping plane y+ direction
 * @retval returns a projection matrix from camera to clip space
 *
 * Currently Complete - Pending Testing
 *
 * @{
 */

SM_INLINE void sm_mat4_i32_ortho(sm_mat4i* out, i32 n, i32 f, i32 l, i32 r, i32 t, i32 b) {
    i32 horizontal_span = r - l;
    i32 vertical_span = b - t;
    i32 depth_span = f - n;

    out->a = (sm_vec4i){
        2.0/horizontal_span,
        0,
        0, 
        0
    };

    out->b = (sm_vec4i){
        0,
        2/vertical_span,
        0,
        0
    };
    out->c = (sm_vec4i){
        0,
        0,
        1/depth_span,
        0
    };
    out->d = (sm_vec4i){
        -(r+l)/horizontal_span,
        -(b+t)/vertical_span,
        -(n)/depth_span,
        1
    };
}

SM_INLINE void sm_mat4_i64_ortho(sm_mat4l* out, i64 n, i64 f, i64 l, i64 r, i64 t, i64 b) {
    i64 horizontal_span = r - l;
    i64 vertical_span = b - t;
    i64 depth_span = f - n;

    out->a = (sm_vec4l){
        2.0/horizontal_span,
        0,
        0, 
        0
    };

    out->b = (sm_vec4l){
        0,
        2/vertical_span,
        0,
        0
    };
    out->c = (sm_vec4l){
        0,
        0,
        1/depth_span,
        0
    };
    out->d = (sm_vec4l){
        -(r+l)/horizontal_span,
        -(b+t)/vertical_span,
        -(n)/depth_span,
        1
    };
}

SM_INLINE void sm_mat4_f32_ortho(sm_mat4f* out, f32 n, f32 f, f32 l, f32 r, f32 t, f32 b) {
    f32 horizontal_span = r - l;
    f32 vertical_span = b - t;
    f32 depth_span = f - n;

    out->a = (sm_vec4f){
        2.0f/horizontal_span,
        0.0f,
        0.0f, 
        0.0f
    };

    out->b = (sm_vec4f){
        0.0f,
        2.0f/vertical_span,
        0.0f,
        0.0f
    };
    out->c = (sm_vec4f){
        0.0f,
        0.0f,
        1.0f/depth_span,
        0.0f
    };
    out->d = (sm_vec4f){
        -(r+l)/horizontal_span,
        -(b+t)/vertical_span,
        -(n)/depth_span,
        1.0f
    };
}

SM_INLINE void sm_mat4_f64_ortho(sm_mat4d* out, f64 n, f64 f, f64 l, f64 r, f64 t, f64 b) {
    f64 horizontal_span = r - l;
    f64 vertical_span = b - t;
    f64 depth_span = f - n;

    out->a = (sm_vec4d){
        2.0/horizontal_span,
        0.0,
        0.0, 
        0.0
    };

    out->b = (sm_vec4d){
        0.0,
        2.0/vertical_span,
        0.0,
        0.0
    };
    out->c = (sm_vec4d){
        0.0,
        0.0,
        1.0/depth_span,
        0.0
    };
    out->d = (sm_vec4d){
        -(r+l)/horizontal_span,
        -(b+t)/vertical_span,
        -(n)/depth_span,
        1.0
    };
}

/** @} **/

#endif
