#ifndef darray_h
#define darray_h

#include <stdio.h>
#include <stdlib.h>

typedef struct darray_node darray_node;
typedef struct darray darray;

typedef struct darray_node {
    void* item;
    darray_node* next;
} darray_node;

typedef struct darray {
    darray_node* head;
    darray_node* last;
    int size;
} darray;

darray* darray_new(void);
int darray_size(darray* darr);
void darray_push_back(darray* darr, void *new_item);
void darray_push_front(darray* darr, void *new_item);
void darray_insert_at_index(darray* darr, void *new_item, int index);
void darray_pop_by_index(darray* darr, int index);
void darray_append(darray* darr, darray* darr_to_append);
darray_node* darray_get_elem_by_index(darray* darr, int index);

#endif /* darray_h */
