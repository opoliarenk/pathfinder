#include "../inc/pathfinder.h"

static int route(int **el, int j) {
    int min = 2147483647;
    int check;

    for (int i = 0; i < j; i++)
        if (el[1][i] != 1)
            if (el[0][i] <= min) {
                min = el[0][i];
                check = i;
            }
    el[1][check] = 1;
    return check;
}

static int **el_of_mas(int **el, int size, int **matrix, int check) {
    int a;

    for (int j = 0; j < size; j++) {
        for (int s = 0; s < size; s++) {
            if (el[0][s] == matrix[check][s] + el[0][check] 
                && matrix[check][s] != -1) {
                a = 0;
                while (el[++a][s] != -1);
                el[a][s] = check;
            }
            if (el[0][s] > matrix[check][s] + el[0][check] 
                && matrix[check][s] != -1) {
                el[0][s] = matrix[check][s] + el[0][check];
                el[2][s] = check;
            }
        }
        check = route(el, size);
    }
    return el;
}

int ***mx_find_route(int size, int **matrix) {
    int **el;
    int ***route = malloc(sizeof(int **) * (size));

    for (int k = 0; k < size; k++) {
        el = mx_square_mas(size);
        el[0][k] = 0;
        el[1][k] = 1;
        el[2][k] = k;
        route[k] = el_of_mas(el, size, matrix, k);
    }
    return route;
}
