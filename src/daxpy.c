#include "daxpy.h"

void daxpy(double a, double *X, double *Y, int n) {
    int i;
    for (i=0; i<n; i++) {
        Y[i] = a*X[i] + Y[i];
    }
}
