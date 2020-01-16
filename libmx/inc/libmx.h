#ifndef LIBMX_H
#define LIBMX_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printint(int n);
int mx_strlen(const char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char *mx_strdup(const char *s1);
char *mx_strdup_n(const char *s1, int n);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_file_to_str(const char *file);
int mx_count_num(int n);
int mx_count_arr(char **arr);
int mx_while_delim(const char *str, int i, char c);
int mx_is_digit(char s);
int mx_atoi(const char *s, char delim, int *i);
int mx_atoi_new(char *s);
int mx_is_digit_n(const char *s, char c);
int mx_is_alfa(char s);
int mx_isfile(const char *fname);

#endif











