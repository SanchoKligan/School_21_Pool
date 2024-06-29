#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>

size_t s21_strlen(const char *string);
int s21_strcmp(const char *string1, const char *string2);
char *s21_strcpy(char *destination, const char *source);
char *s21_strcat(char *destination, const char *source);
char *s21_strchr(const char *string, int ch);
char *s21_strstr(const char *string, const char *substring);
char *s21_strtok(char *string, const char *delim);

#endif