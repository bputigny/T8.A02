#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <omp.h>

#define REPS 10000

// #pragma omp declare simd
float f(float x);

#endif // FUNC_H
