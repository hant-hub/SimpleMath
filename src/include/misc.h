#ifndef SIMPLE_MISC_H
#define SIMPLE_MISC_H
#include "common.h"

/**
 * \defgroup Sqrt  
 * @brief Takes the square root of a number
 * @param x Number
 * @retval Returns square root
 * Uses a bit hack as well as some newton iteration
 * in order to calculate the square root of a number
 * @{
 */


const i32 sqrt_precision = 2; /** Controls number of interations */

/** Single Precision*/
SM_INLINE f32 sm_sqrt_f32(f32 x){
    union { f32 f; u32 i; } val = {x};
    val.i = (1<<29) + (val.i >> 1) - (1<<22);

    for (u8_f i = 0; i < sqrt_precision; i++) {
        val.f = (val.f + x/val.f) * 0.5f;
    }
    return val.f;
}
/** Double Precision*/
SM_INLINE f64 sm_sqrt_f64(f64 x) {
    union { f64 f; u64 i; } val = {x};
    val.i = (1<<29) + (val.i >> 1) - (1<<22);

    for (u8_f i = 0; i < sqrt_precision; i++) {
        val.f = (val.f + x/val.f) * 0.5f;
    }
    return val.f;
}
/** @}*/




#endif
