#include "../inc/pathfinder.h"

int mx_error_input(int argc, const char *argv) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    if (mx_isfile(argv) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" does not exist\n");
        return 1;
    }
    return 0;
}
