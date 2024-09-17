#include "common.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "misc.h"
#include <stdio.h>

int main() {
    //test dot product
    sm_vec4f test1 = (sm_vec4f) {1.0f, 2.0f, -1.0f, -2.0f};
    sm_vec4f test2 = (sm_vec4f) {1.0f, 3.0f,  1.0f,  1.0f};
    printf("Dot product output: %f\n", sm_vec4_f32_dot(test1, test2));

    //test matrix comp
    sm_mat4f mat1 = (sm_mat4f) {
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };


    sm_mat4f mat2 = (sm_mat4f) {
        {1, 0, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0}
    };

    sm_mat4f out = sm_mat4_f32_comp(&mat1, &mat2);
    sm_mat4_f32_print(stdout, &out);

    printf("Complex Test\n");
    sm_complexf a = 1 + 2i;
    sm_complexf b = a * 2;
    sm_complex_f32_print(stdout, a * b);


    printf("Ortho Test\n");
    sm_mat4f ortho_test = sm_mat4_f32_ortho(1, 2, 0, 1, 0, 1);
    sm_mat4_f32_print(stdout, &ortho_test);
    
    
    printf("Perspective Test\n");
    sm_mat4f perp_test = sm_mat4_f32_perspective(1, 2, SM_PI/4, 1920.0/1080.0);
    sm_mat4_f32_print(stdout, &perp_test);

    printf("Euler Rotation Test\n");
    printf("\trx\n");
    sm_mat4f m1 = sm_mat4_f32_rx(&sm_mat4f_identity, SM_PI/2);
    sm_mat4_f32_print(stdout, &m1);

    printf("\try\n");
    m1 = sm_mat4_f32_ry(&sm_mat4f_identity, SM_PI/2);
    sm_mat4_f32_print(stdout, &m1);

    printf("\trz\n");
    m1 = sm_mat4_f32_rz(&sm_mat4f_identity, SM_PI/2);
    sm_mat4_f32_print(stdout, &m1);

    return 0;
}
