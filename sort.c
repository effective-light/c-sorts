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
            if (array->cmp(a, b) < 0) {
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
            if (array->cmp(cur, x) < 0) {
                break;
            }
            memcpy((arr + j * size), cur, size);
        }
        memcpy((arr + j * size), x, size);
    }

    free(x);
    free(cur);
}

static size_t partition(array_t *array, size_t l, size_t r) {
    size_t size = array->item_size;
    char *arr = array->arr;
    void *pivot = malloc(size);
    size_t index = l + (rand() % (r - l + 1));
    swap((arr + r * size), (arr + index * size), size);
    memcpy(pivot, (arr + r * size), size);

    size_t i = l - 1;
    size_t j = r + 1;
    void *cur = malloc(size);
    for (;;) {
        do {
            i++;
            memcpy(cur, (arr + i * size), size);
        } while (array->cmp(cur, pivot) < 0);

        do {
            j--;
            memcpy(cur, (arr + j * size), size);
        } while (array->cmp(cur, pivot) > 0);

        if (j <= i) {
            free(cur);
            free(pivot);
            return j;
        }

        swap((arr + i * size), (arr + j * size), size);
    }
}

static void _quicksort(array_t *array, size_t l, size_t r) {
    if (l < r) {
        size_t p = partition(array, l, r);
        _quicksort(array, l, p);
        _quicksort(array, p + 1, r);
    }
}

void quicksort(array_t *array) {
    _quicksort(array, 0, array->length - 1);
}

static void merge(array_t *array, size_t l, size_t m, size_t r) {
    char *arr = array->arr;
    size_t size = array->item_size;

    size_t index = l;
    size_t i = 0;
    size_t j = 0;
    size_t left_size = m - l + 1;
    size_t right_size = r - m;

    void *a = malloc(size);
    void *b = malloc(size);
    void *left = malloc(size * left_size);
    void *right = malloc(size * right_size);
    memcpy(left, (arr + l * size), left_size * size);
    memcpy(right, (arr + (m + 1) * size), right_size * size);
    while (i < left_size && j < right_size) {
        memcpy(a, (left + i * size), size);
        memcpy(b, (right + j * size), size);
        if (array->cmp(a, b) <= 0) {
            memcpy((arr + index * size), a, size);
            i++;
        } else {
            memcpy((arr + index * size), b, size);
            j++;
        }
        index++;
    }

    while (i < left_size) {
        memcpy((arr + (index++) * size), (left + (i++) * size), size);
    }

    while (j < right_size) {
        memcpy((arr + (index++) * size), (right + (j++) * size), size);
    }

    free(a);
    free(b);
    free(left);
    free(right);
}

static void _mergesort(array_t *array, size_t l, size_t r) {
    if (l < r) {
        size_t m = (l + r) / 2;
        _mergesort(array, l, m);
        _mergesort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void mergesort(array_t *array) {
    _mergesort(array, 0, array->length - 1);
}
