
#ifndef MYMATH_H
#define MYMATH_H

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
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
double simpson_rule(double (*f)(double), double a, double b, int n);

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
void runge_kutta_4(double (*f)(double, double), double y0, double x0, double h, int steps, double *result);

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
int gauss_jordan(double **A, double *b, int n);

/*
 * @brief: この関数は与えられた関数の積分を計算する
 * @param: f: 関数
 * @param: a: 積分区間の下限
 * @param: b: 積分区間の上限
 * @param: n: 区間の数
 */
void least_squares(double *x, double *y, int n, int degree, double *coeff);

#endif