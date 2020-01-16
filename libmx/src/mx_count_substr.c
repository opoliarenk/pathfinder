#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int j = 0;
    int count = 0;

    if (str == NULL || sub == NULL)
        return -1;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == sub[j])
            while (j++ < mx_strlen(sub)) {
                if (str[i++] == sub[j - 1]) {
                    if (sub[j] == '\0')
                        count++;
                }
                else {
                    break;
                }
            }
        j = 0;
    }
    return count;
}
