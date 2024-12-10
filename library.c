#include "library.h"
#include <stdlib.h>

DArray *darray_init(size_t type_size, size_t cap) {
    DArray *da = calloc(1, sizeof(DArray));

    if(da == NULL)
        return NULL;

    da->type_size = type_size;
    da->cap = cap;
    da->data = calloc(da->cap, da->type_size);
    if(da->data == NULL){
        free(da);
        return NULL;
    }

    return da;
}
