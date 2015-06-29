#include "string.h"

#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

void trim(char** str) {
    char* new_end;
    while (isspace(**str)) {
        (*str)++;
    }
    new_end = *str + strlen(*str);
    while (isspace(*(new_end - 1))) {
        new_end--;
    }
    *new_end = '\0';
}

bool starts(char* str, char* str2) {
    return memcmp(str, str2, strlen(str2));
}

void split(char*** result, size_t* token_count, char* str, char delimiter) {
    *token_count = 0;
    if (*str == '\0') { // String is empty.
        return;
    }
    char* temp = str;
    char* start = str;
    while (true) {
        temp++;
        ptrdiff_t diff = temp - start;
        if (*temp == delimiter) {
            *result = realloc((*result), sizeof(char*) * (*token_count + 1));
            (*result)[*token_count] = strndup(start, diff);
            start = temp + 1;
            (*token_count)++;
        } else if (*temp == '\0') {
            *result = realloc((*result), sizeof(char*) * (*token_count + 1));
            (*result)[*token_count] = strndup(start, diff);
            (*token_count)++;
            return;
        }
    }
}

void free_tokens(char** tokens, size_t token_count) {
    for (size_t i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
