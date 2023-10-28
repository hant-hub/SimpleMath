#ifndef TRIG_TEST_H
#define TRIG_TEST_H
#include "logger.h"
#include "../include/trig/cos.h"
#include "../include/trig/sin.h"
#include "../include/trig/tan.h"
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

static void sin_radians_test(float eps) {
    printf("\n\t\tSin: \n");
    radians theta = {0};
    float result;
    int success = 1;


    result = sin_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = pi;
    result = sin_r(theta);
    //printf("\t\t result = %f\n", result);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = pi/2;
    result = 1 - sin_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = -pi/2;
    result = 1 + sin_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 3*pi;
    result = sin_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 1;
    result =  0.8414709848 - sin_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 2;
    result = 0.9092974268 - sin_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 2.94;
    result = 0.2002299847 - sin_r(theta);
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

static void tan_radians_test(float eps) {
    printf("\t\tTan: \n");
    radians theta = {0};
    float result;
    int success = 1;

    result = tan_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = pi/4;
    result = 1 - tan_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = -pi/4;
    result = 1 + tan_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 1;
    result = 1.557407725 - tan_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 2;
    result =  2.185039863 + tan_r(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 3;
    result =  0.1425465431 + tan_r(theta);
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

static void cos_degrees_test(float eps) {
    printf("\t\tCos: \n");
    degrees theta = {0};
    float result;
    int success = 1;


    result = 1 - cos_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 180;
    result = 1 + cos_d(theta);
    //printf("\t\t result = %f\n", result);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 90;
    result = cos_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = -90;
    result = cos_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 540;
    result = 1 + cos_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 57.29577951;
    result =  0.540302305868 - cos_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 114.591559;
    result = 0.416146836547 + cos_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 78.43792215;
    result = 0.200429529171 - cos_d(theta);
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


static void sin_degrees_test(float eps) {
    printf("\n\t\tSin: \n");
    degrees theta = {0};
    float result;
    int success = 1;


    result = sin_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 180;
    result = sin_d(theta);
    //printf("\t\t result = %f\n", result);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 90;
    result = 1 - sin_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = -90;
    result = 1 + sin_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 540;
    result = sin_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 57.29577951;
    result =  0.8414709848 - sin_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 114.591559;
    result = 0.9092974268 - sin_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 168.4495918;
    result = 0.2002299847 - sin_d(theta);
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


static void tan_degrees_test(float eps) {
    printf("\t\tTan: \n");
    degrees theta = {0};
    float result;
    int success = 1;

    result = tan_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = 45;
    result = 1 - tan_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }

    theta.val = -45;
    result = 1 + tan_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 57.29577951;
    result = 1.557407725 - tan_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 114.591559;
    result =  2.185039863 + tan_d(theta);
    if (result <= eps && result >= -eps) {
        printf(GREEN "\t\t\tInput %f passed\n" NRM, theta.val);
    } else {
        printf(RED "\t\t\tInput %f failed\n" NRM, theta.val);
        success = 0;
    }


    theta.val = 171.8873385;
    result =  0.1425465431 + tan_d(theta);
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
    float eps = 0.006;
    printf("\tUsing EPS = %f\n", eps);
    printf("\tTesting Radians\n");
    cos_radians_test(eps);
    sin_radians_test(eps);
    tan_radians_test(eps);

    printf("\tTesting Degrees\n");
    cos_degrees_test(eps);
    sin_degrees_test(eps);
    tan_radians_test(eps);

    printf("\tTesting Inverses\n");

    printf("Trig Tests... " GREEN "passed" CHECK NRM "\n");
}


#endif
