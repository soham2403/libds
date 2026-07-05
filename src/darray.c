#include "darray.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 8

static inline void *ptr_at(darray *arr, size_t index) {
    return (char *)arr->data + index * arr->elem_size;
}

/* internal grow helper */
static int da_grow(darray *arr) {
    size_t new_cap = arr->capacity + arr->capacity / 2;

    void *tmp = realloc(arr->data, new_cap * arr->elem_size);
    if (!tmp)
        return -1;

    arr->data = tmp;
    arr->capacity = new_cap;
    return 0;
}

/* lifecycle */
int da_init(darray *arr, size_t elem_size) {
    arr->size = 0;
    arr->capacity = DEFAULT_CAPACITY;
    arr->elem_size = elem_size;

    arr->data = malloc(arr->capacity * elem_size);
    if (!arr->data)
        return -1;

    return 0;
}

void da_free(darray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
    arr->elem_size = 0;
}

/* capacity */
int da_reserve(darray *arr, size_t capacity) {
    if (capacity <= arr->capacity)
        return 0;

    void *tmp = realloc(arr->data, capacity * arr->elem_size);
    if (!tmp)
        return -1;

    arr->data = tmp;
    arr->capacity = capacity;
    return 0;
}

void da_clear(darray *arr) { arr->size = 0; }

/* access */
void *da_get(darray *arr, size_t index) {
    if (index >= arr->size)
        return NULL;

    return ptr_at(arr, index);
}

/* modifiers */
int da_push_back(darray *arr, const void *elem) {
    if (arr->size == arr->capacity)
        if (da_grow(arr) != 0)
            return -1;

    memcpy(ptr_at(arr, arr->size), elem, arr->elem_size);
    arr->size++;

    return 0;
}