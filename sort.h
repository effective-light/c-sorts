#ifndef _SORT_H_
#define _SORT_H_

typedef int (*cmp_t)(const void *, const void *);

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

#endif // _SORT_H_
