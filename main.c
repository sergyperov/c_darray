#include <stdio.h>
#include <stdlib.h>

#include "darray_wrappers.h"

int main() {
    darray* darr = darray_new(sizeof(char));
    darray_push_back(darr, "First element!");
    darray_push_back(darr, "Second element!");
    printf("%s\n", charptr_darray_get_elem_by_index(darr, 0));
    printf("%s\n", charptr_darray_get_elem_by_index(darr, 1));
}
