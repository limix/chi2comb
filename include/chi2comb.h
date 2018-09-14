#ifndef CHI2COMB_CHI2COMB_H
#define CHI2COMB_CHI2COMB_H

#define CHI2COMB_VERSION "0.0.2"
#define CHI2COMB_VERSION_MAJOR 0
#define CHI2COMB_VERSION_MINOR 0
#define CHI2COMB_VERSION_PATCH 2

void qfc(double *lb1, double *nc1, int *n1, int *r1, double *sigma, double *c1,
         int *lim1, double *acc, double *trace, int *ifault, double *res);

/*  distribution function of a linear combination of non-central
   chi-squared random variables :

input:
   lb[j]            coefficient of j-th chi-squared variable
   nc[j]            non-centrality parameter
   n[j]             degrees of freedom
   j = 0, 2 ... r-1
   sigma            coefficient of standard normal variable
   c                point at which df is to be evaluated
   lim              maximum number of terms in integration
   acc              maximum error

output:
   ifault = 1       required accuracy NOT achieved
            2       round-off error possibly significant
            3       invalid parameters
            4       unable to locate integration parameters
            5       out of memory

   trace[0]         absolute sum
   trace[1]         total number of integration terms
   trace[2]         number of integrations
   trace[3]         integration interval in final integration
   trace[4]         truncation point in initial integration
   trace[5]         s.d. of initial convergence factor
   trace[6]         cycles to locate integration parameters     */

#endif /* end of include guard: CHI2COMB_CHI2COMB_H */