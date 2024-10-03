#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

// f(x) = x^3 - 7x^2 +16x -10
double f(double x) {
    return pow(x, 3) - 7 * pow(x, 2) + 16 * x - 10;
}

// f(x)の導関数
double df(double x) {
    return 3 * pow(x, 2) - 14 * x + 16;
}

int main(void) {
    // f(x)=e^x -3xの解をニュートンラプソン法で求める。x_0 = 0 , ε=10^-5。
    double root = newton_raphson(f, df, 0, 1e-5);
    printf("The root of the function is %f\n", root);
}
