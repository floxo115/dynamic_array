#include "library.h"

#include <locale.h>
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

bool resize_darray_(DArray *da) {
    size_t new_cap = da->cap * 2;
    void *new_data = realloc(da->data, da->type_size * new_cap);
    if (new_data == NULL)
        return false;

    da->data = new_data;
    da->cap = new_cap;

    return true;
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

    if (da->len >= da->cap && !resize_darray_(da))
        return false;

    memcpy((char *) da->data + da->type_size * da->len, value, da->type_size);

    da->len++;

    return true;
}

bool darray_insert(DArray *da, size_t pos, void *value) {
    if (da == NULL || value == NULL)
        return false;
    if (pos > da->len)
        return false;

    if (pos == da->len)
        return darray_append(da, value);

    if (da->len >= da->cap && !resize_darray_(da))
        return false;

    memmove((char *) da->data + (pos + 1) * da->type_size,
            (char *) da->data + da->type_size * pos,
            (da->len - pos) * da->type_size
    );
    memcpy((char *) da->data + da->type_size * pos,
           value,
           da->type_size
    );
    da->len++;

    return true;
}

bool darray_clear(DArray *da) {
    if (da == NULL)
        return false;
    if (da->data == NULL)
        return true;

    da->len = 0;
    free(da->data);
    da->data = NULL;

    return true;
}

bool darray_remove(DArray *da, size_t pos) {
    if (da == NULL)
        return false;
    if (pos >= da->len)
        return false;

    memmove(
        (char *) da->data + pos * da->type_size,
        (char *) da->data + (pos + 1) * da->type_size,
        (da->len - pos - 1) * da->type_size
    );

    da->len--;

    if (da->len == 0) {
        darray_clear(da);
    } else if (da->len < da->cap / 2) {
        void *newdata = realloc(da->data, da->cap / 2);
        if (newdata != NULL) {
            da->data = newdata;
            da->cap = da->cap / 2;
        }
    }

    return true;
}

