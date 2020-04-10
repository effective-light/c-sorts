#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

#define MAX 500

void print_array(array_t *array) {
    printf("{");
    int *arr = array->arr; // Assume int for simplicity
    for (int i = 0; i < array->length; i++) {
        printf(i + 1 != array->length ? "%d, " : "%d", arr[i]);
    }
    printf("}\n\n");
}

int cmp(void *a, void *b) {
    int *l = a;
    int *r = b;

    return *l < *r;
}

array_t *init_array(int len, int item_size) {
    array_t *array = malloc(sizeof(array_t));
    array->length = len;
    array->item_size = item_size;
    array->arr = malloc(len * item_size);

    return array;
}

void set_elements(array_t *array, void *elements) {
    memcpy(array->arr, elements, array->length * array->item_size);
}

int main() {
    int n = random() % MAX;
    array_t *array = init_array(n, sizeof(int));

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = random() % MAX;
    }
    set_elements(array, arr);

    printf("selection_sort: \n");
    selection_sort(array, cmp);
    print_array(array);

    free(arr);
    free(array->arr);
    free(array);

    return 0;
}
