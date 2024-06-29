#include <stdio.h>

int fib(int num);

int main(void) {
    int num = 0;
    char ch = ' ';
    if (scanf("%d%c", &num, &ch) == 2 && ch == '\n') {
        if (num > 0) {
            printf("%d", fib(num));
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int fib(int num) {
    int res = 0;
    if (num == 1 || num == 2) {
        res = 1;
    } else {
        res = fib(num - 2) + fib(num - 1);
    }
    return res;
}