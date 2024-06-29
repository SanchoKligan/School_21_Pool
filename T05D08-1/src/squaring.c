#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n = 0, data[NMAX];
    if (input(data, &n) == 1) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    int res = 0;
    char ch = ' ';
    if (scanf("%d%c", n, &ch) == 2 && ch == '\n') {
        if (*n <= NMAX && *n > 0) {
            for (int *p = a; p - a < *n; p++) {
                if (scanf("%d%c", p, &ch) == 2 && ch == '\n') {
                    res = 1;
                }
            }
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

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}