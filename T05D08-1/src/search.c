/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("%d", search(data, n, mean(data, n), variance(data, n)));
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

int search(int *a, int n, double mean_v, double variance_v) {
    int res = 0;
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p >= mean_v && *p <= mean_v + 3 * sqrt(variance_v) && *p != 0) {
            res = *p;
            break;
        }
    }
    return res;
}