#include "../inc/pathfinder.h"

static int find_index(char *island, t_arrays *arr) {
    for (int i = 0; i < arr->k; i++)
        if (mx_strcmp(island, arr->new[i]) == 0)
            return i;
    return -1;
}

static bool compare_list(char **route_1, char **route_2, t_arrays *arr) {
    int i;
    int j;
    int first;
    int second;

    for (i = arr->k - 1; route_1[i] == NULL; i--);
    for (j = arr->k - 1; route_2[j] == NULL; j--);
    for (; i != 0 || j != 0; i--, j--)
        if (mx_strcmp(route_1[i], route_2[j]) != 0)
            break;
    first = find_index(route_1[i], arr);
    second = find_index(route_2[j], arr);
    if (first > second)
        return true;
    else
        return false;
}

void mx_sort_my_list(t_result *result, t_arrays *arr) {
    t_result *i;
    t_result *j;
    t_result *tmp = (t_result *)malloc(sizeof(t_result));

    for (i = result; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (compare_list(i->route, j->route, arr) == true) {
                tmp->route = i->route;
                i->route = j->route;
                j->route = tmp->route;
                tmp->dist = i->dist;
                i->dist = j->dist;
                j->dist = tmp->dist;
            }
    free(tmp);
}
