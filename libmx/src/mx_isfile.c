#include "../inc/libmx.h"

int mx_isfile(const char *fname) {
    int file;

    if ((file = open(fname, O_RDONLY)) == -1)
        return 0;
    close(file);
    return 1;
}
