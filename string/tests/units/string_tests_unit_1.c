#include "string_tests_unit_1.h"

/*
 МОДУЛЬ 1
 Цель: Тестируем базовый функционал
 Тестируемые методы: string_new(), string_set(), string_get()
 Действия:      1) Создаём новую переменную string* str  с помощью string_new()
                2) Присваеваем ей некоторое значение chararr с помощью string_set(str, chararr)
                3) Метод string_get() должен вернуть значение, равное chararr
 Условие прохождения теста: метод string_get() возращает значение, равное chararr
 */

const int STRING_TESTS_UNIT_1_TESTS_COUNT = ALPHABET_LENGTH + 7;
char* string_tests_unit_1_arr[STRING_TESTS_UNIT_1_TESTS_COUNT];
void string_tests_unit_1_fulfil() {
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        string_tests_unit_1_arr[i] = alphabet[i];
    }
    
    string_tests_unit_1_arr[ALPHABET_LENGTH] = "somesimpletext";
    string_tests_unit_1_arr[ALPHABET_LENGTH + 1] = "ONLYCAPS";
    string_tests_unit_1_arr[ALPHABET_LENGTH + 2] = "CoMbInAtIoN";
    string_tests_unit_1_arr[ALPHABET_LENGTH + 3] = "    ";
    string_tests_unit_1_arr[ALPHABET_LENGTH + 4] = "w h i t e s p a c e";
    string_tests_unit_1_arr[ALPHABET_LENGTH + 5] = "!@&$^#)";
    string_tests_unit_1_arr[ALPHABET_LENGTH + 6] = "Hello, world!";
}
void string_tests_unit_1() {
    printf("[UNIT TESTING] UNIT 1: %i tests upcoming...\n", STRING_TESTS_UNIT_1_TESTS_COUNT);
    int i;
    char* chararr = "";
    for (i = 0; i < STRING_TESTS_UNIT_1_TESTS_COUNT; i++) {
        printf("[UNIT TESTING] TEST #%i: ", i+1);
        chararr = string_tests_unit_1_arr[i];
        string* str = string_new();
        string_set(str, chararr);
        
        if (strcmp(string_get(str), chararr) == 0) {
            printf("OK\n");
        } else {
            printf("ERROR\n");
            break;
        }
    }
    
    if (i >= STRING_TESTS_UNIT_1_TESTS_COUNT) {
        printf("[UNIT TESTING] Unit 1 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 1 testing FAILED on TEST #%i.\n", i+1);
        printf("[UNIT TESTING] String: '%s'.\n", chararr);
    }
    
    printf("\n\n");
}
