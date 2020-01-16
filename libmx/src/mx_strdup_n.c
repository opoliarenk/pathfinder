#include "../inc/libmx.h"

char *mx_strdup_n(const char *str, int n) {
    char *dup = mx_strnew(n);

    mx_strncpy(dup, str, n);
    return dup;
}
