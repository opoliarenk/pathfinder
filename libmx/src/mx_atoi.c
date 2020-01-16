#include "../inc/libmx.h"

int mx_atoi(const char *s, char delim, int *i) {
    int n = 0;
    int m = 0;
    int k = 1;
    int size = 0;
    int j;

    for (; s[size] != delim; size++)
        (*i)++;
    (*i) += 1;
    for (j = 1; j < size; j++)
        k *= 10;
    for (j = 0; k != 0; j++) {
        n = (s[j] - 48) * k;
        m += n;
        k /= 10;
    }
    return m;
}
