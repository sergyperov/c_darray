/*
 * Методы-обёртки для различных типов
 */

#include "darray_wrappers.h"

char char_darray_get_elem_by_index(darray* darr, int index) {
    darray_node* darr_n = darray_get_elem_by_index(darr, index);
    
    char *x;
    x = darr_n->item;
    
    return *x;
}

int int_darray_get_elem_by_index(darray* darr, int index) {
    darray_node* darr_n = darray_get_elem_by_index(darr, index);
    
    int *x;
    x = darr_n->item;
    
    return *x;
}

float float_darray_get_elem_by_index(darray* darr, int index) {
    darray_node* darr_n = darray_get_elem_by_index(darr, index);
    
    float *x;
    x = darr_n->item;
    
    return *x;
}
