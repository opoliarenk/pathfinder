#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *s;

    if (size < 0)
        return NULL;
    s = (char *)malloc(size + 1);
    for (int i = 0; i < size; i++)
        s[i] = '\0';
    s[size] = '\0';
    return s;
}
