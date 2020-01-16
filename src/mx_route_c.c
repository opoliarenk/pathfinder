#include "../inc/pathfinder.h"

void mx_route_c(t_arrays *arr) {
    arr->cou = 0;
    arr->dist = (int *)malloc(sizeof(int) * arr->k);
    arr->route_c = (char **)malloc(sizeof(char *) * (arr->k + 1));
    for (int i = 0; i <= arr->k; i++) {
        arr->dist[i] = -1;
        arr->route_c[i] = NULL;
    }
    arr->route_c[arr->cou++] = mx_strdup(arr->new[arr->path]);
}
