#include <stdio.h>

int main(void)
{
    double x = 0.0, y = 0.0;
    char c = ' ';
    if (scanf("%lf%lf%c", &x, &y, &c) == 3 && c == '\n')
    {
        if (x * x + y * y < 25)
        {
            printf("GOTCHA");
        }
        else
        {
            printf("MISS");
        }
    }
    else
    {
        printf("n/a");
    }
    return 0;
}