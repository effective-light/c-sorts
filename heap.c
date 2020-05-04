#include <stdlib.h>
#include <string.h>

#include "heap.h"

heap_t *heap_init(size_t item_size, cmp_t cmp) {
    heap_t *heap = malloc(sizeof(heap_t));

    heap->size = 0;
    heap->item_size = item_size;
    heap->capacity = 1;
    heap->data = malloc(item_size);
    heap->cmp = cmp;

    return heap;
}

static void *get_item(heap_t *heap, size_t index) {
    if (index >= heap->size) {
        return NULL;
    }

    void *item = malloc(heap->item_size);
    if (!item) {
        return NULL;
    }

    memcpy(item, (char *) (heap->data + index * heap->item_size),
            heap->item_size);

    return item;
}

void *heap_top(heap_t *heap) {
    if (!heap->size) {
        return NULL;
    }

    return get_item(heap, 0);
}

void *heap_pop(heap_t *heap) {

}

void heap_insert(heap_t *heap, void *item) {
    
}
