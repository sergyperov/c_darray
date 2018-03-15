#include "darray_tests_unit_3.h"

/*
 МОДУЛЬ 3
 Цель: Тестируем удаление элементов списка
 Тестируемые методы: darray_pop_by_index(), darray_clear()
 
 Список тестов
 Тест 1: Невозможно удалить несуществующий элемент через darray_pop_by_index()
 Тест 2: Успешное удаление элемента в списке с одним элементом через darray_pop_by_index()
 Тест 3: Успешное удаление элемента в списке с тремя элементами через darray_pop_by_index()
 Тест 4: Удаление несуществующего элемента ничего не испортит через darray_pop_by_index()
 Тест 5: Очищение списка через darray_pop_by_index()
 Тест 6: Очищение списка через darray_clear()
 Тест 7: Успешное удаление последнего элемента, затем обавление элемента в конец
 */
void darray_tests_unit_3() {
    printf("[UNIT TESTING] UNIT 3: 7 tests upcoming...\n");
    int test_ok = 1;
    int test_id = 0;
    
    
    // Тест 1
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        darray_pop_by_index(darr, 0);
        if (darr->head == NULL) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 2
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        int elem = 42;
        darray* darr = darray_new(sizeof(int));
        darray_push_back(darr, &elem);
        darray_pop_by_index(darr, 0);
        if ((darray_size(darr) == 0) && (darr->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 3
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        int elem1 = 42, elem2 = 404, elem3 = 503;
        darray* darr = darray_new(sizeof(int));
        darray_push_back(darr, &elem1);
        darray_push_back(darr, &elem2);
        darray_push_back(darr, &elem3);
        darray_pop_by_index(darr, 1);
        if ((darray_size(darr) == 2) && (int_darray_get_elem_by_index(darr, 0) == elem1) && (int_darray_get_elem_by_index(darr, 1) == elem3)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 4
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        int elem1 = 42, elem2 = 404;
        darray* darr = darray_new(sizeof(int));
        darray_push_back(darr, &elem1);
        darray_push_back(darr, &elem2);
        darray_pop_by_index(darr, 2);
        if ((darray_size(darr) == 2) && (int_darray_get_elem_by_index(darr, 0) == elem1) && (int_darray_get_elem_by_index(darr, 1) == elem2)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 5
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        for (int i = 0; i < 100; i++) {
            darray_push_back(darr, &i);
        }
        while (darray_size(darr) != 0) {
            darray_pop_by_index(darr, 0);
        }
        if ((darray_size(darr) == 0) && (darr->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 6
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        for (int i = 0; i < 100; i++) {
            darray_push_back(darr, &i);
        }
        darray_clear(darr);
        if ((darray_size(darr) == 0) && (darr->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 7
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(sizeof(int));
        int elems_arr[5] = {5, 25, 125, 625};
        
        for (int i = 0; i < 5; i++) {
            darray_push_back(darr, &elems_arr[i]);
        }
        darray_pop_by_index(darr, darray_size(darr)-1);
        darray_push_back(darr, &elems_arr[4]);
        if (darray_size(darr) == 5) {
            test_ok = 1;
            for (int i = 0; i < 5; i++) {
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
        printf("[UNIT TESTING] Unit 3 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 3 testing FAILED on TEST #%i.\n", test_id);
    }
    
    printf("\n\n");
}
