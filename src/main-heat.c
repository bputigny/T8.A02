#include "heat.h"

int main(int argc, char *argv[]) {
    int i, j, n;
    int nx = 256, nt = 1000;
    double alpha = 1e-1;
    double dt, dx;

    char c;
    while ((c = getopt(argc, argv, "t:x:")) != EOF) {
        switch(c) {
            case 'x':
                nx = atoi(optarg);
                break;
            case 't':
                nt = atoi(optarg);
                break;
        }
    }
    dx = 1.0 / (nx-1);
    dt = dx*dx / (4*alpha);

    printf("Heat equation:\n");
    printf("  nx=%d (dx=%e)\n  nt=%d (dt=%e)\n",
            nx, dx, nt, dt);

    double *u0 = malloc(nx*nx * sizeof(*u0));
    double *u1 = malloc(nx*nx * sizeof(*u1));

    if (u0 == NULL || u1 == NULL) {
        error("Could not allocate memory!");
    }

    for (i=0; i<nx; i++) {
        double x = -1. + 2*i*dx;
        for (j=0; j<nx; j++) {
            u0[i*nx+j] = 1 - x*x;
        }
    }
    memcpy(u1, u0, nx*nx*sizeof(*u0));

    clear_heat("heat.dat");
    write_heat(u0, nx, "heat.dat");
    double t0 = omp_get_wtime();
    for (n=0; n<nt; n+=2) {
        time_step(alpha, dx, dt, u1, u0, nx);
        time_step(alpha, dx, dt, u0, u1, nx);
    }
    double t1 = omp_get_wtime();
    printf("CPU time=%.2lfs\n", t1-t0);
    write_heat(u0, nx, "heat.dat");

    free(u0);
    free(u1);

    return 0;
}

