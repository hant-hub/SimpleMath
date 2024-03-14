#ifndef SIMPLE_COMMON_H
#define SIMPLE_COMMON_H
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef float f32;
typedef double f64;
typedef long double f128;

typedef uint32_t u32;
typedef uint64_t u64;

typedef uint_fast8_t u8_f;
typedef uint_fast16_t u16_f;
typedef uint_fast32_t u32_f;

typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t bool;
const bool true = 1;
const bool false = 0;

#define SM_INLINE static inline
#define SM_PI 3.14159265358979323846f






#endif
