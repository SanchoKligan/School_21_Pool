#include <math.h>
#include <stdio.h>

double wit_of_agn(double x);
double quad_hyp(double x);
double lem_of_bern(double x);

int main(void) {
    double pi = 3.141592653589793238462;
    for (double i = -pi; i <= pi; i += (pi * 2) / 41) {
        if (i < -1.414 || i > 1.414) {
            printf("%10.7f | %10.7f | %10c | %10.7f\n", i, wit_of_agn(i), (char)0x2D, quad_hyp(i));
        } else {
            printf("%10.7f | %10.7f | %10.7f | %10.7f\n", i, wit_of_agn(i), lem_of_bern(i), quad_hyp(i));
        }
    }
    return 0;
}

double wit_of_agn(double x) { return 1.0 / (1.0 + pow(x, 2.0)); }

double quad_hyp(double x) { return 1.0 / pow(x, 2.0); }

double lem_of_bern(double x) { return sqrt(sqrt(1.0 + 4.0 * pow(x, 2.0)) - pow(x, 2.0) - 1); }