#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/mymatrix.h"

int main(void) {
    // テスト
    Matrix A = matrix_create(5, 3);
    A.data[0] = (double[]){12, 0, -2};
    A.data[1] = (double[]){14, 2, 7};
    A.data[2] = (double[]){1, 2, 5};
    A.data[3] = (double[]){-4, 6, -8};
    A.data[4] = (double[]){3, 2, 1};

    Matrix B = matrix_create(3, 4);
    B.data[0] = (double[]){1, 1, 2, 1};
    B.data[1] = (double[]){1, 4, 5, -2};
    B.data[2] = (double[]){-3, 13, 19, 0};

    Matrix C = matrix_create(5, 4);

    printf("A • B = \n");
    matrix_multiply(&A, &B, &C);
    matrix_print(&C);
}
