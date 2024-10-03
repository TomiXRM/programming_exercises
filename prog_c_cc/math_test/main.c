#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

// dy/dx = sinx + cosyを定義
double f(double x, double y) {
    return sin(x) + cos(y);
}

int main(void) {
    // 常微分方程式 dy/dx = sinx + cosyの解を、初期条件 x_0,y_0 = 0,0の元で、Runge-Kutta法によりx=pi/2まで15等分して求めよ

    // 普通にやる
    uint8_t n = 15;        // 分割数
    double h = M_PI_2 / n; // 刻み幅
    double x, y = 0;
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
    double result[n];
    runge_kutta_4(f, 0, 0, h, n, result);
    for (int i = 0; i < n; i++) {
        printf("N:%d x:%f y:%f\n", i + 1, (i + 1) * h, result[i]);
    }
}
