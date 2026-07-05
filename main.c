#include "darray.h"
#include <stdio.h>

int main() {
    darray arr;

    if (da_init(&arr, sizeof(int)) != 0) {
        printf("init failed\n");
        return 1;
    }

    int x;

    for (int i = 1; i <= 10; i++) {
        x = i * 10;
        da_push_back(&arr, &x);
    }

    printf("Array: ");
    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", *(int *)da_get(&arr, i));
    }
    printf("\n");

    da_free(&arr);
    return 0;
}