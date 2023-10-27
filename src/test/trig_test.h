#ifndef TRIG_TEST_H
#define TRIG_TEST_H
#include "logger.h"
#include "../include/trig/cos.h"
#include <stdio.h>
#include <stdlib.h>

static void cos_radians_test(float eps) {
    printf("\t\tCos: \n");
    radians theta = {0};
    float result;
    int success = 1;


    result = 1 - cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = pi;
    result = 1 + cos_r(theta);
    //printf("\t\t result = %f\n", result);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = pi/2;
    result = cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = -pi/2;
    result = cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 3*pi;
    result = 1 + cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 1;
    result =  0.540302305868 - cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 2;
    result = 0.416146836547 + cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 1.369;
    result = 0.200429529171 - cos_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    if (success) {
        printf(GREEN "\t\tpassed " CHECK NRM "\n");
    } else {
        printf(RED "\t\tfailed " CROSS NRM "\n");
        exit(0);
    }
}






static void test_trig() {
    float eps = 0.0017;
    printf("\tUsing EPS = %f\n", eps);
    printf("\tTesting Radians\n");
    cos_radians_test(eps);
}


#endif
