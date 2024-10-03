#include "mymath.h"
#include "mymatrix.h"
#include <math.h>
/*
 * @brief: この関数は二分法で与えられた関数の根を見つける
 * @param: f: 関数(関数ポインタ)
 * @param: a: 区間の下限
 * @param: b: 区間の上限
 * @param: tol: 許容誤差(tolerance)
 */
double bisection(double (*f)(double), double a, double b, double tol) {
    double fa = f(a);
    double fb = f(b);
    if (fa * fb > 0) {
        printf("Error: f(a)とf(b)は同符号です\n");
        return 0;
    }
    double c = (a + b) / 2;
    double fc = f(c);
    uint8_t count = 0;
    while (fabs(fc) > tol) {
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        c = (a + b) / 2;
        fc = f(c);
        count++;
        printf("count:%d a=%f, b=%f, c=%f, f(c)=%f\n", count, a, b, c, fc);
    }
    return c;
}

/*
 * @brief: この関数はニュートン・ラプソン法で与えられた関数の根を見つける
 * @param: f: 関数
 * @param: df: 関数の導関数
 * @param: x0: 初期推定値
 * @param: tol: 許容誤差(tolerance)
 */
double newton_raphson(double (*f)(double), double (*df)(double), double x0, double tol) {
    double x = x0;
    double fx = f(x);
    while (fabs(fx) > tol) {
        x = x - fx / df(x);
        fx = f(x);
    }
    return x;
}

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
double trapezoidal_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * (f(a) + f(b) + 2 * sum) / 2;
}

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
double simpson_rule(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum1 += f(a + i * h);
        } else {
            sum2 += f(a + i * h);
        }
    }
    return h * (f(a) + f(b) + 2 * sum1 + 4 * sum2) / 3;
}

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
void runge_kutta_4(double (*f)(double, double), double y0, double x0, double h, int steps, double *result) {
    double x = x0;
    double y = y0;
    for (int i = 0; i < steps; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
        result[i] = y;
    }
}

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
int gauss_jordan(double **A, double *b, int n) {
    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        if (pivot == 0) {
            return 0;
        }
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
        }
        b[i] /= pivot;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double ratio = A[j][i];
                for (int k = 0; k < n; k++) {
                    A[j][k] -= ratio * A[i][k];
                }
                b[j] -= ratio * b[i];
            }
        }
    }
    return 1;
}

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
void least_squares(double *x, double *y, int n, int degree, double *coeff) {
    Matrix A = matrix_create(n, degree + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < degree + 1; j++) {
            A.data[i][j] = pow(x[i], j);
        }
    }
    Matrix At = matrix_create(degree + 1, n);
    matrix_transpose(&A, &At);
    Matrix AtA = matrix_create(degree + 1, degree + 1);
    matrix_multiply(&At, &A, &AtA);
    double *Atb = (double *)malloc((degree + 1) * sizeof(double));
    for (int i = 0; i < n; i++) {
        Atb[i] = 0;
        for (int j = 0; j < n; j++) {
            Atb[i] += At.data[i][j] * y[j];
        }
    }
    gauss_jordan(AtA.data, Atb, degree + 1);
    for (int i = 0; i < degree + 1; i++) {
        coeff[i] = Atb[i];
    }
    matrix_free(&A);
    matrix_free(&At);
    matrix_free(&AtA);
    free(Atb);
}
