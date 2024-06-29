#include <stdio.h>

void code();
void decode();

int main(int argc, char **argv) {
    if (argc == 2) {
        if (argv[1][0] == '0') {
            code();
        } else if (argv[1][0] == '1') {
            decode();
        }
    } else {
        printf("n/a");
    }
}

void code() {
    char ch = ' ';
    do {
        char sym = ' ';
        scanf("%c%c", &sym, &ch);
        if (ch == '\n') {
            printf("%X", sym);
        } else if (ch == ' ') {
            printf("%X ", sym);
        } else {
            printf("n/a");
            break;
        }
    } while (ch != '\n');
}

void decode() {
    char ch = ' ';
    do {
        unsigned int sym = 0;
        _Bool flag = 1;
        scanf("%x%c", &sym, &ch);
        if (sym > 0x7F || sym == 0) {
            flag = 0;
        } else {
            if (ch == '\n') {
                printf("%c", sym);
            } else if (ch == ' ') {
                printf("%c ", sym);
            } else {
                flag = 0;
            }
        }
        if (flag == 0) {
            printf("n/a");
            break;
        }
    } while (ch != '\n');
}