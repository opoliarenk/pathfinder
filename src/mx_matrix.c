#include "../inc/pathfinder.h"

static void el(t_arrays *arr, int k, int i, int j);

static int le(t_arrays *arr, int k, int i, int j) {
    if (mx_is_digit_str(arr->arr[k + 1])) {
        if (mx_strcmp(arr->arr[k - 1], arr->new[i]) == 0) {
            arr->matrix[i][j] = mx_atoi_new(arr->arr[k + 1]);
            return 1;
        }
        else
            el(arr, k, i, j);
    }
    else if (mx_is_digit_str(arr->arr[k + 2])) {
        if (mx_strcmp(arr->arr[k + 1], arr->new[i]) == 0) {
            arr->matrix[i][j] = mx_atoi_new(arr->arr[k + 2]);
            return 1;
        }
        else
            el(arr, k, i, j);
    }
    return 0;
}

static void el(t_arrays *arr, int k, int i, int j) {
    while (k++ <= mx_count_arr(arr->arr) - 1 && k != -1) {
        while (arr->arr[k] != 0 
            && mx_strcmp(arr->arr[k], arr->new[j]) != 0)
            k++;
        if (arr->arr[k] == 0)
            arr->matrix[i][j] = -1; //if path was not found
        else if (le(arr, k, i, j))
            break;
    }
}

void mx_matrix(t_arrays *arr) {
    int k;

    arr->matrix = (int **)malloc(mx_count_arr(arr->new) * sizeof(int*));
    for (int i = 0; i < mx_count_arr(arr->new); i++) {
        arr->matrix[i] = (int *)malloc(mx_count_arr(arr->new) * sizeof(int));
        for (int j = 0; j < mx_count_arr(arr->new); j++) {
            k = -1;
            if (j == i)
                arr->matrix[i][j] = -1;
            else
                el(arr, k, i, j);
        }
    }
}

// ****************************************************************
