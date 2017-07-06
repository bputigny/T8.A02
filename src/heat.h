#ifndef HEAT_H
#define HEAT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <omp.h>

#define error(msg) { fprintf(stderr, "ERROR: %s\n", (msg)); exit(EXIT_FAILURE); }

void time_step(double alpha, double dx, double dt,
        double *u1, const double *u0, int n);

void clear_heat(const char *filename);

void write_heat(double *u, int n, const char *filename);

#endif // HEAT_H
