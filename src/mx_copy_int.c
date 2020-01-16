#include "../inc/pathfinder.h"

void mx_copy_int(int *dist, int **distt, t_arrays *arr) {
    *distt = (int *)malloc(sizeof(int) * arr->k);
    for (int i = 0; i < arr->k; i++)
        (*distt)[i] = dist[i];
}
