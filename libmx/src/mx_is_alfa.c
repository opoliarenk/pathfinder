#include "../inc/libmx.h"

int mx_is_alfa(char s) {
    if ((s >= 65 && s <= 90) || (s >= 97 && s <= 122))
        return 1;
    else
        return 0;
}
