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

void selection_sort(array_t *array) {
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
            if (array->cmp(a, b)) {
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

void insertion_sort(array_t *array) {
    int size = array->item_size;
    char *arr = array->arr;

    size_t i = 1;
    void *x = malloc(size);
    void *cur = malloc(size);
    while (i < array->length) {
        int j = i - 1;
        memcpy(x, (arr + i * size), size);
        memcpy(cur, (arr + j * size), size);
        while (j >= 0 && array->cmp(x, cur)) {
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

static int partition(array_t *array, int l, int r) {
    size_t size = array->item_size;
    char *arr = array->arr;
    void *pivot = malloc(size);
    memcpy(pivot, (arr + r * size), size);

    int i = l;
    void *cur = malloc(size);
    for (int j = l; j <= r; j++) {
        memcpy(cur, (arr + j * size), size);
        if (array->cmp(cur, pivot)) {
            swap((arr + i * size), (arr + j * size), size);
            i++;
        }
    }

    swap((arr + i * size), (arr + r * size), size);

    free(cur);
    free(pivot);

    return i;
}

static void _quicksort(array_t *array, int l, int r) {
    if (l < r) {
        int p = partition(array, l, r);
        _quicksort(array, l, p - 1);
        _quicksort(array, p + 1, r);
    }
}

void quicksort(array_t *array) {
    _quicksort(array, 0, array->length - 1);
}
