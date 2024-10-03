#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

// 関数 f= -xy
double f(double x, double y) {
    return -x * y;
}

int main(void) {
    // f(x,y) = -xy
    // y(0) = 15
    // 計算区間[0,15]
    // 刻み幅h=0.5と0.25の2種

    // 解:y(x) = 15 * exp(-x^2/2)

    double h[2] = {0.5, 0.25};

    double x0 = 0;
    double y0 = 15;

    double result_050[15] = {0}; // 0.5刻みのresult
    double result_025[30] = {0}; // 0.25刻みのresult

    runge_kutta_4(f, y0, x0, 0.5, 15.0, result_050);
    runge_kutta_4(f, y0, x0, 0.25, 30.0, result_025);

    printf("🍣0.5刻み\n");
    for (int i = 0; i < 15; i++) {
        printf("0.5刻み [%d]: %f\n", i, result_050[i]);
    }
    printf("🍣0.25刻み\n");
    for (int i = 0; i < 30; i++) {
        printf("0.25刻み [%d]: %f\n", i, result_025[i]);
    }
}
