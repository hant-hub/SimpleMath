#ifndef SIMPLE_MISC_H
#define SIMPLE_MISC_H
#include "common.h"
#include <complex.h>
#include <stdio.h>



//Complex Numbers
//Use builtins + Macros

//using default c types here -> would prefer stdint types but whatever
typedef _Complex int    sm_complexi;
typedef _Complex long   sm_complexl;
typedef _Complex float  sm_complexf;
typedef _Complex double sm_complexd;

SM_INLINE void sm_complex_i32_print(FILE* stream, sm_complexi val) {
    fprintf(stream, "%d + %di\n", __real__ val, __imag__ val);
}

SM_INLINE void sm_complex_i64_print(FILE* stream, sm_complexl val) {
    fprintf(stream, "%ld + %ldi\n", __real__ val, __imag__ val);
}

SM_INLINE void sm_complex_f32_print(FILE* stream, sm_complexf val) {
    fprintf(stream, "%f + %fi\n", __real__ val, __imag__ val);
}

SM_INLINE void sm_complex_f64_print(FILE* stream, sm_complexd val) {
    fprintf(stream, "%f + %fi\n", __real__ val, __imag__ val);
}

//Rotors
// TODO



#endif
