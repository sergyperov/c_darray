#include "string_tests_unit_4.h"

/*
 МОДУЛЬ 4
 Цель: Тестируем получение подстроки
 Тестируемые методы: string_substr()
 Действия:      1) Создаём новую переменную string* str с помощью string_new()
                2) Присваеваем ей некоторое значение с помощью string_set()
                3) Метод string_substr() при заданных аргументах begin и end должен вернуть соответствующую подстроку
 Условие прохождения теста: метод string_substr() возращает правильную подстроку.
 Комментарий: Сравниваем с заданным значением с помощью string_compare()
 */
const int STRING_TESTS_UNIT_4_TESTS_COUNT = ALPHABET_LENGTH + 13;
struct string_tests_unit_4_struct {
    char* string_to_substr;
    int begin;
    int end;
    char* correct_result;
};
struct string_tests_unit_4_struct string_tests_unit_4_struct_new(char* string_to_substr, int begin, int end, char* correct_result) {
    struct string_tests_unit_4_struct new_struct;
    new_struct.string_to_substr = string_to_substr;
    new_struct.begin = begin;
    new_struct.end = end;
    new_struct.correct_result = correct_result;
    
    return new_struct;
}
struct string_tests_unit_4_struct string_tests_unit_4_arr[STRING_TESTS_UNIT_4_TESTS_COUNT];
void string_tests_unit_4_fulfil() {
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        string_tests_unit_4_arr[i] = string_tests_unit_4_struct_new(alphabet[i], 0, 1, alphabet[i]);
    }
    
    // 14 additional tests
    string_tests_unit_4_arr[ALPHABET_LENGTH] = string_tests_unit_4_struct_new("sometextnowhitespace", 0, 8, "sometext");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 1] = string_tests_unit_4_struct_new("NOWSOMECAPS", 0, 3, "NOW");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 2] = string_tests_unit_4_struct_new("CoMbInAtIoN", 0, 5, "CoMbI");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 3] = string_tests_unit_4_struct_new("w h i t e s p a c e", 0, 9, "w h i t e");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 4] = string_tests_unit_4_struct_new("          ", 0, 4, "    ");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 5] = string_tests_unit_4_struct_new("Hello how are you", 0, 9, "Hello how");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 6] = string_tests_unit_4_struct_new(" one more check ", 0, 5, " one ");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 7] = string_tests_unit_4_struct_new("!?#*%.)^", 0, 4, "!?#*");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 8] = string_tests_unit_4_struct_new("Hello, world!", 0, 7, "Hello, ");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 9] = string_tests_unit_4_struct_new("Now we substr from middle", 7, 22, "substr from mid");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 10] = string_tests_unit_4_struct_new("Some text", 0, 0, "");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 11] = string_tests_unit_4_struct_new("Some text", 5, 5, "");
    string_tests_unit_4_arr[ALPHABET_LENGTH + 12] = string_tests_unit_4_struct_new("123456789", 2, 6, "3456");
}
void string_tests_unit_4() {
    printf("[UNIT TESTING] TESTING UNIT 4: %i tests upcoming...\n", STRING_TESTS_UNIT_4_TESTS_COUNT);
    int  i;
    
    string* string_to_substr = string_new();
    string* correct_result = string_new();
    for (i = 0; i < STRING_TESTS_UNIT_4_TESTS_COUNT; i++) {
        printf("[UNIT TESTING] TEST #%i: ", i+1);
        
        string_set(string_to_substr, string_tests_unit_4_arr[i].string_to_substr);
        string_set(correct_result, string_tests_unit_4_arr[i].correct_result);
        string_substr(string_to_substr, string_tests_unit_4_arr[i].begin, string_tests_unit_4_arr[i].end);
        
        if (string_compare(string_to_substr, correct_result) == 1) {
            printf("OK\n");
        } else {
            printf("ERROR\n");
            break;
        }
    }
    
    if (i >= STRING_TESTS_UNIT_4_TESTS_COUNT) {
        printf("[UNIT TESTING] Unit 4 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 4 testing FAILED on TEST #%i.\n", i+1);
        printf("[UNIT TESTING] String: '%s'. Begin: %i. End: %i. Correct result: %s. Calculated result: %s.\n", string_get(string_to_substr), string_tests_unit_4_arr[i].begin, string_tests_unit_4_arr[i].end,  string_get(correct_result), string_get(string_to_substr));
    }
    
    printf("\n\n");
}
