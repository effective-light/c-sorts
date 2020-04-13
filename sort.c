#include <stdlib.h>
#include <string.h>

#include "sort.h"

static inline void swap(void *a, void *b, size_t size) {
    void *tmp = malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}

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
            swap((arr + size * i), (arr + size * jMin), size);
        }
    }

    free(a);
    free(b);
}

void insertion_sort(array_t *array, cmp_t cmp) {
    int size = array->item_size;
    char *arr = array->arr;

    int i = 1;
    void *x = malloc(size);
    void *cur = malloc(size);
    while (i < array->length) {
        int j = i - 1;
        memcpy(x, (arr + i * size), size);
        memcpy(cur, (arr + j * size), size);
        while (j >= 0 && cmp(x, cur)) {
            memcpy(cur, (arr + j * size), size);
            memcpy((arr + (j + 1) * size), (arr + j * size), size);
            j--;
        }
        memcpy((arr + (j + 1) * size), x, size);
        i++;
    }

    free(x);
    free(cur);
}
