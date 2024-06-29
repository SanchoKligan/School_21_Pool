#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *array);
void output(int *buffer, int length);
_Bool min_array(int *array1, int *array2, int length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main(void) {
    int n = 3, m = 3, arr1[LEN], arr2[LEN];
    n = input(arr1);
    m = input(arr2);
    if (n > 0 && m > 0) {
        if ((n == LEN && m == LEN && *(arr1) + *(arr2) > 9) ||
            (n == LEN && m == LEN && *(arr1 + 1) + *(arr2 + 2) > 9 && *(arr1) + *(arr2) + 1 > 9) ||
            (n == LEN && m == LEN - 1 && *(arr1 + 1) + *(arr2 + 1) > 9 && *(arr1) == 9) ||
            (n == LEN - 1 && m == LEN && *(arr1 + 1) + *(arr2 + 1) > 9 && *(arr2) == 9)) {
            printf("n/a");
        } else {
            int sum_arr[LEN], sub_arr[LEN];
            ;
            int sum_len = 0, sub_len = 0;
            if (n > m) {
                sum(arr1, n, arr2, m, sum_arr, &sum_len);
                sub(arr1, n, arr2, m, sub_arr, &sub_len);
                output(sum_arr, sum_len);
                printf("\n");
                output(sub_arr, sub_len);
            } else if (n < m) {
                sum(arr2, m, arr1, n, sum_arr, &sum_len);
                output(sum_arr, sum_len);
                printf("\nn/a");
            } else if (min_array(arr1, arr2, n)) {
                sum(arr1, n, arr2, m, sum_arr, &sum_len);
                sub(arr1, n, arr2, m, sub_arr, &sub_len);
                output(sum_arr, sum_len);
                printf("\n");
                output(sub_arr, sub_len);
            } else {
                sum(arr2, m, arr1, n, sum_arr, &sum_len);
                output(sum_arr, sum_len);
                printf("\nn/a");
            }
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *array) {
    int count = 0;
    char ch = ' ';
    for (int *p = array; p - array < LEN; p++) {
        if (scanf("%d%c", p, &ch) == 2) {
            if (ch == ' ' && *p < 10 && *p >= 0) {
                count++;
            } else {
                if (ch == '\n' && *p < 10 && *p >= 0) {
                    count++;
                } else {
                    count = 0;
                }
                break;
            }
        }
    }
    return count;
}

void output(int *buffer, int length) {
    _Bool flag = 0;
    for (int *p = buffer; p - buffer < length; p++) {
        if (*p == 0 && !flag) {
            continue;
        } else {
            flag = 1;
            if (p - buffer != length - 1) {
                printf("%d ", *p);
            } else {
                printf("%d", *p);
            }
        }
    }
    if (!flag) {
        printf("0");
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int *p1 = buff1 + (len1 - 1), *p2 = buff2 + (len2 - 1);
    *result_length = len1 + 1;
    for (int *p = result; p - result < *result_length; p++) {
        *p = 0;
    }
    int *p3 = result + (*result_length - 1);
    while (p2 >= buff2) {
        if (*p1 + *p2 + *p3 > 9) {
            *p3 += (*p1 + *p2) % 10;
            *(p3 - 1) += 1;
        } else {
            *p3 += *p1 + *p2;
        }
        p1--;
        p2--;
        p3--;
    }
    while (p1 >= buff1) {
        if (*p1 + *p3 > 9) {
            *p3 = (*p1 + *p3) % 10;
            *(p3 - 1) += 1;
        } else {
            *p3 += *p1;
        }
        p1--;
        p3--;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int *p2 = buff2 + (len2 - 1);
    *result_length = len1;
    for (int i = 0; i < *result_length; i++) {
        *(result + i) = *(buff1 + i);
    }
    int *p3 = result + (*result_length - 1);
    while (p2 >= buff2) {
        if (*p3 - *p2 < 0) {
            for (int *p = p3 - 1; p - result >= 0; p--) {
                if (*p == 0) {
                    *p = 9;
                } else {
                    *p -= 1;
                    break;
                }
            }
            *p3 = (*p3 + 10) - *p2;
        } else {
            *p3 -= *p2;
        }
        p2--;
        p3--;
    }
}

_Bool min_array(int *array1, int *array2, int length) {
    _Bool res = 0;
    for (int i = 0; i < length; i++) {
        if (array1[i] > array2[i] || array1[i] < array2[i]) {
            if (array1[i] > array2[i]) {
                res = 1;
            }
            break;
        }
    }
    if (!res && *(array1 + (length - 1)) == *(array2 + (length - 1))) {
        res = 1;
    }
    return res;
}