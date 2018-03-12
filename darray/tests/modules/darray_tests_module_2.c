#include "darray_tests_module_2.h"

/*
 МОДУЛЬ 2
 Цель: Тестируем добавление элементов в список
 Тестируемые методы: darray_push_front(), darray_push_back(), darray_insert_at_index(), darray_size(), int_darray_get_elem_by_index()
 
 Список тестов
 Тест 1: Успешное добавление элемента через darray_push_front()
 Тест 2: Успешное добавление 10 элементов через darray_push_front()
 Тест 3: Успешное добавление элемента через darray_push_back()
 Тест 4: Успешное добавление 10 элементов через darray_push_front()
 Тест 5: Невозможно добавить первый элемент через darray_insert_at_index()
 Тест 6: Успешное добавление всех не крайних элемнтов в середину списка через darray_insert_at_index()
 Тест 7: Успешное добавление одного элемента через darray_push_front(), другого через darray_push_back()
 Тест 8: Успешное добавление одного элемента через darray_push_back(), другого через darray_push_front()
 Тест 9: Успешное добавление 10 элементов поочерёдно через darray_push_front(), другого через darray_push_back()
 Тест 10: Успешное добавление 10 элементов поочерёдно через darray_push_back(), другого через darray_push_front()
 Тест 11: Успешное добавление элемента, при этом игнорирование изменений переменной-источника
 */
void darray_module_2_tests() {
    printf("[UNIT TESTING] MODULE 2: 11 tests upcoming...\n");
    int test_ok = 1;
    int test_id = 0;
    
    
    // Тест 1
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int new_elem = 42;
        darray_push_front(darr, &new_elem);
        if ((darray_size(darr) == 1) && (int_darray_get_elem_by_index(darr, 0) == 42)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 2
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
        for (int i = 0; i < 10; i++) {
            darray_push_front(darr, &elems_arr[i]);
        }
        if (darray_size(darr) == 10) {
            test_ok = 1;
            for (int i = 0, j = 9; i < 10; i++, j--) {
                if (int_darray_get_elem_by_index(darr, i) !=  elems_arr[j]) {
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
        
        darray* darr = darray_new(sizeof(int));
        int new_elem = 42;
        darray_push_back(darr, &new_elem);
        if ((darray_size(darr) == 1) && (int_darray_get_elem_by_index(darr, 0) == 42)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 4
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {111, 222, 333, 444, 555, 666, 777, 888, 999, 101010};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        if (darray_size(darr) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr, i) !=  elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 5
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int new_elem = 42;
        darray_insert_at_index(darr, &new_elem, 0);
        if (darray_size(darr) == 0) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 6
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 10};
        int result_elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        darray_push_front(darr, &elems_arr[0]);
        darray_push_back(darr, &elems_arr[9]);
        for (int i = 1; i < 9; i++) {
            darray_insert_at_index(darr, &elems_arr[i], darray_size(darr)/2);
        }
        if (darray_size(darr) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr, i) !=  result_elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 7
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int new_elem_1 = 111;
        int new_elem_2 = 222;
        darray_push_front(darr, &new_elem_1);
        darray_push_back(darr, &new_elem_2);
        if ((darray_size(darr) == 2) && (int_darray_get_elem_by_index(darr, 0) == 111) && (int_darray_get_elem_by_index(darr, 1) == 222)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 8
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int new_elem_1 = 111;
        int new_elem_2 = 222;
        darray_push_back(darr, &new_elem_1);
        darray_push_front(darr, &new_elem_2);
        if ((darray_size(darr) == 2) && (int_darray_get_elem_by_index(darr, 0) == 222) && (int_darray_get_elem_by_index(darr, 1) == 111)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 9
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[10] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 10};
        for (int i = 0; i < 10; i++) {
            if (i%2 == 0) {
                darray_push_front(darr, &elems_arr[i]);
            } else {
                darray_push_back(darr, &elems_arr[i]);
            }
        }
        if (darray_size(darr) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr, i) !=  result_elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 10
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[10] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};
        for (int i = 0; i < 10; i++) {
            if (i%2 == 0) {
                darray_push_back(darr, &elems_arr[i]);
            } else {
                darray_push_front(darr, &elems_arr[i]);
            }
        }
        if (darray_size(darr) == 10) {
            test_ok = 1;
            for (int i = 0; i < 10; i++) {
                if (int_darray_get_elem_by_index(darr, i) !=  result_elems_arr[i]) {
                    test_ok = 0;
                    break;
                }
            }
        } else {
            test_ok = 0;
        }
        
        test_result(test_ok);
    }
    
    // Тест 11
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int result = 42;
        int elem = result;
        darray_push_back(darr, &elem);
        elem *= 100;
        
        if ((darray_size(darr) == 1) && (int_darray_get_elem_by_index(darr, 0) == 42)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 11) {
        printf("[UNIT TESTING] Module 2 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Module 2 testing FAILED on TEST #%i.\n", test_id);
    }
    
    printf("\n\n");
}
