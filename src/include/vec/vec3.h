#ifndef SIMPLE_VEC_3_H
#define SIMPLE_VEC_3_H
#include "common.h"


/**
 * \defgroup sm_vec3
 * @brief 3 Component Vector
 * @{
 */
typedef struct {
    i32 x; /** 32 Bit Integer Component of vec3 */
    i32 y; /** 32 Bit Integer Component of vec3 */
    i32 z; /** 32 Bit Integer Component of vec3 */
} sm_vec3i; 

typedef struct {
    i64 x; /** 64 Bit Integer Component of vec3 */
    i64 y; /** 64 Bit Integer Component of vec3 */
    i64 z; /** 64 Bit Integer Component of vec3 */
} sm_vec3l; 

typedef struct {
    f32 x; /** 32 Bit Float Component of vec3 */
    f32 y; /** 32 Bit Float Component of vec3 */
    f32 z; /** 32 Bit Float Component of vec3 */
} sm_vec3f; 

typedef struct {
    f64 x; /** 64 Bit Float Component of vec3 */
    f64 y; /** 64 Bit Float Component of vec3 */
    f64 z; /** 64 Bit Float Component of vec3 */
} sm_vec3d; 
/** @} */


/**
 * \defgroup sm_vec3_add
 * @brief Vector Component Adds
 * @param a vec3
 * @param b vec3
 * @retval Component wise addition
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec3i sm_vec3_i32_add(sm_vec3i a, sm_vec3i b) {
    return (sm_vec3i){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

/** @brief 64 Bit Integer */
SM_INLINE sm_vec3l sm_vec3_i64_add(sm_vec3l a, sm_vec3l b) {
    return (sm_vec3l){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec3f sm_vec3_f32_add(sm_vec3f a, sm_vec3f b) {
    return (sm_vec3f){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec3d sm_vec3_f64_add(sm_vec3d a, sm_vec3d b) {
    return (sm_vec3d){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}
/** @} */


/**
 * \defgroup sm_vec3_sub
 * @brief Vector Component Subtraction
 * @param a vec3
 * @param b vec3
 * @retval Component wise subtraction
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec3i sm_vec3_i32_sub(sm_vec3i a, sm_vec3i b) {
    return (sm_vec3i){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

/** @brief 64 Bit Integer */
SM_INLINE sm_vec3l sm_vec3_i64_sub(sm_vec3l a, sm_vec3l b) {
    return (sm_vec3l){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec3f sm_vec3_f32_sub(sm_vec3f a, sm_vec3f b) {
    return (sm_vec3f){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec3d sm_vec3_f64_sub(sm_vec3d a, sm_vec3d b) {
    return (sm_vec3d){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}
/** @} */


/**
 * \defgroup sm_vec3_mul
 * @brief Vector Component Multiply
 * @param a vec3
 * @param b vec3
 * @retval Component wise Multiply
 * Uses the Hadamard product, or component wise
 * multiplication. Not to be confused with dot
 * product
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec3i sm_vec3_i32_mul(sm_vec3i a, sm_vec3i b) {
    return (sm_vec3i){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    };
}

/** @brief 64 Bit Integer */
SM_INLINE sm_vec3l sm_vec3_i64_mul(sm_vec3l a, sm_vec3l b) {
    return (sm_vec3l){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    };
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec3f sm_vec3_f32_mul(sm_vec3f a, sm_vec3f b) {
    return (sm_vec3f){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    };
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec3d sm_vec3_f64_mul(sm_vec3d a, sm_vec3d b) {
    return (sm_vec3d){
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    };
}
/** @} */

/**
 * \defgroup sm_vec3_dot
 * @brief Vector dot Multiply
 * @param a vec3
 * @param b vec3
 * @retval Dot Product
 * Dot product returning a scalar
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE i32 sm_vec3_i32_dot(sm_vec3i a, sm_vec3i b) {
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}

/** @brief 64 Bit Integer */
SM_INLINE i64 sm_vec3_i64_dot(sm_vec3l a, sm_vec3l b) {
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}
/** @brief 32 Bit Float */
SM_INLINE f32 sm_vec3_f32_dot(sm_vec3f a, sm_vec3f b) {
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}
/** @brief 64 Bit Float */
SM_INLINE f64 sm_vec3_f64_dot(sm_vec3d a, sm_vec3d b) {
    return a.x * b.x +
           a.y * b.y +
           a.z * b.z;
}
/** @} */


/** 
 * \defgroup sm_vec3_len
 * @brief Vector Length Calc
 * @param a vec3
 * @retval Cartesian length of a
 *
 * Calculates the pythagorean length of the vector using sqrt.
 * @{
 * */
/** 32 Bit Integer Vector */
SM_INLINE i32 sm_vec3_i32_len(sm_vec3i a) {
    return (i32)sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
/** 64 Bit Integer Vector */
SM_INLINE i64 sm_vec3_i64_len(sm_vec3l a) {
    return (i64)sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
/** 32 Bit Float Vector */
SM_INLINE f32 sm_vec3_f32_len(sm_vec3f a) {
    return (f32)sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
/** 64 Bit Float Vector */
SM_INLINE f64 sm_vec3_f64_len(sm_vec3d a) {
    return (f64)sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
/** @}*/


#endif
