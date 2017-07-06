#include "memlayout.h"

void init(point_t *pts, int n) {
    int i;
    for (i=0; i<n; i++) {
        pts[i].x = i/(float) n;
        pts[i].y = i/(float) n;
    }
}

void update(point_t *pts, int n) {
    int i;
    for (i=0; i<n; i++) {
        pts[i].x = (pts[i].x + pts[i].y) / 2.;
        pts[i].y = (pts[i].x + pts[i].y) / 2.;
    }
}
