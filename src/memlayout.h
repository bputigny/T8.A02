#ifndef MEMLAYOUT_H
#define MEMLAYOUT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <omp.h>

#define REPS 1000000

typedef struct {
    float x;
    float y;
} point_t;

void init(point_t *pts, int n);

void update(point_t *pts, int n);

#endif // MEMLAYOUT_H
