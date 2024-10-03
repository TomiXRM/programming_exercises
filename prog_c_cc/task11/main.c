#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

// dy/dx = 2x+3yを定義
double f(double x, double y) {
    return 2 * x + 3 * y;
}

int main(void) {
    // 常微分方程式 dy/dx = 2x+3yの解を、初期条件 x_0,y_0 = 0,1の元で、Runge-Kutta法により0.1刻みで求めよ

    // 普通にやる
    uint8_t n = 10;      // 分割数
    double h = 0.1;      // 刻み幅
    double x = 0, y = 1; // 初期条件
    double k1, k2, k3, k4;

    int i = 0;

    while (i < n) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        x = x + h;
        i++;
        printf("N:%d x:%f y:%f\n", i, x, y);
    }
    printf("=========================\n");
    // ライブラリを使ってやる

    double x0 = 0;
    double y0 = 1;
    double result[n];
    runge_kutta_4(f, y0, x0, h, n, result);
    for (int i = 0; i < n; i++) {
        printf("N:%d x:%f y:%f\n", i + 1, (i + 1) * h, result[i]);
    }
}
