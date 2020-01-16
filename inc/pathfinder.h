#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "../libmx/inc/libmx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_result {
    char **route;
    int *dist;
    struct s_result *next;
}   t_result;

typedef struct s_arrays {
    int curr;
    int x;
    int k;
    int next;
    int cou;
    int m;
    int j;
    int i;
    int s;
    int path;
    int num_of;
    char **arr;
    char **new;
    int **matrix;
    int ***route;
    int count;
    char **route_c;
    int *dist;
}   t_arrays;

int mx_count_num(int n);
int mx_line_value(char *s);
void mx_num_of_isl(t_arrays *arr, int k, int j);
void mx_matrix(t_arrays *arr);
int mx_is_digit_str(char *s);
int mx_error_input(int argc, const char *argv);
int mx_print_erinfile(char *s, const char *argv);
void mx_err_num(char *s, t_arrays *arr);
void mx_route(int **matrix, int **dist, char **new, int **mat_dis);
int ***mx_find_route(int i, int **new);
int **mx_square_mas(int i);
void mx_printerr(const char *s);
void mx_fill_list(t_arrays *arr);
void mx_push_2_0(t_result **result, char **route, int *dist);
int *mx_all_path(t_arrays *arr, int **route);
void mx_route_c(t_arrays *arr);
void mx_print_all(t_result *result, t_arrays *arr);
void mx_copy_char(char **route_c, char ***route_cc, t_arrays *arr);
void mx_copy_int(int *dist, int **distt, t_arrays *arr);
void mx_sort_my_list(t_result *result, t_arrays *arr);

#endif
