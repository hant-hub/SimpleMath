#ifndef mat_test_h
#define mat_test_h
#include "../include/types.h"
#include "../include/mat2x2.h"
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


static void test_mat() {
    test_mat2add();
    test_mat2det();

    //printf("\e[1;1H\e[2J");
    printf("Mat Tests... " GREEN "passed " CHECK NRM "\n");
}


#endif
