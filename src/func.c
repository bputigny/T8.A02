#include "func.h"

// #pragma omp declare simd
float f(float x) {
    return x*x + 2*x + 1;
}
