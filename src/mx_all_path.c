#include "../inc/pathfinder.h"

static void sort(int *arr, int size) {
    int swap = 0;

    for (int j = 0; j < size - 1; j++)
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] == -1 || arr[i + 1] == -1) {
                break;
            }
            if (arr[i] > arr[i + 1]) {
                swap = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = swap;
            }
        }
}

int *mx_all_path(t_arrays *arr, int **route) {
    int *all_path = (int *)malloc(sizeof(int) * (arr->k + 1));
    int l;

    for (l = 0; l < arr->k + 1; l++)
        all_path[l] = -1;
    for (l = 0; l < arr->k - 1; l++)
        all_path[l] = route[l + 2][arr->j];
    sort(all_path, arr->k);
    return all_path;
}
