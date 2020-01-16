#include "../inc/pathfinder.h"

int main(int argc, char const *argv[]) {
    char *s = NULL;
    t_arrays *arr = (t_arrays *)malloc(sizeof(t_arrays));

    if (mx_error_input(argc, argv[1]))
        return 0;
    s = mx_file_to_str(argv[1]);
    if (mx_print_erinfile(s, argv[1]))
        return 1;
    mx_err_num(s, arr);
    if (arr->s == 0)
        return 0;
    arr->count = mx_count_arr(arr->new);
    arr->route = mx_find_route(arr->count, arr->matrix);
    arr->k = mx_count_arr(arr->new);
    for (arr->i = 0; arr->i < arr->k - 1; arr->i++)
        for (arr->j = arr->i + 1; arr->j < arr->k; arr->j++)
            mx_fill_list(arr);
    // system ("leaks -q pathfinder");
    return 0;
}
