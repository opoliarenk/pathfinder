#include "../inc/pathfinder.h"

static void print_path(t_result *result, int i) {
    mx_printstr("========================================");
    mx_printchar(10);
    mx_printstr("Path: ");
    for (; result->route[i] == NULL; i--);
    mx_printstr(result->route[i]);
    mx_printstr(" -> ");
    mx_printstr(result->route[0]);
    mx_printchar(10);
}

static void print_route(t_result *result, int i) {
    mx_printstr("Route: ");
    for (; result->route[i] == NULL; i--);
    for (; i != 0; i--) {
        mx_printstr(result->route[i]);
        mx_printstr(" -> ");
    }
    mx_printstr(result->route[i]);
    mx_printchar(10);
}

static void print_distance(t_result *result, int i, t_arrays *arr) {
    mx_printstr("Distance: ");
    for (; result->dist[i] == -1; i--);
    if (i != 0) {
        for (; i != 0; i--) {
            mx_printint(result->dist[i]);
            mx_printstr(" + ");
        }
        mx_printint(result->dist[i]);
        mx_printstr(" = ");
    }
    mx_printint(arr->route[arr->i][0][arr->j]);
    mx_printchar(10);
    mx_printstr("========================================");
    mx_printchar(10);
}

void mx_print_all(t_result *result, t_arrays *arr) {
    mx_sort_my_list(result, arr);
    t_result *new = result;

    while (result != NULL) {
        print_path(result, arr->k - 1);
        print_route(result, arr->k - 1);
        print_distance(result, arr->k - 1, arr);;
        free(result->dist);
        mx_del_strarr(&result->route);
        free(new);
        result = result->next;
        new = result;
    }
}
