/*
 * Методы-обёртки для типа char
 */

#include "char_darray.h"

// обёртка для darray_push_front()
void char_darray_push_front(darray* darr, const char char_to_push) {
    char c = char_to_push;
    char *cs = malloc(sizeof(char));
    cs[0] = c;
    void *c_ptr = cs;
    
    darray_push_front(darr, c_ptr);
}

// обёртка для darray_push_back()
void char_darray_push_back(darray* darr, const char char_to_push) {
    char c = char_to_push;
    char *cs = malloc(sizeof(char));
    cs[0] = c;
    void *c_ptr = cs;
    
    darray_push_back(darr, c_ptr);
}

// обёртка для char_darray_insert_at_index()
void char_darray_insert_at_index(darray* darr, const char char_to_push, int index) {
    char c = char_to_push;
    char *cs = malloc(sizeof(char));
    cs[0] = c;
    void *c_ptr = cs;
    
    darray_insert_at_index(darr, c_ptr, index);
}

// обёртка для char_darray_get_elem_by_index()
char char_darray_get_elem_by_index(darray* darr, int index) {
    darray_node* darr_n = darray_get_elem_by_index(darr, index);
    
    void* vptr = darr_n->item;
    char* char_p;
    char_p = vptr;
    char cc = char_p[0];
    
    return cc;
}
