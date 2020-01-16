#include "../inc/libmx.h"

int mx_is_digit(char s) {
    if (s >= 48 && s <= 57)
        return 1;
    else
        return 0;
}
