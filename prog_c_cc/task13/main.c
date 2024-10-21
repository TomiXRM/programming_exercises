#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "lib/mymatrix.h"
#include "lib/mymath.h"

// 2階微分方程式を解く
// d^2y/dx^2 = f(x,y,dy/dx)
// d^2y/dx^2 = x * {dy/dx} + y
// 初期条件(x0,y0) = (0,1) , [dy/dx = 0 (x=x0)]
// 区間[0,1]
// 10分割

// 2階微分方程式を2本の1階微分方程式に分解する
// dy/dx = y1, dy1/dx = xy1 + y

#define N 10

double f_xy(double x, double y, double y1) {
    return x * y1 + y;
}

double f_y1(double x, double y, double y1) {
    return y1;
}


// 関数 f= -xy
double f(double x, double y) {
    return -x * y;
}

int main(void) {
    // 区間[0,1]を10分割
    double h = 1.0 / N;

    // 初期条件
    double x0 = 0;
    double y0 = 1;
    double y1_0 = 1; // dy/dx = y1 , dy/dx = 1より

    // 結果を格納する配列
    double x[N+1];

    // runge-kutta法で2階微分方程式を解く
    



}
