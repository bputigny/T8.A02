#include "kmeans.h"

point_t alloc_points(int n) {
    point_t pts;
    pts.x = malloc(n*sizeof(*pts.x));
    pts.y = malloc(n*sizeof(*pts.y));
    pts.z = malloc(n*sizeof(*pts.z));
    if (!pts.x || !pts.y || !pts.z) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return pts;
}

void free_points(point_t pts) {
    free(pts.x);
    free(pts.y);
    free(pts.z);
}

// Assign n points to k clusters
void kmeans(point_t pts, int n, int *cluster, int k) {
    int i, j;
    point_t mean = alloc_points(k);
    int *count = malloc(k*sizeof(*count));

    if (!count) {
        fprintf(stderr, "malloc faield\n");
        exit(EXIT_FAILURE);
    }

    for (j=0; j<k; j++) {
        count[j] = 0;
        mean.x[j] = .0;
        mean.y[j] = .0;
        mean.z[j] = .0;
    }

    for (i=0; i<n; i++) {
        cluster[i] = i%k;
        count[cluster[i]]++;

        mean.x[cluster[i]] = pts.x[i];
        mean.y[cluster[i]] = pts.y[i];
        mean.z[cluster[i]] = pts.z[i];
    }

    int flips = 1;
    int iter = 0;
    while (flips > 0) {
        iter++;
        flips = 0;

        // Look for nearest mean
        for (i=0; i<n; i++) {
            float dmin = .0;   // min distance
            int c = cluster[i]; // nearest mean
            for (j=0; j<k; j++) {
                float dx = pts.x[i] - mean.x[j];
                float dy = pts.y[i] - mean.y[j];
                float dz = pts.z[i] - mean.z[j];
                float d = dx*dx + dy*dy + dz*dz;
                if (d < dmin || j == 0) {
                    dmin = d;
                    c = j;
                }
            }

            for (j=0; j<k; j++) {
                if (cluster[i] != c) {
                    flips++;
                    cluster[i] = c;
                }
            }
        }

        // compute new cluster mean
        for (j=0; j<k; j++) {
            mean.x[cluster[i]] = .0;
            mean.y[cluster[i]] = .0;
            mean.z[cluster[i]] = .0;
            count[cluster[i]] = 0;
        }
        for (i=0; i<n; i++) {
            int c = cluster[i];
            mean.x[c] += pts.x[i];
            mean.y[c] += pts.y[i];
            mean.z[c] += pts.z[i];
            count[c]++;
        }
        for (j=0; j<k; j++) {
            mean.x[j] /= count[j];
            mean.y[j] /= count[j];
            mean.z[j] /= count[j];
        }

    }

    free_points(mean);
    free(count);
}
