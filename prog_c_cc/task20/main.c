#include <stdio.h>
#include <math.h>
#include "lib/mymath.h"
#include "lib/mymatrix.h"
/*
肩持ち梁の曲げ問題
片持ちばりの自由端が集中荷重を受けるとき，長さlの片持ちばりが自由端に集中荷重W を受ける場合，固定端 からxの距離にある断面の曲げモーメントMは
M = -W(l-x)
である.また，はりのたわみ曲線を求める基本となる微分方程式は次式で表される.
d^2y/dx^2 = -M/EI = W/EI(l-x)
ここで， E ， I はそれぞれヤング率および断面二次モーメントであり，長方形断面では
I = 1/12 * bh^3 である

上記の微分方程式を数値的に解き、片持ち梁のｘ方向におけるｙ方向の変異の分布を計算する。
また、計算結果をグラフ表示するためにPrintfで出力する。

ただし、先端に集中荷重W=30Nを受けているものとし、ヤング率はE=206GPaとする。

RungeKutta法を用いて微分方程式を解くこと。
*/

/*
+++++メモ+++++

Euler-Bernoulli梁理論に基づいて、片持ち梁のたわみを計算すると

d^2 / dx^2 * (EI * d^2y/dx^2) = q(x)
- x : 梁の長さ
- y(x) : 梁の縦方向の変位
- E : ヤング率
- I : 断面二次モーメント

今回使う梁は長方形なんで、
I = bh^3 / 12 になる

q(x) :  単位長さあたりの荷重(今回は集中荷重なので0 or δ関数)
今回の問題は 梁の先端x=lに集中荷重Wがかかっているので、q(x) = Wδ(x-l) になる
δ(x-l) はデルタ関数

この微分方程式をRunge-Kutta法で解くことで、梁のたわみを求めることができる
EI * d^4y/dx^4 = 0 という曲げモーメント方程式になる

+++++境界条件+++++
固定端(x = 0)
- 変位 : y = 0
- 傾き : dy/dx = 0
自由端(x = l)
- 曲げモーメント : M = 0 (d^2y/dx^2 = 0)
- せん断力 : V = 0 (d^3y/dx^3 = 0)

+++++数値計算+++++
4次方程式を4つの1次方程式に分解
- y1 = y
- y2 = dy/dx
- y3 = d^2y/dx^2
- y4 = d^3y/dx^3

- dy1/dx = y2
- dy2/dx = y3
- dy3/dx = y4
- dy4/dx = q(x) / (EI)
*/

// 定数の定義
#define E 206e9  // ヤング率 [Pa]
#define W 30     // 集中荷重 [N]
#define h_ 0.005 // 厚み [m]
#define b 0.1    // 幅 [m]
#define l 0.5    // 長さ [m]

// 断面二次モーメント I の計算
#define I (1.0 / 12.0) * b *pow(h_, 3)

// Runge-Kutta法で使う微分方程式
double f1(double x, double y1, double y2, double y3, double y4) {
    return y2; // dy1/dx = y2
}

double f2(double x, double y1, double y2, double y3, double y4) {
    return y3; // dy2/dx = y3
}

double f3(double x, double y1, double y2, double y3, double y4) {
    return y4; // dy3/dx = y4
}

double f4(double x, double y1, double y2, double y3, double y4) {
    return -W * (l - x) / (E * I); // dy4/dx = q(x) / EI
}

