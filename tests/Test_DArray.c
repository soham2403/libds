
#include <libds/DArray.h>

#include <assert.h>
#include <stdio.h>

#define MAX 12

static void test_init(void) {
    darray arr;

    assert(da_init(&arr, sizeof(int)) == 0);
    assert(arr.size == 0);
    assert(arr.capacity >= 8);
    assert(arr.elem_size == sizeof(int));

    da_free(&arr);
}

static void test_push_back(void) {
    darray arr;
    assert(da_init(&arr, sizeof(int)) == 0);

    for (int i = 0; i < 100; i++) {
        assert(da_push_back(&arr, &i) == 0);
    }

    assert(arr.size == 100);

    for (size_t i = 0; i < 100; i++) {
        int *value = da_get(&arr, i);
        assert(value != NULL);
        assert(*value == (int)i);
    }

    da_free(&arr);
}

static void test_pop_back(void) {
    darray arr;
    assert(da_init(&arr, sizeof(int)) == 0);

    int value = 42;

    assert(da_push_back(&arr, &value) == 0);
    assert(da_pop_back(&arr) == 0);
    assert(arr.size == 0);
    assert(da_pop_back(&arr) == -1);

    da_free(&arr);
}

static void test_reserve(void) {
    darray arr;
    assert(da_init(&arr, sizeof(int)) == 0);

    assert(da_reserve(&arr, 100) == 0);
    assert(arr.capacity >= 100);

    da_free(&arr);
}

static void test_clear(void) {
    darray arr;
    assert(da_init(&arr, sizeof(int)) == 0);

    int value = 10;

    assert(da_push_back(&arr, &value) == 0);

    da_clear(&arr);

    assert(arr.size == 0);

    da_free(&arr);
}

static void test_get_invalid_index(void) {
    darray arr;
    assert(da_init(&arr, sizeof(int)) == 0);

    assert(da_get(&arr, 0) == NULL);

    da_free(&arr);
}

int main(void) {
    test_init();
    test_push_back();
    test_pop_back();
    test_reserve();
    test_clear();
    test_get_invalid_index();

    printf("All DArray tests passed!\n");

    return 0;
}
