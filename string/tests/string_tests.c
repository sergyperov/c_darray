/*
 Оболочка для тестирования string
 Всего есть 6 модулей, каждый из которых тестирует определённый функционал.
 Все модули лежат в папке units.
 
 Вызвать тестирование можно методом string_run_tests()
 */

#include "string_tests.h"

// Базовый алфавит, включающий в себя 94 символа и пробел
char* alphabet[ALPHABET_LENGTH] = {"!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\\", "]", "^", "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~", " "};

void init_structs() {
    string_tests_unit_1_fulfil();
    string_tests_unit_2_fulfil();
    string_tests_unit_3_fulfil();
    string_tests_unit_4_fulfil();
    string_tests_unit_5_fulfil();
    string_tests_unit_6_fulfil();
}

void string_run_tests() {
    init_structs();
    
    string_tests_unit_1();
    string_tests_unit_2();
    string_tests_unit_3();
    string_tests_unit_4();
    string_tests_unit_5();
    string_tests_unit_6();
}
