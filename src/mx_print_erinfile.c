#include "../inc/pathfinder.h"

static int first_line(const char *s) {
    if (mx_is_digit_n(s, '\n') == 0) {
        mx_printerr("error: line 1 is not valid\n");
        return 1;
    }
    if (mx_is_digit_n(s, '\n') == -1)
        return 1;
    return 0;
}

static int empty(char *s, const char *argv) {
    if (mx_strlen(s) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" is empty\n");
        return 1;
    }
    return 0;
}

static int line(char *s) {
    int x;

    x = mx_line_value(s);
    if (x > 0) {
        mx_printerr("error: line ");
        mx_printint(x);
        mx_printerr(" is not valid\n");
        return 1;
    }
    return 0;
}

int mx_print_erinfile(char *s, const char *argv) {
    if (empty(s, argv))
        return 1;
    if (first_line(s))
        return 1;
    if (line(s))
        return 1;
    return 0;
}
