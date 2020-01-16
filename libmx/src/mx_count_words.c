#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int i = 0;
    int count = 0;

    if (str == NULL)
        return -1;
    while (str[i] == c)
        i++;
    while (str[i] != '\0') {
        while (str[i] != '\0' && str[i] != c)
            i++;
        count++;
        while (str[i] == c)
            i++;
    }
    return count;
}
