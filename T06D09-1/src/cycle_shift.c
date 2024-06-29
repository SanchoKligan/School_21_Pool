#include <stdio.h>

#define NMAX 10

int input(int *array, int *length, int *shift);
void output(int *array, int length);
void cycle_shift(int *array, int length, int shift);

int main(void) {
    int n = 0, k = 0, arr[NMAX];
    if (input(arr, &n, &k) == 0) {
        if (k >= 0) {
            cycle_shift(arr, n, k);
        } else {
            cycle_shift(arr, n, n - (k * -1));
        }
        output(arr, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *array, int *length, int *shift) {
    int res = 0;
    double temp = 0.0;
    *length = 0;
    if (scanf("%lf", &temp) != 1) {
        res = 1;
    } else if ((int)temp != temp) {
        res = 1;
    } else {
        *length = (int)temp;
    }
    if (*length <= NMAX && *length > 0) {
        for (int *p = array; p - array < *length; p++) {
            if (scanf("%lf", &temp) != 1) {
                res = 1;
            } else if ((int)temp != temp) {
                res = 1;
            } else {
                *p = (int)temp;
            }
        }
        if (res == 0 && scanf("%lf", &temp) != 1) {
            res = 1;
        } else if ((int)temp != temp) {
            res = 1;
        } else {
            *shift = (int)temp;
        }
    }
    return res;
}

void output(int *array, int length) {
    for (int *p = array; p - array < length; p++) {
        if (p - array != length - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

void cycle_shift(int *array, int length, int shift) {
    for (int i = 0; i < shift; i++) {
        int temp = *array;
        for (int *p = array; p - array < length - 1; p++) {
            *p = *(p + 1);
        }
        *(array + (length - 1)) = temp;
    }
}