#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// prototype declaration
double bisection(double (*f)(double), double a, double b, double tol);
double newton_raphson(double (*f)(double), double (*df)(double), double x0, double tol);
double trapezoidal_rule(double (*f)(double), double a, double b, int n);
double simpson_rule1_3(double (*f)(double), double a, double b, int n);
double simpson_rule3_8(double (*f)(double), double a, double b, int n);

void runge_kutta_4(double (*f)(double, double), double y0, double x0, double h, int steps, double *result);
int gauss_jordan(Matrix *A, double *b, int n);
void least_squares(double *x, double *y, int n, int degree, double *coeff);

Matrix matrix_create(int rows, int cols);
void matrix_add(Matrix *A, Matrix *B, Matrix *result);
void matrix_subtract(Matrix *A, Matrix *B, Matrix *result);
void matrix_multiply(Matrix *A, Matrix *B, Matrix *result);
void matrix_transpose(Matrix *A, Matrix *result);
void matrix_print(Matrix *matrix);
void matrix_free(Matrix *matrix);

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
    double dfx = df(x);
    double dx = 0;
    uint8_t count = 0;
    printf("inital  x=%f, f(x)=%f, df(x)=%f, dx=%f\n", x, fx, dfx, dx);
    while (fabs(fx) > tol) {
        x = x - fx / df(x);
        fx = f(x);
        dfx = df(x);
        dx = -fx / df(x);
        printf("count:%d x=%f, f(x)=%f, df(x)=%f, dx=%f\n", count, x, fx, dfx, dx);
        count++;
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
 * @brief: この関数は与えられた関数の積分を計算する。Simpsonの1/3公式を使用する。
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数。nは偶数である必要がある。
 */
double simpson_rule1_3(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Error: nは偶数である必要があります\n");
        return 0;
    }
    double h = (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum1 += f(a + i * h);
        } else {
            sum2 += f(a + i * h);
        }
        printf("i:%d sum1=%f, sum2=%f\n", i, sum1, sum2);
    }
    return h * (f(a) + f(b) + 2 * sum1 + 4 * sum2) / 3;
}

/*
 * @brief: この関数は与えられた関数の積分を計算する。Simpsonの3/8公式を使用する。
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数。nは3の倍数である必要がある。
 */
double simpson_rule3_8(double (*f)(double), double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Error: nは3の倍数である必要があります\n");
        return 0;
    }
    double h = (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;
    double sum3 = 0;
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum1 += f(a + i * h);
        } else if (i % 3 == 1) {
            sum2 += f(a + i * h);
        } else {
            sum3 += f(a + i * h);
        }
        printf("i:%d sum1=%f, sum2=%f, sum3=%f\n", i, sum1, sum2, sum3);
    }
    return 3 * h * (f(a) + f(b) + 2 * sum1 + 3 * sum2 + 3 * sum3) / 8;
}

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数(xとyの2変数関数)
 * @param: y0: 初期値
 * @param: x0: 初期値
 * @param: h: 刻み幅
 * @param: steps: ステップ数(分割数)
 * @param: result: 結果を格納する配列
 */
void runge_kutta_4(double (*f)(double, double), double y0, double x0, double h, int steps, double *result) {
    double x = x0;
    double y = y0;
    printf("x0=%f, y0=%f\n", x0, y0);
    printf("h=%f, steps=%d\n", h, steps);
    for (int i = 0; i < steps; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
        result[i] = y;
        printf("i:%d x=%f, y=%f\n", i, x, y);
    }
}

/*
 * @brief: この関数は連立一次方程式をGauss-Jordan法で解く
 * @param: A: 係数行列
 * @param: b: 定数項
 * @param: n: 次数
 */
int gauss_jordan(Matrix *A, double *b, int n) {
    for (int i = 0; i < n; i++) {
        double pivot = A->data[i][i];
        if (pivot == 0) {
            return 0;
        }
        for (int j = 0; j < n; j++) {
            A->data[i][j] /= pivot;
        }
        b[i] /= pivot;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double ratio = A->data[j][i];
                for (int k = 0; k < n; k++) {
                    A->data[j][k] -= ratio * A->data[i][k];
                }
                b[j] -= ratio * b[i];
            }
        }
    }
    return 1;
}

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
    gauss_jordan(&AtA, Atb, degree + 1);
    for (int i = 0; i < degree + 1; i++) {
        coeff[i] = Atb[i];
    }
    matrix_free(&A);
    matrix_free(&At);
    matrix_free(&AtA);
    free(Atb);
}

Matrix matrix_create(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

/*
 * @brief: 二つの行列の和を計算する
 * @param A: 行列A
 * @param B: 行列B
 * @param result: 結果を格納する行列
 */

void matrix_add(Matrix *A, Matrix *B, Matrix *result) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Error: 行列のサイズが一致しません\n");
        return;
    }
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
}

/*
 * @brief: 二つの行列の差を計算する
 * @param A: 行列A
 * @param B: 行列B
 * @param result: 結果を格納する行列
 */

void matrix_subtract(Matrix *A, Matrix *B, Matrix *result) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Error: 行列のサイズが一致しません\n");
        return;
    }
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }
}

/*
 * @brief: 二つの行列の積を計算する
 * @param A: 行列A
 * @param B: 行列B
 * @param result: 結果を格納する行列
 */

void matrix_multiply(Matrix *A, Matrix *B, Matrix *result) {
    if (A->cols != B->rows) {
        printf("Error: 行列のサイズが一致しません\n");
        return;
    }
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++) {
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }
}

/*
 * @brief: 行列の転置を計算する
 * @param A: 元の行列
 * @param result: 結果を格納する行列
 */

void matrix_transpose(Matrix *A, Matrix *result) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->data[j][i] = A->data[i][j];
        }
    }
}

/*
 * @brief: 行列を表示する
 * @param matrix: 行列構造体
 */

void matrix_print(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%.2f\t", matrix->data[i][j]); // 小数点2桁まで表示
        }
        printf("\n");
    }
}

/*
 * @brief: 行列を解放する
 * @param matrix: 行列構造体
 */

void matrix_free(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

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