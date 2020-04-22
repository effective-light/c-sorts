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
    size_t n = array->length;
    size_t size = array->item_size;
    char *arr = array->arr;

    void *a = malloc(size);
    void *b = malloc(size);
    for (size_t i = 0; i < n - 1; i++) {
        size_t j_min = i;
        memcpy(b, (arr + size * j_min), size);
        for (size_t j = i + 1; j < n; j++) {
            memcpy(a, (arr + size * j), size);
            if (array->cmp(a, b)) {
                j_min = j;
                memcpy(b, (arr + size * j_min), size);
            }
        }
        if (j_min != i) {
            swap((arr + size * i), (arr + size * j_min), size);
        }
    }

    free(a);
    free(b);
}

void insertion_sort(array_t *array) {
    size_t size = array->item_size;
    char *arr = array->arr;

    void *x = malloc(size);
    void *cur = malloc(size);
    for (size_t i = 1; i < array->length; i++) {
        memcpy(x, (arr + i * size), size);
        size_t j;
        for (j = i; j; j--) {
            memcpy(cur, (arr + (j - 1) * size), size);
            if (!array->cmp(x, cur)) {
                break;
            }
            memcpy((arr + j * size), cur, size);
        }
        memcpy((arr + j * size), x, size);
    }

    free(x);
    free(cur);
}

static size_t partition(array_t *array, long l, long r) {
    size_t size = array->item_size;
    char *arr = array->arr;
    void *pivot = malloc(size);
    memcpy(pivot, (arr + r * size), size);

    long i = l;
    void *cur = malloc(size);
    for (long j = l; j <= r; j++) {
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

static void _quicksort(array_t *array, long l, long r) {
    if (l < r) {
        size_t p = partition(array, l, r);
        _quicksort(array, l, p - 1);
        _quicksort(array, p + 1, r);
    }
}

void quicksort(array_t *array) {
    _quicksort(array, 0, array->length - 1);
}
