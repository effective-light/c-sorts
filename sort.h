#ifndef _SORT_H_
#define _SORT_H_

typedef struct array {
    void *arr;
    size_t item_size;
    size_t length;
} array_t;

typedef int (*cmp_t)(void *, void *);

void selection_sort(array_t *, cmp_t);
void insertion_sort(array_t *, cmp_t);

#endif // _SORT_H_
