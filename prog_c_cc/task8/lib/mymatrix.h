#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// matrix functions
Matrix matrix_create(int rows, int cols);

void matrix_add(Matrix *A, Matrix *B, Matrix *result);

void matrix_subtract(Matrix *A, Matrix *B, Matrix *result);

void matrix_multiply(Matrix *A, Matrix *B, Matrix *result);

void matrix_transpose(Matrix *A, Matrix *result);

void matrix_print(Matrix *matrix);

void matrix_free(Matrix *matrix);

#endif