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

CHI2COMB_API void qfc(double *lb1, double *nc1, int *n1, int *r1, double *sigma,
                      double *c1, int *lim1, double *acc, double *trace, int *ifault,
                      double *res);

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: CHI2COMB_CHI2COMB_H */