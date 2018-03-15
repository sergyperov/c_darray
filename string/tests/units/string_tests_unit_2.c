#include "string_tests_unit_2.h"

/*
 МОДУЛЬ 2
 Цель: Тестируем вычисление длины
 Тестируемые методы: string_length()
 Действия:      1) Создаём новую переменную string* str  с помощью string_new()
                2) Присваеваем ей некоторое значение помощью string_set()
                3) Метод string_length() должен вернуть длину строки (т.е. количесвто символов строки)
 Условие прохождения теста: метод string_length() возращает значение, равное реальной длине строки
 */
const int STRING_TESTS_UNIT_2_TESTS_COUNT = ALPHABET_LENGTH + 11;
struct string_tests_unit_2_struct {
    char* string_to_mesure;
    int correct_length;
};
struct string_tests_unit_2_struct string_tests_unit_2_struct_new(char* string_to_mesure, int correct_length) {
    struct string_tests_unit_2_struct new_struct;
    new_struct.string_to_mesure = string_to_mesure;
    new_struct.correct_length = correct_length;
    
    return new_struct;
}
struct string_tests_unit_2_struct string_tests_unit_2_arr[STRING_TESTS_UNIT_2_TESTS_COUNT];
void string_tests_unit_2_fulfil() {
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
        string_tests_unit_2_arr[i] = string_tests_unit_2_struct_new(alphabet[i], 1);
    }
    
    string_tests_unit_2_arr[ALPHABET_LENGTH] = string_tests_unit_2_struct_new("simple", 6);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 1] = string_tests_unit_2_struct_new("CAPS", 4);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 2] = string_tests_unit_2_struct_new("CoMbInAtIoN", 11);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 3] = string_tests_unit_2_struct_new("            ", 12);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 4] = string_tests_unit_2_struct_new("some whitespace", 15);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 5] = string_tests_unit_2_struct_new(".?!@(*&#", 8);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 6] = string_tests_unit_2_struct_new("Now, We combiNe iT ALL!!!", 25);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 7] = string_tests_unit_2_struct_new("(){}[]", 6);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 8] = string_tests_unit_2_struct_new("\\\\\\\\", 4);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 9] = string_tests_unit_2_struct_new("", 0);
    string_tests_unit_2_arr[ALPHABET_LENGTH + 10] = string_tests_unit_2_struct_new("!", 1);
}
void string_tests_unit_2() {
    printf("[UNIT TESTING] UNIT 2: %i tests upcoming...\n", STRING_TESTS_UNIT_2_TESTS_COUNT);
    int  i;
    int test_length = -1;
    for (i = 0; i < STRING_TESTS_UNIT_2_TESTS_COUNT; i++) {
        printf("[UNIT TESTING] TEST #%i: ", i+1);
        string* test_string = string_new();
        string_set(test_string, string_tests_unit_2_arr[i].string_to_mesure);
        test_length = string_length(test_string);
        
        if (test_length == string_tests_unit_2_arr[i].correct_length) {
            printf("OK\n");
        } else {
            printf("ERROR\n");
            break;
        }
    }
    
    if (i >= STRING_TESTS_UNIT_2_TESTS_COUNT) {
        printf("[UNIT TESTING] Unit 2 testing SUCCESSEDED.\n");
    } else {
        printf("[UNIT TESTING] Unit 2 testing FAILED on TEST #%i.\n", i+1);
        printf("[UNIT TESTING] String: '%s'. Correct length: %i. Calculated length: %i.\n", string_tests_unit_2_arr[i].string_to_mesure, string_tests_unit_2_arr[i].correct_length, test_length);
    }
    printf("\n\n");
}
