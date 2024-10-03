#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

double f(double x) {
    return 1 / x;
}

int main(void) {
    // Simpson の1/3公式で1→2の範囲で1/xの積分を求める

    uint8_t n[3] = {10, 30, 50}; // 区間の数
    double a = 1;
    double b = 2;
    double sum[3] = {0};

    for (uint8_t i = 0; i < 3; i++) {
        sum[i] = simpson_rule1_3(f, a, b, n[i]);
        printf("n=%dの時 sum = %.10f\n", n[i], sum[i]);
    }
    printf("==============================\n");
    for (uint8_t i = 0; i < 3; i++) {
        printf("n=%dの時 sum = %.10f\n", n[i], sum[i]); // 小数点10桁まで表示
    }
}
