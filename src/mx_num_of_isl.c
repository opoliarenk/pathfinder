#include "../inc/pathfinder.h"

static int count_new_arr(char **arr) {
    int i;
    int j = 0;
    int k = 0;

    for (i = 0; i < mx_count_arr(arr); i++) {
        if (mx_is_digit(arr[i][0]) == 1)
            k++;
        else {
            j = i - 1;
            for (; j >= 0; j--)
                if (mx_strcmp(arr[i], arr[j]) == 0) {
                    k++;
                    j = -1;
                }
        }
    }
    i -= k;
    return i;
}

void mx_num_of_isl(t_arrays *arr, int k, int j) {
    arr->new = malloc(sizeof(char *) * (count_new_arr(arr->arr) + 1));
    for (int i = 0; i < mx_count_arr(arr->arr); i++) {
        if (mx_is_digit(*arr->arr[i]));
        else {
            j = i - 1;
            for (; j >= 0; j--)
                if (mx_strcmp(arr->arr[i], arr->arr[j]) == 0)
                    j = -2;
            if (j > -2)
                arr->new[k++] = arr->arr[i];
        }
    }
    arr->new[k] = 0;
    if (arr->num_of == mx_count_arr(arr->new))
        return;
    mx_del_strarr(&arr->new);
    arr->new = NULL;
    return;
}
