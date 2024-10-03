#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

#define PI 3.14159265

double f(double x) {
    return 1 / (2 + sin(x) + cos(x));
}

int main(void) {

    double root2_times_pi = sqrt(2) * PI;

    uint8_t n[3] = {10, 30, 50};
    double a = -PI;
    double b = PI;
    double sum[3] = {0};

    for (uint8_t i = 0; i < 3; i++) {
        printf("🍣n=%dの時\n", n[i]);
        sum[i] = simpson_rule1_3(f, a, b, n[i]);
    }

    printf("=============================\n");

    printf("√2×π = %.20f\n", root2_times_pi);
    printf("n=%dの時 sum = %.20f 誤差:%f\n", n[0], sum[0], root2_times_pi - sum[0]);
    printf("n=%dの時 sum = %.20f 誤差:%f\n", n[1], sum[1], root2_times_pi - sum[1]);
    printf("n=%dの時 sum = %.20f 誤差:%f\n", n[2], sum[2], root2_times_pi - sum[2]);
}
