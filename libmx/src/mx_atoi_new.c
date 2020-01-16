#include "../inc/libmx.h"

int mx_atoi_new(char *s) {
    int n = 0;
    int m = 0;
    int k = 1;
    int i;

    for (i = 1; i != mx_strlen(s); i++)
        k *= 10;
    for (i = 0; k != 0; i++) {
        n = (s[i] - 48) * k;
        m += n;
        k /= 10;
    }
    return m;
}
