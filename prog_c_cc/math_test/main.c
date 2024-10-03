#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/mymatrix.h"

int main(void) {
    // テスト
    Matrix A = matrix_create(3, 3);
    A.data[0] = (double[]){1, 2, 3};
    A.data[1] = (double[]){4, 5, 6};
    A.data[2] = (double[]){7, 8, 9};

    matrix_print(&A);
}
