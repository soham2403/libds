
#ifndef LIBDS_DARRAY_H
#define LIBDS_DARRAY_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} darray;

/* Lifecycle */
int da_init(darray *arr, size_t elem_size);
void da_free(darray *arr);

/* Capacity */
int da_reserve(darray *arr, size_t capacity);
void da_clear(darray *arr);

/* Access */
void *da_get(darray *arr, size_t index);

/* Modifiers */
int da_push_back(darray *arr, const void *elem);
int da_pop_back(darray *arr);

#endif /* LIBDS_DARRAY_H */
