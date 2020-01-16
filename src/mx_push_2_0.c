#include "../inc/pathfinder.h"

void mx_push_2_0(t_result **result, char **route, int *dist) {
    t_result *tmp = (t_result *)malloc(sizeof(t_result));

    tmp->route = route;
    tmp->dist = dist;
    tmp->next = (*result);
    (*result) = tmp;
}
