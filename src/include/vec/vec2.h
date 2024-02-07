#ifndef SIMPLE_VECTOR_2_H
#define SIMPLE_VECTOR_2_H
#include "include/common.h"


/**
 * \defgroup sm_vec2
 * @brief 2 Component Vector
 * @{
 */
typedef struct {
    i32 x; /** 32 Bit Integer x. Component of Vec2*/
    i32 y; /** 32 Bit Integer y. Component of Vec2*/
} sm_vec2i;

typedef struct {
    i64 x; /** 64 Bit Integer x. Component of Vec2*/
    i64 y; /** 64 Bit Integer y. Component of Vec2*/
} sm_vec2l;

typedef struct {
    f32 x; /** 32 Bit Float x. Component of Vec2*/
    f32 y; /** 32 Bit Float y. Component of Vec2*/
} sm_vec2f;

typedef struct {
    f64 x; /** 64 Bit Float x. Component of Vec2*/
    f64 y; /** 64 Bit Float y, Component of Vec2*/
} sm_vec2d;
/** @} */
 


/**
 * \defgroup sm_vec2_add
 * @brief Vector Component Adds
 * @param a vec2
 * @param b vec2
 * @retval Component wise addition
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec2i sm_vec2_i32_add(sm_vec2i a, sm_vec2i b) {
    return (sm_vec2i){a.x + b.x, a.y + b.y};
}
/** @brief 64 Bit Integer */
SM_INLINE sm_vec2l sm_vec2_i64_add(sm_vec2l a, sm_vec2l b) {
    return (sm_vec2l){a.x + b.x, a.y + b.y};
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec2f sm_vec2_f32_add(sm_vec2f a, sm_vec2f b) {
    return (sm_vec2f){a.x + b.x, a.y + b.y};
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec2d sm_vec2_f64_add(sm_vec2d a, sm_vec2d b) {
    return (sm_vec2d){a.x + b.x, a.y + b.y};
}
/** @} */



/**
 * \defgroup sm_vec2_sub
 * @brief Vector Component Subtraction
 * @param a vec2
 * @param b vec2
 * @retval Component wise subtraction
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec2i sm_vec2_i32_sub(sm_vec2i a, sm_vec2i b) {
    return (sm_vec2i){a.x - b.x, a.y - b.y};
}
/** @brief 64 Bit Integer*/
SM_INLINE sm_vec2l sm_vec2_i64_sub(sm_vec2l a, sm_vec2l b) {
    return (sm_vec2l){a.x - b.x, a.y - b.y};
}
/** @brief 32 Bit Float*/
SM_INLINE sm_vec2f sm_vec2_f32_sub(sm_vec2f a, sm_vec2f b) {
    return (sm_vec2f){a.x - b.x, a.y - b.y};
}
/** @brief 64 Bit Float*/
SM_INLINE sm_vec2d sm_vec2_f64_sub(sm_vec2d a, sm_vec2d b) {
    return (sm_vec2d){a.x - b.x, a.y - b.y};
}
/** @} */




/**
 * \defgroup sm_vec2_mul
 * @brief Vector Component Multiply
 * @param a vec2
 * @param b vec2
 * @retval Component wise Multiply
 * Uses the Hadamard product, or component wise
 * multiplication. Not to be confused with dot
 * product
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE sm_vec2i sm_vec2_i32_mul(sm_vec2i a, sm_vec2i b) {
    return (sm_vec2i){a.x * b.x, a.y * b.y};
}
/** @brief 64 Bit Integer */
SM_INLINE sm_vec2l sm_vec2_i64_mul(sm_vec2l a, sm_vec2l b) {
    return (sm_vec2l){a.x * b.x, a.y * b.y};
}
/** @brief 32 Bit Float */
SM_INLINE sm_vec2f sm_vec2_f32_mul(sm_vec2f a, sm_vec2f b) {
    return (sm_vec2f){a.x * b.x, a.y * b.y};
}
/** @brief 64 Bit Float */
SM_INLINE sm_vec2d sm_vec2_f64_mul(sm_vec2d a, sm_vec2d b) {
    return (sm_vec2d){a.x * b.x, a.y * b.y};
}
/** @} */


/**
 * \defgroup sm_vec2_dot
 * @brief Vector dot Multiply
 * @param a vec2
 * @param b vec2
 * @retval Dot Product
 * Dot product returning a scalar
 * @{
 */
/** @brief 32 Bit Integer */
SM_INLINE i32 sm_vec2_i32_dot(sm_vec2i a, sm_vec2i b) {
    return a.x * b.x + a.y * b.y;
}
/** @brief 64 Bit Integer */
SM_INLINE i64 sm_vec2_i64_dot(sm_vec2l a, sm_vec2l b) {
    return a.x * b.x + a.y * b.y;
}
/** @brief 32 Bit Float */
SM_INLINE f32 sm_vec2_f32_dot(sm_vec2f a, sm_vec2f b) {
    return a.x * b.x + a.y * b.y;
}
/** @brief 64 Bit Float */
SM_INLINE f64 sm_vec2_f64_dot(sm_vec2d a, sm_vec2d b) {
    return a.x * b.x + a.y * b.y;
}
/** @} */

/** 
 * \defgroup sm_vec2_len
 * @brief Vector Length Calc
 * @param a vec2
 * @retval Cartesian length of a
 *
 * Calculates the pythagorean length of the vector using sqrt.
 * @{
 * */
/** 32 Bit Integer Vector */
SM_INLINE i32 sm_vec2_i32_len(sm_vec2i a) {
    return (i32)sqrt(a.x * a.x + a.y * a.y);
}
/** 64 Bit Integer Vector */
SM_INLINE i64 sm_vec2_i64_len(sm_vec2l a) {
    return (i64)sqrt(a.x * a.x + a.y * a.y);
}
/** 32 Bit Float Vector */
SM_INLINE f32 sm_vec2_f32_len(sm_vec2f a) {
    return (f32)sqrt(a.x * a.x + a.y * a.y);
}
/** 64 Bit Float Vector */
SM_INLINE f64 sm_vec2_f64_len(sm_vec2d a) {
    return (f64)sqrt(a.x * a.x + a.y * a.y);
}
/** @}*/


#endif
