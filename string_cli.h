#ifndef string_cli_h
#define string_cli_h

#include <stdio.h>
#include "darray.h"
#include "string.h"
#include "functions.h"

string* string_darray_get_elem_by_index(darray* darr, int index);

void cli_init(void);
void cli_list(void);
void cli_add(void);

#endif /* string_cli_h */
