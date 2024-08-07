#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main(void) {
    double *data;
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        data = (double *)calloc(n, sizeof(double));
        input(data, n);
        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }
        free(data);
    } else {
        printf("ERROR");
    }
    return 0;
}