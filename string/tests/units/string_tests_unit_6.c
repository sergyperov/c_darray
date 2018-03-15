#include "string_tests_unit_6.h"

/*
 МОДУЛЬ 6
 Цель: Тестируем кодировку строк
 Тестируемые методы: string_encode()
 Действия:      1) Создаём две новых переменных string* str1 и string* str2 с помощью string_new()
                2) Присваеваем им некоторые значения помощью string_set()
                3) Метод string_concat() должен вернуть результат конкатенации строк
 Условие прохождения теста: метод string_concat() должен правильно "сложить" строки
 */

char (*encode_funcs[4]) (char a) = {simple_f, lowercase_char, uppercase_char, ceaser_cipher};

const int STRING_TESTS_UNIT_6_TESTS_COUNT = 14;
struct string_tests_unit_6_struct {
    char* string;
    int encode_method;          // 0 for simple_f(), 1 for lowercase_char(), 2 for uppercase_char(), 3 for ceaser_cipher()
    char* correct_result;
};
struct string_tests_unit_6_struct string_tests_unit_6_struct_new(char* string, int encode_method, char* correct_result) {
    struct string_tests_unit_6_struct new_struct;
    new_struct.string = string;
    new_struct.encode_method = encode_method;
    new_struct.correct_result = correct_result;
    
    return new_struct;
}
struct string_tests_unit_6_struct string_tests_unit_6_arr[STRING_TESTS_UNIT_6_TESTS_COUNT];
void string_tests_unit_6_fulfil() {
    string_tests_unit_6_arr[0] = string_tests_unit_6_struct_new("", 0, "");
    string_tests_unit_6_arr[1] = string_tests_unit_6_struct_new("", 1, "");
    string_tests_unit_6_arr[2] = string_tests_unit_6_struct_new("", 2, "");
    string_tests_unit_6_arr[3] = string_tests_unit_6_struct_new("", 3, "");

    string_tests_unit_6_arr[4] = string_tests_unit_6_struct_new("hello", 0, "hello");
    string_tests_unit_6_arr[5] = string_tests_unit_6_struct_new("Hello, world! Nice test :)", 0, "Hello, world! Nice test :)");
    
    string_tests_unit_6_arr[6] = string_tests_unit_6_struct_new("MAKE ME LOWERCASE!!!", 1, "make me lowercase!!!");
    string_tests_unit_6_arr[7] = string_tests_unit_6_struct_new("LoWeRcAsE", 1, "lowercase");
    string_tests_unit_6_arr[8] = string_tests_unit_6_struct_new("   !!!   ", 1, "   !!!   ");
    
    string_tests_unit_6_arr[9] = string_tests_unit_6_struct_new("make me uppercase!!!", 2, "MAKE ME UPPERCASE!!!");
    string_tests_unit_6_arr[10] = string_tests_unit_6_struct_new("uPpErCaSe", 2, "UPPERCASE");
    string_tests_unit_6_arr[11] = string_tests_unit_6_struct_new("   ???   ", 2, "   ???   ");
    
    string_tests_unit_6_arr[12] = string_tests_unit_6_struct_new("Hello, world!", 3, "Pmttw, ewztl!");
    string_tests_unit_6_arr[13] = string_tests_unit_6_struct_new("   @@@   ", 3, "   @@@   ");

}
void string_tests_unit_6() {
    printf("[UNIT TESTING] UNIT 6: %i tests upcoming...\n", STRING_TESTS_UNIT_6_TESTS_COUNT);
    int  i;
    
    string* str = string_new();
    string* str_result = string_new();
    for (i = 0; i < STRING_TESTS_UNIT_6_TESTS_COUNT; i++) {
        printf("[UNIT TESTING] TEST #%i: ", i+1);
        
        string_set(str_result, string_tests_unit_6_arr[i].correct_result);
        string_set(str, string_tests_unit_6_arr[i].string);
        
        string_encode(str, (*encode_funcs[string_tests_unit_6_arr[i].encode_method]));
        
        if (string_compare(str, str_result) == 1) {
            printf("OK\n");
        } else {
            printf("ERROR\n");
            break;
        }
    }
    
    if (i >= STRING_TESTS_UNIT_6_TESTS_COUNT) {
        printf("[UNIT TESTING] Unit 6 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 6 testing FAILED on TEST #%i.\n", i+1);
        printf("[UNIT TESTING] String: %s. Encrypt function id: %i. Correct result: %s. Calculated result: %s.\n", string_tests_unit_6_arr[i].string, string_tests_unit_6_arr[i].encode_method, string_tests_unit_6_arr[i].correct_result,  string_get(str));
    }
    
    printf("\n\n");
}


