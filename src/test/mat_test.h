#ifndef mat_test_h
#define mat_test_h
#include "../include/types.h"
#include "../include/mat2x2.h"
#include "../include/mat3x3.h"
#include "logger.h"
#include <stdio.h>
#include <stdlib.h>

static void test_mat2add() {
    printf("Mat2x2 Add test... ");
    mat2x2_float a = {{
        {1, 1},
        {3, 4}
    }};

    mat2x2_float b = {{
        {5, 9},
        {3, 1}
    }};

    mat2x2_float expected = {{
        {6, 10},
        {6, 5}
    }};

    mat2x2_float actual = mat2x2add(&a, &b);
    if (mat2x2_float_eq(&expected, &actual)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }
};


static void test_mat2det() {
    printf("Mat2x2 Det test... ");
    mat2x2_float m = {{
        {1, 2},
        {3, 4}
    }};
    float expected = -2;

    if (expected == mat2x2det(&m)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }

}


static void test_mat2comp() {
    printf("Mat2x2 Comp test... ");
    mat2x2_float a = {{
        {1, 1},
        {3, 4}
    }};

    mat2x2_float b = {{
        {5, 9},
        {3, 1}
    }};

    mat2x2_float expected = {{
        {8, 10},
        {27, 31}
    }};

    mat2x2_float actual = mat2x2comp(&a, &b);
    if (mat2x2_float_eq(&expected, &actual)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }
}


static void test_mat2app() {
    printf("Mat2x2 App test... ");
    mat2x2_float m = {{
        {1, 2},
        {3, 4}
    }};
    vec2float v = {{1, 2}};

    vec2float expected = {{5, 11}};
    vec2float actual = mat2x2app(&m, &v); 


    if (vec2float_eq(expected, actual)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }
}


static void test_mat3add() {
    printf("Mat3x3 Add test... ");
    mat3x3_float a = {{
        {1, 1, 2},
        {3, 4, 4},
        {3, 1, 4}
    }};

    mat3x3_float b = {{
        {5, 9, 4},
        {3, 1, 1},
        {2, 3, 5}
    }};

    mat3x3_float expected = {{
        {6, 10, 6},
        {6, 5, 5},
        {5, 4, 9}
    }};

    mat3x3_float actual = mat3x3add(&a, &b);
    if (mat3x3_float_eq(&expected, &actual)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }
}


static void test_mat3det() {
    printf("Mat3x3 Det test... ");
    mat3x3_float m = {{
        {1, 1, 2},
        {3, 4, 4},
        {3, 1, 4}
    }};
    float expected = -6;

    if (expected == mat3x3det(&m)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }

}



static void test_mat3comp() {
    printf("Mat3x3 Comp test... ");
    mat3x3_float a = {{
        {1, 1, 2},
        {3, 4, 4},
        {3, 1, 4}
    }};

    mat3x3_float b = {{
        {5, 9, 4},
        {3, 1, 1},
        {2, 3, 5}
    }};

    mat3x3_float expected = {{
        {12, 16, 15},
        {35, 43, 36},
        {26, 40, 33}
    }};

    mat3x3_float actual = mat3x3comp(&a, &b);
    if (mat3x3_float_eq(&expected, &actual)) {
        printf(GREEN "passed " CHECK NRM "\n");
    } else {
        printf(RED "failed " CROSS NRM "\n");
        exit(0);
    }
}

static void test_mat() {
    test_mat2add();
    test_mat2det();
    test_mat2comp();
    test_mat2app();

    test_mat3add();
    test_mat3det();
    test_mat3comp();

    //printf("\e[1;1H\e[2J");
    printf("Mat Tests... " GREEN "passed " CHECK NRM "\n");
}


#endif
