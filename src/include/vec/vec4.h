#ifndef SIMPLE_VEC_4_H
#define SIMPLE_VEC_4_H
#include "common.h"

/**
 * \defgroup sm_vec4
 * @brief 4 Component Vector
 * @{
 */
typedef struct {
    i32 x; /** 32 Bit Integer Component of vec4 */
    i32 y; /** 32 Bit Integer Component of vec4 */
    i32 z; /** 32 Bit Integer Component of vec4 */
    i32 w; /** 32 Bit Integer Component of vec4 */
} sm_vec4i; 

typedef struct {
    i64 x; /** 64 Bit Integer Component of vec4 */
    i64 y; /** 64 Bit Integer Component of vec4 */
    i64 z; /** 64 Bit Integer Component of vec4 */
    i64 w; /** 64 Bit Integer Component of vec4 */
} sm_vec4l; 

typedef struct {
    f32 x; /** 32 Bit Float Component of vec4 */
    f32 y; /** 32 Bit Float Component of vec4 */
    f32 z; /** 32 Bit Float Component of vec4 */
    f32 w; /** 32 Bit Float Component of vec4 */
} sm_vec4f; 

typedef struct {
    f64 x; /** 64 Bit Float Component of vec4 */
    f64 y; /** 64 Bit Float Component of vec4 */
    f64 z; /** 64 Bit Float Component of vec4 */
    f64 w; /** 64 Bit Float Component of vec4 */
} sm_vec4d; 
/** @} */


/**
 * \defgroup sm_vec4_add
 * @brief Vector Component Adds
 * @param a vec4
 * @param b vec4
 * @retval Component wise addition
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec4i sm_vec4_i32_add(sm_vec4i a, sm_vec4i b) {
    return (sm_vec4i){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}

/** @brief 64 Bit Integer */
SM_INLINE sm_vec4l sm_vec4_i64_add(sm_vec4l a, sm_vec4l b) {
    return (sm_vec4l){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec4f sm_vec4_f32_add(sm_vec4f a, sm_vec4f b) {
    return (sm_vec4f){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec4d sm_vec4_f64_add(sm_vec4d a, sm_vec4d b) {
    return (sm_vec4d){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}
/** @} */


/**
 * \defgroup sm_vec4_sub
 * @brief Vector Component Subtraction
 * @param a vec4
 * @param b vec4
 * @retval Component wise Subtraction
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec4i sm_vec4_i32_sub(sm_vec4i a, sm_vec4i b) {
    return (sm_vec4i){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}

/** @brief 64 Bit Integer */
SM_INLINE sm_vec4l sm_vec4_i64_sub(sm_vec4l a, sm_vec4l b) {
    return (sm_vec4l){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec4f sm_vec4_f32_sub(sm_vec4f a, sm_vec4f b) {
    return (sm_vec4f){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec4d sm_vec4_f64_sub(sm_vec4d a, sm_vec4d b) {
    return (sm_vec4d){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}
/** @} */


/**
 * \defgroup sm_vec4_mul
 * @brief Vector Component Multiply
 * @param a vec4
 * @param b vec4
 * @retval Component wise Multiply
 * Uses the Hadamard product, or component wise
 * multiplication. Not to be confused with dot
 * product
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec4i sm_vec4_i32_mul(sm_vec4i a, sm_vec4i b) {
    return (sm_vec4i){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    };
}

/** @brief 64 Bit Integer */
SM_INLINE sm_vec4l sm_vec4_i64_mul(sm_vec4l a, sm_vec4l b) {
    return (sm_vec4l){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    };
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec4f sm_vec4_f32_mul(sm_vec4f a, sm_vec4f b) {
    return (sm_vec4f){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    };
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec4d sm_vec4_f64_mul(sm_vec4d a, sm_vec4d b) {
    return (sm_vec4d){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    };
}
/** @} */


/**
 * \defgroup sm_vec4_dot
 * @brief Vector dot Multiply
 * @param a vec4
 * @param b vec4
 * @retval Dot Product
 * Dot product returning a scalar
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE i32 sm_vec4_i32_dot(sm_vec4i a, sm_vec4i b) {
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z +
           a.w * b.w;
}

/** @brief 64 Bit Integer */
SM_INLINE i64 sm_vec4_i64_dot(sm_vec4l a, sm_vec4l b) {
    return
        a.x * b.x +
        a.y * b.y +
        a.z * b.z +
        a.w * b.w;
}
/** @brief 32 Bit Float */
SM_INLINE f32 sm_vec4_f32_dot(sm_vec4f a, sm_vec4f b) {
    return 
        a.x * b.x +
        a.y * b.y +
        a.z * b.z +
        a.w * b.w;
}
/** @brief 64 Bit Float */
SM_INLINE f64 sm_vec4_f64_dot(sm_vec4d a, sm_vec4d b) {
    return 
        a.x * b.x +
        a.y * b.y +
        a.z * b.z +
        a.w * b.w;
}
/** @} */

/** 
 * \defgroup sm_vec4_len
 * @brief Vector Length Calc
 * @param a vec4
 * @retval Cartesian length of a
 *
 * Calculates the pythagorean length of the vector using sqrt.
 * @{
 * */
/** 32 Bit Integer Vector */
SM_INLINE i32 sm_vec4_i32_len(sm_vec4i a) {
    return (i32)sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}
/** 64 Bit Integer Vector */
SM_INLINE i64 sm_vec4_i64_len(sm_vec4l a) {
    return (i64)sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}
/** 32 Bit Float Vector */
SM_INLINE f32 sm_vec4_f32_len(sm_vec4f a) {
    return (f32)sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}
/** 64 Bit Float Vector */
SM_INLINE f64 sm_vec4_f64_len(sm_vec4d a) {
    return (f64)sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}
/** @}*/

#endif
