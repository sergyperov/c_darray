#include "darray_tests_module_4.h"

/*
 МОДУЛЬ 4
 Цель: Тестируем darray_append()
 Тестируемые методы: darray_append()
 
 Список тестов
 Тест 1: Успешное соединение двух пустых списков
 Тест 2: Успешное соединение пустого и непустого списка
 Тест 3: Успешное соединение непустого и пустого списка
 Тест 4: Успешное соединение двух идентичных списков
 Тест 5: Успешное соединение двух разных списков одинаковой длины
 Тест 6: Успешное соединение двух разных списков разной длины
 */
void darray_module_4_tests() {
    printf("[UNIT TESTING] MODULE 4: 6 tests upcoming...\n");
    int test_ok = 1;
    int test_id = 0;
    
    
    // Тест 1
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr1 = darray_new(sizeof(char));
        darray* darr2 = darray_new(sizeof(char));
        
        darray_append(darr1, darr2);
        if ((darray_size(darr1) == 0) && (darr1->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 2
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr1 = darray_new(sizeof(int));
        darray* darr2 = darray_new(sizeof(int));
        
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr2, &elems_arr[i]);
        }
        darray_append(darr1, darr2);
        
        if (darray_size(darr1) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr1, i) !=  elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 3
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr1 = darray_new(sizeof(int));
        darray* darr2 = darray_new(sizeof(int));
        
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr1, &elems_arr[i]);
        }
        darray_append(darr1, darr2);
        
        if (darray_size(darr1) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr1, i) !=  elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 4
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(char));
        char c = 'a';
        darray_push_back(darr, &c);
        
        darray_append(darr, darr);
        if ((darray_size(darr) == 2) && (char_darray_get_elem_by_index(darr, 0) == 'a') && (char_darray_get_elem_by_index(darr, 1) == 'a')) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 5
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr1 = darray_new(sizeof(int));
        darray* darr2 = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 5; i++) {
            darray_push_back(darr1, &elems_arr[i]);
        }
        for (int i = 5; i < 10; i++) {
            darray_push_back(darr2, &elems_arr[i]);
        }
        darray_append(darr1, darr2);
        if (darray_size(darr1) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr1, i) !=  elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 6
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr1 = darray_new(sizeof(int));
        darray* darr2 = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 4; i++) {
            darray_push_back(darr1, &elems_arr[i]);
        }
        for (int i = 4; i < 10; i++) {
            darray_push_back(darr2, &elems_arr[i]);
        }
        darray_append(darr1, darr2);
        if (darray_size(darr1) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr1, i) !=  elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 6) {
        printf("[UNIT TESTING] Module 4 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Module 4 testing FAILED on TEST #%i.\n", test_id);
    }
    
    printf("\n\n");
}


