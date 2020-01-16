#include "../inc/libmx.h"

int mx_count_arr(char **arr) {
    int i = 0;

    while (arr[i])
        i++;
    return i;
}
