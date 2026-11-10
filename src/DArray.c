
#include <libds/DArray.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DA_INITIAL_CAPACITY 8

/* Internal helpers */

static void *da_ptr_at(darray *arr, size_t index) {
    return (char *)arr->data + index * arr->elem_size;
}

static int da_grow(darray *arr) {
    size_t new_capacity;

    if (arr->capacity == 0) {
        new_capacity = DA_INITIAL_CAPACITY;
    } else {
        if (arr->capacity > SIZE_MAX / 2)
            return -1;

        new_capacity = arr->capacity * 2;
    }

    return da_reserve(arr, new_capacity);
}

/* Lifecycle */

int da_init(darray *arr, size_t elem_size) {
    if (!arr || elem_size == 0)
        return -1;

    *arr = (darray){0};

    arr->elem_size = elem_size;

    if (da_reserve(arr, DA_INITIAL_CAPACITY) != 0) {
        *arr = (darray){0};
        return -1;
    }

    return 0;
}

void da_free(darray *arr) {
    if (!arr)
        return;

    free(arr->data);
    *arr = (darray){0};
}

/* Capacity */

int da_reserve(darray *arr, size_t capacity) {
    if (!arr || arr->elem_size == 0)
        return -1;

    if (capacity <= arr->capacity)
        return 0;

    if (capacity > SIZE_MAX / arr->elem_size)
        return -1;

    void *tmp = realloc(arr->data, capacity * arr->elem_size);

    if (!tmp)
        return -1;

    arr->data = tmp;
    arr->capacity = capacity;

    return 0;
}

void da_clear(darray *arr) {
    if (arr)
        arr->size = 0;
}

/* Access */

void *da_get(darray *arr, size_t index) {
    if (!arr || index >= arr->size)
        return NULL;

    return da_ptr_at(arr, index);
}

/* Modifiers */

int da_push_back(darray *arr, const void *elem) {
    if (!arr || !elem || arr->elem_size == 0)
        return -1;

    if (arr->size == arr->capacity) {
        if (da_grow(arr) != 0)
            return -1;
    }

    memcpy(da_ptr_at(arr, arr->size), elem, arr->elem_size);
    arr->size++;

    return 0;
}

int da_pop_back(darray *arr) {
    if (!arr || arr->size == 0)
        return -1;

    arr->size--;

    return 0;
}
