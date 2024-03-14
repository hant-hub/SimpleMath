#ifndef SIMPLE_MAT_4_H
#define SIMPLE_MAT_4_H
#include "common.h"
#include "vec4.h"


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

SM_INLINE void sm_mat4_i32_sub(sm_mat4i* out, sm_mat4i* a, sm_mat4i* b) {
    out->a = sm_vec4_i32_sub(a->a, b->a);
    out->b = sm_vec4_i32_sub(a->b, b->b);
    out->c = sm_vec4_i32_sub(a->c, b->c);
    out->d = sm_vec4_i32_sub(a->d, b->d);
}



#endif
