#include "../inc/libmx.h"

int mx_while_delim(const char *str, int i, char c) {
    while (str[i] == c)
        i++;
    return i;
}
