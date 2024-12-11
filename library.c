#include "library.h"
#include <stdlib.h>
#include <memory.h>

DArray *darray_init(size_t type_size, size_t cap) {
    DArray *da = calloc(1, sizeof(DArray));

    if (da == NULL)
        return NULL;

    da->type_size = type_size;
    da->cap = cap;
    da->data = calloc(da->cap, da->type_size);

    if (da->data == NULL) {
        free(da);
        return NULL;
    }

    return da;
}

void *darray_access(DArray *da, size_t pos) {
    if (da == NULL)
        return NULL;
    if (pos >= da->len)
        return NULL;

    return (void *) ((char *) da->data + da->type_size * pos);
}

bool darray_append(DArray *da, void *value) {
    if (da == NULL)
        return false;

    if (value == NULL)
        return false;

    if (da->len >= da->cap) {
        size_t new_cap = da->cap * 2;
        void *new_data = realloc(da->data, da->type_size * new_cap);
        if (new_data == NULL)
            return false;

        da->data = new_data;
        da->cap = new_cap;
    }

    memcpy((char *) da->data + da->type_size * da->len, value, da->type_size);

    da->len++;

    return true;
}
