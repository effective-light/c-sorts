#include <stdlib.h>
#include <string.h>

#include "sort.h"

void selection_sort(array_t *array, cmp_t cmp) {
    int n = array->length;
    int size = array->item_size;
    char *arr = array->arr;

    void *a = malloc(size);
    void *b = malloc(size);
    for (int i = 0; i < n - 1; i++) {
        int jMin = i;
        memcpy(b, (arr + size * jMin), size);
        for (int j = i + 1; j < n; j++) {
            memcpy(a, (arr + size * j), size);
            if (cmp(a, b)) {
                jMin = j;
                memcpy(b, (arr + size * jMin), size);
            }
        }
        if (jMin != i) {
            void *tmp = malloc(size);
            memcpy(tmp, (arr + size * i), size);
            memcpy((arr + size * i), b, size);
            memcpy((arr + size * jMin), tmp, size);
            free(tmp);
        }
    }

    free(a);
    free(b);
}
