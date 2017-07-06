#include "memlayout.h"

int main(int argc, char *argv[]) {
    point_t *pts;
    int i, r, n = 64;

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

    pts = malloc(n*sizeof(*pts));
    if (!pts) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; i++) {
        init(pts, n);
    }

    double t0 = omp_get_wtime();
    for (r=0; r<REPS; r++) {
        update(pts, n);
    }
    double t1 = omp_get_wtime();

    printf("CPU time: %.3fs\n", t1 - t0);

    free(pts);

    return 0;
}

