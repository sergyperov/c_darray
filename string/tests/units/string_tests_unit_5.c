#include "string_tests_unit_5.h"

/*
 МОДУЛЬ 5
 Цель: Тестируем конкатенацию строк
 Тестируемые методы: string_concat()
 Действия:      1) Создаём две новых переменных string* str1 и string* str2 с помощью string_new()
                2) Присваеваем им некоторые значения помощью string_set()
                3) Метод string_concat() должен вернуть результат конкатенации строк
 Условие прохождения теста: метод string_concat() должен правильно "сложить" строки
 */

const int STRING_TESTS_UNIT_5_TESTS_COUNT = 13;
struct string_tests_unit_5_struct {
    char* string1;
    char* string2;
    char* correct_result;
};
struct string_tests_unit_5_struct string_tests_unit_5_struct_new(char* string1, char* string2, char* correct_result) {
    struct string_tests_unit_5_struct new_struct;
    new_struct.string1 = string1;
    new_struct.string2 = string2;
    new_struct.correct_result = correct_result;
    
    return new_struct;
}
struct string_tests_unit_5_struct string_tests_unit_5_arr[STRING_TESTS_UNIT_5_TESTS_COUNT];
void string_tests_unit_5_fulfil() {
    string_tests_unit_5_arr[0] = string_tests_unit_5_struct_new("", "", "");
    string_tests_unit_5_arr[1] = string_tests_unit_5_struct_new("Hello!", "", "Hello!");
    string_tests_unit_5_arr[2] = string_tests_unit_5_struct_new("", "Bye-bye!", "Bye-bye!");
    string_tests_unit_5_arr[3] = string_tests_unit_5_struct_new(" ", " ", "  ");
    string_tests_unit_5_arr[4] = string_tests_unit_5_struct_new("ab", "cd", "abcd");
    string_tests_unit_5_arr[5] = string_tests_unit_5_struct_new("!@#$%", "^&*()", "!@#$%^&*()");
    string_tests_unit_5_arr[6] = string_tests_unit_5_struct_new("\\", "", "\\");
    string_tests_unit_5_arr[7] = string_tests_unit_5_struct_new("", "\\", "\\");
    string_tests_unit_5_arr[8] = string_tests_unit_5_struct_new("\\", "\\", "\\\\");
    string_tests_unit_5_arr[9] = string_tests_unit_5_struct_new("\n", "\n", "\n\n");
    string_tests_unit_5_arr[10] = string_tests_unit_5_struct_new("\"", "\"", "\"\"");
    string_tests_unit_5_arr[11] = string_tests_unit_5_struct_new("One more ", "test...", "One more test...");
    string_tests_unit_5_arr[12] = string_tests_unit_5_struct_new("'some ", "text'", "'some text'");
}
void string_tests_unit_5() {
    printf("[UNIT TESTING] UNIT 3: %i tests upcoming...\n", STRING_TESTS_UNIT_5_TESTS_COUNT);
    int  i;
    
    string* string1 = string_new();
    string* string2 = string_new();
    string* string_result = string_new();
    for (i = 0; i < STRING_TESTS_UNIT_5_TESTS_COUNT; i++) {
        printf("[UNIT TESTING] TEST #%i: ", i+1);
        
        string_set(string_result, string_tests_unit_5_arr[i].correct_result);
        
        string_set(string1, string_tests_unit_5_arr[i].string1);
        string_set(string2, string_tests_unit_5_arr[i].string2);
        string_concat(string1, string2);
        
        if (string_compare(string1, string_result) == 1) {
            printf("OK\n");
        } else {
            printf("ERROR\n");
            break;
        }
    }
    
    if (i >= STRING_TESTS_UNIT_5_TESTS_COUNT) {
        printf("[UNIT TESTING] Unit 5 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 5 testing FAILED on TEST #%i.\n", i+1);
        printf("[UNIT TESTING] String 1: %s. String 2: %s. Correct result: %s. Calculated result: %s.\n", string_tests_unit_5_arr[i].string1, string_tests_unit_5_arr[i].string2, string_tests_unit_5_arr[i].correct_result,  string_get(string1));
    }
    
    
    printf("\n\n");
}

