#include "data_process.h"

#include <math.h>

#include "../data_libs/data_stat.h"

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;
    if (fabs(size) >= EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }
    return result;
}

void sort(double *data, int n) {
    for (double *pi = data; pi - data < n; pi++) {
        for (double *pj = data; pj - data < n - (pi - data) - 1; pj++) {
            if (*(pj + 1) < *pj) {
                double temp = *pj;
                *pj = *(pj + 1);
                *(pj + 1) = temp;
            }
        }
    }
}