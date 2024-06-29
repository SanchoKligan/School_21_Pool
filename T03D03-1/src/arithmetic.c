#include <stdio.h>

int sum(int a, int b);
int diff(int a, int b);
int prod(int a, int b);
int quot(int a, int b);

int main(void)
{
    int a = 0, b = 0;
    char x = ' ';
    if (scanf("%d%d%c", &a, &b, &x) == 3 && x == '\n')
    {
        printf("%d %d %d ", sum(a, b), diff(a, b), prod(a, b));
        if (b == 0)
        {
            printf("n/a");
        }
        else
        {
            printf("%d", quot(a, b));
        }
    }
    else
    {
        printf("n/a");
    }
    return 0;
}

int sum(int a, int b)
{
    return a + b;
}

int diff(int a, int b)
{
    return a - b;
}

int prod(int a, int b)
{
    return a * b;
}

int quot(int a, int b)
{
    return a / b;
}