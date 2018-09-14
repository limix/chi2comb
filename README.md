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

TODO: write here

## Acknowledgments

- P. Lafaye de Micheaux for creating the amazing CompQuadForm library for R.

## Authors

- [Danilo Horta](https://github.com/horta)

## License

This project is licensed under the
[MIT License](https://raw.githubusercontent.com/limix/chi2comb/master/LICENSE.md).
