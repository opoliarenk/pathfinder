#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    if (src == NULL)
        return NULL;
    for (int i = 0; i != mx_strlen(src); i++) {
        if (i == len)
            break;
        dst[i] = src[i];
    }
    return dst;
}
