#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
int input(int ***matrix, int *rows, int *cols);
void output(int **matrix, int rows, int cols);
void bubble_sort(int *arr, int n);

int main(void) {
    int **matrix = NULL, **result = NULL;
    int n = 0, m = 0;
    if (input(&matrix, &n, &m) == 0 && matrix != NULL) {
        result = (int **)malloc(n * sizeof(int *) + n * m * sizeof(int));
        int *p = (int *)(result + n);
        for (int i = 0; i < n; i++) {
            result[i] = p + i * m;
        }
        if (result != NULL) {
            sort_vertical(matrix, n, m, result);
            output(result, n, m);
            printf("\n\n");
            sort_horizontal(matrix, n, m, result);
            output(result, n, m);
            free(result);
        }
        free(matrix);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int ***matrix, int *rows, int *cols) {
    int res = 0;
    double temp1 = 0.0, temp2 = 0.0;
    if (scanf("%lf %lf", &temp1, &temp2) != 2) {
        res = 1;
    } else if ((int)temp1 != temp1 || (int)temp2 != temp2 || temp1 < 1 || temp2 < 1) {
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
    if (res == 1) {
        free(*matrix);
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

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *array = calloc(n * m, sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[k] = matrix[i][j];
            k++;
        }
    }
    bubble_sort(array, k);
    k = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[j][i] = array[k];
                k++;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[j][i] = array[k];
                k++;
            }
        }
    }
    free(array);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *array = calloc(n * m, sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[k] = matrix[i][j];
            k++;
        }
    }
    bubble_sort(array, k);
    k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = array[k];
                k++;
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = array[k];
                k++;
            }
        }
    }
    free(array);
}

void bubble_sort(int *arr, int n) {
    for (int *pi = arr; pi - arr < n; pi++) {
        for (int *pj = arr; pj - arr < n - (pi - arr) - 1; pj++) {
            if (*(pj + 1) < *pj) {
                int temp = *pj;
                *pj = *(pj + 1);
                *(pj + 1) = temp;
            }
        }
    }
}