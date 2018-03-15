#include "string_cli.h"

darray* strings_darray;

extern int ceaser_shift;

string* string_darray_get_elem_by_index(darray* darr, int index) {
    darray_node* darr_n = darray_get_elem_by_index(darr, index);
    
    string *x;
    x = darr_n->item;
    
    return x;
}

void cli_help() {
    printf("List of commands:\n");
    printf("add\n");
    printf("concat\n");
    printf("substr\n");
    printf("encode\n");
    printf("help\n");
    printf("quit\n");
    printf("\n");
}

void cli_add() {
    printf("Enter new string: ");
    string* str = string_new();
    
    getchar();
    while(1) {
        string* new_str = string_new();
        char c = getchar();
        if (c == '\n') {
            break;
        }
        
        char *ptr = malloc(2*sizeof(char));
        ptr[0] = c;
        ptr[1] = '\0';
        string_set(new_str, ptr);
        string_concat(str, new_str);
        free(ptr);
    }
    darray_push_back(strings_darray, str);
    printf("String added.\n\n");
}

void cli_concat() {
    int intitial_string_id;
    int additional_string_id;
    
    printf("Enter initial string id: ");
    scanf("%i", &intitial_string_id);
    if ((intitial_string_id < 0) || (intitial_string_id >= darray_size(strings_darray))) {
        printf("Input error! Aborting...\n\n");
        return;
    }
    
    printf("Enter additional string id: ");
    scanf("%i", &additional_string_id);
    if ((additional_string_id < 0) || (additional_string_id >= darray_size(strings_darray))) {
        printf("Input error! Aborting...\n\n");
        return;
    }
    
    string_concat(string_darray_get_elem_by_index(strings_darray, intitial_string_id), string_darray_get_elem_by_index(strings_darray, additional_string_id));
}

void cli_substr() {
    int string_id;
    int i, j;
    
    printf("Enter initial string id: ");
    scanf("%i", &string_id);
    if ((string_id < 0) || (string_id >= darray_size(strings_darray))) {
        printf("Input error! Aborting...\n\n");
        return;
    }
    
    printf("Enter i: ");
    scanf("%i", &i);
    if ((i < 0) || (i >= string_length(string_darray_get_elem_by_index(strings_darray, string_id)))) {
        printf("Input error! Aborting...\n\n");
        return;
    }
    
    printf("Enter j: ");
    scanf("%i", &j);
    if ((j < 0) || (i > j) || (j >= string_length(string_darray_get_elem_by_index(strings_darray, string_id)))) {
        printf("Input error! Aborting...\n\n");
        return;
    }
    
    string_substr(string_darray_get_elem_by_index(strings_darray, string_id), i, j);
}

void cli_list() {
    printf("Printing %i strings. \n", darray_size(strings_darray));
    for (int i = 0; i < darray_size(strings_darray); i++) {
        string* str = string_darray_get_elem_by_index(strings_darray, i);
        
        printf("id: %i, string: %s\n", i, string_get(str));
    }
}

void cli_encode() {
    int string_id;
    int requested_shift;
    
    printf("Enter string id: ");
    scanf("%i", &string_id);
    if ((string_id < 0) || (string_id >= darray_size(strings_darray))) {
        printf("Input error! Aborting...\n\n");
        return;
    }
    
    printf("Enter ceaser cipher shift: ");
    scanf("%i", &requested_shift);
    ceaser_shift = requested_shift;
    
    string_encode(string_darray_get_elem_by_index(strings_darray, string_id), ceaser_cipher);
}

void cli_init() {
    strings_darray = darray_new(sizeof(string));
    printf("Welcome to string library CLI!\n");
    char command[256];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            cli_add();
        } else if (strcmp(command, "list") == 0) {
            cli_list();
        } else if (strcmp(command, "concat") == 0) {
            cli_concat();
        } else if (strcmp(command, "substr") == 0) {
            cli_substr();
        } else if (strcmp(command, "encode") == 0) {
            cli_encode();
        } else if (strcmp(command, "help") == 0) {
            cli_help();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("No such command! Try 'help'.\n\n");
        }
    }
};
