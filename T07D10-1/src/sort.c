#include <stdio.h>
#include <stdlib.h>

int input(int *arr, int n);
int input_length(int *n);
void output(int *arr, int n);
void bubble_sort(int *arr, int n);

int main(void) {
    int n = 0;
    if (input_length(&n) == 0) {
        int *arr = (int *)calloc(n, sizeof(int));
        if (arr != NULL) {
            if (input(arr, n) == 0) {
                bubble_sort(arr, n);
                output(arr, n);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int n) {
    int res = 0;
    double temp = 0.0;
    for (int *p = a; p - a < n; p++) {
        if (scanf("%lf", &temp) != 1) {
            res = 1;
        } else if ((int)temp != temp) {
            res = 1;
        } else {
            *p = (int)temp;
        }
    }
    return res;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a != n - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
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

int input_length(int *n) {
    int res = 0;
    double temp = 0.0;
    if (scanf("%lf", &temp) != 1) {
        res = 1;
    } else if ((int)temp != temp) {
        res = 1;
    } else {
        *n = (int)temp;
    }
    return res;
}