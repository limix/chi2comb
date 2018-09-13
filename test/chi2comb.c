#include "chi2comb.h"
#include <float.h>
#include <stdio.h>
#include <string.h>

int test_chi2comb() {

    double coef[] = {0.4, 1.1};
    double nc[] = {-1.3, 2.9};
    int dof[] = {1, 3};
    int ncoefs = 2;
    double coef1 = 0.41;
    double dof_eval = 2.0;
    int lim = 1000;
    double acc = 1e-8;
    double info[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    int fault = 0;
    double res = 0.0;

    qfc(coef, nc, dof, &ncoefs, &coef1, &dof_eval, &lim, &acc, info, &fault, &res);

    printf("\n");
    for (int i = 0; i < 7; ++i) {
        printf("%f ", info[i]);
    }
    printf("\n");
    printf("%d", fault);
    printf("\n%f\n", res);

    return 0;
}

int main() {
    test_chi2comb();

    size_t i;

    return 0;
}
