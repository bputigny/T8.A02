#ifndef DOTPRODUCT_H
#define DOTPRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <omp.h>

#define REPS 100000

double dotproduct(double *A, double *B, int n);

#endif // DOTPRODUCT_H

