#ifndef darray_wrappers_h
#define darray_wrappers_h

#include <stdio.h>
#include "darray.h"

int int_darray_get_elem_by_index(darray* darr, int index);
char char_darray_get_elem_by_index(darray* darr, int index);
float float_darray_get_elem_by_index(darray* darr, int index);
char* charptr_darray_get_elem_by_index(darray* darr, int index);

#endif /* darray_wrappers_h */
