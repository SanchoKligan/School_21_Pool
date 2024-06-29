#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define MININT -2147483648
#define MAXINT 2147483647

int input_ts(int *type, int *rows, int *cols);
int input_matrix(int **matrix, int rows, int cols);
void output_matrix(int **matrix, int rows, int cols);
void minmax(int **matrix, int rows, int cols, int *max_array, int *min_array);
void output_array(int *array, int length);
void output(int **matrix, int rows, int cols, int *max_array, int *min_array);

int main(void) {
    int type = 0, rows = 0, cols = 0;
    if (input_ts(&type, &rows, &cols) == 0) {
        int max_array[rows], min_array[cols];
        switch (type) {
            case 1: {
                int **matrix;
                int static_matrix[MAXLEN][MAXLEN];
                int *p_array[MAXLEN];
                for (int i = 0; i < rows; i++) {
                    p_array[i] = &static_matrix[i][0];
                }
                matrix = p_array;
                if (input_matrix(matrix, rows, cols) == 0) {
                    output(matrix, rows, cols, max_array, min_array);
                } else {
                    printf("n/a");
                }
                break;
            }
            case 2: {
                int **matrix = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
                int *p_array = (int *)(matrix + rows);
                for (int i = 0; i < rows; i++) {
                    matrix[i] = p_array + cols * i;
                }
                if (matrix != NULL) {
                    if (input_matrix(matrix, rows, cols) == 0) {
                        output(matrix, rows, cols, max_array, min_array);
                    } else {
                        printf("n/a");
                    }
                    free(matrix);
                }
                break;
            }
            case 3: {
                int **matrix = calloc(rows, sizeof(int *));
                for (int i = 0; i < rows; i++) {
                    matrix[i] = calloc(cols, sizeof(int));
                }
                if (matrix != NULL) {
                    if (input_matrix(matrix, rows, cols) == 0) {
                        output(matrix, rows, cols, max_array, min_array);
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
            case 4: {
                int **matrix = calloc(rows, sizeof(int *));
                int *p_array = calloc(rows * cols, sizeof(int));
                for (int i = 0; i < rows; i++) {
                    matrix[i] = p_array + cols * i;
                }
                if (matrix != NULL) {
                    if (input_matrix(matrix, rows, cols) == 0) {
                        output(matrix, rows, cols, max_array, min_array);
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
    if ((*type < 1 || *type > 4) || (*rows < 1 || *rows > MAXLEN) || (*cols < 1 || *cols > MAXLEN)) {
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

void minmax(int **matrix, int rows, int cols, int *max_array, int *min_array) {
    int max = MININT, min = MAXINT;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        max_array[i] = max;
        max = MININT;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[j][i] < min) {
                min = matrix[j][i];
            }
        }
        min_array[i] = min;
        min = MAXINT;
    }
}

void output_array(int *array, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1) {
            printf("%d ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }
}

void output(int **matrix, int rows, int cols, int *max_array, int *min_array) {
    output_matrix(matrix, rows, cols);
    printf("\n");
    minmax(matrix, rows, cols, max_array, min_array);
    output_array(max_array, rows);
    printf("\n");
    output_array(min_array, cols);
}