#include <stdlib.h>
#include <string.h>

void *ft_realloc(void *ptr, size_t new_size) {
    // If new size is 0, free the memory and return NULL
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    // If ptr is NULL, behave like malloc
    if (ptr == NULL) {
        return malloc(new_size);
    }

    // Get the current size of the allocated memory
    size_t old_size = malloc_usable_size(ptr); // This function is not standard, but can be used in some environments
    if (old_size == (size_t)-1) {
        // Handle error if malloc_usable_size fails
        return NULL;
    }

    // Allocate new memory
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        // Allocation failed, return NULL
        return NULL;
    }

    // Copy the old data to the new memory
    size_t copy_size = (new_size < old_size) ? new_size : old_size;
    memcpy(new_ptr, ptr, copy_size);

    // Free the old memory
    free(ptr);

    return new_ptr;
}