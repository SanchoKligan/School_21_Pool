#include <stdio.h>

int input(int *arr, int n);
void output(int *arr, int n);
void bubble_sort(int *arr, int n);

int main(void) {
    int arr[10];
    if (input(arr, 10) == 0) {
        bubble_sort(arr, 10);
        output(arr, 10);
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