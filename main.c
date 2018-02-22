#include <stdio.h>
#include <stdlib.h>

#include "char_darray.h"

void char_darray_print(darray* darr) {
    int darr_size = darray_size(darr);
    for (int i = 0; i < darr_size; i++) {
        printf("%c\n",char_darray_get_elem_by_index(darr, i));
    }
}

int main() {
    darray* darr = darray_new();
    char_darray_push_back(darr, 'a');
    char_darray_push_back(darr, 'b');
    char_darray_push_back(darr, 'c');
    char_darray_push_back(darr, 'd');
    char_darray_push_front(darr, 'e');
    char_darray_print(darr);
    printf("\n\n");
    char_darray_insert_at_index(darr, 'k', 4);
    
    char_darray_print(darr);
    
    

}
