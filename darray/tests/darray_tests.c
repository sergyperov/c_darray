/*
    Оболочка для тестирования darray
    Всего есть 6 модулей, каждый из которых тестирует определённый функционал
    Все модули лежат в папке units.
 
    Вызвать тестирование можно методом darray_run_tests()
 */

#include "darray_tests.h"

void test_prepare(int *test_id, int *test_ok) {
    (*test_id)++;
    (*test_ok) = 0;
    printf("[UNIT TESTING] TEST #%i: ", *test_id);
}

void test_result(int test_ok) {
    if (test_ok == 1) {
        printf("OK.\n");
    } else {
        printf("ERROR.\n");
    }
}

void darray_run_tests() {
    darray_tests_unit_1();
    darray_tests_unit_2();
    darray_tests_unit_3();
    darray_tests_unit_4();
    darray_tests_unit_5();
    darray_tests_unit_6();
}
