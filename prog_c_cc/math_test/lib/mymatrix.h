#ifndef MYMATH_H
#define MYMATH_H

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

// void matrix_add(double **A, double **B, double **result, int rows, int cols);

// void matrix_subtract(double **A, double **B, double **result, int rows, int cols);

// void matrix_multiply(double **A, double **B, double **result, int rows, int cols, int common);

// void matrix_transpose(double **A, double **result, int rows, int cols);

// void matrix_print(double **A, int rows, int cols);

// void matrix_free(double **A, int rows);

#endif