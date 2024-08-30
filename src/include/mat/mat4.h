#ifndef SIMPLE_MAT_4_H
#define SIMPLE_MAT_4_H
#include "common.h"
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
 * \defgroup sm_mat4_rotate
 * @brief Matrix rotate
 * @param out mat4
 * @param a mat4
 * @param b mat4
 * @retval specifies rotate in 3d space
 * @{
 */

SM_INLINE void sm_mat4_i32_rotate(sm_mat4i* out, i32 x, i32 y, i32 z) {

}





/** @} **/

#endif