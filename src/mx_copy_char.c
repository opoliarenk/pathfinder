#include "../inc/pathfinder.h"

void mx_copy_char(char **route_c, char ***route_cc, t_arrays *arr) {
    *route_cc = (char **)malloc(sizeof(char *) * arr->k);
    for (int i = 0; i < arr->k; i++)
        (*route_cc)[i] = mx_strdup(route_c[i]);
}
