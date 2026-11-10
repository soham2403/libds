
#include <libds/DArray.h>

#include <stdio.h>

int main(void) {
    darray arr;

    if (da_init(&arr, sizeof(int)) != 0) {
        fprintf(stderr, "Failed to initialize array\n");
        return 1;
    }

    /* Insert elements */
    for (int i = 1; i <= 10; i++) {
        int value = i * 10;

        if (da_push_back(&arr, &value) != 0) {
            fprintf(stderr, "Failed to insert element\n");
            da_free(&arr);
            return 1;
        }
    }

    /* Display elements */
    printf("Array: ");

    for (size_t i = 0; i < arr.size; i++) {
        int *value = da_get(&arr, i);
        printf("%d ", *value);
    }

    printf("\n");

    /* Remove last element */
    da_pop_back(&arr);

    printf("After pop: ");

    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", *(int *)da_get(&arr, i));
    }

    printf("\n");

    da_free(&arr);

    return 0;
}
