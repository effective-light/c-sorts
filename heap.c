#include <stdlib.h>
#include <string.h>

#include "heap.h"

#define parent(i) (((i) - 1) / 2)
#define left(i) (2 * (i) + 1)
#define right(i) (2 * (i) + 2)

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

static void heapify(heap_t *heap, size_t index) {
    size_t size = heap->item_size;
    char *arr = heap->data;
    size_t l = left(index);
    size_t r = right(index);
    size_t target = index;

    void *a = get_item(heap, index);
    void *b = get_item(heap, l);
    if (b && heap->cmp(b, a) < 0) {
        memcpy(a, b, size);
        target = l;
    }

    free(b);
    b = get_item(heap, r);
    if (b && heap->cmp(b, a) < 0) {
        target = r;
    }

    free(a);
    free(b);

    if (target != index) {
        swap((arr + index * size), (arr + target * size), size);
        heapify(heap, target);
    }

}

void *heap_pop(heap_t *heap) {
    if (!heap->size) {
        return NULL;
    }

    void *top = heap_top(heap);
    char *arr = heap->data;
    size_t size = heap->item_size;

    memcpy(heap->data, (arr + (heap->size - 1) * size), size);
    heap->size--;
    heapify(heap, 0);

    return top;
}

void heap_insert(heap_t *heap, void *item) {
    
}