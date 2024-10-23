#include <stdio.h>
#include "lib/mymath.h"

//連立一次方程式をGauss-Jordan法で解く
// 3x_1 + 2x_2 + 7x_3 + x_4 = 8
// x_1 + 5x_2 + x_3 -x_4 = 5
// 4x_1 + x_2 + 3x_3 - 2x_4 = 7
// x_1 + 6x_2 + 4x_3 +3x_4 = 13

int main() {
    Matrix A = {
        .data = (double *[]) { (double []) {3, 2, 7, 1},
                               (double []) {1, 5, 1, -1},
                               (double []) {4, 1, 3, -2},
                               (double []) {1, 6, 4, 3} },
        .rows = 4,
        .cols = 4
    };

    double b[] = {8, 5, 7, 13};

    int n = 4;

    if (gauss_jordan(&A, b, n) == 0) {
        printf("Error: 0で割り算が発生しました\n");
        return 1;
    }
    // 計算結果を表示

    for (int i = 0; i < n; i++) {
        printf("x_%d = %f\n", i + 1, b[i]);
    }
}