#ifndef DAXPY_H
#define DAXPY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <omp.h>

#define REPS 100000

void daxpy(double a, double *X, double *Y, int n);

#endif // DAXPY_H
