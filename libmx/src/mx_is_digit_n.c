#include "../inc/libmx.h"

int mx_is_digit_n(const char *s, char c) {
    int i = 0;
    int k = 0;

    if (s[i] == 48 && ((s[i + 1] == '\n' 
        && s[i + 2] == '\0') || s[i + 1] == '\0'))
        return -1;
    while (s[i] != c) {
        if (s[i] > 47 && s[i] < 58)
            i++;
        else {
            k = 1;
            break;
        }
    }
    if (s[i] == c && k != 1 && i != 0)
        return 1;
    else
        return 0;
}
