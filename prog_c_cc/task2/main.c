#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const uint8_t kMatrixCommon = 3;
const uint8_t kMatrixN = 5;
const uint8_t kMatrixM = 4;

int16_t matrixC[kMatrixN][kMatrixM] = {0};

void print_matrix(int16_t matrix[kMatrixN][kMatrixM]) {
    for (uint8_t i = 0; i < 5; i++) {
        for (uint8_t j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // n x 3 matrix multiplication
    // 行 = n, 列 = 3

    const int16_t kMatrixA[kMatrixN][kMatrixCommon] = {
        {12, 0, -2},
        {14, 2, 7},
        {1, 2, 5},
        {-4, 6, -8},
        {3, 2, 1}};

    const int16_t kMatrixB[kMatrixCommon][kMatrixM] = {
        {1, 1, 2, 1},
        {1, 4, 5, -2},
        {-3, 13, 19, 0}};

    for (uint8_t i = 0; i < kMatrixN; i++) {
        for (uint8_t j = 0; j < kMatrixM; j++) {
            for (uint8_t k = 0; k < kMatrixCommon; k++) {
                matrixC[i][j] += kMatrixA[i][k] * kMatrixB[k][j];
            }
        }
    }

    print_matrix(matrixC);
}