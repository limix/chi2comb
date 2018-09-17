# chi2comb

[![Travis](https://img.shields.io/travis/com/limix/chi2comb/master.svg?style=flat-square&label=linux%20%2F%20macos%20build)](https://travis-ci.com/limix/chi2comb) [![AppVeyor](https://img.shields.io/appveyor/ci/Horta/chi2comb.svg?style=flat-square&label=windows%20build)](https://ci.appveyor.com/project/Horta/chi2comb)

Cumulative density function of linear combinations of independent chi-square random
variables and a standard Normal distribution.

As of now, this is basically a repackaging of the `davies` function implemented in the
[CompQuadForm](https://cran.r-project.org/package=CompQuadForm) library for R.

## Requirements

It requires an C compiler toolchain that supports the C11 standard and the
[cmake](https://cmake.org/) software for orchestrating the building process.

## Install

You can install it via `conda`:

```bash
conda install -c conda-forge chi2comb
```

A second installation option would be to download the latest source and to build it by
yourself.
On Linux or macOS systems it can be as simple as:

```bash
bash <(curl -fsSL https://raw.githubusercontent.com/limix/chi2comb/master/install)
```

Similarly, on Windows you can install by entering in the terminal:

```powershell
powershell -Command "(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/limix/chi2comb/master/install.bat', 'install.bat')" && install.bat
```

## Documentation

This library exports a single function:

```C
/** Cumulative distribution function of Chi-Square distribution combination.
 *
 * Parameters
 * ----------
 * q : double
 *     Value point at which distribution function is to be evaluated.
 * chi2s : struct chi2comb_chisquares
 *     Chi-square distributions.
 * gcoef : double
 *     Coefficient of the standard Normal distribution.
 * lim : int
 *     Maximum number of integration terms.
 * abstol : double
 *     Absolute error tolerance.
 * info : struct chi2comb_info*
 *     Algorithm information.
 * result : double *
 *     Estimated c.d.f. evaluated at `q`.
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
CHI2COMB_API int chi2comb_cdf(double q, struct chi2comb_chisquares *chi2s, double gcoef,
                              int lim, double abstol, struct chi2comb_info *info,
                              double *result);
```

The structure

```C
struct chi2comb_chisquares {
    const double *coefs;  /* chi-square coefficients */
    const double *ncents; /* noncentrality parameters */
    const int *dofs;      /* degree of freedoms */
    int n;                /* number of terms */
};
```

represents a list of
[Noncentral chi-squared distributions](https://en.wikipedia.org/wiki/Noncentral_chi-squared_distribution)
and their coefficients.

The structure

```C
struct chi2comb_info {
    double emag; /* error magnitude */
    int niterms; /* total number of integration terms */
    int nints;   /* number of integrations */
    double intv; /* integration interval in final integration */
    double truc; /* truncation point in initial integration */
    double sd;   /* s.d. of initial convergence factor */
    int ncycles; /* cycles to locate integration parameters */
};
```

stores information about the optimisation method for estimating the c.d.f.

## Acknowledgments

- P. Lafaye de Micheaux for creating the amazing CompQuadForm library for R.

## Authors

- [Danilo Horta](https://github.com/horta)

## License

This project is licensed under the
[MIT License](https://raw.githubusercontent.com/limix/chi2comb/master/LICENSE.md).
