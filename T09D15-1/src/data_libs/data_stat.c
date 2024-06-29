#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double res = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p > res) {
            res = *p;
        }
    }
    return res;
}

double min(double *data, int n) {
    double res = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p < res) {
            res = *p;
        }
    }
    return res;
}

double mean(double *data, int n) {
    double res = 0.0;
    for (double *p = data; p - data < n; p++) {
        res += *p;
    }
    return res / (double)n;
}

double variance(double *data, int n) {
    double res = 0.0;
    for (double *p = data; p - data < n; p++) {
        res += *p * *p;
    }
    return (res / (double)n) - (mean(data, n) * mean(data, n));
}