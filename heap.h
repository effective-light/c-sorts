#ifndef _HEAP_H_
#define _HEAP_H_

#include "cmp.h"

typedef struct heap {
    size_t size;
    size_t item_size;
    size_t capacity;
    void *data;
    cmp_t cmp;
} heap_t;

heap_t *heap_init(size_t, cmp_t);
void *heap_top(heap_t *);
void *heap_pop(heap_t *);
void heap_insert(heap_t *, void *);

#endif // _HEAP_H_
