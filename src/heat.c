#include "heat.h"

void time_step(double alpha, double dx, double dt,
        double *u1, const double *u0, int n) {
    for (int i=1; i<n-1; i++) {
        for (int j=1; j<n-1; j++) {
            u1[i*n + j] = u0[i*n + j] +
                alpha*(u0[(i-1)*n + j] +
                        u0[(i+1)*n + j] -
                        4*u0[i*n + j] +
                        u0[i*n + j-1] +
                        u0[i*n + j+1]) * dt / (dx*dx);
        }
    }
}

void clear_heat(const char *filename) {
    FILE *f = fopen(filename, "w+");
    if (!f) {
        fprintf(stderr, "Opening `%s\' failed\n", filename);
        return;
    }
    fclose(f);
}

void write_heat(double *u, int n, const char *filename) {
    int i, j;
    FILE *f = fopen(filename, "a");
    if (!f) {
        fprintf(stderr, "Opening `%s\' failed\n", filename);
        return;
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            fprintf(f, "%e ", u[i*n + j]);
        }
    }
    fprintf(f, "\n");
    fclose(f);
}
