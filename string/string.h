#ifndef string_h
#define string_h

#include <stdio.h>
#include <stdlib.h>
#include "darray.h"
#include "darray_wrappers.h"

typedef struct string string;

typedef struct string {
    darray* darr;
    char* buffer;
} string;

string* string_new(void);
void string_set(string* str, char* value);
void string_encode (string* str, char (*f)(char));
void string_substr(string* str, int i, int j);
int string_length(string* str);
void string_concat(string* str1, string* str2);
char* string_get(string* str);
int string_compare(string* str1, string* str2);
void string_free(string* str);
void string_copy(string* str_to, string* str_from);

#endif /* string_h */
