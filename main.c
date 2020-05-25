#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

#define MAX 500

void print_array(array_t *array) {
    printf("{");
    int *arr = array->arr; // Assume int for simplicity
    int sorted = 1;
    for (size_t i = 0; i < array->length; i++) {
        if (sorted && i + 1 < array->length) {
            if (array->cmp(&arr[i], &arr[i + 1]) > 0) {
                sorted = 0;
            }
        }
        printf(i + 1 != array->length ? "%d, " : "%d", arr[i]);
    }

    printf("}\nsorted?: %s\n\n", sorted ? "true" : "false");
}

int cmp(const void *a, const void *b) {
    int left = *((int *) a);
    int right = *((int *) b);

    if (left < right) {
        return -1;
    } else if (left > right) {
        return 1;
    }

    return 0;
}

void test_sort(char *msg, array_t *array, void *elements,
        void (*sort)(array_t *)) {
    memcpy(array->arr, elements, array->length * array->item_size);

    printf("%s: \n", msg);
    sort(array);
    print_array(array);
}

int main() {
    int n = random() % MAX;
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = random() % MAX;
    }

    array_t array = { .length = n, .item_size = sizeof(int),
        .arr = malloc(n * sizeof(int)), .cmp = cmp};

    char *names[] = {"selection_sort", "insertion_sort", "quicksort", "mergesort",
        "heapsort"};
    void *prototypes[] = {selection_sort, insertion_sort, quicksort, mergesort, heapsort};
    for (int i = 0; i < 5; i++) {
        test_sort(names[i], &array, arr, (void (*)(array_t *)) prototypes[i]);
    }

    free(arr);
    free(array.arr);

    return 0;
}
