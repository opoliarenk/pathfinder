#include "../inc/libmx.h"

int mx_count_num(int n) {
    int count = 0;

    while (n != 0) {
        if (n < 0) {
            n *= -1;
            count++;
        }
        n /= 10;
        count++;
    }
    return count;
}
