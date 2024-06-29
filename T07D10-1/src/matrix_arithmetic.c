#include <stdio.h>
#include <stdlib.h>

int input_operation(int *op);
int input(int ***matrix, int *rows, int *cols);
void output(int **matrix, int rows, int cols);
void sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int ***matrix_result);
void transpose(int **matrix, int n, int m, int ***t_matrix);
void mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int m_second,
         int ***matrix_result, int *n_result, int *m_result);

int main(void) {
    int op = 0;
    if (input_operation(&op) == 0) {
        switch (op) {
            case 1: {
                int **matrix1 = NULL, **matrix2 = NULL;
                int rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0;
                if (input(&matrix1, &rows1, &cols1) == 0 && matrix1 != NULL &&
                    input(&matrix2, &rows2, &cols2) == 0 && matrix2 != NULL && rows1 == rows2 &&
                    cols1 == cols2) {
                    int **sum_matrix = NULL;
                    sum(matrix1, rows1, cols1, matrix2, &sum_matrix);
                    output(sum_matrix, rows1, cols1);
                    free(matrix1);
                    free(matrix2);
                    free(sum_matrix);
                } else {
                    printf("n/a");
                }
                break;
            }
            case 2: {
                int **matrix1 = NULL, **matrix2 = NULL;
                int rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0, rows3 = 0, cols3 = 0;
                if (input(&matrix1, &rows1, &cols1) == 0 && matrix1 != NULL &&
                    input(&matrix2, &rows2, &cols2) == 0 && matrix2 != NULL && cols1 == rows2) {
                    int **mul_matrix = NULL;
                    mul(matrix1, rows1, cols1, matrix2, cols2, &mul_matrix, &rows3, &cols3);
                    output(mul_matrix, rows3, cols3);
                    free(matrix1);
                    free(matrix2);
                    free(mul_matrix);
                } else {
                    printf("n/a");
                }
                break;
            }
            case 3: {
                int **matrix = NULL;
                int rows = 0, cols = 0;
                if (input(&matrix, &rows, &cols) == 0 && matrix != NULL) {
                    int **t_matrix = NULL;
                    transpose(matrix, rows, cols, &t_matrix);
                    output(t_matrix, cols, rows);
                    free(matrix);
                    free(t_matrix);
                } else {
                    printf("n/a");
                }
                break;
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input_operation(int *op) {
    int res = 0;
    double temp1 = 0.0;
    if (scanf("%lf", &temp1) != 1) {
        res = 1;
    } else if ((int)temp1 != temp1) {
        res = 1;
    } else {
        *op = (int)temp1;
    }
    if (*op < 1 || *op > 3) {
        res = 1;
    }
    return res;
}

int input(int ***matrix, int *rows, int *cols) {
    int res = 0;
    double temp1 = 0.0, temp2 = 0.0;
    if (scanf("%lf %lf", &temp1, &temp2) != 2) {
        res = 1;
    } else if ((int)temp1 != temp1 || (int)temp2 != temp2) {
        res = 1;
    } else {
        *rows = (int)temp1;
        *cols = (int)temp2;
        *matrix = malloc(*rows * sizeof(int *) + *rows * *cols * sizeof(int));
        int *p = (int *)(*matrix + *rows);
        for (int i = 0; i < *rows; i++) {
            (*matrix)[i] = p + *cols * i;
        }
        for (int i = 0; i < *rows; i++) {
            for (int j = 0; j < *cols; j++) {
                if (scanf("%lf", &temp1) != 1) {
                    res = 1;
                } else if ((int)temp1 != temp1) {
                    res = 1;
                } else {
                    (*matrix)[i][j] = (int)temp1;
                }
            }
        }
    }
    return res;
}

void output(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j != cols - 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("%d", matrix[i][j]);
            }
        }
        if (i != rows - 1) {
            printf("\n");
        }
    }
}

void transpose(int **matrix, int n, int m, int ***t_matrix) {
    *t_matrix = (int **)malloc(m * sizeof(int *) + n * m * sizeof(int));
    int *pt = (int *)(*t_matrix + m);
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

void sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int ***matrix_result) {
    *matrix_result = (int **)malloc(n_first * sizeof(int *) + n_first * m_first * sizeof(int));
    int *pt = (int *)(*matrix_result + n_first);
    for (int i = 0; i < n_first; i++) {
        (*matrix_result)[i] = pt + m_first * i;
    }
    if (*matrix_result != NULL) {
        for (int i = 0; i < n_first; i++) {
            for (int j = 0; j < m_first; j++) {
                (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }
}

void mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int m_second,
         int ***matrix_result, int *n_result, int *m_result) {
    *n_result = n_first;
    *m_result = m_second;
    *matrix_result = (int **)malloc(*n_result * sizeof(int *) + *n_result * *m_result * sizeof(int));
    int *pt = (int *)(*matrix_result + *n_result);
    for (int i = 0; i < n_first; i++) {
        (*matrix_result)[i] = pt + *m_result * i;
    }
    if (*matrix_result != NULL) {
        for (int i = 0; i < *n_result; i++) {
            for (int j = 0; j < *m_result; j++) {
                (*matrix_result)[i][j] = 0;
                for (int k = 0; k < m_first; k++) {
                    (*matrix_result)[i][j] += matrix_first[i][k] * matrix_second[k][j];
                }
            }
        }
    }
}
