#include "../inc/pathfinder.h"

static void allways(t_arrays *arr, t_result **result, int **route);

static int find_x(t_arrays *arr, int current) {
    int x = 0;

    mx_route_c(arr);
    for (int i = 0; i < arr->k; i++)
        arr->dist[i] = -1;
    arr->dist[x] = current - arr->route[arr->i][0][arr->path];
    return x;
}

static void recursion(t_arrays *arr, t_result **result, int **route) {
    for (int m = 3; route[m][arr->path] != -1
        && route[m][arr->path] != arr->i; m++) {
        t_arrays *new = (t_arrays *)malloc(sizeof(t_arrays));

        new->i = arr->i; //first loop
        new->j = arr->j; //second loop
        new->x = arr->x; //my index
        new->curr = route[0][arr->path]; //current element
        new->path = route[m][arr->path]; //path
        new->curr -= route[0][new->path]; //example 20 - 16 = 4
        new->cou = arr->cou; //for fill my array
        new->k = arr->k; //number of islands
        mx_copy_int(arr->dist, &new->dist, arr);
        new->new = arr->new;
        mx_copy_char(arr->route_c, &new->route_c, arr);
        new->route_c[new->cou++] = mx_strdup(new->new[new->path]);
        new->dist[new->x++] = new->curr;
        allways(new, result, route);
        free(new);
    }
}

static void allways(t_arrays *arr, t_result **result, int **route) {
    while (route[2][arr->path] != arr->i) {
        recursion(arr, result, route);
        arr->curr = route[0][arr->path];
        arr->path = route[2][arr->path];
        arr->curr -= route[0][arr->path];
        arr->route_c[arr->cou++] = mx_strdup(arr->new[arr->path]);
        arr->dist[arr->x++] = arr->curr;
    }
    recursion(arr, result, route);
    if (route[0][arr->path] != 0)
        arr->dist[arr->x++] = route[0][arr->path];
    arr->route_c[arr->cou++] = mx_strdup(arr->new[arr->i]);
    mx_push_2_0(result, arr->route_c, arr->dist);
}

static void highway(t_arrays *arr, t_result **result) {
    mx_route_c(arr);
    arr->route_c[1] = mx_strdup(arr->new[arr->i]);
    arr->dist[0] = arr->route[arr->i][0][arr->j];
    mx_push_2_0(result, arr->route_c, arr->dist);
}

void mx_fill_list(t_arrays *arr) {
    t_result *result = 0;
    int *all_path = mx_all_path(arr, arr->route[arr->i]);

    for (int s = 0; all_path[s] != -1; s++) {
        arr->path = arr->j;
        if (all_path[s] != arr->i && all_path[s] != 2147483647
            && arr->route[arr->i][0][arr->j] >= 0) {
            arr->x = find_x(arr, arr->route[arr->i][0][arr->j]);
            allways(arr, &result, arr->route[arr->i]);
            break;
        }
        if (all_path[s] == arr->i)
            highway(arr, &result);
        if (all_path[s] == all_path[s + 1])
            break;
    }
    mx_print_all(result, arr);
    free(all_path);
}
