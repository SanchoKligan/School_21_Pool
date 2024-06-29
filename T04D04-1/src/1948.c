#include <math.h>
#include <stdio.h>

int max_div(int num);
_Bool is_simple(int num);
int div_rem(int x, int y);

int main(void) {
    int num = 0;
    char ch = ' ';
    if (scanf("%d%c", &num, &ch) == 2 && ch == '\n') {
        printf("%d", max_div(num));
    } else {
        printf("n/a");
    }
    return 0;
}

int div_rem(int x, int y) {
    int a = 0, b = 0;
    if (x > y) {
        a = x;
        b = y;
    } else {
        a = y;
        b = x;
    }
    while (a >= b) {
        a -= b;
    }
    return a;
}

_Bool is_simple(int num) {
    int rt = (int)sqrt(num);
    _Bool res = 1;
    for (int i = 2; i <= rt; i++) {
        if (div_rem(num, i) == 0) {
            res = 0;
            break;
        }
    }
    return res;
}

int max_div(int num) {
    num = (int)fabs((double)num);
    int rt = (int)sqrt(num);
    int res = 0;
    for (int i = rt; i >= 2; i--) {
        if (div_rem(num, i) == 0 && is_simple(i)) {
            res = i;
            break;
        }
    }
    if (res == 0) {
        res = num;
    }
    return res;
}