#include "dotproduct.h"

int main(int argc, char *argv[]) {
    double *A, *B;
    int i, r, n = 10000;

    char c;
    while ((c = getopt(argc, argv, "n:")) != EOF) {
        switch(c) {
            case 'n':
                n = atoi(optarg);
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }

    A = malloc(n * sizeof(*A));
    B = malloc(n * sizeof(*B));

    if (!A || !B) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; i++) {
        A[i] = i+1;
        B[i] = 1./A[i];
    }

    double t0 = omp_get_wtime();
    double d = 0;
    for (r=0; r<REPS; r++) {
        d += dotproduct(A, B, n);
    }
    d /= REPS;
    double t1 = omp_get_wtime();

    if (fabs(((double) n) - d) > 1e-10) {
        fprintf(stderr, "ERROR in dotproduct\n");
        fprintf(stderr, "dot=%e, should be:%e\n", d, (double) n);
    }
    printf("CPU time: %.3fs\n", t1 - t0);

    free(A);
    free(B);

    return 0;
}

