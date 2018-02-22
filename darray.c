/*
 *  darray (dynamic array)
 *  Реализация полиморфного динамического массива на языке программирования C
 *  Элементы массива могут быть любого типа, так как используется указатель void*
 *
 *  Для удобной работы для каждого типа данных, используемого в работе, нужно написать методы-обёртки, которые будут работать непосредственно с этим типом данных напрямую.
 *  Пример (для типа mytype):
 *  для метода darray_push_back(darray* darr, void *new_item) нужен метод mytype_darray_push_back(darray* darr, mytype *new_item)
 *  и так далее
 */

#include "darray.h"

darray_node* NULL_NODE;

/*
 * Создаёт новый динамический массив и воращает указатель на него
 */
darray* darray_new(void) {
    darray* darr = malloc(sizeof(darray));
    darr->size = 0;
    darr->head = NULL;
    darr->last = NULL;
    
    return darr;
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
    darray_node* darr_n_ptr = malloc(sizeof(darray_node));
    darr_n_ptr->item = new_item;
    
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
    
    free(current_node_ptr);
    
    if (current_node_ptr == darr->head) {
        darr->head = next_node_ptr;
    } else {
        prev_node_ptr->next = next_node_ptr;
    }
    
    darr->size--;
}

/*
 * Возращает элемент массива с индексом index, или элемент NULL_NODE, если элемента с таким индексом нет
 * Сложность операции O(n)
 */
darray_node* darray_get_elem_by_index(darray* darr, int index) {
    if ((index < 0) || (index >= darr->size)) {
        return NULL_NODE;
    }
    
    darray_node* current_node_ptr = darr->head;
    for (int i = 0; i < index; i++) {
        current_node_ptr = current_node_ptr->next;
    }
    
    return current_node_ptr;
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