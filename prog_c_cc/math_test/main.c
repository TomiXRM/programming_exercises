#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

double f(double x) {
    return exp(x) - 3 * x;
}

int main(void) {
    // f(x)=e^x -3xの解を二分法で[0,1]の範囲で求める。ε=10^-5。
    double root = bisection(f, 0, 1, 1e-5);
    printf("The root of the function is %f\n", root);
}
