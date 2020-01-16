#include "../inc/libmx.h"

int mx_is_digit_str(char *s) {
    while (*s >= 48 && *s <= 57 && *s != '\0')
        s++;
    if (*s == '\0')
        return 1;
    else
        return 0;
}
