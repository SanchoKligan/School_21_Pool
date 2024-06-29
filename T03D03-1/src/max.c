#include <stdio.h>

int max(int a, int b);

int main(void)
{
    int a = 0, b = 0;
    char x = ' ';
    if (scanf("%d%d%c", &a, &b, &x) == 3 && x == '\n')
    {
        printf("%d", max(a, b));
    }
    else
    {
        printf("n/a");
    }
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}