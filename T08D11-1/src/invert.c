#include <stdio.h>
#include <stdlib.h>

void invert(double **matrix, int n, int m, double ***temp_matrix, double det_val);
int input(double ***matrix, int *rows, int *cols);
void output(double **matrix, int rows, int cols);
void transpose(double **matrix, int n, int m, double ***t_matrix);
double det(double **matrix, int n, int m);
void minor(double **matrix, double **min_matrix, int row, int col, int n);

int main(void) {
    double **matrix = NULL;
    int n = 0, m = 0;
    if (input(&matrix, &n, &m) == 0 && matrix != NULL) {
        double det_val = det(matrix, n, m);
        if (det_val != 0) {
            double **inv_matrix = NULL;
            invert(matrix, n, m, &inv_matrix, det_val);
            output(inv_matrix, n, m);
            free(inv_matrix);
        } else {
            printf("n/a");
        }
        free(matrix);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(double ***matrix, int *rows, int *cols) {
    int res = 0;
    double temp1 = 0.0, temp2 = 0.0;
    if (scanf("%lf %lf", &temp1, &temp2) != 2) {
        res = 1;
    } else if ((int)temp1 != temp1 || (int)temp2 != temp2 || temp1 < 1 || temp2 < 1 || temp1 != temp2) {
        res = 1;
    } else {
        *rows = (int)temp1;
        *cols = (int)temp2;
        *matrix = malloc(*rows * sizeof(double *) + *rows * *cols * sizeof(double));
        double *p = (double *)(*matrix + *rows);
        for (int i = 0; i < *rows; i++) {
            (*matrix)[i] = p + *cols * i;
        }
        for (int i = 0; i < *rows; i++) {
            for (int j = 0; j < *cols; j++) {
                if (scanf("%lf", &temp1) != 1) {
                    res = 1;
                } else {
                    (*matrix)[i][j] = temp1;
                }
            }
        }
    }
    if (res == 1) {
        free(*matrix);
    }
    return res;
}

void output(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j != cols - 1) {
                printf("%.6f ", matrix[i][j]);
            } else {
                printf("%.6f", matrix[i][j]);
            }
        }
        if (i != rows - 1) {
            printf("\n");
        }
    }
}

double det(double **matrix, int n, int m) {
    double **min_matrix = (double **)malloc(n * sizeof(double *) + n * m * sizeof(double));
    double *p = (double *)(min_matrix + n);
    for (int i = 0; i < n; i++) {
        min_matrix[i] = p + i * m;
    }
    double res = 0.0;
    int k = 1;
    if (n == 1) {
        res = matrix[0][0];
    } else if (n == 2) {
        res = matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
    } else if (n > 2) {
        for (int i = 0; i < n; i++) {
            minor(matrix, min_matrix, i, 0, n);
            res += k * matrix[i][0] * det(min_matrix, n - 1, m - 1);
            k *= -1;
        }
    }
    free(min_matrix);
    return res;
}

void minor(double **matrix, double **min_matrix, int row, int col, int n) {
    int del_row = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i == row) {
            del_row = 1;
        }
        int del_col = 0;
        for (int j = 0; j < n - 1; j++) {
            if (j == col) {
                del_col = 1;
            }
            min_matrix[i][j] = matrix[i + del_row][j + del_col];
        }
    }
}

void transpose(double **matrix, int n, int m, double ***t_matrix) {
    *t_matrix = (double **)malloc(m * sizeof(double *) + n * m * sizeof(double));
    double *pt = (double *)(*t_matrix + m);
    for (int i = 0; i < m; i++) {
        (*t_matrix)[i] = pt + n * i;
    }
    if (*t_matrix != NULL) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (*t_matrix)[j][i] = matrix[i][j];
            }
        }
    }
}

void invert(double **matrix, int n, int m, double ***res_matrix, double det_val) {
    double **temp_matrix = (double **)malloc(n * sizeof(double *) + n * m * sizeof(double));
    double *p = (double *)(temp_matrix + n);
    for (int i = 0; i < n; i++) {
        temp_matrix[i] = p + i * m;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double **min_matrix = (double **)malloc(n * sizeof(double *) + n * m * sizeof(double));
            double *pt = (double *)(min_matrix + n);
            for (int k = 0; k < n; k++) {
                min_matrix[k] = pt + k * m;
            }
            minor(matrix, min_matrix, i, j, n);
            temp_matrix[i][j] = det(min_matrix, n - 1, m - 1);
            free(min_matrix);
            if ((i + j) % 2 == 1) {
                temp_matrix[i][j] *= -1;
            }
            temp_matrix[i][j] /= det_val;
        }
    }
    transpose(temp_matrix, n, n, res_matrix);
    free(temp_matrix);
}