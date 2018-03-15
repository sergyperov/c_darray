/*
 *  string
 *  Реализация строки на языке программирования C
 */

#include "string.h"

/*
 * Создаёт новую строку и возвращает указатель на неё
 * Выделение памяти для новой строки
 */
string* string_new(void) {
    string* new_str = malloc(sizeof(string));
    new_str->darr = darray_new(sizeof(char));
    new_str->buffer = malloc(sizeof(char*));
    
    return new_str;
}

/*
 * Возвращает длину строки
 */
int string_length(string* str) {
    return darray_size(str->darr);
}

/*
 * Изменяет содержимое строки в соответствии с аргументом value
 */
void string_set(string* str, char* value) {
    darray_clear(str->darr);
    char* end = value;
    for (;*end;++end) {
        char c = *end;
        if (c != '\0') {
            darray_push_back(str->darr, &c);
        }
    }
}

/*
 * Преобразует строку str в строку char
 */
char* string_get(string* str) {
    if (str->buffer != NULL) {
        free(str->buffer);
    }
    str->buffer = malloc(sizeof(char*));
    for (int i = 0; i < darray_size(str->darr); i++) {
        str->buffer[i] = char_darray_get_elem_by_index(str->darr, i);
    }
    str->buffer[darray_size(str->darr)] = '\0';
    
    return str->buffer;
}

/*
 * Сравнивает строки str1 и str2
 * Возвращает 1 при равенстве строк и 0 при их различии
 */
int string_compare(string* str1, string* str2) {
    int str1_length = string_length(str1);
    int str2_length = string_length(str2);
    
    if (str1_length != str2_length) {
        return 0;
    }
    
    for (int i = 0; i < str1_length; i++) {
        if (char_darray_get_elem_by_index(str1->darr, i) != char_darray_get_elem_by_index(str2->darr, i)) {
            return 0;
        }
    }
    
    return 1;
}

/*
 * Освобожает всю память, выделенную под строку
 */
void string_free(string* str) {
    free(str->buffer);
    darray_clear(str->darr);
}

/*
 * Копирует содержимое строки str_from в строку str_to
 */
void string_copy(string* str_to, string* str_from) {
    darray_clear(str_to->darr);
    free(str_to->darr);
    free(str_to->buffer);
    str_to->darr = malloc(sizeof(darray));
    str_to->buffer = malloc(sizeof(char*));
    memcpy(str_to->darr, str_from->darr, sizeof(darray));
    memcpy(str_to->buffer, str_from->buffer, sizeof(char*));
}

/*
 * Производит конкатенацию строк str1 и str2, изменяя при этом str1
 */
void string_concat(string* str1, string* str2) {
    darray_append(str1->darr, str2->darr);
}

/*
 * Изменяет строку str на подстроку в диапозоне [i, j). То есть не включая j
 */
void string_substr(string* str, int i, int j) {
    darray_cut(str->darr, i, j-i);
}

/*
 * Кодирует строку str в соотвествии с аргументом f
 * Функция f() должна принимть единственный аргумент типа char и возвращать значение типа char
 */
void string_encode(string* str, char (*f)(char)) {
    int size = darray_size(str->darr);
    for (int i = 0; i < size; i++) {
        char c;
        c = char_darray_get_elem_by_index(str->darr, i);
        c = f(c);
        darray_pop_by_index(str->darr, i);
        if (i == 0) {
            darray_push_front(str->darr, &c);
        } else if (i == size-1) {
            darray_push_back(str->darr, &c);
        } else {
            darray_insert_at_index(str->darr, &c, i);
        }
    }
}
