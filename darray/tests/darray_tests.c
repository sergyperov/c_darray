/*
 *  Тестирование darray
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
    darray_module_1_tests();
    darray_module_2_tests();
    darray_module_3_tests();
    darray_module_4_tests();
    darray_module_5_tests();
    darray_module_6_tests();
}
