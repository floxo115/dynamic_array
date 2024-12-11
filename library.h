#ifndef DYNAMIC_ARRAY_LIBRARY_H
#define DYNAMIC_ARRAY_LIBRARY_H
#include <stddef.h>

typedef struct {
    size_t cap;
    size_t len;
    size_t type_size;
    void *data;
} DArray;

DArray *darray_init(size_t, size_t);
void *darray_access(DArray *, size_t);

#endif //DYNAMIC_ARRAY_LIBRARY_H
