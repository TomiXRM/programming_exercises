#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

// f(x)=e^x -3x
double f(double x) {
    return exp(x) - 3 * x;
}

// f(x)の導関数
double df(double x) {
    return exp(x) - 3;
}

int main(void) {
    // f(x)=e^x -3xの解をニュートンラプソン法で求める。x_0 = 0 , ε=10^-5。
    double root = newton_raphson(f, df, 0, 1e-5);
    printf("The root of the function is %f\n", root);
}
