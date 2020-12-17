#include "chi2comb/chi2comb.h"
#include "acutest.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPSILON 1e-12

static void test_chi2comb(void) {

    double gcoef = 0.41;
    double q = 2.0;
    int lim = 1000;
    double abstol = 1e-16;
    struct chi2comb_info info;
    int fault = 0;
    double res = 0.0;

    struct chi2comb_chisquareds chi2s = {(double[2]){0.4, 1.1}, (double[2]){1.3, 2.9},
                                         (int[2]){1, 3}, 2};

    fault = chi2comb_cdf(q, &chi2s, gcoef, lim, abstol, &info, &res);
    res = 1 - res;

    TEST_CHECK(fabs(res - 0.9183206009070191) < EPSILON);
}

static void test_chi2comb_table(void) {

    double coefs[] = {
        6, 3, 1, 6, 3, 1, 6, 3, 1, 6, 3, 1,  6,  3, 1, 6,  3,  1, 6, 3,  1,
        6, 3, 1, 6, 3, 1, 7, 3, 7, 3, 7, 3,  7,  3, 7, 3,  7,  3, 7, 3,  7,
        3, 7, 3, 7, 3, 7, 3, 7, 3, 7, 3, -7, -3, 7, 3, -7, -3, 7, 3, -7, -3,
    };
    int dofs[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 4, 2, 6,
                  4, 2, 6, 4, 2, 6, 2, 6, 2, 6, 2, 1, 1, 1, 1, 1, 1, 6, 2, 1, 1, 6,
                  2, 1, 1, 6, 2, 1, 1, 6, 2, 1, 1, 6, 2, 1, 1, 6, 2, 1, 1

    };
    int ncoefs[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4};
    double noncentrals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 6, 2, 6,
                            2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2, 6,
                            2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2, 6, 2};
    double gcoef[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double q[] = {1,   7,  20, 2,   20, 60,  10,  50,  120, 20, 100,
                  200, 10, 60, 150, 70, 160, 260, -40, 40,  140};
    int lim = 1000;
    double abstol = 1e-4;
    struct chi2comb_info info;
    int fault = 0;
    double res = 0.0;

    double expected[] = {
        0.054212946675253226303,  0.49355520181330159168, 0.8760272280402326972,
        0.0064348332078802972234, 0.60020819879723130708, 0.98389684789412334975,
        0.002697179606063082602,  0.56475302904079760502, 0.99122881453974709398,
        0.0061246216052206481351, 0.5913392182262962038,  0.97791384613661402891,
        0.045126148881611038988,  0.59243135753281106481, 0.97764841290122861395,
        0.043679499423862400143,  0.58476547524879196605, 0.95377443935266215114,
        0.078208009100773745459,  0.52210759195266853716, 0.96037034711779101226};

    int offset = 0;
    struct chi2comb_chisquareds chi2s;
    for (int i = 0; i < 21; ++i) {
        chi2s.coefs = coefs + offset;
        chi2s.dofs = dofs + offset;
        chi2s.ncents = noncentrals + offset;
        chi2s.n = ncoefs[i];
        fault = chi2comb_cdf(q[i], &chi2s, gcoef[i], lim, abstol, &info, &res);
        TEST_CHECK(fault == 0);
        TEST_CHECK(fabs(res - expected[i]) < EPSILON);
        offset += *(ncoefs + i);
    }
}

TEST_LIST = {{"test_chi2comb", test_chi2comb},
             {"test_chi2comb_table", test_chi2comb_table},
             {NULL, NULL}};