// Runge-Kutta法を用いた計算 (4次のルンゲクッタ法) 引数は関数ポインタ4つ
void runge_kutta_4th(
    double (*f1)(double, double, double, double, double),
    double (*f2)(double, double, double, double, double),
    double (*f3)(double, double, double, double, double),
    double (*f4)(double, double, double, double, double),
    double y[], double x0, double h, int steps, double result[]) {

    for (int i = 0; i < steps; i++) {
        double k1[4], k2[4], k3[4], k4[4];
        double x = x0 + i * h;

        // k1の計算
        k1[0] = h * f1(x, y[0], y[1], y[2], y[3]);
        k1[1] = h * f2(x, y[0], y[1], y[2], y[3]);
        k1[2] = h * f3(x, y[0], y[1], y[2], y[3]);
        k1[3] = h * f4(x, y[0], y[1], y[2], y[3]);

        // k2の計算
        k2[0] = h * f1(x + h / 2, y[0] + k1[0] / 2, y[1] + k1[1] / 2, y[2] + k1[2] / 2, y[3] + k1[3] / 2);
        k2[1] = h * f2(x + h / 2, y[0] + k1[0] / 2, y[1] + k1[1] / 2, y[2] + k1[2] / 2, y[3] + k1[3] / 2);
        k2[2] = h * f3(x + h / 2, y[0] + k1[0] / 2, y[1] + k1[1] / 2, y[2] + k1[2] / 2, y[3] + k1[3] / 2);
        k2[3] = h * f4(x + h / 2, y[0] + k1[0] / 2, y[1] + k1[1] / 2, y[2] + k1[2] / 2, y[3] + k1[3] / 2);

        // k3の計算
        k3[0] = h * f1(x + h / 2, y[0] + k2[0] / 2, y[1] + k2[1] / 2, y[2] + k2[2] / 2, y[3] + k2[3] / 2);
        k3[1] = h * f2(x + h / 2, y[0] + k2[0] / 2, y[1] + k2[1] / 2, y[2] + k2[2] / 2, y[3] + k2[3] / 2);
        k3[2] = h * f3(x + h / 2, y[0] + k2[0] / 2, y[1] + k2[1] / 2, y[2] + k2[2] / 2, y[3] + k2[3] / 2);
        k3[3] = h * f4(x + h / 2, y[0] + k2[0] / 2, y[1] + k2[1] / 2, y[2] + k2[2] / 2, y[3] + k2[3] / 2);
        // k4の計算
        k4[0] = h * f1(x + h, y[0] + k3[0], y[1] + k3[1], y[2] + k3[2], y[3] + k3[3]);
        k4[1] = h * f2(x + h, y[0] + k3[0], y[1] + k3[1], y[2] + k3[2], y[3] + k3[3]);
        k4[2] = h * f3(x + h, y[0] + k3[0], y[1] + k3[1], y[2] + k3[2], y[3] + k3[3]);
        k4[3] = h * f4(x + h, y[0] + k3[0], y[1] + k3[1], y[2] + k3[2], y[3] + k3[3]);

        // yの更新 (y1, y2, y3, y4)
        for (int j = 0; j < 4; j++) {
            y[j] += (k1[j] + 2 * k2[j] + 2 * k3[j] + k4[j]) / 6;
        }

        result[i] = y[0]; // y(x) を格納
    }
}

int main() {
    // 初期化
    double y[4] = {0, 0, 0, 0}; // y, dy/dx, d^2y/dx^2, d^3y/dx^3
    double result[100];
    double x0 = 0.0;
    double h = 0.01; // ステップサイズ
    int steps = (int)(l / h);

    // Runge-Kutta法で解く
    runge_kutta_4th(f1, f2, f3, f4, y, x0, h, steps, result);

    // 結果を出力
    for (int i = 0; i < steps; i++) {
        printf("%f,%f\n", i * h, result[i]);
    }

    // gnuplotでグラフ表示
    FILE *gp;
    gp = popen("gnuplot -persist", "w");
    fprintf(gp, "set title '片持ちばりのx方向における y方向変位の分布'\n");
    fprintf(gp, "set xlabel 'x [m]'\n");
    fprintf(gp, "set ylabel 'y [m]'\n");
    fprintf(gp, "plot '-' w l\n");
    for (int i = 0; i < steps; i++) {
        fprintf(gp, "%f %f\n", i * h, result[i]);
    }
    fprintf(gp, "e\n");
    fflush(gp);
    pclose(gp);
    printf("💪ワッショイワッショイ💪\n");
    return 0;
}
