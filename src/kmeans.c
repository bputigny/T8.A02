#include "kmeans.h"

point_t *alloc_points(int n) {
    point_t *pts = malloc(n*sizeof(*pts));
    if (!pts) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return pts;
}

void free_points(point_t *pts) {
    free(pts);
}

// Assign n points to k clusters
void kmeans(point_t *pts, size_t n, size_t *cluster, size_t k) {
    size_t i, j;
    point_t *mean = alloc_points(k);
    size_t *count = malloc(k*sizeof(*count));

    if (!count) {
        fprintf(stderr, "malloc faield\n");
        exit(EXIT_FAILURE);
    }

    for (j=0; j<k; j++) {
        count[j] = 0;
        mean[j].x = .0;
        mean[j].y = .0;
        mean[j].z = .0;
    }

    for (i=0; i<n; i++) {
        cluster[i] = i%k;
        count[cluster[i]]++;

        mean[cluster[i]].x = pts[i].x;
        mean[cluster[i]].y = pts[i].y;
        mean[cluster[i]].z = pts[i].z;
    }

    int flips = 1;
    int iter = 0;
    while (flips > 0) {
        iter++;
        flips = 0;

        // Look for nearest mean
        for (i=0; i<n; i++) {
            float dmin = .0;   // min distance
            size_t c = cluster[i]; // nearest mean
            for (j=0; j<k; j++) {
                float dx = pts[i].x - mean[j].x;
                float dy = pts[i].y - mean[j].y;
                float dz = pts[i].z - mean[j].z;
                float d = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
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
            mean[cluster[i]].x = .0;
            mean[cluster[i]].y = .0;
            mean[cluster[i]].z = .0;
            count[cluster[i]] = 0;
        }
        for (i=0; i<n; i++) {
            size_t c = cluster[i];
            mean[c].x += pts[i].x;
            mean[c].y += pts[i].y;
            mean[c].z += pts[i].z;
            count[c]++;
        }
        for (j=0; j<k; j++) {
            mean[j].x /= count[j];
            mean[j].y /= count[j];
            mean[j].z /= count[j];
        }

    }

    free_points(mean);
    free(count);
}
