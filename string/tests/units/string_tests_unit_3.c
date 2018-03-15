#include "string_tests_unit_3.h"

/*
 МОДУЛЬ 3
 Цель: Тестируем сравнение строк
 Тестируемые методы: string_compare()
 Действия:      1) Создаём две новых переменных string* str1 и string* str2 с помощью string_new()
                2) Присваеваем им некоторые значения помощью string_set()
                3) Метод string_compare() должен вернуть 1, если строки равны и 0, если строки различны
 Условие прохождения теста: метод string_compare() возращает значение 1 для равных строк и 0 для неравных
 */

const int STRING_TESTS_UNIT_3_TESTS_COUNT = 11;
struct string_tests_unit_3_struct {
    char* string1;
    char* string2;
    int correct_result;
};
struct string_tests_unit_3_struct string_tests_unit_3_struct_new(char* string1, char* string2, int correct_result) {
    struct string_tests_unit_3_struct new_struct;
    new_struct.string1 = string1;
    new_struct.string2 = string2;
    new_struct.correct_result = correct_result;
    
    return new_struct;
}
struct string_tests_unit_3_struct string_tests_unit_3_arr[STRING_TESTS_UNIT_3_TESTS_COUNT];
void string_tests_unit_3_fulfil() {
    string_tests_unit_3_arr[0] = string_tests_unit_3_struct_new("", "", 1);
    string_tests_unit_3_arr[1] = string_tests_unit_3_struct_new("hello", "hello", 1);
    string_tests_unit_3_arr[2] = string_tests_unit_3_struct_new("HELLO", "HELLO", 1);
    string_tests_unit_3_arr[3] = string_tests_unit_3_struct_new("HELLO", "hello", 0);
    string_tests_unit_3_arr[4] = string_tests_unit_3_struct_new("   ", "   ", 1);
    string_tests_unit_3_arr[5] = string_tests_unit_3_struct_new("Hello world", "Hello world", 1);
    string_tests_unit_3_arr[6] = string_tests_unit_3_struct_new("!&#$*", "!&#$*", 1);
    string_tests_unit_3_arr[7] = string_tests_unit_3_struct_new("!&#$*??", "!&#$*?^", 0);
    string_tests_unit_3_arr[8] = string_tests_unit_3_struct_new("Hello, world!", "Hello, world?", 0);
    string_tests_unit_3_arr[9] = string_tests_unit_3_struct_new("\\\\", "\\\\\\", 0);
    string_tests_unit_3_arr[10] = string_tests_unit_3_struct_new("\\\\\\", "\\\\\\", 1);
}
void string_tests_unit_3() {
    printf("[UNIT TESTING] UNIT 3: %i tests upcoming...\n", STRING_TESTS_UNIT_3_TESTS_COUNT);
    int  i;
    
    string* string1 = string_new();
    string* string2 = string_new();
    int calculated_result = -1;
    for (i = 0; i < STRING_TESTS_UNIT_3_TESTS_COUNT; i++) {
        printf("[UNIT TESTING] TEST #%i: ", i+1);
        
        string_set(string1, string_tests_unit_3_arr[i].string1);
        string_set(string2, string_tests_unit_3_arr[i].string2);
        calculated_result = string_compare(string1, string2);
        
        if (calculated_result == string_tests_unit_3_arr[i].correct_result) {
            printf("OK\n");
        } else {
            printf("ERROR\n");
            break;
        }
    }
    
    if (i >= STRING_TESTS_UNIT_3_TESTS_COUNT) {
        printf("[UNIT TESTING] Unit 3 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 3 testing FAILED on TEST #%i.\n", i+1);
        printf("[UNIT TESTING] String 1: '%s'. String 2: '%s'. Correct result: %i. Calculate result: %i.\n", string_get(string1), string_get(string2), string_tests_unit_3_arr[i].correct_result,  calculated_result);
    }
    
    
    printf("\n\n");
}
