#include <stdio.h>
#include <math.h>

double func(double x);

int main(void)
{
    double x = 0.0;
    char y = ' ';
    if (scanf("%lf%c", &x, &y) == 2 && y == '\n')
    {
        double res = func(x);
        if (!isnan(res))
        {
            printf("%.1f", res);
        }
        else
        {
            printf("n/a");
        }
    }
    else
    {
        printf("n/a");
    }
    return 0;
}

double func(double x)
{
    return 7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1e3) * x + 3) / (x * x / 2) - x * pow(10 + x, 2 / x) - 1.01;
}