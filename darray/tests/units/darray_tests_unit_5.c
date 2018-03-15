#include "darray_tests_unit_5.h"

/*
 МОДУЛЬ 4
 Цель: Тестируем darray_cut()
 Тестируемые методы: darray_cut()
 
 Список тестов
 Тест 1: Успешное полное обрезание пустого списка
 Тест 2: Успешное полное обрезание непустого списка
 Тест 3: Успешное неполное обрезание непустого списка (с начала)
 Тест 4: Успешное неполное обрезание непустого списка (до конца)
 Тест 5: Успешное неполное обрезание непустого списка (в середине)
 Тест 6: Успешное пустое обрезание непустого списка
 Тест 7: Выход за границы списка
 */
void darray_tests_unit_5() {
    printf("[UNIT TESTING] UNIT 5: 7 tests upcoming...\n");
    int test_ok = 1;
    int test_id = 0;
    
    
    // Тест 1
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        
        darray_cut(darr, 0, 0);
        if ((darray_size(darr) == 0) && (darr->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 2
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        
        darray_cut(darr, 0, 0);
        if ((darray_size(darr) == 0) && (darr->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 3
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[4] = {1, 2, 3, 4};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        
        darray_cut(darr, 0, 4);
        if (darray_size(darr) == 4) {
            test_ok = 1;
            for (int i = 0; i < 4; i++) {
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
    
    // Тест 4
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[4] = {7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        
        darray_cut(darr, 6, 4);
        if (darray_size(darr) == 4) {
            test_ok = 1;
            for (int i = 0; i < 4; i++) {
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
    
    // Тест 5
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result_elems_arr[10] = {3, 4, 5, 6, 7};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        
        darray_cut(darr, 2, 5);
        if (darray_size(darr) == 5) {
            test_ok = 1;
            for (int i = 0; i < 5; i++) {
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
    
    // Тест 6
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        
        darray_cut(darr, 0, 10);
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
    
    // Тест 7
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        
        darray_cut(darr, 0, 1000);
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
    
    if (test_id == 7) {
        printf("[UNIT TESTING] Unit 5 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 5 testing FAILED on TEST #%i.\n", test_id);
    }
    
    printf("\n\n");
}
