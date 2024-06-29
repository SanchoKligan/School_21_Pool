#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
            printf("%d\n", *p);
        }
    }
}

int max(int *a, int n) {
    int res = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > res) {
            res = *p;
        }
    }
    return res;
}

int min(int *a, int n) {
    int res = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < res) {
            res = *p;
        }
    }
    return res;
}

double mean(int *a, int n) {
    double res = 0.0;
    for (int *p = a; p - a < n; p++) {
        res += *p;
    }
    return res / (double)n;
}

double variance(int *a, int n) {
    double res = 0.0;
    for (int *p = a; p - a < n; p++) {
        res += *p * *p;
    }
    return (res / (double)n) - (mean(a, n) * mean(a, n));
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}