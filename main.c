#include <stdio.h>
#include <stdlib.h>

#include "darray_wrappers.h"

int main() {
    darray* darr = darray_new(sizeof(int));
    char x = 'h';
    darray_push_front(darr, &x);
    x = 't';
    printf("%c ", char_darray_get_elem_by_index(darr, 0));
}
