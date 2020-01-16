#include "../inc/pathfinder.h"

static long atoi_here(const char *s, int size, int i) {
    long n = 0;
    long m = 0;
    long k = 1;
    int j = i;

    for (i = 1; i < size; i++)
        k *= 10;
    for (; k != 0; j++) {
        n = (s[j] - 48) * k;
        m += n;
        k /= 10;
    }
    if (m > 2147483646 || m == 0 || size > 10)
        return -1;
    return m;
}


static int while_tire(char *s, int i) {
    int k = 0;

    for (; mx_is_alfa(s[i]) == 1; i++)
        k++;
    if (s[i] == '-' && i != -1 && k != 0)
        i += 1;
    else
        i = -1;
    return i;
}

static int while_koma(char *s, int i) {
    int k = 0;

    for (; mx_is_alfa(s[i]) == 1; i++)
        k++;
    if (s[i] == ',' && i != -1 && k != 0) {
        s[i] = '-';
        i += 1;
    }
    else
        i = -1;
    return i;
}

static int while_digit(char *s, int i) {
    int k = i;

    while (mx_is_digit(s[i]) == 1)
        i++;
    if (s[i] == '\n' && i != -1 && (mx_is_digit(s[i - 1]) == 1)) {
        s[i] = '-';
        i += 1;
        if (atoi_here(s, i - k - 1, k) == -1)
            return -1;
    }
    else
        i = -1;
    return i;
}

int mx_line_value(char *s) {
    int i = 0;
    int count = 1;

    while (s[i] != '\n')
        i++;
    i += 1;
    while (i < mx_strlen(s) && i != -1) {
        count++;
        i = while_tire(s, i);
        i = while_koma(s, i);
        i = while_digit(s, i);
        if (i == 0)
            break;
        if (i == -1)
            return count;
    }
    return 0;
}
