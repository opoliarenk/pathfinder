#include "../inc/pathfinder.h"

void mx_err_num(char *s, t_arrays *arr) {
    int i = 0;

    arr->num_of = mx_atoi(s, '\n', &i);
    arr->arr = mx_strsplit(&s[i], '-');
    mx_num_of_isl(arr, 0, 0);
    if (arr->new == NULL) {
        mx_printstr("error: invalid number of islands\n");
        arr->s = 0;
        return;
    }
    if (arr->num_of == 1 && arr->new[1] == NULL) {
        arr->s = 0;
        return;
    }
    arr->s = 1;
    mx_matrix(arr);
    return;
}
