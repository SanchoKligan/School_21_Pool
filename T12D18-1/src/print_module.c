#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char *message) {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    char time_str[9];
    strftime(time_str, sizeof(time_str), "%T", now);
    char *p = Log_prefix;
    while (*p) {
        print(*p);
        p++;
    }
    print(' ');
    p = time_str;
    while (*p) {
        print(*p);
        p++;
    }
    print(' ');
    p = message;
    while (*p) {
        print(*p);
        p++;
    }
}