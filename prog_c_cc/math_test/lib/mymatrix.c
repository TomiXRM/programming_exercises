#include "mymatrix.h"

/*
 * @brief: 行列を作成する
 * @param rows: 行数
 * @param cols: 列数
 * @return: 作成された行列
 */

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

void mateix_transpose(Matrix *A, Matrix *result) {
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
            printf("%f ", matrix->data[i][j]);
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
