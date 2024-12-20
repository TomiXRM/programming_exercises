#include <stdio.h>
#include <math.h>
#include "lib/mymath.h"
#include "lib/mymatrix.h"

// table2のデータ
const double x_data[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
const double y_data[] = {13.4, 7.2, 2.7, 1.2, 0.6, 3.1, 6.9, 12.5, 20.8, 31.7, 44.0};

// 最小二乗法で与えられたデータをもとにN次多項式を求める
void least_squares_polynomial(int degree, const double x[], const double y[], int n, double *coefficients) {
    int m = degree + 1;
    Matrix A = matrix_create(m, m);
    double *b = (double *)malloc(m * sizeof(double));

    // 行列Aとベクトルbを初期化
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A.data[i][j] = 0;
            for (int k = 0; k < n; k++) {
                A.data[i][j] += pow(x[k], i + j);
            }
        }
        b[i] = 0;
        for (int k = 0; k < n; k++) {
            b[i] += y[k] * pow(x[k], i);
        }
    }

    // print
    printf("🟥A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", A.data[i][j]);
        }
        printf("\n");
    }
    printf("🟦b:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f\n", b[i]);
    }

    // 連立方程式を解く
    gauss_jordan(&A, b, m);
    for (int i = 0; i < m; i++) {
        coefficients[i] = b[i];
    }

    // メモリ解放
    matrix_free(&A);
    free(b);
}

// 2乗累積誤差を計算する関数
double calculate_accumulated_square_error(int degree, const double x[], const double y[], int n, const double *coefficients) {
    double error = 0.0;
    for (int i = 0; i < n; i++) {
        double y_estimated = 0.0;
        for (int j = 0; j <= degree; j++) {
            y_estimated += coefficients[j] * pow(x[i], j);
        }
        error += pow(y[i] - y_estimated, 2);
    }
    return error;
}

int main() {
    double coefficients[4];
    int n = sizeof(x_data) / sizeof(x_data[0]);

    // 1次多項式の係数を求める
    least_squares_polynomial(1, x_data, y_data, n, coefficients);
    double error1 = calculate_accumulated_square_error(1, x_data, y_data, n, coefficients);
    printf("1次多項式: a = %f, b = %f\n", coefficients[1], coefficients[0]);
    printf("y = %fx + %f\n", coefficients[1], coefficients[0]);
    printf("Accumulated Square Error (1次): %f\n", error1);

    // 2次多項式の係数を求める
    least_squares_polynomial(2, x_data, y_data, n, coefficients);
    double error2 = calculate_accumulated_square_error(2, x_data, y_data, n, coefficients);
    printf("2次多項式: a = %f, b = %f, c = %f\n", coefficients[2], coefficients[1], coefficients[0]);
    printf("y = %fx^2 + %fx + %f\n", coefficients[2], coefficients[1], coefficients[0]);
    printf("Accumulated Square Error (2次): %f\n", error2);

    // 3次多項式の係数を求める
    least_squares_polynomial(3, x_data, y_data, n, coefficients);
    double error3 = calculate_accumulated_square_error(3, x_data, y_data, n, coefficients);
    printf("3次多項式: a = %f, b = %f, c = %f, d = %f\n", coefficients[3], coefficients[2], coefficients[1], coefficients[0]);
    printf("y = %fx^3 + %fx^2 + %fx + %f\n", coefficients[3], coefficients[2], coefficients[1], coefficients[0]);
    printf("Accumulated Square Error (3次): %f\n", error3);

    return 0;
}