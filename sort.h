#ifndef _SORT_H_
#define _SORT_H_

#include "cmp.h"

typedef struct array {
    void *arr;
    size_t item_size;
    size_t length;
    cmp_t cmp;
} array_t;

void selection_sort(array_t *);
void insertion_sort(array_t *);
void quicksort(array_t *);
void mergesort(array_t *);
void heapsort(array_t *);

#endif // _SORT_H_
