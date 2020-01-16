#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    int i = mx_count_words(s, c);
    int k = 0;
    int j = 0;
    int g;
    char **arr = malloc(sizeof(char *) * (i + 1));

    if (s == NULL)
        return NULL;
    for (i = 0; i < mx_strlen(s); i++, j = 0) {
        i = mx_while_delim(s, i, c);
        g = i;
        for (; s[i] != c; i++, j++)
            if (s[i] == '\0')
                break;
        arr[k] = mx_strnew(j);
        mx_strncpy(arr[k++], (char *)&s[g], j);
    }
    arr[k] = 0;
    return arr;
}
