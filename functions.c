// Различные функции-кодировщики

#include "functions.h"

char simple_f(char a) {
    return a;
}

char uppercase_char(char a) {
    int a_code = (int) a;
    
    if ((a_code >= 97) && (a_code <= 122)) {
        a_code -= 32;
    }
    
    char result = (char) a_code;
    return result;
}

char lowercase_char(char a) {
    int a_code = (int) a;
    
    if ((a_code >= 65) && (a_code <= 90)) {
        a_code += 32;
    }
    
    char result = (char) a_code;
    return result;
}

int ceaser_shift = 8;
char ceaser_cipher(char a) {
    ceaser_shift %= 26;
    int a_code = (int) a;
    if (a > 0) {
        if ((a_code >= 65) && (a_code <= 90)) {
            if ((a_code + ceaser_shift) > 90) {
                a_code = 65 + (a_code + ceaser_shift - 90 - 1);
            } else if ((a_code + ceaser_shift) < 65) {
                a_code = 90 - (65 - (a_code + ceaser_shift + 1));
            } else {
                a_code += ceaser_shift;
            }
        }
        if ((a_code >= 97) && (a_code <= 122)) {
            if ((a_code + ceaser_shift) > 122) {
                a_code = 97 + (a_code + ceaser_shift - 122 - 1);
            } else if ((a_code + ceaser_shift) < 97) {
                a_code = 122 - (97 - (a_code + ceaser_shift + 1));
            } else {
                a_code += ceaser_shift;
            }
        }
    }
    
    char result = (char) a_code;
    return result;
}
