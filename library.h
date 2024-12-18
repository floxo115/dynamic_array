#ifndef DYNAMIC_ARRAY_LIBRARY_H
#define DYNAMIC_ARRAY_LIBRARY_H

#include <stddef.h>
#include<stdbool.h>

typedef struct {
    size_t cap;
    size_t len;
    size_t type_size;
    void *data;
} DArray;

DArray *darray_init(size_t, size_t);

void *darray_access(DArray *, size_t);

bool darray_append(DArray *, void *value);

bool darray_insert(DArray *da, size_t pos, void *value);

bool darray_clear(DArray *da);

bool darray_remove(DArray *da, size_t pos);


#endif //DYNAMIC_ARRAY_LIBRARY_H
