
#ifndef MYMATH_H
#define MYMATH_H

#include "mymatrix.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * @brief: This file contains the prototypes of the functions that are implemented in mymath.c
 */

/*
 * @brief: この関数は二分法で与えられた関数の根を見つける
 * @param: f: 関数
 * @param: a: 区間の下限
 * @param: b: 区間の上限
 * @param: tol: 許容誤差(tolerance)
 */
double bisection(double (*f)(double), double a, double b, double tol);

/*
 * @brief: この関数はニュートン・ラプソン法で与えられた関数の根を見つける
 * @param: f: 関数
 * @param: df: 関数の導関数
 * @param: x0: 初期推定値
 * @param: tol: 許容誤差(tolerance)
 */
double newton_raphson(double (*f)(double), double (*df)(double), double x0, double tol);

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
double trapezoidal_rule(double (*f)(double), double a, double b, int n);

/*
 * @brief: この関数は与えられた関数の積分を計算する。Simpsonの1/3公式を使用する。
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数。nは偶数である必要がある。
 */
double simpson_rule1_3(double (*f)(double), double a, double b, int n);

/*
 * @brief: この関数は与えられた関数の積分を計算する。Simpsonの3/8公式を使用する。
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数。nは3の倍数である必要がある。
 */
double simpson_rule3_8(double (*f)(double), double a, double b, int n);

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数(xとyの2変数関数)
 * @param: y0: 初期値
 * @param: x0: 初期値
 * @param: h: 刻み幅
 * @param: steps: ステップ数
 * @param: result: 結果を格納する配列
 */
void runge_kutta_4(double (*f)(double, double), double y0, double x0, double h, int steps, double *result);



int gauss_jordan(Matrix *A, double *b, int n);


void least_squares(double *x, double *y, int n, int degree, double *coeff);

#endif