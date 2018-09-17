#ifndef CHI2COMB_CHI2COMB_H
#define CHI2COMB_CHI2COMB_H

#define CHI2COMB_VERSION "0.0.2"
#define CHI2COMB_VERSION_MAJOR 0
#define CHI2COMB_VERSION_MINOR 0
#define CHI2COMB_VERSION_PATCH 2

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#ifdef CHI2COMB_API_EXPORTS
#define CHI2COMB_API __declspec(dllexport)
#else
#define CHI2COMB_API __declspec(dllimport)
#endif
#else
#define CHI2COMB_API
#endif

struct chi2comb_chisquares {
    const double *coefs;  /* chi-square coefficients */
    const double *ncents; /* noncentrality parameters */
    const int *dofs;      /* degree of freedoms */
    int n;                /* number of terms */
};

struct chi2comb_info {
    double atol;     /* absolute error tolerance */
    int niterms;     /* total number of integration terms */
    int nints;       /* number of integrations */
    double interval; /* integration interval in final integration */
    double truc;     /* truncation point in initial integration */
    double sd;       /* s.d. of initial convergence factor */
    int ncycles;     /* cycles to locate integration parameters */
};

/** Cumulative distribution function of Chi-Square distribution combination.
 *
 * Returns
 * -------
 * error : int
 *     0: completed successfully
 *     1: required accuracy not achieved
 *     2: round-off error possibly significant
 *     3: invalid parameters
 *     4: unable to locate integration parameters
 *     5: out of memory
 */
CHI2COMB_API int chi2comb_cdf(double dof, struct chi2comb_chisquares *chi2s,
                              double *coef1, int *lim1, double *acc, double *trace,
                              double *res);

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: CHI2COMB_CHI2COMB_H */