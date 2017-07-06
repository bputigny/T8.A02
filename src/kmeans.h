#ifndef KMEANS_H
#define KMEANS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <omp.h>

#define REPS 2000

typedef struct {
    float x;
    float y;
    float z;
} point_t;

point_t *alloc_points(int n);

void free_points(point_t *pts);

// Assign n points to k clusters
void kmeans(point_t *pts, size_t n, size_t *cluster, size_t k);

#endif // KMEANS_H
