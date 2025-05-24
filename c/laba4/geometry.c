#include <math.h>
#include <stdio.h>
#include "geometry.h"

int proverkaTreugolnika(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double perimetr(double a, double b, double c) {
    return a + b + c;
}

double ploshad(double a, double b, double c) {
    double p = perimetr(a, b, c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double visotaToSide(double Side, double pl) {
    if (pl == 0) {
        return 0;
    }
    return (2 * pl) / Side;
}
