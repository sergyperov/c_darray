#ifndef char_darray_h
#define char_darray_h

#include <stdio.h>
#include "darray.h"

void char_darray_push_front(darray* darr, const char char_to_push);
void char_darray_push_back(darray* darr, const char char_to_push);
void char_darray_insert_at_index(darray* darr, const char char_to_push, int index);
char char_darray_get_elem_by_index(darray* darr, int index);

#endif /* char_darray_h */
