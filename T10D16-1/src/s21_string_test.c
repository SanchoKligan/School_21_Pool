#include "s21_string.h"

void s21_strlen_test(const char *test_string, size_t expected);
void s21_strcmp_test(const char *test_string1, const char *test_string2, int expected);
void s21_strcpy_test(char *test_string1, const char *test_string2, const char *expected);
void s21_strcat_test(char *test_string1, const char *test_string2, const char *expected);
void s21_strchr_test(const char *test_string, int test_char, int expected);
void s21_strstr_test(const char *test_string1, const char *test_string2, int expected);
void s21_strtok_test(char *test_string1, const char *test_string2, const char *expected, int length);

int main(void) {
#ifdef STRLEN
    s21_strlen_test("Hello!", 6);
    s21_strlen_test("\n", 1);
    s21_strlen_test("", 0);
    s21_strlen_test("\0", 0);
    s21_strlen_test(" ", 1);
#endif
#ifdef STRCMP
    s21_strcmp_test("Hello!", "Hello!", 0);
    s21_strcmp_test("Hello", "Hello!", -1);
    s21_strcmp_test("Helloo", "Hellao", 1);
    s21_strcmp_test("Hellao", "Hello", -1);
    s21_strcmp_test("Helloo", "Hello", 1);
#endif
#ifdef STRCPY
    char destination1[7];
    s21_strcpy_test(destination1, "Hello!", "Hello!");
    char destination2[1];
    s21_strcpy_test(destination2, "", "");
    char destination3[3];
    s21_strcpy_test(destination3, "A\n", "A\n");
#endif
#ifdef STRCAT
    char destination1[13] = "Hello1";
    s21_strcat_test(destination1, "Hello2", "Hello1Hello2");
    char destination2[7] = "";
    s21_strcat_test(destination2, "Hello!", "Hello!");
    char destination3[7] = "Hello!";
    s21_strcat_test(destination3, "", "Hello!");
#endif
#ifdef STRCHR
    s21_strchr_test("Hello!", 'l', 2);
    s21_strchr_test(" Hello!", ' ', 0);
    s21_strchr_test("Hello!\n", '\n', 6);
    s21_strchr_test("Hello!", 'w', -1);
#endif
#ifdef STRSTR
    s21_strstr_test("Hello!", "lo", 3);
    s21_strstr_test("loHello!", "lo", 0);
    s21_strstr_test("Hello!", "wx", -1);
    s21_strstr_test("Hello!", "", -1);
#endif
#ifdef STRTOK
    char test1[] = "Hello! World!";
    s21_strtok_test(test1, "! ", "Hello\0\0World\0", 13);
    char test2[] = "   ";
    s21_strtok_test(test2, " ", "", 0);
    char test3[] = "Hello!";
    s21_strtok_test(test3, "", "Hello!", 8);
#endif
    return 0;
}

void s21_strlen_test(const char *test_string, size_t expected) {
    size_t actual = s21_strlen(test_string);
    if (actual == expected) {
        printf("Input:\n\t%s\nOutput:\n\t%d\nResult:\n\tSUCCESS\n", test_string, (int)actual);
    } else {
        printf("Input:\n\t%s\nOutput:\n\t%d\nResult:\n\tFAIL\n", test_string, (int)actual);
    }
    printf("\n");
}

void s21_strcmp_test(const char *test_string1, const char *test_string2, int expected) {
    printf("Input:\n\t%s\n\t%s\n", test_string1, test_string2);
    int actual = s21_strcmp(test_string1, test_string2);
    if (actual == expected) {
        printf("Output:\n\t%d\nResult:\n\tSUCCESS\n", actual);
    } else {
        printf("Output:\n\t%d\nResult:\n\tFAIL\n", actual);
    }
    printf("\n");
}

void s21_strcpy_test(char *test_string1, const char *test_string2, const char *expected) {
    printf("Input:\n\t%s\n", test_string2);
    char *actual = s21_strcpy(test_string1, test_string2);
    if (s21_strcmp(actual, expected) == 0) {
        printf("Output:\n\t%s\nResult:\n\tSUCCESS\n", actual);
    } else {
        printf("Output:\n\t%s\nResult:\n\tFAIL\n", actual);
    }
    printf("\n");
}

void s21_strcat_test(char *test_string1, const char *test_string2, const char *expected) {
    printf("Input:\n\t%s\n\t%s\n", test_string1, test_string2);
    char *actual = s21_strcat(test_string1, test_string2);
    if (s21_strcmp(actual, expected) == 0) {
        printf("Output:\n\t%s\nResult:\n\tSUCCESS\n", actual);
    } else {
        printf("Output:\n\t%s\nResult:\n\tFAIL\n", actual);
    }
    printf("\n");
}

void s21_strchr_test(const char *test_string, int test_char, int expected) {
    printf("Input:\n\t%s\n\t%c\n", test_string, test_char);
    char *actual = s21_strchr(test_string, test_char);
    if (actual != NULL) {
        if (actual - test_string == expected) {
            printf("Output:\n\t%d\nResult:\n\tSUCCESS\n", (int)(actual - test_string));
        } else {
            printf("Output:\n\t%d\nResult:\n\tFAIL\n", (int)(actual - test_string));
        }
    } else {
        int actual_i = -1;
        if (actual_i == expected) {
            printf("Output:\n\t%d\nResult:\n\tSUCCESS\n", actual_i);
        } else {
            printf("Output:\n\t%d\nResult:\n\tFAIL\n", actual_i);
        }
    }
    printf("\n");
}

void s21_strstr_test(const char *test_string1, const char *test_string2, int expected) {
    printf("Input:\n\t%s\n\t%s\n", test_string1, test_string2);
    char *actual = s21_strstr(test_string1, test_string2);
    if (actual != NULL) {
        if (actual - test_string1 == expected) {
            printf("Output:\n\t%d\nResult:\n\tSUCCESS\n", (int)(actual - test_string1));
        } else {
            printf("Output:\n\t%d\nResult:\n\tFAIL\n", (int)(actual - test_string1));
        }
    } else {
        int actual_i = -1;
        if (actual_i == expected) {
            printf("Output:\n\t%d\nResult:\n\tSUCCESS\n", actual_i);
        } else {
            printf("Output:\n\t%d\nResult:\n\tFAIL\n", actual_i);
        }
    }
    printf("\n");
}

void s21_strtok_test(char *test_string1, const char *test_string2, const char *expected, int length) {
    printf("Input:\n\t%s\n\t%s\nOutput:\n", test_string1, test_string2);
    char *actual = s21_strtok(test_string1, test_string2);
    while (actual != NULL) {
        printf("\t%s\n", actual);
        actual = s21_strtok(NULL, test_string2);
    }
    int count = 0;
    if (length != 0) {
        count++;
    }
    for (int i = 0; i < length; i++) {
        if (test_string1[i] == expected[i]) {
            count++;
        }
    }
    if (count == length) {
        printf("Result:\n\tSUCCESS\n");
    } else {
        printf("Result:\n\tFAIL\n");
    }
}