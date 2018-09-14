#include "chi2comb.h"
#include "acutest.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPSILON 1e-12

void test_chi2comb(void) {

    double coefs[] = {0.4, 1.1};
    double ncentrals[] = {1.3, 2.9};
    int dofs[] = {1, 3};
    int ncoefs = 2;
    double coef1 = 0.41;
    double dof_eval = 2.0;
    int lim = 1000;
    double acc = 1e-16;
    double info[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    int fault = 0;
    double res = 0.0;

    qfc(coefs, ncentrals, dofs, &ncoefs, &coef1, &dof_eval, &lim, &acc, info, &fault,
        &res);
    res = 1 - res;

    TEST_CHECK(fabs(res - 0.9183206009070191) < EPSILON);
}

TEST_LIST = {{"test_chi2comb", test_chi2comb}, {NULL, NULL}};