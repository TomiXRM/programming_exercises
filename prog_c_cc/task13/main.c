#include <stdio.h>
#include "lib/mymath.h"

// 2階微分方程式を解く
// d^2y/dx^2 = f(x,y,dy/dx)
// d^2y/dx^2 = x * {dy/dx} + y
// 初期条件(x0,y0) = (0,1) , [dy/dx = 1 (x=x0)]
// 区間[0,1]
// 10分割

#define N 10
#define H 0.1

// 2階微分方程式を2本の1階微分方程式に分解する

// f'' = f(x,y,y') = x * y' + y
// f' = y'
// f = y
double f__(double x, double y, double y_) {
    return x * y_ + y;
}

double f_(double x, double y, double y_) {
    return y_;
}

void runge_kutta_4_system(double (*f1)(double, double, double), double (*f2)(double, double, double), double y0, double y1_0, double x0, double h, int steps, double *result_y, double *result_y1) {
    double x = x0;
    double y = y0;
    double y1 = y1_0;
    for (int i = 0; i < steps; i++) {
        double k1_y = h * f1(x, y, y1);
        double k1_y1 = h * f2(x, y, y1);

        double k2_y = h * f1(x + h / 2, y + k1_y / 2, y1 + k1_y1 / 2);
        double k2_y1 = h * f2(x + h / 2, y + k1_y / 2, y1 + k1_y1 / 2);

        double k3_y = h * f1(x + h / 2, y + k2_y / 2, y1 + k2_y1 / 2);
        double k3_y1 = h * f2(x + h / 2, y + k2_y / 2, y1 + k2_y1 / 2);

        double k4_y = h * f1(x + h, y + k3_y, y1 + k3_y1);
        double k4_y1 = h * f2(x + h, y + k3_y, y1 + k3_y1);

        y = y + (k1_y + 2 * k2_y + 2 * k3_y + k4_y) / 6;
        y1 = y1 + (k1_y1 + 2 * k2_y1 + 2 * k3_y1 + k4_y1) / 6;
        x = x + h;

        result_y[i] = y;
        result_y1[i] = y1;
    }
}

int main() {
    double result_y[N];
    double result_y1[N];

    runge_kutta_4_system(f_, f__, 1.0, 1.0, 0.0, H, N, result_y, result_y1);

    for (int i = 0; i < N; i++) {
        printf("x = %f, y = %f, y' = %f\n", i * H, result_y[i], result_y1[i]);
    }

    return 0;
}