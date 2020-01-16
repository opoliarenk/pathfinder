#include "../inc/pathfinder.h"

int **mx_square_mas(int i) {
    int **el_of_mas = (int **)malloc(sizeof(int *) * (i + 1));

    for (int h = 0; h < i + 1; h++) {
        el_of_mas[h] = (int *)malloc(sizeof(int) * (i));
        for (int j = 0; j < i; j++) {
            if (h > 2)
                el_of_mas[h][j] = -1;
            else 
                el_of_mas[h][j] = 2147483647;
        }
    }
    return el_of_mas;
}
