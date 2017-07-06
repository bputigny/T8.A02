#include "dotproduct.h"

double dotproduct(double *A, double *B, int n) {
    int i;
    double s = .0;
#pragma omp simd reduction(+: s)
    for (i=0; i<n; i++) {
        s += A[i] * B[i];
    }
    return s;
}
