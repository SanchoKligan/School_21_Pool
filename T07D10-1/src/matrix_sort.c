#include <stdio.h>
#include <stdlib.h>

int input_ts(int *type, int *rows, int *cols);
int input_matrix(int **matrix, int rows, int cols);
void output_matrix(int **matrix, int rows, int cols);
void maxmin_rows(int **matrix, int rows, int cols);
void sort(int **matrix, int *sum_array, int rows);

int main(void) {
    int type = 0, rows = 0, cols = 0;
    if (input_ts(&type, &rows, &cols) == 0) {
        switch (type) {
            case 1: {
                int **matrix = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
                int *p_array = (int *)(matrix + rows);
                for (int i = 0; i < rows; i++) {
                    matrix[i] = p_array + cols * i;
                }
                if (matrix != NULL) {
                    if (input_matrix(matrix, rows, cols) == 0) {
                        maxmin_rows(matrix, rows, cols);
                        output_matrix(matrix, rows, cols);
                    } else {
                        printf("n/a");
                    }
                    free(matrix);
                }
                break;
            }
            case 2: {
                int **matrix = calloc(rows, sizeof(int *));
                for (int i = 0; i < rows; i++) {
                    matrix[i] = calloc(cols, sizeof(int));
                }
                if (matrix != NULL) {
                    if (input_matrix(matrix, rows, cols) == 0) {
                        maxmin_rows(matrix, rows, cols);
                        output_matrix(matrix, rows, cols);
                    } else {
                        printf("n/a");
                    }
                    for (int i = 0; i < rows; i++) {
                        free(matrix[i]);
                    }
                    free(matrix);
                }
                break;
            }
            case 3: {
                int **matrix = calloc(rows, sizeof(int *));
                int *p_array = calloc(rows * cols, sizeof(int));
                for (int i = 0; i < rows; i++) {
                    matrix[i] = p_array + cols * i;
                }
                if (matrix != NULL) {
                    if (input_matrix(matrix, rows, cols) == 0) {
                        maxmin_rows(matrix, rows, cols);
                        output_matrix(matrix, rows, cols);
                    } else {
                        printf("n/a");
                    }
                    free(p_array);
                    free(matrix);
                }
                break;
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input_ts(int *type, int *rows, int *cols) {
    int res = 0;
    double temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
    if (scanf("%lf %lf %lf", &temp1, &temp2, &temp3) != 3) {
        res = 1;
    } else if ((int)temp1 != temp1 || (int)temp2 != temp2 || (int)temp3 != temp3) {
        res = 1;
    } else {
        *type = (int)temp1;
        *rows = (int)temp2;
        *cols = (int)temp3;
    }
    if (*type < 1 || *type > 3) {
        res = 1;
    }
    return res;
}

int input_matrix(int **matrix, int rows, int cols) {
    int res = 0;
    double temp = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &temp) != 1) {
                res = 1;
            } else if ((int)temp != temp) {
                res = 1;
            } else {
                matrix[i][j] = (int)temp;
            }
        }
    }
    return res;
}

void output_matrix(int **matrix, int rows, int cols) {
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
void maxmin_rows(int **matrix, int rows, int cols) {
    int sum_array[rows], sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        sum_array[i] = sum;
        sum = 0;
    }
    sort(matrix, sum_array, rows);
}

void sort(int **matrix, int *sum_array, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (sum_array[j + 1] < sum_array[j]) {
                int temp = sum_array[j];
                sum_array[j] = sum_array[j + 1];
                sum_array[j + 1] = temp;
                int *temp_p = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp_p;
            }
        }
    }
}