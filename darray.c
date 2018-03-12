/*
 *  darray (dynamic array)
 *  Реализация полиморфного динамического списка на языке программирования C
 *  Элементы массива могут быть любого типа, так как используется указатель void*
 *
 *  Для удобной работы для каждого типа данных, используемого в работе, нужно написать методы-обёртки, которые будут работать непосредственно с этим типом данных напрямую.
 */

#include "darray.h"

darray_node* NULL_NODE;

/*
 * Создаёт новый динамический массив и воращает указатель на него
 */
darray* darray_new(int elem_size) {
    darray* darr = malloc(sizeof(darray));
    darr->size = 0;
    darr->elem_size = elem_size;
    darr->head = NULL;
    darr->last = NULL;
    
    return darr;
}

/*
 * Удалит все элементы массива (очистит массив)
 * Сложность операции O(n)
 */
void darray_clear(darray* darr) {
    int darr_length = darray_size(darr);
    
    for (int i = 0; i < darr_length; i++) {
        darray_pop_by_index(darr, 0);
    }
}

/*
 * Размер массива
 */
int darray_size(darray* darr) {
    return darr->size;
}

/*
 * Добававляет элемент в конец массива
 * Сложность операции O(1)
 */
void darray_push_back(darray* darr, void *new_item) {
    void *new_item_copy = malloc(darr->elem_size);
    memcpy(new_item_copy, new_item, darr->elem_size);
    
    darray_node* darr_n_ptr = malloc(sizeof(darray_node));
    darr_n_ptr->item = new_item;
    darr_n_ptr->next = NULL;
    
    if (darr->size == 0) {
        darr->head = darr_n_ptr;
        darr->last = darr_n_ptr;
    } else {
        darr->last->next = darr_n_ptr;
        darr->last = darr->last->next;
    }
    darr->size++;
}

/*
 * Добавляет элемент в начала массива
 * Сложность операции O(1)
 */
void darray_push_front(darray* darr, void *new_item) {
    void *new_item_copy = malloc(sizeof(darr->elem_size));
    memcpy(new_item_copy, new_item, sizeof(darr->elem_size));
    
    darray_node* darr_n_ptr = malloc(sizeof(darray_node));
    darr_n_ptr->item = new_item_copy;
    
    if (darr->size == 0) {
        darr_n_ptr->next = NULL;
        darr->head = darr_n_ptr;
        darr->last = darr_n_ptr;
    } else {
        darr_n_ptr->next = darr->head;
        darr->head = darr_n_ptr;
    }
    darr->size++;
}

/*
 * Вставляет элемент на место index, сдвигая всю остальную часть массива вправо
 * Работает в диапозоне индексов [0, darr->size-1]. Если нужно добавить элемент в конец, использовать darray_push_back (оно и быстрее будет)
 * Сложность операции O(n)
 */
void darray_insert_at_index(darray* darr, void *new_item, int index) {
    if ((index < 0) || (index >= darr->size)) {
        return;
    }
    
    void *new_item_copy = malloc(sizeof(darr->elem_size));
    memcpy(new_item_copy, new_item, sizeof(darr->elem_size));
    
    darray_node* darr_n_ptr = malloc(sizeof(darray_node));
    darr_n_ptr->item = new_item;
    darr_n_ptr->next = NULL;
    
    darray_node* prev_node_ptr = darr->head;
    darray_node* current_node_ptr = darr->head;
    darray_node* next_node_ptr = darr->head->next;
    
    for (int i = 0; i < index; i++) {
        prev_node_ptr = current_node_ptr;
        current_node_ptr = next_node_ptr;
        next_node_ptr = next_node_ptr->next;
    }
    
    if (current_node_ptr == darr->head) {
        darr_n_ptr->next = darr->head;
        darr->head = darr_n_ptr;
    } else {
        darr_n_ptr-> next = current_node_ptr;
        prev_node_ptr->next = darr_n_ptr;
    }
    
    darr->size++;
}

/*
 * Удаляет элемент на месте index, сдвигая всю остальную часть массива влево
 * Сложность операции O(n)
 */
void darray_pop_by_index(darray* darr, int index) {
    if ((index < 0) || (index >= darr->size)) {
        return;
    }
    
    darray_node* prev_node_ptr = darr->head;
    darray_node* current_node_ptr = darr->head;
    darray_node* next_node_ptr = darr->head->next;
    
    for (int i = 0; i < index; i++) {
        prev_node_ptr = current_node_ptr;
        current_node_ptr = next_node_ptr;
        next_node_ptr = next_node_ptr->next;
    }
    
    free(current_node_ptr->item);
    free(current_node_ptr);
    
    if (current_node_ptr == darr->head) {
        darr->head = next_node_ptr;
    } else {
        prev_node_ptr->next = next_node_ptr;
    }
    
    darr->size--;
}

/*
 * Добавляет к массиву darr все элементы массива darr_to_append (модифицируя при этом сам массив darr)
 * Сложность операции O(n)
 */
void darray_append(darray* darr, darray* darr_to_append) {
    int darr2_length = darray_size(darr_to_append);

    for (int i = 0; i < darr2_length; i++) {
        darray_push_back(darr, darray_get_elem_by_index(darr_to_append, i)->item);
    }
}

/*
 * Обрежет массив, оставив подмассив, который начинается с элемента begin и будет длины length
 * Сложность операции O(n)
 */
void darray_cut(darray* darr, int begin, int length) {
    int darr_length = darray_size(darr);
    int end = begin + length;
    if ((begin < 0) || (begin >= darr_length) || (end < 0) || (end >= darr_length) || (begin > end)) {
        return;
    }
    
    for (int i = 0; i < begin; i++) {
        darray_pop_by_index(darr, 0);
    }
    for (int i = end; i < darr_length; i++) {
        darray_pop_by_index(darr, length);
    }
}

/*
 * Возращает элемент массива с индексом index, или элемент NULL_NODE, если элемента с таким индексом нет
 * Сложность операции O(n)
 */
darray_node* darray_get_elem_by_index(darray* darr, int index) {
    if ((index < 0) || (index >= darr->size)) {
        return NULL;
    }
    
    darray_node* current_node_ptr = darr->head;
    for (int i = 0; i < index; i++) {
        current_node_ptr = current_node_ptr->next;
    }
    
    return current_node_ptr;
}
