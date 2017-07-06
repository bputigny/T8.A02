#include "kmeans.h"

int main(int argc, char *argv[]) {
    point_t pts;
    int i, r, n = 10000;
    int k = 3;
    int *cluster;

    char c;
    while ((c = getopt(argc, argv, "n:k:")) != EOF) {
        switch(c) {
            case 'n':
                n = atoi(optarg);
                break;
            case 'k':
                k = atoi(optarg);
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }

    pts = alloc_points(n);
    cluster = malloc(n * sizeof(*cluster));

    if (!cluster) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; i++) {
        pts.x[i] = i;
        pts.y[i] = i;
        pts.z[i] = i;
    }

    double t0 = omp_get_wtime();
    for (r=0; r<REPS; r++) {
        kmeans(pts, n, cluster, k);
    }
    double t1 = omp_get_wtime();

    // for (i=0; i<n; i++) {
    //     printf("point %d (%.2f, %.2f) -> cluster %d\n", i, x[i], y[i], cluster[i]);
    // }

    printf("CPU time: %.3fs\n", t1 - t0);

    free_points(pts);
    free(cluster);

    return 0;
}

