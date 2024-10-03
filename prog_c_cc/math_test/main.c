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

    // 区間の数
    int n = 100;
    double a = 1;
    double b = 2;
    float sum = simpson_rule1_3(f, a, b, n);

    printf("sum = %f\n", sum);
}
