#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include <stdio.h>

int main() {
    //test dot product
    sm_vec4f test1 = (sm_vec4f) {1.0f, 2.0f, -1.0f, -2.0f};
    sm_vec4f test2 = (sm_vec4f) {1.0f, 3.0f,  1.0f,  1.0f};
    printf("Dot product output: %f\n", sm_vec4_f32_dot(test1, test2));

    //test matrix comp
    sm_mat4f mat1 = (sm_mat4f) {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };


    sm_mat4f mat2 = (sm_mat4f) {
        {2, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 2}
    };

    sm_mat4f out;
    sm_mat4_f32_comp(&out, &mat1, &mat2);

    printf("Matrix Comp:\n");
    printf("%f\t", out.a.x); 
    printf("%f\t", out.b.x); 
    printf("%f\t", out.c.x); 
    printf("%f\t", out.d.x); 
    printf("\n");

    printf("%f\t", out.a.y); 
    printf("%f\t", out.b.y); 
    printf("%f\t", out.c.y); 
    printf("%f\t", out.d.y); 
    printf("\n");

    printf("%f\t", out.a.z); 
    printf("%f\t", out.b.z); 
    printf("%f\t", out.c.z); 
    printf("%f\t", out.d.z); 
    printf("\n");

    printf("%f\t", out.a.w); 
    printf("%f\t", out.b.w); 
    printf("%f\t", out.c.w); 
    printf("%f\t", out.d.w); 
    printf("\n");





    return 0;
}
