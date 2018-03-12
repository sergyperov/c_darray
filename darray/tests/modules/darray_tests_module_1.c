#include "darray_tests_module_1.h"

/*
 МОДУЛЬ 1
 Цель: Тестируем создание списка
 Тестируемые методы: darray_new()
 
 Список тестов
 Тест 1: Успешное создание списка
 Тест 2: Невозможно создать список с отрицательный размеров элементов
 */
void darray_module_1_tests() {
    printf("[UNIT TESTING] MODULE 1: 2 tests upcoming...\n");
    int test_ok = 1;
    int test_id = 0;
    
    
    // Тест 1
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(8);
        if ((darr != NULL) && (darr->size == 0) && (darr->last == NULL) && (darr->head == NULL)) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    // Тест 2
    if (test_ok == 1) {
        test_prepare(&test_id, &test_ok);
        
        darray* darr = darray_new(0);
        if (darr == NULL) {
            test_ok = 1;
        }
        
        test_result(test_ok);
    }
    
    if (test_id == 2) {
        printf("[UNIT TESTING] Module 1 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Module 1 testing FAILED on TEST #%i.\n", test_id);
    }
    
    printf("\n\n");
}


