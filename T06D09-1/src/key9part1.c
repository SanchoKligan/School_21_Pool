/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n = 0, arr[NMAX];
    input(arr, &n);
    if (n == 0) {
        printf("n/a");
    } else {
        int sum = sum_numbers(arr, n);
        if (sum == 0) {
            printf("n/a");
        } else {
            int res_arr[NMAX];
            int m = find_numbers(arr, n, sum, res_arr);
            if (m == 0) {
                printf("n/a");
            } else {
                printf("%d\n", sum);
                output(res_arr, m);
            }
        }
    }
    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p % 2 == 0) {
            sum += *p;
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0 && number % *p == 0) {
            count++;
            *(numbers + (count - 1)) = *p;
        }
    }
    return count;
}

void input(int *buffer, int *length) {
    int res = 0;
    double temp = 0.0;
    *length = 0;
    if (scanf("%lf", &temp) != 1) {
        res = 1;
    } else if ((int)temp != temp) {
        res = 1;
    } else {
        *length = (int)temp;
    }
    if (*length <= NMAX && *length > 0) {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%lf", &temp) != 1) {
                res = 1;
            } else if ((int)temp != temp) {
                res = 1;
            } else {
                *p = (int)temp;
            }
        }
    }
    if (res == 1) {
        *length = 0;
    }
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (p - buffer != length - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}