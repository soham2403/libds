#ifndef DARRAY_H
#define DARRAY_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} darray;

/* lifecycle */
int da_init(darray *arr, size_t elem_size);
void da_free(darray *arr);

/* capacity */
int da_reserve(darray *arr, size_t capacity);
void da_clear(darray *arr);

/* access */
void *da_get(darray *arr, size_t index);

/* modifiers */
int da_push_back(darray *arr, const void *elem);

#endif