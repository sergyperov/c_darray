#include "darray_tests_unit_6.h"

/*
 МОДУЛЬ 6
 Цель: Тестируем добавление элементов в массив и его очищение
 Тестируемые методы: darray_push_back(), darray_clear(),
 Действия:      1) Создаём новый массив darray* darr  с помощью darray_new(...)
                2) Добавляем в массив n-ое количесвто элементов (много) с помощью darray_push(...), засекаем время, сравниваем, длину массива с заявленной
                3) Очищяем массив с помощью метода darray_clear(...), засекаем время, сравниваем длину массива с 0
 Условие прохождения теста: Длина массива после заполнения далжна быть равна заявленной, после очищения должна быть равна 0
 */
void darray_tests_unit_6() {
    printf("[UNIT TESTING] UNIT 6: 8 tests upcoming...\n");
    int million = 1000000;
    int i, j;
    for (i = 1, j = 1; i <= 8; i++, j*=2) {
        if (fill_and_empty_darray(i, j*million) == 0) {
            break;
        }
    }
    
    if (i >= 8) {
        printf("[UNIT TESTING] Unit 6 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 6 testing FAILED on TEST #%i.\n", i);
    }
    
    printf("\n\n");
}

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

int fill_and_empty_darray (int test_id, int size) {
    int test_ok = 1;
    long long time_begin;
    long long time_end;
    long long time_delta;
    
    int elems_per_sec_add = 0;
    int elems_per_sec_remove = 0;
    
    printf("[UNIT TESTING] TEST #%i (2^%i million elems): ", test_id, test_id);
    darray* darr = darray_new(8);
    void* elem = malloc(sizeof(char));
    
    time_begin = current_timestamp();
    for (int i = 0; i < size; i++) {
        darray_push_back(darr, elem);
    }
    time_end = current_timestamp();
    time_delta = time_end - time_begin;
    
    if (darray_size(darr) == size) {
        elems_per_sec_add = size / time_delta;
    } else {
        test_ok = 0;
    }
    
    time_begin = current_timestamp();
    darray_clear(darr);
    time_end = current_timestamp();
    time_delta = time_end - time_begin;
    
    if (darray_size(darr) == 0) {
        elems_per_sec_remove = size / time_delta;
    } else {
        test_ok = 0;
    }
    
    if (test_ok == 1) {
        printf("OK. (add: %i elems/ms, remove: %i elems/ms)\n", elems_per_sec_add, elems_per_sec_remove);
    } else {
        printf("ERROR.\n");
    }
    
    return test_ok;
}

