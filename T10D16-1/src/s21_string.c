#include "s21_string.h"

size_t s21_strlen(const char *string) {
    const char *p = string;
    size_t count = 0;
    while (*p != '\0') {
        count++;
        p++;
    }
    return count;
}

int s21_strcmp(const char *string1, const char *string2) {
    _Bool flag = 0;
    const char *p1 = string1, *p2 = string2;
    int res = 0, len1 = s21_strlen(string1), len2 = s21_strlen(string2);
    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2 && (int)*p1 > ((int)*p2) && !flag) {
            res = 1;
            flag = 1;
        } else if (*p1 != *p2 && (int)*p1 < ((int)*p2) && !flag) {
            res = -1;
            flag = 1;
        }
        p1++;
        p2++;
    }
    if (res == 0 && len1 > len2) {
        res = 1;
    } else if (res == 0 && len1 < len2) {
        res = -1;
    }
    return res;
}

char *s21_strcpy(char *destination, const char *source) {
    const char *ps = source;
    char *pd = destination;
    while (*ps != '\0') {
        *pd = *ps;
        ps++;
        pd++;
    }
    *pd = '\0';
    return destination;
}

char *s21_strcat(char *destination, const char *source) {
    const char *ps = source;
    char *pd = destination;
    while (*pd != '\0') {
        pd++;
    }
    while (*ps != '\0') {
        *pd = *ps;
        ps++;
        pd++;
    }
    *pd = '\0';
    return destination;
}

char *s21_strchr(const char *string, int ch) {
    const char *p = string;
    const char *res = NULL;
    _Bool flag = 0;
    while (*p != '\0') {
        if ((int)(*p) == ch && !flag) {
            res = p;
            flag = 1;
        }
        p++;
    }
    return (char *)res;
}

char *s21_strstr(const char *string, const char *substring) {
    const char *ps = string, *p1 = NULL;
    const char *pss = substring;
    int count = 0, len = s21_strlen(substring);
    _Bool flag = 0;
    while (*ps != '\0' && !flag) {
        const char *ps1 = ps;
        while (*pss != '\0' && *ps1 != '\0' && *ps1 == *pss) {
            if (p1 == NULL) {
                p1 = ps;
            }
            count++;
            ps1++;
            pss++;
        }
        if (count == len) {
            flag = 1;
        } else {
            count = 0;
            p1 = NULL;
            pss = substring;
        }
        ps++;
    }
    return (char *)p1;
}

char *s21_strtok(char *string, const char *delim) {
    static char *token = NULL;
    char *ps = string;
    if (string == NULL) {
        ps = token;
    }
    if (ps != NULL) {
        while (*ps != '\0' && s21_strchr(delim, *ps) != NULL) {
            ps++;
        }
        if (*ps == '\0') {
            token = NULL;
            ps = NULL;
        } else {
            char *end = ps;
            while (*end != '\0' && s21_strchr(delim, *end) == NULL) {
                end++;
            }
            if (*end == '\0') {
                token = NULL;
            } else {
                *end = '\0';
                token = end + 1;
            }
        }
    }
    return ps;
}